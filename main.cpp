#include "Bat.h"
#include "Ball.h"
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
	//Create ball
	Ball ball(1920 / 2, 0);
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
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) { window.close(); }//when window is closed
		}
		// handle the player quitting
		if (Keyboard::isKeyPressed(Keyboard::Escape)) { window.close(); }
		if (Keyboard::isKeyPressed(Keyboard::Left)) { bat.moveLeft(); } else { bat.stopLeft(); }
		if (Keyboard::isKeyPressed(Keyboard::Right)) { bat.moveRight(); } else { bat.stopRight(); }
		/*
		* Update bat, ball and HUD
		**********************
		**********************
		*/
		Time dt = clock.restart();//update delta time
		bat.update(dt);
		ball.update(dt);
		std::stringstream ss;//Update HUD text
		ss << "Score:" << score << "Lives:" << lives;
		hud.setString(ss.str());
		//Handle ball hitting bottom
		if (ball.getPosition().top > window.getSize().y)
		{
			//reverse ball direction
			ball.reboundBottom();
			//remove life
			lives--;
			//check for zero lives
			if (lives < 1) { score = 0;lives = 3; }//reset the score and lives
		}
		//handle ball hitting sides
		if (ball.getPosition().left<0 || ball.getPosition().left + ball.getPosition().width>window.getSize().x)
		{
			ball.reboundSides();
		}
		//added handle ball hitting top
		if (ball.getPosition().top<0)
		{
			ball.reboundBatOrTop();
		}
		//has ball hit bat?
		if (ball.getPosition().intersects(bat.getPosition()))
		{
		//hit detected 
			ball.reboundBatOrTop();
		}
		/*
		* Draw bat, ball and HUD
		**********************
		**********************
		*/
		window.clear();
		window.draw(hud);
		window.draw(bat.getShape());
		window.draw(ball.getShape());
		window.display();
		
	}
	return 0;
}