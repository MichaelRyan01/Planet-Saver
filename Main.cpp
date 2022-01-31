#include "TileManager.h"
#include "Vehicle.h"
#include "Rocks.h"
#include "Waste.h"
#include "Shark.h"
#include "TopBorder.h"
#include "SideBorder.h"
#include <sstream>

int main() {
	TileManager holder;

	enum class State { PAUSED, LEVELING_UP, GAME_OVER, PLAYING };
	State state = State::PLAYING;

	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	RenderWindow window(VideoMode(resolution.x, resolution.y),
		"Planet Saver - Submarine", Style::Fullscreen);

	View mainView(FloatRect(0, 0, resolution.x, resolution.y));

	Clock clock;

	Time gameTime;

	// waste variables for submarine game
	int numOfWaste;
	int wasteRemaining = 1;

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

	// creating objects
	vehicle sub(960, 500);

	Rocks rock(500, 500);

	Waste waste(1000, 750, true);

	Shark shark(960, 1080);

	TopBorder topBorder(0, 0);

	SideBorder leftBorder(0, 0);

	SideBorder rightBorder(100, 100);

	//RightSideBorder rightBorder(1900, 0);

	//Rocks rock2;
	//Rocks rock3;

	IntRect map;

	VertexArray background;

	Texture textureBackground = TileManager::GetTexture(
		"graphics/background.png");

	Sprite spriteBackground;
	spriteBackground.setTexture(textureBackground);
	spriteBackground.setPosition(0, 0);

	//While the window is open
	while (window.isOpen()) {
		//Closes the window
		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			window.close();
		}

		//Updates the pixels and current state of the sub 
		if (state == State::PLAYING) 
		
		{
			
			sub.movement();

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

			//Sub and Right Border Collisions
			//if (sub.getPosition().intersects
			//(rightBorder.getPosition())) {
			//	sub.negDistanceX();
			//}

			//Sub and Rocks Collisions
			if (sub.getPosition().intersects
			(rock.getPosition())) {
				if (sub.getX() <= rock.getX() + 10) {
					sub.posDistanceX();
				}
				else {
					sub.negDistanceX();
				}

				if (sub.getY() >= rock.getY() - 10) {
					sub.posDistanceY();
				}
				else {
					sub.negDistanceY();
				}
			}

			//Shark and Sub damage collision
			if (shark.getPosition().intersects
			(sub.getPosition())) {
				sub.hit(gameTime);
			}

			// waste removal
			if (sub.getPosition().intersects(waste.getPosition()) && Keyboard::isKeyPressed(Keyboard::Space) && waste.isSpawned())

			{

				waste.clean();
				wasteRemaining--;

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

			}

			if (sub.getHealth() == 0)

			{

				state = State::GAME_OVER;

			}

		}

		if (state == State::GAME_OVER)

		{

			if (Keyboard::isKeyPressed(Keyboard::R))

			{

				state = State::PLAYING;

			}

		}


		/*
		********
		* DRAW *
		********
		*/
		//Draws the view in the window while in the playing state 
		if (state == State::PLAYING) 
		
		{
			window.setView(mainView);

			window.draw(spriteBackground);

			window.draw(healthBarBackground);

			window.draw(healthBar);

			window.draw(topBorder.getSprite());

			window.draw(leftBorder.getSprite());

			window.draw(rightBorder.getSprite());

			window.setView(hudView);

			window.draw(rock.getSprite());

			if (waste.isSpawned())

			{

				window.draw(waste.getSprite());

			}

			window.draw(shark.getSprite());

			window.draw(sub.getSprite());

			window.draw(wasteRemainingText);

			window.display();
		}

		if (state == State::GAME_OVER)

		{

			window.setView(mainView);

			window.draw(spriteBackground);

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
			gameOverText2.setPosition(400, 600);
			gameOverText2.setString("Press R to restart or ESC to exit game.");

			window.draw(gameOverText1);
			window.draw(gameOverText2);

			window.display();

		}
	}
	
	return 0;
}