/* Joshua Crotts
* First C++ SFML Assignment - Bouncing Balls (Random positions)
* Using pointers, random numbers, addresses, SFML, classes and OOP
* October 10, 2017
*/

#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <math.h>

#include "Ball.h"

float randFloat(float);

int main() {
	srand(time(NULL));
	
	//Dimenions of screen
	const int WIDTH = 600;
	const int HEIGHT = 600;
	const int SHAPE_AMT = 2 << 5;

	//Initializes a new window with a specified width and height and title
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML Works!");

	//Initializes a pointer vector of Ball objects called shapes
	std::vector<Ball*> shapes;

	//Initialize and instantiate the balls
	for (int i = 0; i < SHAPE_AMT; i++) {
		sf::CircleShape* shape = new sf::CircleShape(rand() % 25);
		shapes.push_back(new Ball(shape, rand() % WIDTH, rand() % HEIGHT, shape->getRadius(), randFloat(0.75f), randFloat(0.75f)));
	}

	//While the window is open, poll events and do what is necessary
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}

		}
		//Clears the window from the previous screen to utilize double buffering
		window.clear();
		//******UPDATE HERE*******/

		//Loops through the shapes vector and ticks all the Ball objects
		for (int i = 0; i < shapes.size(); i++) {
			if (shapes[i]->getY() < -5 || shapes[i]->getY() > HEIGHT + shapes[i]->getRadius()) {
				delete shapes[i]; //Deletes the object itself
				shapes.erase(shapes.begin() + i); //Erases the element from the vector
			}
			shapes[i]->tick();//If it's in bounds, tick it (update it)
			
		}
		
		/*******DRAW HERE*********/
		
		//Loops through the shapes vector, calls the draw method from the window object and draws the shape 
		for (int i = 0; i < shapes.size(); i++) {
			window.draw(shapes[i]->getShape()); //Draws the sf::CS object
		}

		//End draw
		window.display();
	}

}

//Returns a random float from [0, max)
float randFloat(float max) {
	return ((float)rand() / (float)(RAND_MAX / max));
}