#include "Platform.h"
#include "AssetManager.h"

Platform::Platform(sf::Vector2f newPosition)
	: SpriteObject()
{
	m_sprite.setTexture(AssetManager::RequestTexture("Assets/Graphics/Platform.png"));

	m_CollisionOffset = sf::Vector2f(0, -57.f);
	m_CollisionScale = sf::Vector2f(1.0f, 0.25f);

	SetPosition(newPosition);
}
