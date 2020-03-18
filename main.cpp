#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "map.h"
#include "globals.h"
#include "player.h"
#include "Enemy.h"
#include <list>
#include "Pushka.h"

using namespace std;
using namespace sf;


void winner(RenderWindow & window)
{
	Texture winning_screen;
	winning_screen.loadFromFile("images/win.jpeg");//экран при выйгрыше
	Sprite winscreen(winning_screen);
	winscreen.setPosition(0, 0);

	window.draw(winscreen);
	window.display();
}


void lose(RenderWindow & window)
{
	Texture losee;
	losee.loadFromFile("images/lose.jpeg");//экран при проигрыше
	Sprite lose(losee);
	lose.setPosition(0, 0);

	window.draw(lose);
	window.display();
}


int main()
{


	return 0;
}




