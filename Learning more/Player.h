#pragma once
#include "SpriteObject.h"
class Player :
    public SpriteObject
{
public:
    Player();

    void Update(sf::Time _frameTime) override;
    

private:

    void UpdateAcceleration();

    sf::Vector2f m_twoFramesOldPos;
    sf::Vector2f m_velocity;
    sf::Vector2f m_acceleration;

};

