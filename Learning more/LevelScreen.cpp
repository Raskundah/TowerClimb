#include "LevelScreen.h"
#include "AssetManager.h"
#include "MovingPlatform.h"
#include "BreakingPlatform.h"
#include "DeadlyPlatform.h"
#include "Platform.h"

LevelScreen::LevelScreen(Game* newGamePointer)
	: Screen(newGamePointer)
	, player()
	, platforms()
	, door()
{
	//default positions for non dynamically allocated and test objects.

	//TODO: add vectors of object positions.

	
	player.SetPosition(30, 30);
	door.SetPosition(30, 500);

	platforms.push_back(new Platform(sf::Vector2f(500, 500)));
	platforms.push_back(new DeadlyPlatform(sf::Vector2f(90, 800)));
	platforms.push_back(new MovingPlatform(sf::Vector2f(500, 700), sf::Vector2f(0, 700),sf::Vector2f(1000, 700)));
	platforms.push_back(new BreakingPlatform(sf::Vector2f(700, 700)));

}

void LevelScreen::Update(sf::Time frameTime)
{
	//update moving positions

	player.Update(frameTime);
	for (int i = 0; i < platforms.size(); ++i)
	{
		platforms[i]->Update(frameTime);
	}

	//default colllisiuon states

	player.SetColliding(false);
	door.SetColliding(false);

	for (int i = 0; i < platforms.size(); ++i)
	{
		platforms[i]->SetColliding(false);

		if (platforms[i]->CheckCollision(player))
		{
			player.SetColliding(true);
			platforms[i]->SetColliding(true);
			player.HandleCollision(*platforms[i]);
			platforms[i]->HandleCollision(player);
		}
	}

	if (player.CheckCollision(door))
	{
		player.SetColliding(true);
		door.SetColliding(true);
	};
}

//draw all objects to game window

void LevelScreen::Draw(sf::RenderTarget& _target)
{
	for (int i = 0; i < platforms.size(); ++i)
	{
		platforms[i]->Draw(_target);
	}
	door.Draw(_target);
	player.Draw(_target);
}
