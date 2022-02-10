#include <SFML/Graphics.hpp>
#include "Helicopter.h"
#include "TileManager.h"
#include <iostream>

using namespace sf;
using namespace std;

//default constructor for helicopter
Helicopter::Helicopter(float heliX, float heliY) 

{
	
	//x value
	m_Position.x = heliX;
	//y value
	m_Position.y = heliY;

	//speed of the helicopter
	m_speed = START_SPEED;

	//sprite using heli texture
	m_Sprite = Sprite(TileManager::GetTexture("graphics/Heli.png"));
	//tells the program what part of the spreadsheet to use
	sf::IntRect heliUpdate(0, 0, 200, 244);
	//sets the sprite texture to heliUpdate, to use first frame of spritesheet
	m_Sprite.setTextureRect(heliUpdate);

	//sets the origin to the center of a sprites
	m_Sprite.setOrigin(100, 122);
	//sets scale to 40% of original size on each axis
	m_Sprite.setScale(0.4f, 0.4f);

}

//spawn method
void Helicopter::spawn(IntRect map, Vector2f resolution, int tileSize) 

{
	
	//sets position of x to half of map width
	m_Position.x = map.width / 2;
	//sets position of y to half of map height
	m_Position.y = map.height / 2;

	//map left
	m_Map.left = map.left;
	//map width
	m_Map.width = map.width;
	//map top
	m_Map.top = map.top;
	//map height
	m_Map.height = map.height;

	//sets tile size
	m_TileSize = tileSize;

	//sets resolution of x
	m_Resolution.x = resolution.x;
	//sets resolution of y
	m_Resolution.y = resolution.y;

}

//get position method
FloatRect Helicopter::getPosition() 

{

	//returns global bounds of sprite
	return m_Sprite.getGlobalBounds();

}

//get rotation
float Helicopter::getRotation() 

{

	//gets the rotation of the sprite
	return m_Sprite.getRotation();

}

//gets sprite
Sprite Helicopter::getSprite() 

{

	//returns sprite
	return m_Sprite;

}

//move left
void Helicopter::moveLeft() 

{

	//returns true if left is pressed
	m_LeftPressed = true;

}

//move right
void Helicopter::moveRight()

{

	//returns true if right is pressed
	m_RightPressed = true;

}

//move up
void Helicopter::moveUp()

{

	//returns true if up is pressed
	m_UpPressed = true;

}

//move down
void Helicopter::moveDown()

{

	//returns true if down is pressed
	m_DownPressed = true;

}


//stop left
void Helicopter::stopLeft()

{

	//returns false if left is pressed
	m_LeftPressed = false;

}

//move right
void Helicopter::stopRight()

{

	//returns false if right is pressed
	m_RightPressed = false;

}

//move up
void Helicopter::stopUp()

{

	//returns false if up is pressed
	m_UpPressed = false;

}

//move down
void Helicopter::stopDown()

{

	//returns false if down is pressed
	m_DownPressed = false;

}

//updating the helicopter
void Helicopter::update(float elapsedTime)

{

	//if up is pressed
	if (m_UpPressed) 
	
	{
		
		// change y to y minus speed x time
		m_Position.y -= m_speed * elapsedTime;
	
	}

	//if down is pressed
	if (m_DownPressed) 
	
	{
	
		// change y to y plus speed x time
		m_Position.y += m_speed * elapsedTime;
	
	}

	//if right is pressed
	if (m_RightPressed)
	
	{
	
		// change x to x plus speed x time
		m_Position.x += m_speed * elapsedTime;
	
	}

	//if left is pressed
	if (m_LeftPressed) 
	
	{
	
		// change x to x minus speed x time
		m_Position.x -= m_speed * elapsedTime;
	
	}

	//sets position of sprite
	m_Sprite.setPosition(m_Position);



	// Keep the helicopter in the map
	if (m_Position.y > m_Map.height - m_TileSize) {
		m_Position.y = m_Map.height - m_TileSize;
	}

	if (m_Position.y < m_Map.top + m_TileSize) {
		m_Position.y = m_Map.top + m_TileSize;
	}

}

