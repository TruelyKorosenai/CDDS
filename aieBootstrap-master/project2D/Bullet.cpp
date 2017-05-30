#include "Bullet.h"



Bullet::Bullet(aie::Renderer2D *renderer) //pass in velocity

{
	m_timer = 0;
    m_rotate = 0;
    m_renderer = renderer;
    m_texture = new aie::Texture("./textures/bullet.png");
    m_counter = 0;
    //store a vector 3, for velocity, size
}

Bullet::Bullet()
{
	m_timer = 0;
}



Bullet::~Bullet()
{
}

void Bullet::SetVelocity (Vector2 velocity)
{
	m_velocity = velocity;
}

void Bullet::UpdateVelocity (float deltaTime)
{
	m_position = m_position + (m_velocity * deltaTime);
}

void Bullet::UpdateTimer (float deltaTime)
{
	m_timer	+= deltaTime;
}

