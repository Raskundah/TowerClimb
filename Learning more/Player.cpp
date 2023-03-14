#include "Player.h"
#include "AssetManager.h"

enum class PhysicsType {
	FORWARD_EULER,
	BACKWARD_EULER,
	SYMPLECTIC_EULER,
	INCORRECT_VERLET,
	VELOCITY_VERLET
};

Player::Player()
	: SpriteObject()
	, m_position(10,10)
	,m_twoFramesOldPos(m_position)
	, m_velocity()
	, m_acceleration(100,100)
{
	m_sprite.setTexture(AssetManager::RequestTexture("Assets/Graphics/PlayerStand.png"));
	m_sprite.setPosition(m_position);
}

void Player::Update(sf::Time _frameTime)
{
	const PhysicsType physics = PhysicsType::SYMPLECTIC_EULER;

	switch (physics)
	{
	case PhysicsType::FORWARD_EULER:
	{
			m_position = m_position + m_velocity * _frameTime.asSeconds();

			m_velocity = m_velocity + m_acceleration * _frameTime.asSeconds();

			m_velocity *= 0.5f;


			UpdateAcceleration();
	}
	break;

	case PhysicsType::BACKWARD_EULER:
	{
		UpdateAcceleration();

		m_velocity = m_velocity + m_acceleration * _frameTime.asSeconds();

		m_velocity *= 0.5f;

		m_position = m_position + m_velocity * _frameTime.asSeconds();

	}
	break;

	case PhysicsType::SYMPLECTIC_EULER:
	{
		m_velocity = m_velocity + m_acceleration * _frameTime.asSeconds();

		m_velocity *= 0.5f;


		m_position = m_position + m_velocity * _frameTime.asSeconds();


		UpdateAcceleration();

	}
	break;

	case PhysicsType::INCORRECT_VERLET: //position verlet
	{
		UpdateAcceleration();

		sf::Vector2f lastFramePos = m_position;

		//current frame pos
		m_position = 2.0f * lastFramePos - m_twoFramesOldPos + m_acceleration * _frameTime.asSeconds() * _frameTime.asSeconds();

		//two frames ago (for next frame)

		m_twoFramesOldPos = lastFramePos;
	}
	break;

	case PhysicsType::VELOCITY_VERLET:
	{

		//get half frame velocity using

		//previous frame's acceleration 
		sf::Vector2f halfFrameVel = m_velocity + m_acceleration * _frameTime.asSeconds() / 2.0f;

		//get new frame position using hjalf frame velocity
		m_position = m_position + halfFrameVel * _frameTime.asSeconds();


		//update acceleration
		UpdateAcceleration();


		//get new frames velocity using half frame velocity and updated acceleration
		m_velocity = halfFrameVel + m_acceleration * _frameTime.asSeconds();

		m_velocity *= 0.5f;

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
	const float ACCEL = 20000;


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
