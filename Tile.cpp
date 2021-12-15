#include "Tile.h"
Tile::Tile()

{}

int createBackground(sf::VertexArray& rVA, sf::IntRect map)
{
	//The size of each texture
	const int TILE_SIZE = 50;
	const int TILE_TYPES = 4;
	const int VERTS_IN_QUAD = 4;

	int mapWidth = map.width / TILE_SIZE;
	int mapHeight = map.height / TILE_SIZE;

	rVA.setPrimitiveType(sf::PrimitiveType::Quads);
	//The size of the vertex array is being set
	rVA.resize(mapWidth * mapHeight * VERTS_IN_QUAD);

	int currentVertex = 0;

	for (int w = 0; w < mapWidth; w++)
	{
		for (int h = 0; h < mapHeight; h++)
		{
			//Each vertex is being set into the current quad
			rVA[currentVertex + 0].position = sf::Vector2f(w * TILE_SIZE, h * TILE_SIZE);
			rVA[currentVertex + 1].position = sf::Vector2f((w * TILE_SIZE) + TILE_SIZE, h * TILE_SIZE);
			rVA[currentVertex + 2].position = sf::Vector2f((w * TILE_SIZE) + TILE_SIZE, (h * TILE_SIZE) + TILE_SIZE);
			rVA[currentVertex + 3].position = sf::Vector2f((w * TILE_SIZE), (h * TILE_SIZE) + TILE_SIZE);

			if (h == 0 || h == mapHeight - 1 || w == 0 || w == mapWidth - 1)
			{
				//Using a wall texture
				rVA[currentVertex + 0].texCoords = sf::Vector2f(0, 0 + TILE_TYPES * TILE_SIZE);
				rVA[currentVertex + 1].texCoords = sf::Vector2f(TILE_SIZE, 0 + TILE_TYPES * TILE_SIZE);
				rVA[currentVertex + 2].texCoords = sf::Vector2f(TILE_SIZE, TILE_SIZE + TILE_TYPES * TILE_SIZE);
				rVA[currentVertex + 3].texCoords = sf::Vector2f(0, TILE_SIZE + TILE_TYPES * TILE_SIZE);
			}
			else
			
				//using a floor texture
				srand((int)time(0) + h * w - h);
				int mOrG = (rand() % TILE_TYPES);
				int verticalOffset = mOrG * TILE_SIZE;

				rVA[currentVertex + 0].texCoords = sf::Vector2f(0, 0 + verticalOffset);
				rVA[currentVertex + 1].texCoords = sf::Vector2f(TILE_SIZE, 0 + verticalOffset);
				rVA[currentVertex + 2].texCoords = sf::Vector2f(TILE_SIZE, TILE_SIZE + verticalOffset);
				rVA[currentVertex + 3].texCoords = sf::Vector2f(0, TILE_SIZE + verticalOffset);

			}
			currentVertex = currentVertex + VERTS_IN_QUAD;
		}
	return TILE_SIZE;
}