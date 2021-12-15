#pragma once
#include "TileManager.h"

#ifndef TILE_H
#define TILE_H
#include <SFML/Graphics.hpp>

class Tile
{
public:
	//Constructor 
	Tile();
	//backgound method of type int 
	int createBackground(sf::VertexArray& rVA, sf::IntRect map);

private:

};
#endif