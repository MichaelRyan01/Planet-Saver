//code by sam
#pragma once
#ifndef RIGHTBORDER_H
#define RIGHTBORDER_H

#include "TileManager.h"
#include <SFML/Graphics.hpp>


class RightBorder

{

public:
	RightBorder(float rightBorderX, float rightBorderY);
	FloatRect getPosition();
	Sprite getSprite();

private:
	Sprite s_Sprite;
	Texture s_Texture;
	Vector2f s_Position;

};

#endif