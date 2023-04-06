#pragma once
#include "SpriteObject.h"

class LevelScreen;

//forward decleration, allowed because done in h file, not used here, and the instance it tracks is a pointer.

class Door :
    public SpriteObject
{
public:
    Door(LevelScreen* newLevelScreen);
    void HandleCollision(SpriteObject& other) override;


private:
    LevelScreen* levelScreen;
};
