//code by sam
#pragma once
#ifndef SHARK_H
#define SHARK_H

#include "TileManager.h"
#include <SFML/Graphics.hpp>


class Shark

{

public:
	Shark(float sharkX, float sharkY);
	void attack(float elapsedTime, Vector2f subLocation);
	Sprite getSprite();
	FloatRect getPosition();

private:
	float sharkX = 0;
	float sharkY = 0;
	float damage = 40;
	float m_speed = 100;

	Sprite s_Sprite;
	Texture s_Texture;
	Vector2f s_Position;

};

#endif