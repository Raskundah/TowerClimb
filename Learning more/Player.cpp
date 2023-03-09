#include "Player.h"
#include "AssetManager.h"

enum class PhysicsType {
	FORWARD_EULER,
	BACKWARD_EULER
};

Player::Player()
	: SpriteObject()
	, m_position(10,10)
	, m_velocity()
	, m_acceleration(100,100)
{
	m_sprite.setTexture(AssetManager::RequestTexture("Assets/Graphics/PlayerStand.png"));
	m_sprite.setPosition(m_position);
}

void Player::Update(sf::Time _frameTime)
{
	const PhysicsType physics = PhysicsType::BACKWARD_EULER;

	switch (physics)
	{
	case PhysicsType::FORWARD_EULER:
	{
			m_position = m_position + m_velocity * _frameTime.asSeconds();

			m_velocity = m_velocity + m_acceleration * _frameTime.asSeconds();

			m_velocity *= 0.99f;


			UpdateAcceleration();
	}
	break;

	case PhysicsType::BACKWARD_EULER:
	{
		UpdateAcceleration();

		m_velocity = m_velocity + m_acceleration * _frameTime.asSeconds();

		m_velocity *= 0.99f;

		m_position = m_position + m_velocity * _frameTime.asSeconds();

	}
	break;

	default:
		break;
	}

	m_sprite.setPosition(m_position);
}

void Player::UpdateAcceleration()
{
	//update acceleration

	m_acceleration.x = 0;
	m_acceleration.y = 0;
	const float ACCEL = 1000;


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_acceleration.x = -ACCEL;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_acceleration.x = ACCEL;

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		m_acceleration.y = -ACCEL;

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_acceleration.y = ACCEL;

	}
}
