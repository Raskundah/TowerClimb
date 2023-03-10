#pragma once
#include "Screen.h"
#include <SFML/Graphics.hpp>
#include "Player.h"

class Game;

class LevelScreen :
    public Screen
{

public:
    LevelScreen(Game* newGamePointer);

    void Update(sf::Time frameTime) override;
    void Draw(sf::RenderTarget& target) override;


private:

    Player player;

};

