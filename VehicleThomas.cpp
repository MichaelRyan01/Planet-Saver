#include "Vehicle.h"
#include <iostream>

using namespace std;
//#include "stdafx.h"

Vehicle::Vehicle()
{}

void Vehicle::spawn(sf::Vector2f startPosition, float gravity)
{
	// Place the player at the starting point
	m_Position.x = startPosition.x;
	m_Position.y = startPosition.y;

	// Initialize the gravity
	m_Gravity = gravity;


	// Move the sprite in to position
	m_Sprite.setPosition(m_Position);
	//m_SpriteSheet.setPosition(m_Position);

}

void Vehicle::setSpeed(float value)
{
	m_Speed = value;
}
float Vehicle::getSpeed()
{
	return m_Speed;
}


void Vehicle::moveToFR(float elapsedTime, sf::FloatRect playerLocation, float speed, int** map_ArrayLevel)
{
	float playerX = playerLocation.left;
	float playerY = playerLocation.top;

	int playerGridLocRow = ((playerY + 49) / 50);
	int playerGridLocCol = ((playerX + 49) / 50);

	//float speed = m_Speed / 2;

	
	 //Update the rect for all body parts
	// cout << "MoveTo PlayerX " << playerX << "\n";
	// cout << "MoveTo PlayerY " << playerY << "\n";
	// cout << "MoveTo m_Position.x " << m_Position.x << "\n";
	// cout << "MoveTo m_Position.y " << m_Position.y << "\n";

}


void  Vehicle::moveTo(float elapsedTime, sf::Vector2f playerLocation, float speed, int** map_ArrayLevel)
{
	float playerX = playerLocation.x;
	float playerY = playerLocation.y;
	//player value is centre of sprite coords so we add only 24 
	int playerGridLocX = ((playerX) / 50);
	int playerGridLocY = ((playerY) / 50);
	//enemy is top left corner coord
	cout << "playerX " << playerX << "\n";
	cout << "playerY " << playerY << "\n";
	cout << "playerGridLocX " << playerGridLocX << "\n";
	cout << "playerGridLocY " << playerGridLocY << "\n";


	//float speed = m_Speed / 2;


	void update(float elapsedTime);
	{
		/*
			if (m_RightPressed)
			{
				m_Position.x += m_Speed * elapsedTime;
				direction = sf::Vector2f(0, -1);
				cout << "playableCharacter update Right Pressed call SetSpriteFrom Sheet \n";
				setSpriteFromSheet(sf::IntRect(12, 62, 150, 50));
			}

			if (m_LeftPressed)
			{
				m_Position.x -= m_Speed * elapsedTime;
			}

			if (m_UpPressed)
			{
				m_Position.y -= m_Speed * elapsedTime;
			}

			if (m_DownPressed)
			{
				m_Position.y += m_Speed * elapsedTime;
			}
		*/


		// Move the sprite into position
		m_Sprite.setPosition(m_Position);

	}


	sf::FloatRect Vehicle::getPosition()
	{
		return m_Sprite.getGlobalBounds();
	}
}
/*
sf::Vector2f getCenter()
{
	//LevelManager l;
	return Vector2f(
		m_Position.x + (l.TILE_SIZE / 2),
		m_Position.y + (l.TILE_SIZE / 2));
}
*/


Sprite Vehicle::getSprite()
{
	return m_Sprite;
}

Sprite Vehicle::getSpriteFromSheet()
{
	return m_Sprite;
}


void Vehicle::stopDown(float position)
{
	m_Position.y = position - getPosition().height;

	m_Sprite.setPosition(m_Position);
	m_SpriteSheet.setPosition(m_Position);
	cout << "Stop Down was called \n";

}

void Vehicle::stopUp(float position)
{
	m_Position.y = position + getPosition().height;
		m_Position.y = position;
	m_Sprite.setPosition(m_Position);
	m_SpriteSheet.setPosition(m_Position);
	cout << "Stop up was called \n";

}

void Vehicle::stopRight(float position)
//reduce x by the position - m_Sprite.getGlobalBounds().width;
{
		cout << "Stop Right m_Position.x was " << m_Position.x;
		cout << " Stop Right m_Position.y was " << m_Position.y << "\n" ;
		cout << "Stop Right Position " << position << " getPosition().width" << getPosition().width << "\n";
	m_Position.x = position - getPosition().width;
		cout << "Stop Right m_Position. x updated to " << m_Position.x;
		cout << " Stop Right m_Position.y updated to " << m_Position.y << "\n";
	m_Sprite.setPosition(m_Position);
	m_SpriteSheet.setPosition(m_Position);
}

void Vehicle::stopLeft(float position)
//increment X by the width of the sprite
{
		cout << "Stop Left m_Position.x was " << m_Position.x;
		cout << " Stop Left m_Position.y was " << m_Position.y << "\n";
		cout << "Stop Left Position " << position << " getPosition().width" << getPosition().width << "\n";

	m_Position.x = position + getPosition().width;
		cout << "Stop Left m_Position. x updated to " << m_Position.x;
		cout << " Stop Left m_Position.y updated to " << m_Position.y << "\n";
	m_Sprite.setPosition(m_Position);
	m_SpriteSheet.setPosition(m_Position);
}

/*
void Vehicle::setSpriteFromSheet(sf::IntRect textureBox)
{
	LevelManager l;
	int tile_size = l.TILE_SIZE;
	sheetCoordinate = sf::Vector2i(textureBox.left, textureBox.top);
	spriteSize = sf::Vector2i(tile_size, tile_size);
	if (textureBox.width > tile_size)
	{
		animation_it_limit = textureBox.width / tile_size;

	///	horizontal = true;
	///}
	///else if (textureBox.height > tile_size)
	///{
	///	animation_it_limit = textureBox.height / tile_size;
	///	horizontal = false;
	///}
	///else
	throw std::logic_error("Animation bounding box must contain multiply sprites, setSprite(sf::IntRect )\n");

	//	cout << "setSpriteFromSheet  " << "animation_it limit" << animation_it_limit << "\n";
	//	cout << "setSpriteFromSheet func " << "ani_counter " << ani_counter << "\n";

	///m_Sprite.setTextureRect(sf::IntRect{ sheetCoordinate, spriteSize });

}
*/

