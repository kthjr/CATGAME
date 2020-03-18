#include <SFML/Graphics.hpp>
#include "globals.h"
#include "map.h"
#include <fstream>
#include <string>

RenderWindow window(sf::VideoMode(1080, 800), "CAT GAME");


Map::Map() {

	image1.loadFromFile("images/map3.png");

	map.loadFromImage(image1);

	s_map.setTexture(map);

	Clock clock;



}

Map::~Map() {

}




void Map::drawing() {
	for (int i = 0; i < HEIGHT_MAP; i++)
		for (int j = 0; j < WIDTH_MAP; j++)
		{
			if (TileMap[i][j] == ' ')  s_map.setTextureRect(IntRect(0, 0, 32, 32)); //если встретили символ пробел, то рисуем 1й квадратик
			if ((TileMap[i][j] == '0')) s_map.setTextureRect(IntRect(0, 64, 32, 32));//если встретили символ 0, то рисуем 3й квадратик
			if ((TileMap[i][j] == '2')) s_map.setTextureRect(IntRect(64, 64, 32, 32));
			if ((TileMap[i][j] == '3')) s_map.setTextureRect(IntRect(96, 64, 32, 32));
			if ((TileMap[i][j] == '4')) s_map.setTextureRect(IntRect(64, 96, 32, 32));
			if ((TileMap[i][j] == '5')) s_map.setTextureRect(IntRect(96, 96, 32, 32));
			if ((TileMap[i][j] == '6')) s_map.setTextureRect(IntRect(64, 32, 32, 32));
			if ((TileMap[i][j] == '7')) s_map.setTextureRect(IntRect(96, 32, 32, 32));

			if ((TileMap[i][j] == '8')) s_map.setTextureRect(IntRect(64, 0, 32, 32));
			if ((TileMap[i][j] == '9')) s_map.setTextureRect(IntRect(96, 0, 32, 32));

			if ((TileMap[i][j] == 'i')) s_map.setTextureRect(IntRect(128, 64, 32, 32));
			if ((TileMap[i][j] == 'o')) s_map.setTextureRect(IntRect(160, 64, 32, 32));
			if ((TileMap[i][j] == 'u')) s_map.setTextureRect(IntRect(192, 64, 32, 32));

			if ((TileMap[i][j] == 'c')) s_map.setTextureRect(IntRect(0, 96, 32, 32));//дверь1
			if ((TileMap[i][j] == 'v')) s_map.setTextureRect(IntRect(0, 96, 32, 32));//дверь2
			if ((TileMap[i][j] == 'n')) s_map.setTextureRect(IntRect(0, 96, 32, 32));//дверь3



			if ((TileMap[i][j] == '[')) s_map.setTextureRect(IntRect(32, 96, 52, 52));//открытая дверь


			if ((TileMap[i][j] == '*')) s_map.setTextureRect(IntRect(0, 128, 52, 52));//открытая грядка
			if ((TileMap[i][j] == '&')) s_map.setTextureRect(IntRect(64, 128, 52, 52));//открытая грядка 2
			if ((TileMap[i][j] == '%')) s_map.setTextureRect(IntRect(32, 128, 52, 52));//открытая грядка 2

			if ((TileMap[i][j] == 'q')) s_map.setTextureRect(IntRect(96, 0, 32, 32));
			if ((TileMap[i][j] == 'w')) s_map.setTextureRect(IntRect(128, 32, 32, 32));
			if ((TileMap[i][j] == '1')) s_map.setTextureRect(IntRect(32, 64, 32, 32));

			if ((TileMap[i][j] == 'k')) s_map.setTextureRect(IntRect(96, 128, 32, 32));//рыбка
			if ((TileMap[i][j] == 'm')) s_map.setTextureRect(IntRect(128, 0, 32, 32));//ключ
			
			if ((TileMap[i][j] == 'x')) s_map.setTextureRect(IntRect(0, 0, 32, 32));
			if ((TileMap[i][j] == 'b')) s_map.setTextureRect(IntRect(0, 0, 32, 32));
			if ((TileMap[i][j] == 'd')) s_map.setTextureRect(IntRect(0, 0, 32, 32));

			if ((TileMap[i][j] == 'h')) s_map.setTextureRect(IntRect(96, 160, 32, 32));//сердечко
			if (TileMap[i][j] == 'L')  s_map.setTextureRect(IntRect(0, 0, 32, 32));
			if (TileMap[i][j] == 'P') s_map.setTextureRect(IntRect(0, 0, 32, 32));

			if ((TileMap[i][j] == '<')) s_map.setTextureRect(IntRect(0, 160, 32, 32));//сердечко
			if (TileMap[i][j] == 'j')  s_map.setTextureRect(IntRect(32, 160, 32, 32));
			if (TileMap[i][j] == '>') s_map.setTextureRect(IntRect(64, 160, 32, 32));


			s_map.setPosition(j * 32, i * 32);

			window.draw(s_map);


		}
}

String TileMap[HEIGHT_MAP] = {

	"2111911111iooooooooooooou111111113",
	"0   0  k        k            S   0",
	"0   0      L            k        0",
	"61[15     h          L    h S    0",
	"0             k         S        0",
	"0   S                    L   L   0",
	"0      L             h    k    S 0",
	"0  k        L    k      S     x  0",
	"611111111119191111111111111119c917",
	"0          0 0               0 0 0",
	"0 P0 1111115 6111 13 2111113 0 0 0",
	"0  0         0     0 0     0 0   0",
	"0 P0 213 213 61113 0 0 213 415 217",
	"0  0 0 0 0 0 0   0 0   0 0     0 0",
	"0 P0 0 0 0 0 41115 0 215 4111115 0",
	"0b 0 0     0   m   0 0           0",
	"6v18181191181111111818111911111117",
	"0       0     <j>    P   0     P 0",
	"0       0     0           P      0",
	"0   0          P                 0",
	"0   0               P0         dP0",
	"0          P0        0  <j>  21n17",
	"0 <j>  P    0                0   0",
	"0                 P      0   0 w 0",
	"4111111111111111111111111811181115",

};