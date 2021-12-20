//code by sam
#include "Shark.h"
#include "Vehicle.h"

Shark::Shark(float sharkX, float sharkY)

{

	s_Sprite = Sprite(TileManager::GetTexture("graphics/sharkspritesheet.png"));
	
	s_Position.x = sharkX;
	s_Position.y = sharkY;
	
	s_Sprite.setScale(0.1, 0.1);
	s_Sprite.setOrigin(150, 250);
	s_Sprite.setPosition(s_Position);

}

void Shark::attack(float elapsedTime, Vector2f subLocation)

{
	float playerX = subLocation.x;
	float playerY = subLocation.y;

	// Update the shark position variables
	if (playerX > s_Position.x)
	
	{
	
		s_Position.x = s_Position.x + m_speed * elapsedTime;
	
	}

	if (playerY > s_Position.y)

	{

		s_Position.y = s_Position.y +
			m_speed * elapsedTime;
	
	}

	if (playerX < s_Position.x)
	
	{
	
		s_Position.x = s_Position.x -
			m_speed * elapsedTime;
	
	}

	if (playerY < s_Position.y)
	
	{
	
		s_Position.y = s_Position.y -
			m_speed * elapsedTime;
	
	}

	// Move the sprite
	s_Sprite.setPosition(s_Position);

	// Face the sprite in the correct direction
	float angle = (atan2(playerY - s_Position.y, playerX - s_Position.x) * 180) / 3.141;

	s_Sprite.setRotation(angle);

}

Sprite Shark::getSprite() 

{
	
	return s_Sprite;

}

FloatRect Shark::getPosition() 

{
	
	return s_Sprite.getGlobalBounds();

}