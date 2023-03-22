#pragma once
#include <SFML/Graphics.hpp>

enum class CollisionType
{
	CIRCLE,
	AABB
};

class SpriteObject
{
public:

	SpriteObject();

	virtual void Update(sf::Time _frameTime);
	virtual void Draw(sf::RenderTarget& _target);

	sf::Vector2f GetPosition();
	

	void SetPosition(sf::Vector2f _newPosition);
	void SetPosition(float m_newX, float m_newY);

	bool CheckCollision(SpriteObject other);
	void SetColliding(bool newColliding);

protected:

	sf::Sprite m_sprite;
	sf::Vector2f m_CollisionOffset;
	sf::Vector2f m_CollisionScale;
	CollisionType collisionType;

private:

	sf::Vector2f GetCollsionCentre();
	float GetCircleColliderRadius();
	sf::FloatRect GetAABB();

	sf::Vector2f m_position;
	bool m_colliding;


};