#pragma once
#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
using namespace sf;


class Vehicle
{
protected:
	// we need a sprite
	Sprite m_Sprite;
	Sprite m_SpriteSheet;


	// Which directions is the character currently moving in
	bool m_LeftPressed;
	bool m_RightPressed;

	//2020 nov 5th up and down movement 
	bool m_UpPressed;
	bool m_DownPressed;


	//which direction is the character headed? used to see if we need to reset the animation to first frame as we have changed direction
	sf::Vector2f direction{ 0, 0 };

	// What is the gravity
	float m_Gravity;

	// How fast is the character
	float m_Speed = 400;

	// Where is the player 
	sf::Vector2f m_Position;


	// And a texture
	bool m_Texture;

	sf::Vector2i sheetCoordinate; // Coordinate on spritesheet
	sf::Vector2i spriteSize;
	bool alive{ true };
	int animation_it_limit; //Max animation iterations
	bool horizontal{ true };
	int ani_counter{};
	int counter{};
	bool clock;
	float timeElapsed;
	//50 ms for each frame

	float animationTimer = 0;

	// Private variables and functions come next
private:



	// All our public functions will come next
public:


	Vehicle();
	void spawn(sf::Vector2f startPosition, float gravity);

	void setSpeed(float value);
	float getSpeed();
	//setSprite to use correct animation cell
	void setSpriteFromSheet(sf::IntRect textureBox);

	//move the rectangle to the next cell in the animation
	void moveTextureRect();


	// This is a pure virtual function
	bool virtual handleInput() = 0;
	// This class is now abstract and cannot be instanciated


	// Where is the player
	sf::FloatRect getPosition();

	// Send a copy of the sprite to main
	sf::Sprite getSprite();
	sf::Sprite getSpriteFromSheet();

	// Make the character stand firm
	void stopDown(float position);
	void stopUp(float position);
	void stopRight(float position);
	void stopLeft(float position);


	// Where is the center of the character
	sf::Vector2f getCenter();

	// We will call this function once every frame
    void update(float elapsedTime);
	void moveTo(float elapsedTime, sf::Vector2f playerLocation, float speed, int** map_ArrayLevel);
	void moveToFR(float elapsedTime, sf::FloatRect playerLocation, float speed, int** map_ArrayLevel);



};

#endif