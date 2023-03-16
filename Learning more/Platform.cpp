#include "Platform.h"
#include "AssetManager.h"

Platform::Platform()
	: SpriteObject()
{
	m_sprite.setTexture(AssetManager::RequestTexture("Assets/Graphics/Platform.png"));

}
