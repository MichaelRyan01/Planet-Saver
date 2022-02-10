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
	//constructor using x and y
	Helicopter(float heliX, float heliY);
	//spawn method
	void spawn(IntRect map, Vector2f resolution, int tileSize);
	//get position using floatrect
	FloatRect getPosition();
	//get rotation (for rotating the sprite during movement)
	float getRotation();
	//get the sprite
	Sprite getSprite();

	//move left
	void moveLeft();
	//move right
	void moveRight();
	//move up
	void moveUp();
	//move down
	void moveDown();

	//stop moving left
	void stopLeft();
	//stop moving right
	void stopRight();
	//stop moving up
	void stopUp();
	//stop moving down
	void stopDown();

	//function for updating the sprite using time since start
	void update(float elapsedTime);

	//decrements x distance
	int negDistanceX();
	//increments x distance
	int posDistanceX();
	//decrements y distance
	int negDistanceY();
	//increments y distance
	int posDistanceY();

	//gets the y value
	float getY();
	//gets the x value
	float getX();

	//movement class handling arrow keys/wasd movement
	void movement();

	//resets stats to default (for restarting the game)
	void resetVehicleStats();

	//maximum water the helicopter can hold
	int maxWater = 5;
	//current water the helicopter holds
	int currentWater = 5;

private:
	//starting speed of the helicopter
	const float START_SPEED = 200;

	//x value of the helicopter
	float heliX = 0;
	//y value of the helicopter
	float heliY = 0;

	//position of the helicopter
	Vector2f m_Position;

	//sprite of the helicopter
	Sprite m_Sprite;
	
	//texture of the helicopter
	Texture m_Texture;

	//resolution (used for main)
	Vector2f m_Resolution;

	//map (used for main)
	IntRect m_Map;

	//tile size (used for main)
	int m_TileSize;

	//pressing up or not
	bool m_UpPressed;
	//pressing down or not
	bool m_DownPressed;
	//pressing left or not
	bool m_LeftPressed;
	//pressing right or not
	bool m_RightPressed;

	//speed of the helicopter
	float m_speed;

	//time since last hit
	Time m_LastHit;
};
#endif