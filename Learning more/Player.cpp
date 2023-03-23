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
	,m_twoFramesOldPos(GetPosition())
	, m_velocity()
	, m_acceleration(100,100)
	
{
	m_sprite.setTexture(AssetManager::RequestTexture("Assets/Graphics/PlayerStand.png"));

	m_CollisionOffset = sf::Vector2f(0, 30);
	m_CollisionScale = sf::Vector2f(0.5f, 0.5f);

	collisionType = CollisionType::CIRCLE;
}

void Player::Update(sf::Time _frameTime)
{
	const float DRAG_MULT = 10.0f;
	const PhysicsType physics = PhysicsType::FORWARD_EULER;

	switch (physics)
	{
	case PhysicsType::FORWARD_EULER:
	{
			SetPosition(GetPosition() + m_velocity * _frameTime.asSeconds());

			m_velocity = m_velocity + m_acceleration * _frameTime.asSeconds();

			 m_velocity = m_velocity - m_velocity * DRAG_MULT * _frameTime.asSeconds();


			UpdateAcceleration();
	}
	break;

	case PhysicsType::BACKWARD_EULER:
	{
		UpdateAcceleration();

		m_velocity = m_velocity + m_acceleration * _frameTime.asSeconds();

		m_velocity = m_velocity - m_velocity * DRAG_MULT * _frameTime.asSeconds();

		SetPosition(GetPosition() + m_velocity * _frameTime.asSeconds());

	}
	break;

	case PhysicsType::SYMPLECTIC_EULER:
	{
		m_velocity = m_velocity + m_acceleration * _frameTime.asSeconds();

		m_velocity = m_velocity - m_velocity * DRAG_MULT * _frameTime.asSeconds();


		SetPosition(GetPosition() + m_velocity * _frameTime.asSeconds());


		UpdateAcceleration();

	}
	break;

	case PhysicsType::INCORRECT_VERLET: //position verlet
	{
		UpdateAcceleration();

		sf::Vector2f lastFramePos = GetPosition();

		//current frame pos
		GetPosition() = 2.0f * lastFramePos - m_twoFramesOldPos + m_acceleration * _frameTime.asSeconds() * _frameTime.asSeconds();

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
		SetPosition(GetPosition() + halfFrameVel * _frameTime.asSeconds());


		//update acceleration
		UpdateAcceleration();


		//get new frames velocity using half frame velocity and updated acceleration
		m_velocity = halfFrameVel + m_acceleration * _frameTime.asSeconds();

		m_velocity = m_velocity - m_velocity * DRAG_MULT * _frameTime.asSeconds();

	}
	break;
	default:
		break;
	}

	m_sprite.setPosition(GetPosition());
}

void Player::HandleCollision(SpriteObject other)
{
	sf::Vector2f depth = GetCollisionDepth(other);
	sf::Vector2f newPos = GetPosition();

	if (abs(depth.x) < abs(depth.y))
	{
		// move in x direction
		newPos.x += depth.x;
	}

	else
	{
		//move in y
		newPos.y += depth.y;
	}
	SetPosition(newPos);
}

void Player::UpdateAcceleration()
{
	//update acceleration

	m_acceleration.x = 0;
	m_acceleration.y = 0;
	const float ACCEL = 10000;


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
