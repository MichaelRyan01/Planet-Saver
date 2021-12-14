#include "TileManager.h"
#include "Vehicle.h"

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

   vehicle sub;

   IntRect map;

   VertexArray background;

   Texture textureBackground = TileManager::GetTexture(
      "graphics/background.png");

   Sprite spriteBackground;
   spriteBackground.setTexture(textureBackground);
   spriteBackground.setPosition(0, 0);

   while (window.isOpen()){
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

	   if (state == State::PLAYING) {
		   Time dt = clock.restart();

		   gameTime += dt;

		   float dtAsSeconds = dt.asSeconds();

		   mouseScreenPosition = Mouse::getPosition();

		   mouseMapPosition = window.mapPixelToCoords(
			   Mouse::getPosition(), mainView);

		   sub.update(dtAsSeconds, Mouse::getPosition());

		   Vector2f subPosition(sub.getCenter());
	   }


	   if (state == State::PLAYING) {
		   window.setView(mainView);

		   window.draw(spriteBackground);

		   window.draw(sub.getSprite());

		   window.display();
	   }
   }
   return 0;
}