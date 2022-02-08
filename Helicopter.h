#pragma once
#include<SFML/Graphics.hpp>
#include <string>
#ifndef HELICOPTER_H
#define HELICOPTER_H

using namespace sf;
using namespace std;

class Helicopter
{
public:
	Helicopter(float heliX, float heliY);
	void spawn(IntRect map, Vector2f resolution, int tileSize);
	FloatRect getPosition();
	float getRotation();
	Sprite getSprite();

	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();

	void stopLeft();
	void stopRight();
	void stopUp();
	void stopDown();

	void update(float elapsedTime);

	int negDistanceX();
	int posDistanceX();
	int negDistanceY();
	int posDistanceY();

	float getY();
	float getX();

	void movement();

	void resetVehicleStats();

	int maxWater = 5;
	int currentWater = 5;

	//int getDistance();

private:
	const float START_SPEED = 200;

	float heliX = 0;
	float heliY = 0;

	Vector2f m_Position;

	Sprite m_Sprite;

	Texture m_Texture;

	Vector2f m_Resolution;

	IntRect m_Map;

	int m_TileSize;

	bool m_UpPressed;
	bool m_DownPressed;
	bool m_LeftPressed;
	bool m_RightPressed;

	float m_speed;

	Time m_LastHit;
};
#endif