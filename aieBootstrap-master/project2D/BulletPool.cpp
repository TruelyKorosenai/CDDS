#include "BulletPool.h"



BulletPool::BulletPool(aie::Renderer2D *renderer)
{
    m_renderer = renderer;
}


BulletPool::~BulletPool()
{
}



void BulletPool::Spawn(float x, float y, Vector3 velocity)
{
    Bullet *bullet = new Bullet(m_renderer); //pass in velcity into bullet.
    bullet->SetScale(1, 1);
    bullet->SetPosition(x, y);
    m_bullets.push_back(bullet);
    
    Application2D::instance().addToScene(bullet);
//    Application2D::addToScene(bullet);
}


void BulletPool::Update(float deltatime)
{
    for (size_t i = 0; i < m_bullets.size(); i++)
    {
        // The current bullet
        Bullet *bullet = m_bullets[i];

        bullet->m_counter += deltatime;
        if (bullet->m_counter > 4)
        {
            Delete(bullet);
        }
        else
        {
            Manage(bullet);
            //manage the bullet, collisions etc., increase position in the direction of its velocity.
        }
    }
}



void BulletPool::Delete(Bullet *bullet)
{
    //delete the bullet
}


void BulletPool::Manage(Bullet *bullet)
{
    
    //increase position according to the velocity //moving bullet.
}