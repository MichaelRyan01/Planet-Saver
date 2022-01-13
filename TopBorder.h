#pragma once
#include "TileManager.h"
#include <SFML/Graphics.hpp>
#ifndef TOPBORDER_H
#define TOPBORDER_H

using namespace sf;
class TopBorder {
public:
	TopBorder(float X, float Y);
	Sprite getSprite();
	FloatRect getPosition();

private:
	float X = 0;
	float Y = 0;

	Sprite topB_Sprite;
	Texture topB_Texture;
	Vector2f topB_Position;
};
#endif