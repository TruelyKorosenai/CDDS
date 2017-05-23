#pragma once
#include "Object.h"
#include <Renderer2D.h>
#include <Application.h>
#include "Application2D.h"
#include <vector>
#include <KoroMaths.h>
#include <Texture.h>


// Tank represents a game object that is a tank vehicle. It
// encapsulates multiple 'Object' objects for the various parts of the tank.
class Tank : public Object
{
public:
    //--FUNCTIONS--//
    Tank(aie::Renderer2D *renderer, Vector2 scale, Vector2 position);
    Tank();
    ~Tank();

    void rotateHead(float angle);
    void rotateBody(float angle);


//**************************************************************************************

    //--VARIABLES--//


private:
    void SetEverything(Vector2 scale, Vector2 position); //This function will set the scale, position, and the textures.

};

