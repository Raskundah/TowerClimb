#include "MovingPlatform.h"
#include "AssetManager.h"
#include "VectorHelper.h"

MovingPlatform::MovingPlatform(sf::Vector2f newPos1, sf::Vector2f newPos2)
	: Platform()
	, SPEED()
	, m_POS1(newPos1)
	, m_POS2(newPos2)
	, velocity (0, 0)
	, targetPoint(& m_POS2)
{
	m_sprite.setTexture(AssetManager::RequestTexture("Assets/Graphics/MovingPlatform.png"));
}

void MovingPlatform::Update(sf::Time _frameTime)
{
	float frameSeconds = _frameTime.asSeconds();

	sf::Vector2f newPos = GetPosition();

	newPos += velocity * frameSeconds;


	sf::Vector2f toMove = velocity * frameSeconds;

	float squareDistToTarget = VectorHelper::SquareMagnitude(toMove);


	sf::Vector2f vectorToTarget = *targetPoint - newPos;

	float squareDistToTarget = VectorHelper::SquareMagnitude(vectorToTarget);

	if (squareDistToTarget >= squareDistToTarget)

	{
		newPos = *targetPoint;

		if (targetPoint == &m_POS1)
			targetPoint = &m_POS2;
		else
			targetPoint = &m_POS1;

		sf::Vector2f vectorToNewTarget = *targetPoint - newPos;

	}


	newPos += toMove;
}
