#include "Object.h"

/////////////////////////////////////////
//Custom Constructor
////////////////////////////////////////
Object::Object(aie::Renderer2D *renderer, aie::Texture *texture)
{
    m_texture = texture;
    m_renderer = renderer;
    m_rotate = 0;
}


/////////////////////////////////////////
//Constructor
////////////////////////////////////////
Object::Object()
{
    m_renderer = nullptr;
    m_texture = nullptr;
    m_rotate = 0;
}


/////////////////////////////////////////
//Copy Constructor
////////////////////////////////////////
Object::Object(const Object & other)
{
    //setting all the values to itself
    m_texture = other.m_texture;
    m_renderer = other.m_renderer;
    m_scale = other.m_scale;
    m_position = other.m_position;
    m_rotate = other.m_rotate;
    m_children = other.m_children;
}


Object::~Object()
{
}


/////////////////////////////////////////
//SetPosition
////////////////////////////////////////
void Object::SetPosition(float x, float y)
{
    m_position.m_x = x; m_position.m_y = y;
}


/////////////////////////////////////////
//SetScale
////////////////////////////////////////
void Object::SetScale(float x, float y)
{
    m_scale.m_x = x; m_scale.m_y = y;
}


/////////////////////////////////////////
//SetTexture
////////////////////////////////////////
void Object::SetTexture(aie::Renderer2D *renderer, aie::Texture *texture)
{
    m_renderer = renderer; m_texture = texture;
}


/////////////////////////////////////////
//Draw
////////////////////////////////////////
void Object::Draw(Matrix3 parent)
{
    if (m_texture != NULL)
    {
    m_renderer->drawSpriteTransformed3x3(m_texture, parent * m_modelmatrix); //draw final calculation on screen
    }

    for (size_t i = 0; i < m_children.size(); i++) //go through all the children of the main object and draw them on screen.
                                        //parents always come first in the hierachy. dont touch children without their parents!
    {
        m_children[i].Draw(parent * m_modelmatrix);
    }
}


/////////////////////////////////////////
//Calculate Hierachy
////////////////////////////////////////
void Object::CalculateHierachy()
{
    Matrix3 translateM1;
    Matrix3 rotateM2;
    Matrix3 scaleM3;

    translateM1 = translateM1.SetTranslateVectors (m_position); //set the position
    rotateM2.setRotateZ(m_rotate); //set the rotation
    scaleM3 = scaleM3.SetScaleWithVectors (m_scale); //set the scale

    m_modelmatrix = translateM1 * rotateM2 * scaleM3; //times all together to get final result.
}


/////////////////////////////////////////
//Call this calculate function
////////////////////////////////////////
void Object::Calculate()
{
    CalculateHierachy(); //call function, then proceed onto calculating all the children
                         //parents always come first in the hierachy. dont touch children without their parents!
    for (size_t i = 0; i < m_children.size(); i++)
    {
        m_children[i].Calculate();
    }
}