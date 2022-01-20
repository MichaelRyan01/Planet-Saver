#include <SFML/Graphics.hpp>
#include "Vehicle.h"
#include "TileManager.h"
#include <iostream>

using namespace sf;
using namespace std;

vehicle::vehicle(float subX, float subY){
	m_Position.x = subX;
	m_Position.y = subY;

	m_speed = START_SPEED;
	m_health = START_HEALTH;
	m_maxHealth = START_HEALTH;

	m_Sprite = Sprite(TileManager::GetTexture(
		"graphics/sub.png"));

	m_Sprite.setOrigin(25, 25);
	m_Sprite.setScale(0.2f, 0.2f);
}

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

FloatRect vehicle::getPosition() {
	return m_Sprite.getGlobalBounds();
}

Vector2f vehicle::getCenter() {
	return m_Position;
}

float vehicle::getRotation() {
	return m_Sprite.getRotation();
}

Sprite vehicle::getSprite() {
	return m_Sprite;
}

int vehicle::getHealth() {
	return m_health;
}

void vehicle::moveLeft(){
	m_LeftPressed = true;
}

void vehicle::moveRight(){
	m_RightPressed = true;
}

void vehicle::moveUp(){
	m_UpPressed = true;
}

void vehicle::moveDown(){
	m_DownPressed = true;
}

void vehicle::stopLeft(){
	m_LeftPressed = false;
}

void vehicle::stopRight(){
	m_RightPressed = false;
}

void vehicle::stopUp(){
	m_UpPressed = false;
}

void vehicle::stopDown(){
	m_DownPressed = false;
}

void vehicle::update(float elapsedTime, Vector2i mousePosition){

	if (m_UpPressed){
		m_Position.y -= m_speed * elapsedTime;
	}

	if (m_DownPressed){
		m_Position.y += m_speed * elapsedTime;
	}

	if (m_RightPressed){
		m_Position.x += m_speed * elapsedTime;
	}

	if (m_LeftPressed){
		m_Position.x -= m_speed * elapsedTime;
	}

	m_Sprite.setPosition(m_Position);



	// Keep the sub in the arena
	if (m_Position.x > m_Map.width - m_TileSize){
		m_Position.x = m_Map.width - m_TileSize;
	}

	if (m_Position.x < m_Map.left + m_TileSize){
		m_Position.x = m_Map.left + m_TileSize;
	}

	if (m_Position.y > m_Map.height - m_TileSize){
		m_Position.y = m_Map.height - m_TileSize;
	}

	if (m_Position.y < m_Map.top + m_TileSize){
		m_Position.y = m_Map.top + m_TileSize;
	}

	float angle = (atan2(mousePosition.y - m_Resolution.y / 2,
		mousePosition.x - m_Resolution.x / 2)
		* 180) / 3.141;

	m_Sprite.setRotation(angle);
}

void vehicle::boost(int boost) {
	boost = .5;
	m_speed += (START_SPEED + boost);
}

int vehicle::negDistanceX() {
	float newX = m_Position.x --;

	return newX;
}

int vehicle::posDistanceX() {
	float newX = m_Position.x++;

	return newX;
}

int vehicle::negDistanceY() {
	float newY = m_Position.y--;

	return newY;
}

int vehicle::posDistanceY() {
	float newY = m_Position.y++;

	return newY;
}

float vehicle::getY() {
	return subY;
}

float vehicle::getX() {
	return subX;
}

bool vehicle::hit(Time timeHit)
{
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