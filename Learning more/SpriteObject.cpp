#include "SpriteObject.h"

SpriteObject::SpriteObject()
	: m_sprite()
	, m_position(0, 0)
{

}

void SpriteObject::Update(sf::Time _frameTime)
{
}

void SpriteObject::Draw(sf::RenderTarget& _target)
{
	_target.draw(m_sprite);
}

sf::Vector2f SpriteObject::GetPosition()
{
	return m_position;
}

void SpriteObject::SetPosition(sf::Vector2f _newPosition)
{
	m_position = _newPosition;
	m_sprite.setPosition(_newPosition);
}

void SpriteObject::SetPosition(float m_newX, float m_newY)
{
	SetPosition(sf::Vector2f(m_newX, m_newY));
}
