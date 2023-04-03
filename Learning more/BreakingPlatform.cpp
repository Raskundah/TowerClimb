#include "BreakingPlatform.h"
#include "AssetManager.h"

BreakingPlatform::BreakingPlatform(sf::Vector2f newPosition)
	: Platform(newPosition)

{
	m_sprite.setTexture(AssetManager::RequestTexture("Assets/Graphics/BreakingPlatform.png"));

}

void BreakingPlatform::HandleCollision(SpriteObject& other)
{
	m_isAlive = false;
}
