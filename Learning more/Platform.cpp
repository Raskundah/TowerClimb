#include "Platform.h"
#include "AssetManager.h"

Platform::Platform()
	: SpriteObject()
{
	m_sprite.setTexture(AssetManager::RequestTexture("Assets/Graphics/Platform.png"));

	m_CollisionOffset = sf::Vector2f(0, -40);
	m_CollisionScale = sf::Vector2f(1.0f, 0.5f);
}
