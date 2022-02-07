#include "RightBorder.h"
RightBorder::RightBorder(float rightBorderX, float rightBorderY)

{

	s_Sprite = Sprite(TileManager::GetTexture("graphics/subUI.png"));

	s_Position.x = rightBorderX;
	s_Position.y = rightBorderY;

	s_Sprite.setPosition(s_Position);
	s_Sprite.setRotation(90.0f);

}

FloatRect RightBorder::getPosition()

{

	return s_Sprite.getGlobalBounds();

}

Sprite RightBorder::getSprite()

{

	return s_Sprite;

}