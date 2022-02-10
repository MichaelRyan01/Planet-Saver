//code by sam
#pragma once
#ifndef SHARK_H
#define SHARK_H

#include "TileManager.h"
#include <SFML/Graphics.hpp>


class Shark
{
public:
	//Constructor for the shark
	Shark(float sharkX, float sharkY);
	//Attack function
	void attack(float elapsedTime, Vector2f subLocation);
	//Function to return the sprite itself
	Sprite getSprite();
	//FloatRect designed to get the sprites position
	FloatRect getPosition();
	//funcion that sets the sharks position on the map
	void setPosition(float sharkX, float sharkY);

private:
	//Sharks coordinates are set to (0,0)
	float sharkX = 0;
	float sharkY = 0;

	//The sharks damage and speed variables
	float damage = 40;
	float m_speed = 100;

	//Sprite, texture and position variables
	Sprite s_Sprite;
	Texture s_Texture;
	Vector2f s_Position;
};
#endif