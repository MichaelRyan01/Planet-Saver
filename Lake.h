//code by sam
#pragma once
#ifndef LAKE_H
#define LAKE_H

#include "TileManager.h"
#include <SFML/Graphics.hpp>


class Lake

{

public:
	Lake(float lakeX, float lakeY);
	FloatRect getPosition();
	Sprite getSprite();

private:
	Sprite s_Sprite;
	Texture s_Texture;
	Vector2f s_Position;

};

#endif