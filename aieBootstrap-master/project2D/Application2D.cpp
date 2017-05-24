#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Tank.h"
float time = 0;


Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {
    //--
    //credit fransico for this position code.
    //--
    float sizeX = float(this->getWindowWidth());
    float sizeY = float(this->getWindowHeight());
    float halfX = float(this->getWindowWidth()) / 2.0f;
    float halfY = float(this->getWindowHeight()) / 2.0f;
    float textTop = halfY + (halfY - 325);


    //load renderer
    m_2dRenderer = new aie::Renderer2D();

    //load textures
  
    //--
    // set object tree
    //--

    // Create a background object first so its behind    


    // Create another tank
    m_tankTwo = new Tank(m_2dRenderer, Vector2(0.7, 0.7), Vector2(300, 300));

    // ...and add it to the scene.
    m_scene.push_back(m_tankTwo);


    return true;
}

void Application2D::shutdown() {
	//delete all the created memory in here
    delete m_2dRenderer;
}

void Application2D::update(float deltaTime) {

    // input example
    aie::Input* input = aie::Input::getInstance();

    //--
    //credit fransico for the size management below
    //--
    time += deltaTime;
    float halfX = float(this->getWindowWidth()) / 2.0f;
    float halfY = float(this->getWindowHeight()) / 2.0f;
    float textTop = halfY + (halfY - 325);
    float textBottom = halfY - (halfY - 325);

    /////////////////
    /////Update background
    ////////////////
/************************
    m_objectbackground1.m_position.m_x = halfX;
    m_objectbackground2.m_position.m_x = halfX;
    m_objectbackground1.m_position.m_y -= deltaTime * 50;
    m_objectbackground2.m_position.m_y -= deltaTime * 50;     //make the background go down the screen

    if (m_objectbackground1.m_position.m_y < (textBottom - 650)) m_objectbackground1.m_position.m_y = textTop + 650;
    if (m_objectbackground2.m_position.m_y < (textBottom - 650)) m_objectbackground2.m_position.m_y = textTop + 650;
**********************/


    /////////////////
    /////Update tank
    ////////////////
  
    Matrix3 Pos;
    Vector3 forward(0, 1, 0);
    if (input->isKeyDown(aie::INPUT_KEY_UP))
    {
       Pos.setRotateZ(m_tankTwo->m_rotate);
       forward = Pos * forward;
       m_tankTwo->m_position.m_x += forward.m_x * 600 * deltaTime;
       m_tankTwo->m_position.m_y += forward.m_y * 600 * deltaTime;
    }
    
    if (input->isKeyDown(aie::INPUT_KEY_LEFT))
    {
        m_tankTwo->rotateBody(6 * deltaTime);
    }
    
    if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
        m_tankTwo->rotateBody(-6 * deltaTime);

    //rotate head
    if (input->isKeyDown(aie::INPUT_KEY_END))
        m_tankTwo->rotateHead(6 * deltaTime);

    if (input->isKeyDown(aie::INPUT_KEY_DELETE))
        m_tankTwo->rotateHead(-6*deltaTime);
        

    


    /////////////////
    /////Final calculations
    ////////////////
    for (size_t i = 0; i < m_scene.size(); i++)
    {
        m_scene[i]->Calculate();
    }

}

void Application2D::draw() {

    //wipe the screen to the background color
    clearScreen();

    // begin drawing sprites
    m_2dRenderer->begin();
    ////////////////////////////////
    ///////////START DRAWING///////
    ///////////////////////////////


    /////////////////
    /////Draw Background
    ////////////////
/***********************
     m_objectbackground1.Draw(Matrix3());
     m_objectbackground2.Draw(Matrix3());
***********************/


     /////////////////
     /////Draw all scene objects
     ////////////////
    for (size_t i = 0; i < m_scene.size(); i++)
    {
        m_scene[i]->Draw(Matrix3());


    }

     m_2dRenderer->end();
}