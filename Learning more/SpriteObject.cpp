#include "SpriteObject.h"

SpriteObject::SpriteObject()
	: m_sprite()
{

}

void SpriteObject::Update(sf::Time _frameTime)
{
}

void SpriteObject::Draw(sf::RenderTarget& _target)
{
	_target.draw(m_sprite);
}
