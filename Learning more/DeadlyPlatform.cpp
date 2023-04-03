#include "DeadlyPlatform.h"
#include "AssetManager.h"

DeadlyPlatform::DeadlyPlatform(sf::Vector2f newPosition)
	: Platform(newPosition)
{
	m_sprite.setTexture(AssetManager::RequestTexture("Assets/Graphics/DeadlyPlatform.png"));

}

void DeadlyPlatform::HandleCollision(SpriteObject& other)
{
	other.SetAlive(false);
}
