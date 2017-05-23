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

void Tank::rotateHead(float angle)
{
   
    m_children[0].m_rotate += angle;

}



void Tank::rotateBody(float angle)
{
   
    m_rotate += angle;

}



/////////////////////////////////////////
//Set everything function
////////////////////////////////////////
void Tank::SetEverything(Vector2 scale, Vector2 position)
{
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