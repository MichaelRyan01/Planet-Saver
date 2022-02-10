#include "HeliUI.h"

//default constructor
HeliUI::HeliUI(float heliUIX, float heliUIY)

{

	//set sprite to heliUI
	s_Sprite = Sprite(TileManager::GetTexture("graphics/heliUI.png"));

	//helicopter x
	s_Position.x = heliUIX;
	//helicopter y
	s_Position.y = heliUIY;

	//set position using x and y
	s_Sprite.setPosition(s_Position);

}

//get position
FloatRect HeliUI::getPosition()

{

	//returns position of sprite
	return s_Sprite.getGlobalBounds();

}

//get sprite
Sprite HeliUI::getSprite()

{

	//returns sprite
	return s_Sprite;

}