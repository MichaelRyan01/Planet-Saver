#include "Trees.h"
Trees::Trees(float treeX, float treeY, bool isOnFire)

{

	t_Sprite = Sprite(TileManager::GetTexture("graphics/treeFire.png"));

	t_Position.x = treeX;
	t_Position.y = treeY;
	isOnFire = true;
	t_Sprite.setOrigin(148, 244);
	t_Sprite.setPosition(t_Position);

}

Sprite Trees::getSprite()

{

	return t_Sprite;

}

FloatRect Trees::getPosition()

{

	return t_Sprite.getGlobalBounds();

}

bool Trees::isOnFire()

{

	return t_OnFire;

}

bool Trees::extinguish()

{

	t_OnFire = false;
	t_Sprite.setTexture(TileManager::GetTexture("graphics/tree.png"));
	return t_OnFire;

}

void Trees::reignite()

{

	t_OnFire = true;

}

void Trees::setPosition(float treeX, float treeY)

{

	t_Position.x = treeX;
	t_Position.y = treeY;

}