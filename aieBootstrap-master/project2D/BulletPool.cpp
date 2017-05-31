#include "BulletPool.h"



BulletPool::BulletPool(aie::Renderer2D *renderer)
{
    m_renderer = renderer;
}


BulletPool::~BulletPool()
{
}



void BulletPool::Spawn(float x, float y, float rotation, Vector3 velocity)
{
	Bullet *bullet = new Bullet(m_renderer); //pass in velcity into bullet.
    bullet->SetScale(1, 1);
    bullet->SetPosition(x, y);
	bullet->m_rotate = rotation;
	bullet->SetVelocity(Vector2(velocity.m_x, velocity.m_y));
    m_bullets.push_back(bullet);
    Application2D::instance().addToScene(bullet);
//    Application2D::addToScene(bullet);
}


void BulletPool::Update(float deltatime)
{
    for (size_t i = 0; i < m_bullets.size(); i++)
    {
		m_bullets[i]->UpdateTimer(deltatime);
        if (m_bullets[i]->m_timer >= 4.0f)
        {
            Delete(m_bullets[i]);
        }
        else
        {
			
            Manage(m_bullets[i], deltatime);
            //manage the bullet, collisions etc., increase position in the direction of its velocity.
		}
    }
}



void BulletPool::Delete (Bullet *bullet)
{
	//delete the bullet
	m_bullets.erase(m_bullets.begin());
	
}

void BulletPool::Manage(Bullet *bullet, float deltaTime)
{
    //increase position according to the velocity //moving bullet.
	
	bullet->UpdateVelocity (deltaTime);
}