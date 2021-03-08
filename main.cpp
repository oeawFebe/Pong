#include "Bat.h"
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
int main()
{
	VideoMode vm(1920, 1080);
	RenderWindow window(vm, "Pong", Style::Fullscreen);
	int score = 0;
	int lives = 3;

	//Create bat 
	Bat bat(1920 / 2, 1080 - 20);

	//create text obj called hud
	Text hud;
	Font font;
	font.loadFromFile("fonts/DS-DIGIT.TTF");
	hud.setFont(font);
	hud.setCharacterSize(75);
	hud.setFillColor(Color::White);
	hud.setPosition(20, 20);
	Clock clock;

	while (window.isOpen())
	{
		/*
		* Handle player input
		**********************
		**********************
		*/
		/*
		* Update bat, ball and HUD
		**********************
		**********************
		*/
		/*
		* Draw bat, ball and HUD
		**********************
		**********************
		*/
		
	}
	return 0;
}