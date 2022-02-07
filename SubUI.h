//code by sam
#pragma once
#ifndef SUBUI_H
#define SUBUI_H

#include "TileManager.h"
#include <SFML/Graphics.hpp>


class SubUI

{

public:
	SubUI(float subUIX, float subUIY);
	FloatRect getPosition();
	Sprite getSprite();

private:
	Sprite s_Sprite;
	Texture s_Texture;
	Vector2f s_Position;

};

#endif