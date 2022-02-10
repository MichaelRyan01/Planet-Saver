#include <SFML/Graphics.hpp>
#include "Vehicle.h"
#include "TileManager.h"
#include <iostream>

using namespace sf;
using namespace std;

//The vehicle constructor will ask for specific coordinates 
vehicle::vehicle(float subX, float subY) {
	//The position is being set to the float coords
	m_Position.x = subX;
	m_Position.y = subY;

	//Setting the speed and health variables
	m_speed = START_SPEED;
	m_health = START_HEALTH;
	m_maxHealth = START_HEALTH;

	//Setting the sub sprites texture
	m_Sprite = Sprite(TileManager::GetTexture(
		"graphics/sub.png"));

	//Scale and Origin
	m_Sprite.setOrigin(90, 202);
	m_Sprite.setScale(0.2f, 0.2f);
}

//Spawning the submarine into the map 
void vehicle::spawn(IntRect map, Vector2f resolution, int tileSize) {
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

//Returns the sprites global bounds
FloatRect vehicle::getPosition() {
	return m_Sprite.getGlobalBounds();
}

//returns the sprites center
Vector2f vehicle::getCenter() {
	return m_Position;
}

//returns the sprites rotation
float vehicle::getRotation() {
	return m_Sprite.getRotation();
}

//Returns the sprite itself when called
Sprite vehicle::getSprite() {
	return m_Sprite;
}

//Returns the health variable of the sprite
int vehicle::getHealth() {
	return m_health;
}

//Sets the moveLeft to true when pressed
void vehicle::moveLeft() {
	m_LeftPressed = true;
}

//Sets the moveRight true when pressed
void vehicle::moveRight() {
	m_RightPressed = true;
}

//Sets the moveUp to true when pressed
void vehicle::moveUp() {
	m_UpPressed = true;
}

//Sets the moveDown to true when pressed
void vehicle::moveDown() {
	m_DownPressed = true;
}

//Sets the stopLeft to false when pressed
void vehicle::stopLeft() {
	m_LeftPressed = false;
}

//Sets the stopRight to false when pressed
void vehicle::stopRight() {
	m_RightPressed = false;
}

//Sets the stopUp to false when pressed
void vehicle::stopUp() {
	m_UpPressed = false;
}

//Sets the stopDown to false when pressed
void vehicle::stopDown() {
	m_DownPressed = false;
}

//Updates the submarine so that it moves based on speed and 
//updates its position
void vehicle::update(float elapsedTime) {

	if (m_UpPressed) {
		m_Position.y -= m_speed * elapsedTime;
	}

	if (m_DownPressed) {
		m_Position.y += m_speed * elapsedTime;
	}

	if (m_RightPressed) {
		m_Position.x += m_speed * elapsedTime;
	}

	if (m_LeftPressed) {
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

//Boost function (incomplete)
void vehicle::boost(Time boostingTime) {
	m_boostLive = BOOST_LIVE_TIME;
	m_waitTime = BOOST_WAIT_TIME;

	boostingTime.asMilliseconds() - boostTime.asMilliseconds() > 5000;// 5 seconds
	{
		int boostValue = 5;
		m_speed = m_speed + boostValue;

	}
}
//Increments the negative distance of X
int vehicle::negDistanceX() {
	float newX = m_Position.x--;

	return newX;
}

//Increments the positive distance of X
int vehicle::posDistanceX() {
	float newX = m_Position.x++;

	return newX;
}

//Increments the negative distance of Y
int vehicle::negDistanceY() {
	float newY = m_Position.y--;

	return newY;
}

//Increments the positive distance of Y
int vehicle::posDistanceY() {
	float newY = m_Position.y++;

	return newY;
}

//Returns the subY coordinate
float vehicle::getY() {
	return subY;
}

//Returns the subX coordinate
float vehicle::getX() {
	return subX;
}

//Hit function
bool vehicle::hit(Time timeHit)
{
	//Creates a 2 second delay whenever the submarine takes damage
	if (timeHit.asMilliseconds() - m_LastHit.asMilliseconds() > 2000)// 2 seconds
	{
		m_LastHit = timeHit;
		m_health -= 10;
		return true;
	}
	else
	{
		return false;
	}
}

//Movement function to determine correct sprite directions
//Sets the keys based on specific needs and controls
void vehicle::movement()

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

	if (Keyboard::isKeyPressed(Keyboard::LShift) || (Keyboard::isKeyPressed(Keyboard::RShift)))

	{

		boost(boostTime);

	}
}

//resets the vehicles stats whenever the games are to restart
void vehicle::resetVehicleStats()
{
	m_speed = START_SPEED;
	m_health = START_HEALTH;
	m_maxHealth = START_HEALTH;
}