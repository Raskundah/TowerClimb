#include "LevelScreen.h"
#include "AssetManager.h"

LevelScreen::LevelScreen(Game* newGamePointer)
	: Screen(newGamePointer)
	, player()
{

}

void LevelScreen::Update(sf::Time frameTime)
{
	player.Update(frameTime);
}

void LevelScreen::Draw(sf::RenderTarget& _target)
{
	player.Draw(_target);
}
