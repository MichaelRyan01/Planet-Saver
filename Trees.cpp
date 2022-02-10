#include "Trees.h"

//constructor for the tree
Trees::Trees(float treeX, float treeY, bool isOnFire)

{

	//set the sprite to use the treeFire texture
	t_Sprite = Sprite(TileManager::GetTexture("graphics/treeFire.png"));

	//x value of the tree being set using the constructor
	t_Position.x = treeX;
	//y value of the tree being set using the constructor
	t_Position.y = treeY;
	//isOnFire being set to true
	isOnFire = true;
	//set the origin to the middle of the sprite
	t_Sprite.setOrigin(148, 244);
	//set position using x and y values
	t_Sprite.setPosition(t_Position);

}

//get sprite method
Sprite Trees::getSprite()

{

	//returns the sprite of the tree
	return t_Sprite;

}

//get position method
FloatRect Trees::getPosition()

{

	//returns global bounds of the tree
	return t_Sprite.getGlobalBounds();

}

//is on fire method
bool Trees::isOnFire()

{

	//returns true or false on t_OnFire
	return t_OnFire;

}

//extinguish the tree method
bool Trees::extinguish()

{

	//sets on fire to false
	t_OnFire = false;
	//sets texture to regular tree
	t_Sprite.setTexture(TileManager::GetTexture("graphics/tree.png"));
	//return state of the tree
	return t_OnFire;

}

//reignite the tree (for restarting the game)
void Trees::reignite()

{

	//set on fire to true
	t_OnFire = true;
	//set texture back to treeFire
	t_Sprite.setTexture(TileManager::GetTexture("graphics/treeFire.png"));

}

//set position
void Trees::setPosition(float treeX, float treeY)

{

	//set new x
	t_Position.x = treeX;
	//set new y
	t_Position.y = treeY;

}