#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"
#include "Object.h"


//#include "Bullet.h"

// Forward declaration
class Tank;
class BulletPool;


// Singleton
class Application2D : public aie::Application {
public:

    static Application2D & instance();

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

    //--my custom coded functions--//
    void PlayerTwoControls(float deltaTime);
    void PlayerOneControls(float deltaTime);

    void addToScene(Object *object);

protected:

    // The world, i.e. our "scene", is an array of all objects in the scene, i.e. a "scene graph".
    std::vector<Object *> m_scene;
   // std::vector<Bullet *> m_bulletScene;

    // Out two tanks for both players
    Tank *m_tankOne;
    Tank *m_tankTwo;
   
    


/*********************
    //background objects
    Object              m_objectbackground1;
    Object              m_objectbackground2;
*****************/

    //background texture
    aie::Texture*       m_background;

    //renderer
    aie::Renderer2D*	m_2dRenderer;

    BulletPool *m_bulletPool;
private:
    
};