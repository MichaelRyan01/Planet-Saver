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
	//submarine constructor
	vehicle(float subX, float subY);
	//Void function used to spawn the submarine into the game
	void spawn(IntRect map, Vector2f resolution, int tileSize);
	//FloatRect designed to get the sprites position
	FloatRect getPosition();
	//Vectir used to get the centre of the sprite
	Vector2f getCenter();
	//Float function used to get the roatation values of the sprite
	float getRotation();
	//Function to return the sprite itself
	Sprite getSprite();
	//Int function used to retrieve the current health of the submarine 
	int getHealth();

	//Void functions for movements of the vehicle
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();

	//void functions used to handle the stopping of movement
	void stopLeft();
	void stopRight();
	void stopUp();
	void stopDown();

	//Update function
	void update(float elapsedTime);
	void boost(Time boostingTime);

	//Functions that are used for collision detections
	int negDistanceX();
	int posDistanceX();
	int negDistanceY();
	int posDistanceY();

	//Float functions to get the x and y coordinates
	float getY();
	float getX();

	//The hit function for the sub taking damage
	bool hit(Time timeHit);

	//Movement function designed to correctly align the sprite
	//based on its direction
	void movement();

	//Function that resets the stats for the vehicle
	//during the end of each game
	void resetVehicleStats();

private:
	//The starting health and speed of the submarine
	const float START_SPEED = 200;
	const float START_HEALTH = 100;

	//The wait time and live time for the boost function
	const int BOOST_WAIT_TIME = 10;
	const int BOOST_LIVE_TIME = 5;

	//Variables that were to be used in the boost function
	int m_waitTime;
	int m_boostLive;
	Time boostTime;

	//Automatically sets the coords to (0,0)
	float subX = 0;
	float subY = 0;

	//Sprite, texture and position variables
	Vector2f m_Position;
	Sprite m_Sprite;
	Texture m_Texture;

	//Variables for the resolution, map and tilesize in spawn 
	Vector2f m_Resolution;
	IntRect m_Map;
	int m_TileSize;

	//bool variables for the directional input 
	bool m_UpPressed;
	bool m_DownPressed;
	bool m_LeftPressed;
	bool m_RightPressed;

	//General variables for health, speed and is alive
	int m_health;
	int m_maxHealth;
	float m_speed;
	bool m_alive;

	//Time since the last hit
	Time m_LastHit;
};
#endif