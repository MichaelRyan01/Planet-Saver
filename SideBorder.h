#pragma once
#include "TileManager.h"
#include <SFML/Graphics.hpp>
#ifndef SIDEBORDER_H
#define SIDEBORDER_H

using namespace sf;

class SideBorder {
public:
	SideBorder(float X, float Y);
	Sprite getSprite();
	FloatRect getPosition();

private:
	float X = 0;
	float Y = 0;

	Sprite sideB_Sprite;
	Texture sideB_Texture;
	Vector2f sideB_Position;
};
#endif