//decrements x of helicopter
int Helicopter::negDistanceX() 

{
	
	float newX = m_Position.x--;
	return newX;

}

//increments x of helicopter
int Helicopter::posDistanceX()

{
	
	float newX = m_Position.x++;
	return newX;

}

//decrements y of helicopter
int Helicopter::negDistanceY() 

{
	
	float newY = m_Position.y--;
	return newY;

}

//increments y of helicopter
int Helicopter::posDistanceY()

{
	
	float newY = m_Position.y++;
	return newY;

}

//gets y of helicopter
float Helicopter::getY()

{

	return heliY;

}

// gets x of helicopter
float Helicopter::getX()

{

	return heliX;

}

// movement handling 
void Helicopter::movement()

{

	//if w or arrow key up is pressed
	if (Keyboard::isKeyPressed(Keyboard::W) || (Keyboard::isKeyPressed(Keyboard::Up)))

	{

		//call move up method
		moveUp();
		//set rotation to 0 degrees clockwise
		m_Sprite.setRotation(0.f);

	}

	else

	{

		//or stop up if not pressed
		stopUp();

	}


	//if s or arrow key down is pressed
	if (Keyboard::isKeyPressed(Keyboard::S) || (Keyboard::isKeyPressed(Keyboard::Down)))

	{

		//move down
		moveDown();
		//set rotation to 180 degrees
		m_Sprite.setRotation(180.f);

	}

	else

	{

		//or stop down if not pressed
		stopDown();

	}

	// if a or arrow key left is pressed
	if (Keyboard::isKeyPressed(Keyboard::A) || (Keyboard::isKeyPressed(Keyboard::Left)))

	{

		//move left
		moveLeft();
		//set rotation to 270 degrees
		m_Sprite.setRotation(270.f);

	}

	else

	{

		//or stop left if not pressed
		stopLeft();

	}

	//if d or arrow key right is pressed
	if (Keyboard::isKeyPressed(Keyboard::D) || (Keyboard::isKeyPressed(Keyboard::Right)))

	{

		//move right
		moveRight();
		//set rotation to 90 degrees
		m_Sprite.setRotation(90.f);

	}

	else

	{

		//or stop right if not pressed
		stopRight();

	}

	//if w and d or arrow key up and right are pressed
	if (Keyboard::isKeyPressed(Keyboard::W) && (Keyboard::isKeyPressed(Keyboard::D)) || Keyboard::isKeyPressed(Keyboard::Up) && (Keyboard::isKeyPressed(Keyboard::Right)))

	{

		//set rotation to 45 degrees
		m_Sprite.setRotation(45.f);

	}

	//if d and s or arrow key right and down are pressed
	if (Keyboard::isKeyPressed(Keyboard::D) && (Keyboard::isKeyPressed(Keyboard::S)) || Keyboard::isKeyPressed(Keyboard::Right) && (Keyboard::isKeyPressed(Keyboard::Down)))

	{

		//set rotation to 135 degrees
		m_Sprite.setRotation(135.f);

	}

	//if s and a or arrow key down and left are pressed
	if (Keyboard::isKeyPressed(Keyboard::S) && (Keyboard::isKeyPressed(Keyboard::A)) || Keyboard::isKeyPressed(Keyboard::Down) && (Keyboard::isKeyPressed(Keyboard::Left)))

	{


		//set rotation to 225 degrees
		m_Sprite.setRotation(225.f);

	}

	//if a and w or arrow key left and up are pressed
	if (Keyboard::isKeyPressed(Keyboard::A) && (Keyboard::isKeyPressed(Keyboard::W)) || Keyboard::isKeyPressed(Keyboard::Left) && (Keyboard::isKeyPressed(Keyboard::Up)))

	{


		//set rotation to 315 degrees
		m_Sprite.setRotation(315.f);

	}

}

//reset vehicle stats (for restarting the game)
void Helicopter::resetVehicleStats()

{
	
	//speed
	m_speed = START_SPEED;
	//max water
	maxWater = 5;
	//current water
	currentWater = 5;

}