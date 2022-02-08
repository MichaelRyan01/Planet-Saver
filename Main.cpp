#include "TileManager.h"
#include "Vehicle.h"
#include "Rocks.h"
#include "Waste.h"
#include "Shark.h"
#include "TopBorder.h"
#include "SideBorder.h"
#include "SubUI.h"
#include "RightBorder.h"
#include "HeliUI.h"
#include "Trees.h"
#include "Helicopter.h"
#include "Lake.h"
#include <sstream>

int main() {
	TileManager holder;

	enum class State {MENU, ABOUT, HOWTOPLAY, GAMEOVERSUB, GAMEOVERHELI, PLAYINGSUB, PLAYINGHELI};
	State state = State::MENU;

	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	RenderWindow window(VideoMode(resolution.x, resolution.y),
		"Planet Saver - Submission Edition (tm)", Style::Fullscreen);

	View mainView(FloatRect(0, 0, resolution.x, resolution.y));

	Clock clock;

	//waste variable
	int wasteRemaining = 2;

	int firesRemaining = 2;

	bool subWin = false;
	bool heliWin = false;

	int score = 0;

	Time gameTime;

	/*
	*****************
	* The Games Hud *
	*****************
	*/
	View hudView(sf::FloatRect(0, 0, resolution.x, resolution.y));

	//Font
	Font font;
	font.loadFromFile("fonts/komikap.ttf");

	//Health bar
	RectangleShape healthBar;
	healthBar.setFillColor(Color::Green);
	healthBar.setPosition(25, 980);
	RectangleShape healthBarBackground;
	healthBarBackground.setFillColor(Color::Red);
	healthBarBackground.setPosition(25, 980);

	//Updating the hud
	int framesSinceLastHUDUpdate = 0;
	int fpsMeasurementFrameInterval = 1000;

	//Waste Remaining Text
	Text wasteRemainingText;
	wasteRemainingText.setFont(font);
	wasteRemainingText.setCharacterSize(70);
	wasteRemainingText.setFillColor(Color::White);
	wasteRemainingText.setPosition(400, 975);
	wasteRemainingText.setString("Waste Remaining: " + wasteRemaining);

	//Score Text
	Text scoreText;
	scoreText.setFont(font);
	scoreText.setCharacterSize(70);
	scoreText.setFillColor(Color::White);
	scoreText.setPosition(1250, 975);
	scoreText.setString("Waste Remaining: " + wasteRemaining);

	//Fire Text
	Text fireText;
	fireText.setFont(font);
	fireText.setCharacterSize(70);
	fireText.setFillColor(Color::White);
	fireText.setPosition(750, 975);
	fireText.setString("Fires Remaining: " + firesRemaining);

	//Fire Text
	Text waterText;
	waterText.setFont(font);
	waterText.setCharacterSize(70);
	waterText.setFillColor(Color::White);
	waterText.setPosition(50, 975);
	waterText.setString("Water Left: ");

	///code by tommy

	// For the home/game over screen
	Sprite spriteGameOver;
	Texture textureGameOver = TileManager::GetTexture("graphics/MainMenu.png");
	spriteGameOver.setTexture(textureGameOver);
	spriteGameOver.setPosition(0, 0);

	// How to play
	Text howToPlayText;
	howToPlayText.setFont(font);
	howToPlayText.setCharacterSize(55);
	howToPlayText.setFillColor(Color::Magenta);
	howToPlayText.setPosition(300, 100);

	std::stringstream howToPlayStream;
	howToPlayStream <<
		"How to Play" <<
		"\n"
		"\nClean the oil spills and avoid the Sharks!!" <<
		"\nGet water and put out fires!" <<
		"\n"
		"\nW/Arrow Up = Move Up" <<
		"\nA/Arrow Left = Move Left" <<
		"\nS/Arrow Down = Move Down" <<
		"\nD/Arrow Right = Move Right" <<
		"\nRight/Left Shift = Boost (Submarine)" <<
		"\nClean Waste/Put Out Fire/Get Water = Space" <<
		"\n"
		"\nR = Back to Menu";
	howToPlayText.setString(howToPlayStream.str());

	//About
	Text aboutText;
	aboutText.setFont(font);
	aboutText.setCharacterSize(55);
	aboutText.setFillColor(Color::Magenta);
	aboutText.setPosition(300, 100);

	std::stringstream aboutStream;
	aboutStream <<
		"About" <<
		"\n"
		"\nThis is our 3rd year group project." <<
		"\nThis projects theme was climate change." <<
		"\nThis game is a series of mini games" <<
		"\ncentered around climate change." <<
		"\n" <<
		"\nWe hope you enjoy our game." <<
		"\n- Sam, Mick and Thomas" <<
		"\n"
		"\nR = Back to Menu";
	aboutText.setString(aboutStream.str());

	// Menu
	Text menuText;
	menuText.setFont(font);
	menuText.setCharacterSize(110);
	menuText.setFillColor(Color::White);
	menuText.setPosition(170, 330);


	std::stringstream MenuStream;
	MenuStream <<
		"1- Submarine Game" <<
		"\n2- Forest Fire Game" <<
		"\n3- How to Play" <<
		"\n4- About" <<
		"\n5- Quit"
		;
	menuText.setString(MenuStream.str());


	// creating objects
	vehicle sub(960, 500);

	Helicopter heli(960, 500);

	Rocks rock1(500, 500);
	Rocks rock2(700, 400);

	Waste waste1(1000, 750, true);
	Waste waste2(1300, 850, true);

	Trees tree1(1400, 600, true);
	Trees tree2(300, 400, true);

	Shark shark(960, 1080);

	Lake lake(710, 290);

	TopBorder topBorder(0, 0);

	SideBorder leftBorder(0, 0);

	RightBorder rightBorder(2045, 0);

	SubUI SubUI(0, 965);
	HeliUI HeliUI(0, 965);

	IntRect map;

	VertexArray background;

	Texture textureBackground = TileManager::GetTexture(
		"graphics/background.png");

	Texture textureBackgroundHeli = TileManager::GetTexture("graphics/backgroundHeli.png");

	Texture textureGameOverSub = TileManager::GetTexture("graphics/gameOverSub.png");

	Texture textureGameOverHeli = TileManager::GetTexture("graphics/gameOverHeli.png");

	Texture textureOtherMenu = TileManager::GetTexture("graphics/pause.png");

	Texture textureBoostButton = TileManager::GetTexture("graphics/boostIcon.png");

	Texture textureCheckMark = TileManager::GetTexture("graphics/checkmark.png");

	Sprite spriteBackground;
	spriteBackground.setTexture(textureBackground);
	spriteBackground.setPosition(0, 0);

	Sprite spriteBackgroundHeli;
	spriteBackgroundHeli.setTexture(textureBackgroundHeli);
	spriteBackgroundHeli.setPosition(0, 0);

	Sprite gameOverSub;
	gameOverSub.setTexture(textureGameOverSub);
	gameOverSub.setPosition(0, 0);

	Sprite gameOverHeli;
	gameOverHeli.setTexture(textureGameOverHeli);
	gameOverSub.setPosition(0, 0);

	Sprite otherMenu;
	otherMenu.setTexture(textureOtherMenu);
	otherMenu.setPosition(0, 0);

	Sprite boostButton;
	boostButton.setTexture(textureBoostButton);
	boostButton.setPosition(1125, 975);

	Sprite checkMark1;
	checkMark1.setTexture(textureCheckMark);
	checkMark1.setPosition(115, 375);
	checkMark1.setScale(0.1f, 0.1f);

	Sprite checkMark2;
	checkMark2.setTexture(textureCheckMark);
	checkMark2.setPosition(115, 525);
	checkMark2.setScale(0.1f, 0.1f);

	//While the window is open
	while (window.isOpen()) {
		//Closes the window
		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Num1))

		{

			shark.setPosition(960, 1080);

		}

		//Updates the pixels and current state of the sub 
		if (state == State::PLAYINGSUB)

		{

			sub.movement();
			//Sub and Rocks Collisions
			if (sub.getPosition().intersects(rock1.getPosition()) 
			|| sub.getPosition().intersects(rock2.getPosition())) {
				if (Keyboard::isKeyPressed(Keyboard::W) || (Keyboard::isKeyPressed(Keyboard::Up))) {
					sub.stopUp();
				}
				else if (Keyboard::isKeyPressed(Keyboard::A) || (Keyboard::isKeyPressed(Keyboard::Right))) {
					sub.stopLeft();
				}
				else if (Keyboard::isKeyPressed(Keyboard::D) || (Keyboard::isKeyPressed(Keyboard::Left))) {
					sub.stopRight();
				}
				else if (Keyboard::isKeyPressed(Keyboard::S) || (Keyboard::isKeyPressed(Keyboard::Down))) {
					sub.stopDown();
				}
			}

			//Collision Detection

			//Sub and Top Border Collision
			if (sub.getPosition().intersects
			(topBorder.getPosition())) {
				sub.posDistanceY();
			}

			//Sub and Left Border Position
			if (sub.getPosition().intersects
			(leftBorder.getPosition())) {
				sub.posDistanceX();
			}

			if (sub.getPosition().intersects(SubUI.getPosition()))

			{

				 if (Keyboard::isKeyPressed(Keyboard::S)) {
					sub.stopDown();
				}

			}

			if (sub.getPosition().intersects(rightBorder.getPosition()))

			{

				if (Keyboard::isKeyPressed(Keyboard::D)) {
					sub.stopRight();
				}

			}

			map.width = 500;
			map.height = 500;
			map.left = 0;
			map.top = 0;

			Time dt = clock.restart();

			gameTime += dt;

			float dtAsSeconds = dt.asSeconds();

			sub.update(dtAsSeconds);

			shark.attack(dtAsSeconds, sub.getCenter());

			Vector2f subPosition(sub.getCenter());

			//Shark and Sub damage collision
			if (shark.getPosition().intersects
			(sub.getPosition())) {
				sub.hit(gameTime);

				if (score > 0)

				{

					score = score - 50;

				}

			}

			// waste removal
			if (sub.getPosition().intersects(waste1.getPosition()) && Keyboard::isKeyPressed(Keyboard::Space) && waste1.isSpawned())

			{

				waste1.clean();
				wasteRemaining--;
				score = score + 100;

			}

			if (sub.getPosition().intersects(waste2.getPosition()) && Keyboard::isKeyPressed(Keyboard::Space) && waste2.isSpawned())

			{

				waste2.clean();
				wasteRemaining--;
				score = score + 100;

			}

			//size up health bar
			healthBar.setSize(Vector2f(sub.getHealth() * 3, 75));
			healthBarBackground.setSize(Vector2f(300, 75));

			//Increment the frames since last hud calculation
			framesSinceLastHUDUpdate++;

			if (framesSinceLastHUDUpdate > fpsMeasurementFrameInterval)

			{
				//Add possible scores or waste remaining bits here
				//std::stringstream ssWaste;
				std::stringstream ssWaste;

				//Update waste text
				ssWaste << "Waste Remaining: " << wasteRemaining;
				wasteRemainingText.setString(ssWaste.str());

				std::stringstream ssScore;

				//Update waste text
				ssScore << "Score: " << score;
				scoreText.setString(ssScore.str());

			}

			if (sub.getHealth() == 0)

			{

				state = State::GAMEOVERSUB;

			}

			if (wasteRemaining == 0)

			{

				state = State::MENU;
				waste1.respawnWaste();
				waste2.respawnWaste();
				sub.resetVehicleStats();
				wasteRemaining = 2;
				subWin = true;
				score = 0;

			}

		}

		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		if (state == State::PLAYINGHELI)

		{

			map.width = 500;
			map.height = 500;
			map.left = 0;
			map.top = 0;

			Time dt = clock.restart();

			gameTime += dt;

			float dtAsSeconds = dt.asSeconds();

			heli.update(dtAsSeconds);

			heli.movement();

			//Helicopter and border detection
			if (heli.getPosition().intersects(topBorder.getPosition())) 
			
			{
			
				if (Keyboard::isKeyPressed(Keyboard::W) || (Keyboard::isKeyPressed(Keyboard::Up)))

				{

					heli.stopUp();

				}
			
			}

			if (heli.getPosition().intersects(leftBorder.getPosition())) 
			
			{

				if (Keyboard::isKeyPressed(Keyboard::A) || (Keyboard::isKeyPressed(Keyboard::Left)))

				{

					heli.stopLeft();

				}
			
			}

			if (heli.getPosition().intersects(HeliUI.getPosition()))

			{

				if (Keyboard::isKeyPressed(Keyboard::S) || (Keyboard::isKeyPressed(Keyboard::Down)))

				{

					heli.stopDown();

				}

			}

			if (heli.getPosition().intersects(rightBorder.getPosition()))

			{

				if (Keyboard::isKeyPressed(Keyboard::D) || (Keyboard::isKeyPressed(Keyboard::Right)))
				
				{
				
					heli.stopRight();
				
				}

			}

			//Increment the frames since last hud calculation
			framesSinceLastHUDUpdate++;

			if (framesSinceLastHUDUpdate > fpsMeasurementFrameInterval)

			{

				std::stringstream ssFireRemaining;

				ssFireRemaining << "Fires Left: " << firesRemaining;
				fireText.setString(ssFireRemaining.str());

				std::stringstream ssWaterSupplies;

				ssWaterSupplies << "Water Left: " << heli.currentWater << "/" << heli.maxWater;
				waterText.setString(ssWaterSupplies.str());


			}

			// putting out fires
			if (heli.getPosition().intersects(tree1.getPosition()) && Keyboard::isKeyPressed(Keyboard::Space))

			{

					if (heli.currentWater > 0)

					{

						tree1.extinguish();
						firesRemaining--;
						heli.currentWater--;

					}

			}

			if (heli.getPosition().intersects(tree2.getPosition()) && Keyboard::isKeyPressed(Keyboard::Space) && tree2.isOnFire() == true)

			{

				if (heli.currentWater > 0)

				{

					tree2.extinguish();
					firesRemaining--;
					heli.currentWater--;

				}

			}

			//get water

			if (heli.getPosition().intersects(lake.getPosition()) && Keyboard::isKeyPressed(Keyboard::Space))

			{

				if (heli.currentWater < heli.maxWater)

				{

					heli.currentWater = heli.currentWater++;

				}

			}

			// if timer

			//{

			//	state = State::GAMEOVERSUB;

			//}

			if (firesRemaining == 0)

			{

				state = State::MENU;
				tree1.reignite();
				tree2.reignite();
				heli.resetVehicleStats();
				firesRemaining = 2;
				heliWin = true;

			}

		}

		if (Keyboard::isKeyPressed(Keyboard::R) && state == State::GAMEOVERSUB)
		{
			state = State::PLAYINGSUB;
			waste1.respawnWaste();
			waste2.respawnWaste();
			sub.resetVehicleStats();
			wasteRemaining = 2;
			score = 0;
		}

		if (Keyboard::isKeyPressed(Keyboard::Enter) && state == State::GAMEOVERSUB)
		{
			state = State::MENU;
			waste1.respawnWaste();
			waste2.respawnWaste();
			sub.resetVehicleStats();
			wasteRemaining = 2;
			score = 0;
		}

		if (Keyboard::isKeyPressed(Keyboard::R) && state == State::GAMEOVERHELI)
		
		{
		
			state = State::PLAYINGHELI;

		}

		if (Keyboard::isKeyPressed(Keyboard::Enter) && state == State::GAMEOVERHELI)
		
		{
		
			state = State::MENU;

		}


		// Return to menu (Tommy)
		if (Keyboard::isKeyPressed(Keyboard::R) &&
			state == State::ABOUT)
		{
			state = State::MENU;
		}

		if (Keyboard::isKeyPressed(Keyboard::R) && state == State::HOWTOPLAY)
		
		{
		
			state = State::MENU;
		
		}

		// Handles picking play (Tommy)
		if (Keyboard::isKeyPressed(Keyboard::Num1) &&
			state == State::MENU)
		{
			state = State::PLAYINGSUB;
		}

		if (Keyboard::isKeyPressed(Keyboard::Num2) && state == State::MENU)
		
		{
		
			state = State::PLAYINGHELI;
		
		}

		if (Keyboard::isKeyPressed(Keyboard::Num3) && state == State::MENU)

		{

			state = State::HOWTOPLAY;

		}

		// Handles picking about (Tommy)
		if (Keyboard::isKeyPressed(Keyboard::Num4) &&
			state == State::MENU)
		{
			state = State::ABOUT;
		}

		// Handles picking about (Tommy)
		if (Keyboard::isKeyPressed(Keyboard::Num5) &&
			state == State::MENU)
		{
			window.close();
		}

		/*
		********
		* DRAW *
		********
		*/
		//Draws the view in the window while in the playing state 
		if (state == State::PLAYINGSUB)

		{
			window.setView(mainView);

			window.draw(spriteBackground);

			window.draw(topBorder.getSprite());

			window.draw(leftBorder.getSprite());

			window.draw(rightBorder.getSprite());

			window.setView(hudView);

			window.draw(rock1.getSprite());

			window.draw(rock2.getSprite());

			if (waste1.isSpawned())

			{

				window.draw(waste1.getSprite());

			}

			if (waste2.isSpawned())

			{

				window.draw(waste2.getSprite());

			}

			window.draw(shark.getSprite());

			window.draw(sub.getSprite());

			window.draw(SubUI.getSprite());

			window.draw(healthBarBackground);

			window.draw(healthBar);

			window.draw(wasteRemainingText);

			window.draw(scoreText);

			window.draw(boostButton);

			window.display();
		}

		if (state == State::GAMEOVERSUB)

		{

			window.setView(mainView);

			window.draw(gameOverSub);

			Text gameOverText1;
			gameOverText1.setFont(font);
			gameOverText1.setCharacterSize(100);
			gameOverText1.setFillColor(Color::Red);
			gameOverText1.setPosition(700, 500);
			gameOverText1.setString("Game Over!");

			Text gameOverText2;
			gameOverText2.setFont(font);
			gameOverText2.setCharacterSize(50);
			gameOverText2.setFillColor(Color::White);
			gameOverText2.setPosition(300, 600);
			gameOverText2.setString("Press R to restart or Enter to return to menu.");

			window.draw(gameOverText1);
			window.draw(gameOverText2);

			window.display();

		}

		if (state == State::PLAYINGHELI)

		{

			window.setView(mainView);

			window.draw(spriteBackgroundHeli);

			window.draw(topBorder.getSprite());

			window.draw(leftBorder.getSprite());

			window.draw(rightBorder.getSprite());

			window.setView(hudView);

			window.draw(lake.getSprite());

			window.draw(tree1.getSprite());

			window.draw(tree2.getSprite());

			window.draw(heli.getSprite());

			window.draw(HeliUI.getSprite());

			window.draw(fireText);

			window.draw(waterText);

			window.display();

		}

		if (state == State::GAMEOVERHELI)

		{

			window.setView(mainView);

			window.draw(gameOverHeli);

			Text gameOverText1;
			gameOverText1.setFont(font);
			gameOverText1.setCharacterSize(100);
			gameOverText1.setFillColor(Color::Red);
			gameOverText1.setPosition(700, 500);
			gameOverText1.setString("Game Over!");

			Text gameOverText2;
			gameOverText2.setFont(font);
			gameOverText2.setCharacterSize(50);
			gameOverText2.setFillColor(Color::White);
			gameOverText2.setPosition(300, 600);
			gameOverText2.setString("Press R to restart or ESC to return to menu.");

			window.draw(gameOverText1);
			window.draw(gameOverText2);

			window.display();

		}

		if (state == State::MENU) {
			window.setView(mainView);

			window.draw(spriteGameOver);

			window.draw(menuText);

			if (subWin == true)

			{

				window.draw(checkMark1);

			}

			if (heliWin == true)

			{

				window.draw(checkMark2);

			}

			window.display();
		}

		if (state == State::HOWTOPLAY) {

			window.setView(mainView);

			window.draw(otherMenu);

			window.draw(howToPlayText);

			window.display();
		}

		if (state == State::ABOUT) 
		
		{

			window.setView(mainView);

			window.draw(otherMenu);

			window.draw(aboutText);

			window.display();
		
		}

	}

	return 0;
}