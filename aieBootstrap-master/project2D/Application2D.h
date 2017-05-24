#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"
#include "Object.h"

// Forward declaration
class Tank;

class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

    // The world, i.e. our "scene", is an array of all objects in the scene, i.e. a "scene graph".
    std::vector<Object *> m_scene;

    // creating a tank
   // Tank *m_tankOne;
    Tank *m_tankTwo;
    
    //renderer
    aie::Renderer2D*	m_2dRenderer;
};