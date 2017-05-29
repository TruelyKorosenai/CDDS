#pragma once
#include "Object.h"
#include "Application2D.h"
#include <Texture.h>



class Bullet : public Object
{
public: 
    Bullet(aie::Renderer2D *renderer);
    Bullet();
    ~Bullet();
    //get velocity function

private:

    friend class BulletPool; // Allow BulletPool access to 'm_count'
    float m_counter;
    //private vector3
};

