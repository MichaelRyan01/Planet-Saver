#include "Submarine.h"

Submarine::Submarine()
{
	// Associate a texture with the sprite
	 /* m_Sprite = Sprite(TextureHolder::GetTexture(
		"graphics/player.png")); */
		///m_Sprite = Sprite(TextureHolder::GetTexture(
	"graphics/pacman-spritesheet-resized-810-730.jpg";
	///m_Sprite.setTextureRect(sf::IntRect{ 12,62,50,50 });
	ani_counter = 1;


}

bool Submarine::handleInput()
{


	//2019 up and down movement
	///if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		m_UpPressed = true;

	}
	///else
	{
		m_UpPressed = false;
	}

	///if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		m_DownPressed = true;

	}
	///else
	{
		m_DownPressed = false;
	}
	///if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		m_LeftPressed = true;

	}
	///else
	{
		m_LeftPressed = false;
	}


	///if (Keyboard::isKeyPressed(Keyboard::Right))
	{

		m_RightPressed = true;
		//	cout << "right key pressed Player update \n";

	}
	///else
	{
		m_RightPressed = false;
	}

	return 0;
}

void Submarine::update(float elapsedTime)
{
	timeElapsed = elapsedTime;

	if (m_RightPressed)
	{
		m_Position.x += m_Speed * elapsedTime;
		direction = sf::Vector2f(0, -1);
		//2nd row of sprite sheet 3 characters
	//	cout << "player update Right Pressed call SetSpriteFrom Sheet , time elapsed" << clock.getElapsedTime().asSeconds() << "\n";
		setSpriteFromSheet(sf::IntRect(12, 62, 150, 50));
		//move the rectangle to the appropriate cell
		moveTextureRect();

		/*		counter++;
			if (counter > 2)
				{
				cout << "right key press about to call moveTextureRect counter val " << counter << "\n";
					counter = 0;
					moveTextureRect();
				//	clock.restart();
				}
		*/
	}
	if (m_LeftPressed)
	{
		m_Position.x -= m_Speed * elapsedTime;
		direction = sf::Vector2f(0, 1);
		//1st row of sprite sheet 3 characters
		setSpriteFromSheet(sf::IntRect(12, 12, 150, 50));
		//move the rectangle to the appropriate cell
		moveTextureRect();

		/*		counter++;
			if (counter > 3)
				{
				cout << "right key press about to call moveTextureRect counter val " << counter << "\n";
					counter = 0;
					moveTextureRect();
				//	clock.restart();
				}
		*/
	}

	if (m_UpPressed)
	{
		m_Position.y -= m_Speed * elapsedTime;
		direction = sf::Vector2f(1, 0);
		//3rd row of sprite sheet 3 characters
		//cout << "player update up Pressed call SetSpriteFrom Sheet \n";
		setSpriteFromSheet(sf::IntRect(12, 112, 150, 50));
		//move the rectangle to the appropriate cell
		moveTextureRect();

		/*		counter++;
			if (counter > 3)
				{
				cout << "right key press about to call moveTextureRect counter val " << counter << "\n";
					counter = 0;
					moveTextureRect();
				//	clock.restart();
				}
		*/
	}

	if (m_DownPressed)
	{

		m_Position.y += m_Speed * elapsedTime;
		direction = sf::Vector2f(-1, 0);
		//4th row of sprite sheet 3 characters
//		cout << "playableCharacter update down Pressed call SetSpriteFrom Sheet \n";
		setSpriteFromSheet(sf::IntRect(12, 162, 150, 50));
		//move the rectangle to the appropriate cell
		moveTextureRect();

		/*		counter++;
			if (counter > 3)
				{
				cout << "right key press about to call moveTextureRect counter val " << counter << "\n";
					counter = 0;
					moveTextureRect();
				//	clock.restart();
				}
		*/
	}
}