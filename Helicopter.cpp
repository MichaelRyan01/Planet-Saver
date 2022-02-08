#include <SFML/Graphics.hpp>
#include "Helicopter.h"
#include "TileManager.h"
#include <iostream>

using namespace sf;
using namespace std;

Helicopter::Helicopter(float heliX, float heliY) 

{
	
	m_Position.x = heliX;
	m_Position.y = heliY;

	m_speed = START_SPEED;

	m_Sprite = Sprite(TileManager::GetTexture("graphics/Heli.png"));
	sf::IntRect heliUpdate(0, 0, 200, 244);
	m_Sprite.setTextureRect(heliUpdate);

	m_Sprite.setOrigin(100, 122);
	m_Sprite.setScale(0.4f, 0.4f);

}

void Helicopter::spawn(IntRect map, Vector2f resolution, int tileSize) 

{
	
	m_Position.x = map.width / 2;
	m_Position.y = map.height / 2;

	m_Map.left = map.left;
	m_Map.width = map.width;
	m_Map.top = map.top;
	m_Map.height = map.height;

	m_TileSize = tileSize;

	m_Resolution.x = resolution.x;
	m_Resolution.y = resolution.y;

}

FloatRect Helicopter::getPosition() 

{

	return m_Sprite.getGlobalBounds();

}

float Helicopter::getRotation() 

{

	return m_Sprite.getRotation();

}

Sprite Helicopter::getSprite() 

{

	return m_Sprite;

}


void Helicopter::moveLeft() 

{

	m_LeftPressed = true;

}

void Helicopter::moveRight()

{

	m_RightPressed = true;

}

void Helicopter::moveUp()

{

	m_UpPressed = true;

}

void Helicopter::moveDown()

{

	m_DownPressed = true;

}

void Helicopter::stopLeft()

{

	m_LeftPressed = false;

}

void Helicopter::stopRight()

{

	m_RightPressed = false;

}

void Helicopter::stopUp()

{

	m_UpPressed = false;

}

void Helicopter::stopDown()

{

	m_DownPressed = false;

}

void Helicopter::update(float elapsedTime)

{

	if (m_UpPressed) 
	
	{
		
		m_Position.y -= m_speed * elapsedTime;
	
	}

	if (m_DownPressed) 
	
	{
	
		m_Position.y += m_speed * elapsedTime;
	
	}

	if (m_RightPressed)
	
	{
	
		m_Position.x += m_speed * elapsedTime;
	
	}

	if (m_LeftPressed) 
	
	{
	
		m_Position.x -= m_speed * elapsedTime;
	
	}

	m_Sprite.setPosition(m_Position);



	// Keep the sub in the arena
	if (m_Position.x > m_Map.width - m_TileSize) {
		m_Position.x = m_Map.width - m_TileSize;
	}

	if (m_Position.x < m_Map.left + m_TileSize) {
		m_Position.x = m_Map.left + m_TileSize;
	}

	if (m_Position.y > m_Map.height - m_TileSize) {
		m_Position.y = m_Map.height - m_TileSize;
	}

	if (m_Position.y < m_Map.top + m_TileSize) {
		m_Position.y = m_Map.top + m_TileSize;
	}

}

int Helicopter::negDistanceX() 

{
	
	float newX = m_Position.x--;
	return newX;

}

int Helicopter::posDistanceX()

{
	
	float newX = m_Position.x++;
	return newX;

}

int Helicopter::negDistanceY() 

{
	
	float newY = m_Position.y--;
	return newY;

}

int Helicopter::posDistanceY()

{
	
	float newY = m_Position.y++;
	return newY;

}

float Helicopter::getY()

{

	return heliY;

}

float Helicopter::getX()

{

	return heliX;

}

void Helicopter::movement()

{

	if (Keyboard::isKeyPressed(Keyboard::W) || (Keyboard::isKeyPressed(Keyboard::Up)))

	{

		moveUp();
		m_Sprite.setRotation(0.f);

	}

	else

	{

		stopUp();

	}

	if (Keyboard::isKeyPressed(Keyboard::S) || (Keyboard::isKeyPressed(Keyboard::Down)))

	{

		moveDown();
		m_Sprite.setRotation(180.f);

	}

	else

	{

		stopDown();

	}

	if (Keyboard::isKeyPressed(Keyboard::A) || (Keyboard::isKeyPressed(Keyboard::Left)))

	{

		moveLeft();
		m_Sprite.setRotation(270.f);

	}

	else

	{

		stopLeft();

	}

	if (Keyboard::isKeyPressed(Keyboard::D) || (Keyboard::isKeyPressed(Keyboard::Right)))

	{

		moveRight();
		m_Sprite.setRotation(90.f);

	}

	else

	{

		stopRight();

	}

	if (Keyboard::isKeyPressed(Keyboard::W) && (Keyboard::isKeyPressed(Keyboard::D)) || Keyboard::isKeyPressed(Keyboard::Up) && (Keyboard::isKeyPressed(Keyboard::Right)))

	{


		m_Sprite.setRotation(45.f);

	}

	if (Keyboard::isKeyPressed(Keyboard::D) && (Keyboard::isKeyPressed(Keyboard::S)) || Keyboard::isKeyPressed(Keyboard::Right) && (Keyboard::isKeyPressed(Keyboard::Down)))

	{

		m_Sprite.setRotation(135.f);

	}

	if (Keyboard::isKeyPressed(Keyboard::S) && (Keyboard::isKeyPressed(Keyboard::A)) || Keyboard::isKeyPressed(Keyboard::Down) && (Keyboard::isKeyPressed(Keyboard::Left)))

	{


		m_Sprite.setRotation(225.f);

	}

	if (Keyboard::isKeyPressed(Keyboard::A) && (Keyboard::isKeyPressed(Keyboard::W)) || Keyboard::isKeyPressed(Keyboard::Left) && (Keyboard::isKeyPressed(Keyboard::Up)))

	{


		m_Sprite.setRotation(315.f);

	}

}

void Helicopter::resetVehicleStats()

{
	
	m_speed = START_SPEED;
	maxWater = 5;
	currentWater = 5;

}