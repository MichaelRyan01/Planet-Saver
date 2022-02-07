#pragma once
#ifndef TREES_H
#define TREES_H

#include "TileManager.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class Trees

{

public:
	Trees(float treeX, float treeY, bool isOnFire);
	Sprite getSprite();
	FloatRect getPosition();
	bool isOnFire();
	bool extinguish();
	void reignite();

private:
	float treeX = 0;
	float treeY = 0;
	bool t_OnFire;

	Sprite t_Sprite;
	Texture t_Texture;
	Vector2f t_Position;
};
#endif