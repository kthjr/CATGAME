#include "SFML/Graphics.hpp" 
#include <iostream> 
#include "map.h" 
#include "globals.h" 
#include "Enemy.h" 
#include "player.h" 
#include "Pushka.h"



Pushka::Pushka(int x, int y) {
	t.loadFromFile("images/dogs.png");
	sprite.setTexture(t);
	sprite.setTextureRect(IntRect(0, 0, 23, 23));
	rect = FloatRect(x * 32, y * 32, 0, 0);
	dx = 0;
}

void Push::drawing()
{
	sprite.setPosition(rect.left, rect.top);
	window.draw(sprite);
}


FloatRect Push::polozenie() {
	return rect;
}
float Push::uskorenie() {
	return dx;
}

Push::Bullet::Bullet(FloatRect polozh, float uskor) {
	bullet_rect = polozh;
	life = true;
	im.loadFromFile("images/bullet.png");
	sprite.setTextureRect(IntRect(0, 0, 23, 23));
	t.loadFromImage(im);
	sprite.setTexture(t);
	//	dx = loc_dx * (-3);
	dx = -0.1;
}

void Push::Bullet::drawing() {

	time = clock.getElapsedTime().asMicroseconds();
	clock.restart();

	time = time / 400;

	sprite.setPosition(bullet_rect.left, bullet_rect.top);
	bullet_rect.left = bullet_rect.left + dx * time;

	WithMap();

	window.draw(sprite);
}


