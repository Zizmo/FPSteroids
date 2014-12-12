/**
  * Ship.h
  *
  * This class is the 2D representation of the ship to be added to the minimap
  */
#ifndef SHIP_H
#define SHIP_H

#include "Vertex.h"

class Ship
{
public:
	Ship(void); // default constructor
	Ship(Vertex* pos); // constructor with position param
	Ship(const Ship& s); // copy constructor
	Ship& operator=(Ship s); // copy assignment operator
	~Ship(void); // destructor

	// getters n' setters
	Vertex* getPosition();

	void setPosition(Vertex v);

	void toString(); // outputs coordinates for debugging
private:
	static int const NUM_VERTICIES = 5; // number of verticies that make up the ship's shape
	Vertex* position; // center coordinate of ship
	Vertex* verticies[NUM_VERTICIES]; // verticies to be drawn

	void setVerticies();
};
#endif // SHIP_H

