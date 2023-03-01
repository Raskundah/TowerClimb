#include "Game.h"
#include "Screen.h"

Game::Game()
	: window(sf::VideoMode::getDesktopMode(), "TowerGame", sf::Style::Titlebar | sf::Style::Close)
	, gameClock()
	, currentScreen(nullptr)
{

	//window setup
	window.setMouseCursorVisible(false);

	//TODO Setup Screeens
}

void Game::RunGameLoop()
{

	//Repeat as long as the window is open

	while (window.isOpen())
	{
		Update();
		Draw();
		EventHandling();
	}
}

void Game::EventHandling()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}

	//close game if escape is pressed

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		window.close();
	}
}

void Game::Update()
{
	sf::Time frameTime = gameClock.restart();

	if (currentScreen)
	{
		currentScreen->Update(frameTime);
	}

	//TODO: Handle changes to other screens.
}

void Game::Draw()
{
	window.clear();
	
	//TODO Draw current screen
	if(currentScreen)
	currentScreen->Draw(window);


	window.display();
}
