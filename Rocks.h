#pragma once
#ifndef ROCKS_H
#define ROCKS_H

#include "TileManager.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class Rocks

{

public:
	//Constructor for the rocks
	Rocks(float rockX, float rockY);
	Sprite getSprite();
	FloatRect getPosition();
	Vector2f getCenter();
	//float functions to get the x and y coords
	float getY();
	float getX();

	FloatRect getBottom();
	FloatRect getTop();
	FloatRect getRight();
	FloatRect getLeft();

private:
	//Automatically sets the coords to (0,0)
	float rockX = 0;
	float rockY = 0;

	//Sprite, texture and position variables
	Sprite r_Sprite;
	Texture r_Texture; 
	Vector2f r_Position;

	FloatRect m_bottom;
	FloatRect m_top;
	FloatRect m_right;
	FloatRect m_left;
};

#endif