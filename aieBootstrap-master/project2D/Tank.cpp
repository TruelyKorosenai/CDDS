#include "Tank.h"

/////////////////////////////////////////
//Custom constructor
////////////////////////////////////////
Tank::Tank(aie::Renderer2D *renderer, Vector2 scale, Vector2 position)
{
    m_renderer = renderer;
    m_texture = new aie::Texture("./textures/tankGreen.png");
    m_rotate = 0;
    SetEverything(scale,position);
}


/////////////////////////////////////////
//Constructor
////////////////////////////////////////
Tank::Tank()
{
    m_renderer = nullptr;
    m_texture = nullptr;
    m_rotate = 0;
}

Tank::~Tank()
{
   
}


/////////////////////////////////////////
//Set everything function
////////////////////////////////////////
//this function is used to set the texture of the head and barrel attached to the tank, and set the positions and scale
void Tank::SetEverything(Vector2 scale, Vector2 position)
{




    //m_texture = new aie::Texture("./textures/tankGreen.png");
    Object tank_head(m_renderer, new aie::Texture("./textures/ball.png"));
    Object tank_barrel(m_renderer, new aie::Texture("./textures/barrelRed.png"));

    //set the positions
    //set tank
    this->SetScale(scale.m_x, scale.m_y); //0.6,0.6
    this->SetPosition(position.m_x, position.m_y); //half x, half y , 40,40. position

    //set tank head scale
    tank_head.SetScale(scale.m_x + 0.1, scale.m_y + 0.1);

    //set the tank barrel
    tank_barrel.SetScale(scale.m_x + 0.2, scale.m_y + 0.2);
    tank_barrel.SetPosition(0, 30);

    //--
    //CREATE THE HIERACHY OF THE TANK
    //--
    tank_head.m_children.push_back(tank_barrel);
    this->m_children.push_back(tank_head);

}



void Tank::rotateHead(float angle)
{
   // m_children[1].m_rotate += 0.01f;
    m_children[0].m_rotate += angle;

}



void Tank::rotateBody(float angle)
{
    // m_children[1].m_rotate += 0.01f;
    m_rotate += angle;

}


/////////////////////////////////////////
//Move Forward function
////////////////////////////////////////
//In this where using a direction vector to allow the tank to move in the direction that we are facing (the way we have rotated)
void Tank::MoveForward(float deltatime)
{
    Matrix3 setrotateMatrix;
    Vector3 directionVector(0, 1, 0); //the direction vector x,y,z controls which way im facing. x = 0, y = positive 1, z = 0. (the direction is positive y.
                                       //if it was x = 1, y = 0, z = 0 (1,0,0), it means we would go positive on the x axis.

    setrotateMatrix.setRotateZ(m_rotate);
    directionVector = setrotateMatrix * directionVector; //returning a vector from matrix times a vector

    this->m_position.m_x += directionVector.m_x * 400 * deltatime;
    this->m_position.m_y += directionVector.m_y * 400 * deltatime;
}


/////////////////////////////////////////
//Move Backward function
////////////////////////////////////////
void Tank::MoveBackward(float deltatime)
{
    Matrix3 setrotateMatrix;
    Vector3 directionVector(0, -1, 0); //the direction vector x,y,z controls which way im facing. x = 0, y = positive 1, z = 0. (the direction is positive y.
                                      //if it was x = 1, y = 0, z = 0 (1,0,0), it means we would go positive on the x axis.

    setrotateMatrix.setRotateZ(m_rotate);
    directionVector = setrotateMatrix * directionVector; //returning a vector from matrix times a vector

    this->m_position.m_x += directionVector.m_x * 40 * deltatime;
    this->m_position.m_y += directionVector.m_y * 40 * deltatime;
}


