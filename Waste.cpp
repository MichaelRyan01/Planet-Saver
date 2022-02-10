#include "Waste.h"

//The constructor ask for specific coordinates 
Waste::Waste(float wasteX, float wasteY, bool isSpawned)

{

	w_Sprite = Sprite(TileManager::GetTexture("graphics/oilspill.png"));

	w_Position.x = wasteX;
	w_Position.y = wasteY;
	isSpawned = true;
	w_Sprite.setScale(0.2, 0.2);
	w_Sprite.setOrigin(125, 125);
	w_Sprite.setPosition(w_Position);

}

Sprite Waste::getSprite()

{
	//returns the sprite to wherever its being called from
	return w_Sprite;

}

FloatRect Waste::getPosition()

{
	//Returns the sprites position and global bounds
	return w_Sprite.getGlobalBounds();

}

bool Waste::isSpawned()

{
	//returns the spawned so that it can spawn the waste properly
	return w_Spawned;

}

bool Waste::clean()

{
	//Cleans up the waste by returning the false variable
	w_Spawned = false;
	return w_Spawned;

}

void Waste::respawnWaste()

{
	//respawns waste if the variable is true
	w_Spawned = true;

}