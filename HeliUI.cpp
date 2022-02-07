#include "HeliUI.h"
HeliUI::HeliUI(float heliUIX, float heliUIY)

{

	s_Sprite = Sprite(TileManager::GetTexture("graphics/heliUI.png"));

	s_Position.x = heliUIX;
	s_Position.y = heliUIY;

	s_Sprite.setPosition(s_Position);

}

FloatRect HeliUI::getPosition()

{

	return s_Sprite.getGlobalBounds();

}

Sprite HeliUI::getSprite()

{

	return s_Sprite;

}