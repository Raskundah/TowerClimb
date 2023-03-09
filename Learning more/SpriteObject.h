#pragma once
#include <SFML/Graphics.hpp>

class SpriteObject
{
public:

	SpriteObject();

	virtual void Update(sf::Time _frameTime);
	virtual void Draw(sf::RenderTarget& _target);

protected:

	sf::Sprite m_sprite;

};