#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Tank.h"
#include "Bullet.h"
#include "BulletPool.h"
float times = 0;


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

    //new bullet
    m_bulletPool = new BulletPool(m_2dRenderer);

    //load textures
    m_background = new aie::Texture("./textures/concrete.png");

   

    // Create a background object. We do this first so that the background will
    // always be under the tanks.
    Object *background = new Object;
    background->SetScale(3, 3); //2.3 //2.3
    background->SetTexture(m_2dRenderer, m_background);
    background->SetPosition(halfX, textTop); //0 = x, 1 = y

    // ...and add it to the scene.
    m_scene.push_back(background);



    // Create a new tank and store its pointer for later use
    m_tankOne = new Tank(m_2dRenderer, Vector2(0.7,0.7), Vector2(100, 100));

    // ...and add it to the scene.
    m_scene.push_back(m_tankOne);

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
    times += deltaTime;
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
    //m_tankOne->rotateHead(-0.2);
   // m_tankOne->rotateBody(0.05);
    PlayerOneControls(deltaTime);
    PlayerTwoControls(deltaTime);

    /////////////////
    /////Update bullet
    ////////////////
    m_bulletPool->Update(deltaTime);

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

     /////////////////
     /////Draw all scene objects
     ////////////////
    for (size_t i = 0; i < m_scene.size(); i++)
    {
        m_scene[i]->Draw(Matrix3());
    }

     m_2dRenderer->end();
}



/////////////////////////////////////////
//Player One controls
////////////////////////////////////////
void Application2D::PlayerOneControls(float deltaTime)
{
    aie::Input* input = aie::Input::getInstance();

    //move tank forward
    if (input->isKeyDown(aie::INPUT_KEY_UP))
    {
        m_tankTwo->MoveForward(deltaTime);
    }

    //move tank backwards
    if (input->isKeyDown(aie::INPUT_KEY_DOWN))
    {
        m_tankTwo->MoveBackward(deltaTime);
    }

    //rotate body left
    if (input->isKeyDown(aie::INPUT_KEY_LEFT))
    {
        m_tankTwo->rotateBody(2 * deltaTime);
    }

    //rotate body right
    if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
        m_tankTwo->rotateBody(-2 * deltaTime);

    //rotate head left
    if (input->isKeyDown(aie::INPUT_KEY_DELETE))
        m_tankTwo->rotateHead(-1 * deltaTime);

    //rotate head right
    if (input->isKeyDown(aie::INPUT_KEY_END))
        m_tankTwo->rotateHead(1 * deltaTime);

    if (input->wasKeyPressed(aie::INPUT_KEY_L))
    {

		Matrix3 mat1 = m_tankTwo->m_modelmatrix;
		Matrix3 mat2 = m_tankTwo->m_children[0].m_modelmatrix;
		Matrix3 mat3 = m_tankTwo->m_children[0].m_children[0].m_modelmatrix;
		
		Vector3 velocity = (mat1 * mat2 * mat3) * Vector3 (0, 1, 0);
		
        m_bulletPool->Spawn(m_tankTwo->m_position.m_x, m_tankTwo->m_position.m_y, velocity * 750);
     }
                
}



/////////////////////////////////////////
//Player Two controls
////////////////////////////////////////
void Application2D::PlayerTwoControls(float deltaTime)
{
    aie::Input* input = aie::Input::getInstance();

    //move tank forward
    if (input->isKeyDown(aie::INPUT_KEY_W))
    {
        m_tankOne->MoveForward(deltaTime);
    }

    //move tank backwards
    if (input->isKeyDown(aie::INPUT_KEY_S))
    {
        m_tankOne->MoveBackward(deltaTime);
    }

    //rotate body left
    if (input->isKeyDown(aie::INPUT_KEY_A))
    {
        m_tankOne->rotateBody(2 * deltaTime);
    }

    //rotate body right
    if (input->isKeyDown(aie::INPUT_KEY_D))
        m_tankOne->rotateBody(-2 * deltaTime);

    //rotate head left
    if (input->isKeyDown(aie::INPUT_KEY_Q))
        m_tankOne->rotateHead(-1 * deltaTime);

    //rotate head right
    if (input->isKeyDown(aie::INPUT_KEY_E))
        m_tankOne->rotateHead(1 * deltaTime);

	if (input->wasKeyPressed (aie::INPUT_KEY_SPACE))
	{

		Matrix3 mat1 = m_tankOne->m_modelmatrix;
		Matrix3 mat2 = m_tankOne->m_children[0].m_modelmatrix;
		Matrix3 mat3 = m_tankOne->m_children[0].m_children[0].m_modelmatrix;

		Vector3 velocity = (mat1 * mat2 * mat3) * Vector3 (0, 1, 0);

		m_bulletPool->Spawn (m_tankOne->m_position.m_x, m_tankOne->m_position.m_y, velocity * 750);
	}
}

void Application2D::addToScene(Object *object)
{
    m_scene.push_back(object);

}

// Static function to return a reference to the static global instance of APplication2D
Application2D & Application2D::instance()
{
    static Application2D app; // This has global application lifetime!!! NOT local!!!

    return app;
}




//in the update section!!
//
//// use arrow keys to move camera
//if (input->isKeyDown(aie::INPUT_KEY_UP))
//m_cameraY += 500.0f * deltaTime;
//
//if (input->isKeyDown(aie::INPUT_KEY_DOWN))
//m_cameraY -= 500.0f * deltaTime;
//
//if (input->isKeyDown(aie::INPUT_KEY_LEFT))
//m_cameraX -= 500.0f * deltaTime;
//
//if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
//m_cameraX += 500.0f * deltaTime;
//
//// example of audio
//if (input->wasKeyPressed(aie::INPUT_KEY_SPACE))
//m_audio->play();
//
//// exit the application
//if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
//quit();