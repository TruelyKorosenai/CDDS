#pragma once
#include <Application.h>
#include <Renderer2D.h>
#include <KoroMaths.h>
#include <vector>


// Object represents all visual game objects that can exist in the world.
// It is a hierarchy of other Objects that represent the copmponent parts of the 
// game object. It provides the basic functions for animation, movement and rendering.
// It is a base class from which all other game object classes will derive.
class Object
{
public:

    //--FUNCTIONS--//

    Object(aie::Renderer2D *renderer, aie::Texture *texture); //custom constructor
    Object(const Object & other); //copy constructor
    Object();
    ~Object();
    void SetPosition(float x, float y); //set position 
    void SetScale(float x, float y); //set scale
    void SetTexture(aie::Renderer2D *renderer, aie::Texture *texture); //set texture

    void Draw(Matrix3 parent);
    void CalculateHierachy();
    void Calculate();
//**************************************************************************************

    //--VARIABLES--//
    float m_rotate;
    Vector2 m_scale;
    Vector2 m_position;
    Matrix3 m_modelmatrix; //One Matirx which stores the final SRT results after final calculation

    std::vector<Object> m_children; //used to create a dynamic hierachy of objects
    aie::Texture    *m_texture;
protected:
    aie::Renderer2D *m_renderer;
};

