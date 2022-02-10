//code by sam
#pragma once
#ifndef LAKE_H
#define LAKE_H

#include "TileManager.h"
#include <SFML/Graphics.hpp>


class Lake

{

public:
	//constructor
	Lake(float lakeX, float lakeY);
	//get position using floatrect
	FloatRect getPosition();
	//get sprite
	Sprite getSprite();

private:
	//sprite
	Sprite s_Sprite;
	//texture
	Texture s_Texture;
	//position
	Vector2f s_Position;

};

#endif