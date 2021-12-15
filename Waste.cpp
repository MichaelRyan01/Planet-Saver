#include "Waste.h"

Waste::Waste(float wasteX, float wasteY)

{

	w_Sprite = Sprite(TileManager::GetTexture("graphics/oilspill.png"));
	
	w_Position.x = wasteX;
	w_Position.y = wasteY;
	w_Sprite.setScale(0.1, 0.1);
	w_Sprite.setOrigin(25, 25);
	w_Sprite.setPosition(w_Position);

}

void Waste::status()

{

	if (w_health <= 0)

	{

		wasteLeft--;


	}

}
