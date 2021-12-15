#include "TileManager.h"
#include "Vehicle.h"
#include "Rocks.h"
#include "Tile.h"
#include "Waste.h"

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

   vehicle sub(0, 0);

   Rocks rock(500,500);

   Waste waste(1000,750);

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
   while (window.isOpen()){
	   //Closes the window
       if (Keyboard::isKeyPressed(Keyboard::Escape)){
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

		   Vector2f subPosition(sub.getCenter());

		   //Collision Detection
		   for (int i = 0; i < 100; i++) {
			   for (int j = 0; j < 100; j++) {
				   if (sub.getPosition().intersects
				   (rock.getPosition())) {
					   sub.getDistance();
				   }
			   }
		   }
	   }

	   
	   //Draws the view in the window while in the playing state 
	   if (state == State::PLAYING) {
		   window.setView(mainView);

		   window.draw(spriteBackground);

		   window.draw(rock.getSprite());

		   window.draw(sub.getSprite());

		   window.draw(waste.getSprite());

		   window.display();
	   }
   }
   return 0;
}