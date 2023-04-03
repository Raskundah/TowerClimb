#include "LevelScreen.h"
#include "AssetManager.h"

LevelScreen::LevelScreen(Game* newGamePointer)
	: Screen(newGamePointer)
	, player()
	, testPlatform()
	, testMovingPlatform(sf::Vector2f(0, 700),sf::Vector2f(1000, 700))
	, door()
{
	//default positions for non dynamically allocated and test objects.

	//TODO: add vectors of object positions.

	testPlatform.SetPosition(500, 500);
	door.SetPosition(30, 500);
	testMovingPlatform.SetPosition(sf::Vector2f(500, 700));
	player.SetPosition(30, 30);

}

void LevelScreen::Update(sf::Time frameTime)
{
	//update moving positions

	player.Update(frameTime);
	testMovingPlatform.Update(frameTime);

	//default colllisiuon states

	player.SetColliding(false);
	testPlatform.SetColliding(false);
	testMovingPlatform.SetColliding(false);
	door.SetColliding(false);

	//check if player collides with static platform

	if (testPlatform.CheckCollision(player))
	{
		player.SetColliding(true);
		testPlatform.SetColliding(true);
		player.HandleCollision(testPlatform);
	}

	//check is player collides with a dynamic, moving platform
	if (testMovingPlatform.CheckCollision(player))
	{
		player.SetColliding(true);
		testMovingPlatform.SetColliding(true);
		player.HandleCollision(testPlatform);
	}


	//check if player collides with the door.
	if (player.CheckCollision(door))
	{
		player.SetColliding(true);
		door.SetColliding(true);
	};
}

//draw all objects to game window

void LevelScreen::Draw(sf::RenderTarget& _target)
{
	testPlatform.Draw(_target);
	testMovingPlatform.Draw(_target);
	door.Draw(_target);
	player.Draw(_target);
}
