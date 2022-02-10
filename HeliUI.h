//code by sam
#pragma once
#ifndef HELIUI_H
#define HELIUI_H

#include "TileManager.h"
#include <SFML/Graphics.hpp>


class HeliUI

{

public:
	//constructor for the UI
	HeliUI(float heliUIX, float heliUIY);
	//get position of floatrect
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