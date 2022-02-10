#pragma once
#ifndef TREES_H
#define TREES_H

#include "TileManager.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class Trees

{

public:
	//constructor for a tree using x and y values and a boolean to check the state
	Trees(float treeX, float treeY, bool isOnFire);
	//gets the sprite
	Sprite getSprite();
	//gets the position of floatrect
	FloatRect getPosition();
	//boolean checking if the tree is on fire or not
	bool isOnFire();
	//set on fire to false, set texture to normal tree
	bool extinguish();
	//set on fire to true, set texture to fire tree
	void reignite();
	//set position of the tree
	void setPosition(float treeX, float treeY);
	//is the tree on fire or not
	bool t_OnFire;

private:
	//x value of the tree
	float treeX = 0;
	//y value of the tree
	float treeY = 0;

	//sprite of the tree
	Sprite t_Sprite;
	//texture of the tree
	Texture t_Texture;
	//position of the tree
	Vector2f t_Position;
};
#endif