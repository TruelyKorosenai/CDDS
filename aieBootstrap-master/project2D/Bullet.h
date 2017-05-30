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
	void SetVelocity (Vector2 velocity);
	void UpdateVelocity (float deltaTime);
	void UpdateTimer (float deltaTime);
	
	float m_timer;
private:

    friend class BulletPool; // Allow BulletPool access to 'm_count'
    float m_counter;
	Vector2 m_velocity;
};

