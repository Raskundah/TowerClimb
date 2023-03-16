
#include "Door.h"
#include "AssetManager.h"

Door::Door()
	: SpriteObject()
{
	m_sprite.setTexture(AssetManager::RequestTexture("Assets/Graphics/Door.png"));
}