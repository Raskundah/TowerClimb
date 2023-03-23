#include "VectorHelper.h"

float VectorHelper::SquareMagnitude(sf::Vector2f vec)
{
	return vec.x * vec.x + vec.y * vec.y;
}

sf::Vector2f VectorHelper::Normalise(sf::Vector2f vec)
{
	float mag = SquareMagnitude(vec);

	vec.x = vec.x / mag;
	vec.y = vec.y / mag;
}

float VectorHelper::Magnitude(sf::Vector2f vec)
{
	return sqrt(Magnitude(vec));
}
