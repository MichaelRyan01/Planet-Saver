#pragma once
#ifndef ROCKS_H
#define ROCKS_H

#include "TileManager.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class Rocks

{

public:
	Rocks(float rockX, float rockY);
	Sprite getSprite();
	FloatRect getPosition();
	float getX();
	float getY();

private:
	float rockX = 0;
	float rockY = 0;

	Sprite r_Sprite;
	Texture r_Texture;
	Vector2f r_Position;
};

#endif