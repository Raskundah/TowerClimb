#include "LevelScreen.h"
#include "AssetManager.h"

LevelScreen::LevelScreen(Game* newGamePointer)
	: Screen(newGamePointer)
	, player()
	, testPlatform()
	, door()
{

}

void LevelScreen::Update(sf::Time frameTime)
{
	player.Update(frameTime);
}

void LevelScreen::Draw(sf::RenderTarget& _target)
{
	testPlatform.Draw(_target);
	door.Draw(_target);
	player.Draw(_target);
}
