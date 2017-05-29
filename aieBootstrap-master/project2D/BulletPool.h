#pragma once
#include "Bullet.h"
#include <Renderer2D.h>
class BulletPool
{
public:
    BulletPool(aie::Renderer2D *renderer);
    ~BulletPool();

    void Spawn(float x, float y, Vector3 velocity);
    void Update(float deltatime);



private:

    void Manage(Bullet *bullet);
    void Delete(Bullet *bullet);

    std::vector<Bullet *> m_bullets;
    aie::Renderer2D *m_renderer;
};

