//code by sam
#pragma once
#ifndef HELIUI_H
#define HELIUI_H

#include "TileManager.h"
#include <SFML/Graphics.hpp>


class HeliUI

{

public:
	HeliUI(float heliUIX, float heliUIY);
	FloatRect getPosition();
	Sprite getSprite();

private:
	Sprite s_Sprite;
	Texture s_Texture;
	Vector2f s_Position;

};

#endif