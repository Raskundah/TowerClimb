#pragma once
#include <SFML/Graphics.hpp>

class Game;

class Screen
{
public:
	Screen(Game* gamePointer);

	virtual void Update(sf::Time frameTime); 
	virtual void Draw(sf::RenderTarget& target);

protected:

	Game* gamePointer;

};

