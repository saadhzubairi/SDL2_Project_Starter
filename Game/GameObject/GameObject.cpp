#include "GameObject.h"
#include "../game.h"


GameObject::GameObject(const char *textureSheet, int x, int y, int sheetSizeX, int sheetSizeY, int rows, int cols,
                       double zoom) {
    objTexture = TextureManager::LoadSprite(textureSheet, sheetSizeX, sheetSizeY, rows, cols, spriteSourceRects);
    xPos = x;
    yPos = y;
    tX = 0;
    tY = 0;
    fric = 0.95;
    this->NumOfSprites = rows * cols;
    this->ObjWidth = sheetSizeX / cols * zoom;
    this->ObjHeight = sheetSizeY / rows * zoom;
}

GameObject::~GameObject() = default;

void GameObject::Update() {
    destR.h = this->ObjHeight;
    destR.w = this->ObjWidth;
    destR.x = xPos - destR.w / 2;
    destR.y = yPos - destR.h / 2;

    this->xMin = xPos - ObjWidth / 2;
    this->xMax = xMin + ObjWidth;
    this->yMin = yPos - ObjHeight / 2;
    this->yMax = yMin + ObjHeight;
}

/*void GameObject::UpdateObject() {

}*/

void GameObject::Render() {

    SDL_RenderCopy(game::renderer, objTexture, &spriteSourceRects[Counters::spriteFrame % this->NumOfSprites], &destR);
}


void GameObject::Destroy() {
    alive = false;
}

bool GameObject::isAlive() {
    return alive;
}

void GameObject::Move() {}

void GameObject::Translate(int x, int y) {
    this->tX = x;
    this->tY = y;
}

void
GameObject::setObjTexture(const char *textureSheet, int sheetSizeX, int sheetSizeY, int rows, int cols, double zoom) {
    objTexture = TextureManager::LoadSprite(textureSheet, sheetSizeX, sheetSizeY, rows, cols, spriteSourceRects);
    this->NumOfSprites = rows * cols;
    this->ObjWidth = sheetSizeX / cols * zoom;
    this->ObjHeight = sheetSizeY / rows * zoom;
}