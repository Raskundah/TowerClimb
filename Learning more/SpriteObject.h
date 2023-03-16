#pragma once
#include <SFML/Graphics.hpp>

class SpriteObject
{
public:

	SpriteObject();

	virtual void Update(sf::Time _frameTime);
	virtual void Draw(sf::RenderTarget& _target);

	sf::Vector2f GetPosition();
	

	void SetPosition(sf::Vector2f _newPosition);
	void SetPosition(float m_newX, float m_newY);

protected:

	sf::Sprite m_sprite;

private:

	sf::Vector2f m_position;
};