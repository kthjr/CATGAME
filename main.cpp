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

	while (window.isOpen())
	{
		if (z.win >= 1)
		{
	
			window.close();
			RenderWindow window(sf::VideoMode(900, 590), "CATGAME"); 
			winner(window); while (!Mouse::isButtonPressed(Mouse::Right));
		}
		if (z.hp <= 0)
		{
		
			window.close();
			RenderWindow window(sf::VideoMode(900, 900), "CATGAME");
			lose(window); while (!Mouse::isButtonPressed(Mouse::Right));
		}




		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

		}
		window.clear(Color(33, 30, 30));


		m.drawing();
		z.draw_p();

		for (ee = enemy.begin(); ee != enemy.end(); ee++) {
			(*ee)->drawing(z.GetPlayerCoordinateX(), z.GetPlayerCoordinateY(), z);
		}

		for (pp = pus.begin(); pp != pus.end(); pp++) {
			(*pp)->drawing();


			if ((*pp)->shoot > 300) {
				(*pp)->shoot = 0;
				FloatRect polozh = (*pp)->polozenie();
				float uskor = (*pp)->uskorenie();
				bullets.push_back(new Push::Bullet(polozh, uskor));
			}
			(*pp)->shoot++;
		}

		for (bul = bullets.begin(); bul != bullets.end(); bul++) {
			if ((*bul)->life) {

				(*bul)->WithPlayer(z);
				(*bul)->drawing();
			}
			else {
				delete((*bul));
				bullets.remove(*bul);
				break;
			}
		}






		text.setString("«доровье:");
		text.setPosition(400, 0);
		window.draw(text);
		window.draw(z.hpbar);
		window.display();

	}

	return 0;
}




