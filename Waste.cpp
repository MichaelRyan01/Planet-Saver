#include "Waste.h"
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

	return w_Sprite;

}

FloatRect Waste::getPosition()

{

	return w_Sprite.getGlobalBounds();

}

bool Waste::isSpawned()

{

	return w_Spawned;

}

bool Waste::clean()

{

	w_Spawned = false;
	return w_Spawned;

}