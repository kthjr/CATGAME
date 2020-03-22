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
	Map drawing;
	Player z("cat.png", 78, 48, 20.0, 20.0); 
	Map m;
	Clock clock;


	std::list<Entity*> enemy;//список врагов
	std::list<Entity*>::iterator ee;


	std::list<Push*> pus;//распылители
	std::list<Push*>::iterator pp;

	std::list<Push::Bullet*> bullets;//пули(капли)
	std::list<Push::Bullet*>::iterator bul;
	
    //по¤вление врагов на карте
	for (int i = 0; i < HEIGHT_MAP; i++) {
		for (int j = 0; j < WIDTH_MAP; j++) {

			if (TileMap[i][j] == 'L') {

				enemy.push_back(new Dog(j, i));
				

			}

			if (TileMap[i][j] == 'S') {

				enemy.push_back(new Dogs(j, i));

			}

			if (TileMap[i][j] == 'P') {

				pus.push_back(new Pushka(j, i));

			}


		}
	}

	Font font;
	font.loadFromFile("Ben_Krush.ttf");
	Text text("", font, 20);
	text.setStyle(sf::Text::Bold);
//

	text.setString("«доровье:");
	text.setPosition(400, 0);
	window.draw(text);
	window.draw(z.hpbar);
	window.display();
	
	
	return 0;
}




