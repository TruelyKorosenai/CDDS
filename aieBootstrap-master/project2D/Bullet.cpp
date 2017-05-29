#include "Bullet.h"



Bullet::Bullet(aie::Renderer2D *renderer) //pass in velocity
{
    m_rotate = 0;
    m_renderer = renderer;
    m_texture = new aie::Texture("./textures/bullet.png");
    m_counter = 0;
    //store a vector 3, for velocity, siz
}

Bullet::Bullet()
{

}



Bullet::~Bullet()
{
}

//get direction of tank barrel, normalise it, that = direction. velocity = direction *times by speed, (float)
//m_position += velocity *deltatime