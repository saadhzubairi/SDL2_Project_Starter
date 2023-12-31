#pragma once

#include "SDL.h"
#include "../TextureManager/TextureManager.h"
#include "../Utilities/Counters.h"
class GameObject {

public:

    GameObject(const char *textureSheet, int x, int y, int sheetSizeX, int sheetSizeY, int rows, int cols, double zoom);
    ~GameObject();

    virtual void Render();

    bool isAlive();
    void Destroy();
    virtual void Move() = 0;
    void Translate(int x, int y);

    int xPos, yPos;
    float fric, tX, tY;
    bool alive = true;
    void setObjTexture(const char *textureSheet, int sheetSizeX,int sheetSizeY,int rows,int cols,double zoom);
    SDL_Texture *objTexture;
    SDL_Rect destR;
    SDL_Rect spriteSourceRects[16];

    virtual void Update();

    int NumOfSprites;
    int ObjHeight;
    int ObjWidth;

    int xMin;
    int xMax;
    int yMin;
    int yMax;

};