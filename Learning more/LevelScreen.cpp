#include "LevelScreen.h"
#include "AssetManager.h"

LevelScreen::LevelScreen(Game* newGamePointer)
	: Screen(newGamePointer)
	, player()
	, testPlatform()
	, door()
{
	testPlatform.SetPosition(500, 500);
	door.SetPosition(30, 500);
	player.SetPosition(30, 30);

}

void LevelScreen::Update(sf::Time frameTime)
{
	player.SetColliding(false);
	testPlatform.SetColliding(false);
	door.SetColliding(false);

	player.Update(frameTime);
	if (player.CheckCollision(testPlatform))
	{
		player.SetColliding(true);
		testPlatform.SetColliding(true);
	}

	if (player.CheckCollision(door))
	{
		player.SetColliding(true);
		door.SetColliding(true);
	};
}

void LevelScreen::Draw(sf::RenderTarget& _target)
{
	testPlatform.Draw(_target);
	door.Draw(_target);
	player.Draw(_target);
}
