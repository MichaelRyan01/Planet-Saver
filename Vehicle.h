#pragma once
#include<SFML/Graphics.hpp>
#include <string>
#ifndef VEHICLE_H
#define VEHICLE_H

using namespace sf;
using namespace std;

class vehicle
{
public: 
	vehicle();
	void spawn(IntRect map, Vector2f resolution, int tileSize);
	FloatRect getPosition();
	Vector2f getCenter();
	float getRotation();
	Sprite getSprite();
	int getHealth();

	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();

	void stopLeft();
	void stopRight();
	void stopUp();
	void stopDown();

	void update(float elapsedTime, Vector2i mousePosition);
	void boost(int boost);

private:
	const float START_SPEED = 200;
	const float START_HEALTH = 100;

	Vector2f m_vehicleX;
	Vector2f m_vehicleY;

	Sprite m_Sprite;
	
	Texture m_Texture;

	Vector2f m_Resolution;

	IntRect m_Map;
	
	int m_TileSize;

	bool m_UpPressed;
	bool m_DownPressed;
	bool m_LeftPressed;
	bool m_RightPressed;

	int m_health;
	int m_maxHealth;
	float m_speed;
};
#endif