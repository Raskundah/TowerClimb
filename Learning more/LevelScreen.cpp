#include "LevelScreen.h"


LevelScreen::LevelScreen(Game* gamePointer)
	: Screen(gamePointer)
	, tempTex()
	,tempSprite()
{
	tempTex.loadFromFile("Assets/Graphics/PlayerStand.png");
	tempSprite.setTexture(tempTex);
}

void LevelScreen::Update(sf::Time frameTime)
{
}

void LevelScreen::Draw(sf::RenderTarget& target)
{
	target.draw(tempSprite);
}
