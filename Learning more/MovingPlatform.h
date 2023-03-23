#pragma once
#include "Platform.h"
class MovingPlatform :
    public Platform
{
public:
    MovingPlatform(sf::Vector2f newPos1, sf::Vector2f newPos2);

    void Update(sf::Time _frameTime) override;

    private:
        const float SPEED;
        const sf::Vector2f m_POS1;
        const sf::Vector2f m_POS2;
        sf::Vector2f velocity;
        const sf::Vector2f* targetPoint;
};

