#include "TileManager.h"
#include "Vehicle.h"
#include "Rocks.h"
#include "Tile.h"
#include "Waste.h"
#include "Shark.h"
#include "TopBorder.h"
#include "SideBorder.h"

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

	Vector2f mouseMapPosition;

	Vector2i mouseScreenPosition;

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
	wasteRemainingText.setCharacterSize(55);
	wasteRemainingText.setFillColor(Color::White);
	wasteRemainingText.setPosition(25, 25);
	wasteRemainingText.setString("Waste Remaining: ");

	// creating objects
	vehicle sub(960, 500);

	Rocks rock(500, 500);

	Waste waste(1000, 750, true);

	Shark shark(960, 1080);

	TopBorder topBorder(0, 0);

	SideBorder leftBorder(0, 0);

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

		// Where is the mouse pointer
		//mouseScreenPosition = Mouse::getPosition();

		// Convert mouse position to world coordinates of mainView
		//mouseMapPosition = window.mapPixelToCoords(
			//Mouse::getPosition(), mainView);


		if (state == State::PLAYING) {
			// Handle the pressing and releasing of the WASD keys
			if (Keyboard::isKeyPressed(Keyboard::W)) {
				sub.moveUp();
			}
			else {
				sub.stopUp();
			}

			if (Keyboard::isKeyPressed(Keyboard::S)) {
				sub.moveDown();
			}
			else {
				sub.stopDown();
			}
			if (Keyboard::isKeyPressed(Keyboard::A)) {
				sub.moveLeft();
			}
			else {
				sub.stopLeft();
			}

			if (Keyboard::isKeyPressed(Keyboard::D)) {
				sub.moveRight();
			}
			else {
				sub.stopRight();
			}

			if (Keyboard::isKeyPressed(Keyboard::X)) {
				sub.boost();
			}
		}

		//Updates the pixels and current state of the sub 
		if (state == State::PLAYING) {
			map.width = 500;
			map.height = 500;
			map.left = 0;
			map.top = 0;

			Time dt = clock.restart();

			gameTime += dt;

			float dtAsSeconds = dt.asSeconds();

			mouseScreenPosition = Mouse::getPosition();

			mouseMapPosition = window.mapPixelToCoords(
				Mouse::getPosition(), mainView);

			sub.update(dtAsSeconds, Mouse::getPosition());

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
			if (sub.getPosition().intersects(waste.getPosition()) && Keyboard::isKeyPressed(Keyboard::Space))

			{

				waste.clean();
				wasteRemaining--;

			}

			//size up health bar
			healthBar.setSize(Vector2f(sub.getHealth() * 3, 75));
			healthBarBackground.setSize(Vector2f(300, 75));

			//Increment the frames since last hud calculation
			framesSinceLastHUDUpdate++;

			if (framesSinceLastHUDUpdate > fpsMeasurementFrameInterval) {
				//Add possible scores or waste remaining bits here
				//std::stringstream ssWaste;

				//Update the Waste Text
				//ssWaste << "Waste: " << waste;
				//wasteRemainingText.setString(ssWaste.str());
			}
		}


		/*
		********
		* DRAW *
		********
		*/
		//Draws the view in the window while in the playing state 
		if (state == State::PLAYING) {
			window.setView(mainView);

			window.draw(spriteBackground);

			window.draw(healthBarBackground);

			window.draw(healthBar);

			window.draw(topBorder.getSprite());

			window.draw(leftBorder.getSprite());

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
	}
	return 0;
}