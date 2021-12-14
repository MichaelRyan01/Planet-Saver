#pragma once
#include "TileManager.h"

#ifndef TILE_H
#define TILE_H
#include <SFML/Graphics.hpp>

class Tile
{
public:
	Tile();
	int createBackground(sf::VertexArray& rVA, sf::IntRect map);

private:

};
#endif