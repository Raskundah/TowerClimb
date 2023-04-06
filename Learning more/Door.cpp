
#include "Door.h"
#include "AssetManager.h"
#include "LevelScreen.h"

Door::Door(LevelScreen* newLevelScreen)
	: SpriteObject()
	, levelScreen(newLevelScreen)
{
	m_sprite.setTexture(AssetManager::RequestTexture("Assets/Graphics/Door.png"));
	m_CollisionOffset = sf::Vector2f(0, 10.0f);
	m_CollisionScale = sf::Vector2f(0.45, 0.89f);
}

void Door::HandleCollision(SpriteObject& other)
{
	SpriteObject::HandleCollision(other);
	levelScreen->TriggerEndState(true);
}
