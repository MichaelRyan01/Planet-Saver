//code by sam
#include "Shark.h"
#include "Vehicle.h"

//The constructor ask for specific coordinates 
Shark::Shark(float sharkX, float sharkY)

{
	//Sets the texture of the sprite from the file
	s_Sprite = Sprite(TileManager::GetTexture("graphics/sharkspritesheet.png"));
	//Updates the spritesheet so that it loops for animations (incomplete)
	sf::IntRect sharkUpdate(0, 0, 300, 500);
	s_Sprite.setTextureRect(sharkUpdate);

	//The position is being set to the float coords
	s_Position.x = sharkX;
	s_Position.y = sharkY;

	//The sprites scale, origin and position is being set
	s_Sprite.setScale(0.2, 0.2);
	s_Sprite.setOrigin(150, 250);
	s_Sprite.setPosition(s_Position);



}

//The attack function used for the shark to start patrolling and goind after the player
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
	float angle = (atan2(playerY - s_Position.y, playerX - s_Position.x) * 180) / 3.141 + 90;

	s_Sprite.setRotation(angle);

}

Sprite Shark::getSprite()

{
	//returns the sprite to wherever its being called from
	return s_Sprite;

}

FloatRect Shark::getPosition()

{
	//Returns the sprites position and global bounds
	return s_Sprite.getGlobalBounds();

}

//Sets the current position the shark in game
void Shark::setPosition(float sharkX, float sharkY)

{

	s_Position.x = sharkX;
	s_Position.y = sharkY;

}