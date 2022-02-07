#include "SubUI.h"
SubUI::SubUI(float subUIX, float subUIY)

{

	s_Sprite = Sprite(TileManager::GetTexture("graphics/subUI.png"));

	s_Position.x = subUIX;
	s_Position.y = subUIY;

	s_Sprite.setPosition(s_Position);

}

FloatRect SubUI::getPosition()

{

	return s_Sprite.getGlobalBounds();

}

Sprite SubUI::getSprite()

{

	return s_Sprite;

}