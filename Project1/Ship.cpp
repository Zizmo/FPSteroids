#include "Ship.h"

// default constructor
Ship::Ship(void) : position(new Vertex(0.0f, 0.0f, 0.0f)) {	setVerticies(); }

// constructor with position params
Ship::Ship(Vertex* pos) : position(pos) { setVerticies(); }

// copy constructor
Ship::Ship(const Ship& s) : position(new Vertex(s.position->getX(), 
	s.position->getY(), s.position->getZ())) { setVerticies(); }

// copy assignment operator
Ship& Ship::operator=(Ship s)
{
	*position = *s.getPosition();
	setVerticies();

	return *this;
}

// destructor
Ship::~Ship(void)
{
	std::cout << "Ship destructor called." << std::endl;

	std::cout << "Deleting position..." << std::endl;
	delete position;

	for (int i = 0; i < NUM_VERTICIES; i++)
	{
		std::cout << "Deleting render vertex " << i << "..." << std::endl;
		delete verticies[i];
	}

	std::cout << "Deleting render array..." << std::endl;
	delete[] verticies;

	std::cout << "Done!" << std::endl;
}

// getters n' setters
Vertex* Ship::getPosition()
{
	return position;
}

void Ship::setPosition(Vertex v)
{
	*position = v;
}

//outputs coordinates for debugging
void Ship::toString()
{
	std::cout << "Ship at ";
	position->toString();
}

// verticies to be drawn
// hard-coded, sorry (not sorry)
void Ship::setVerticies()
{
	verticies[0] = new Vertex(0.0f, 1.0f, 0.0f); // just the tip
	verticies[1] = new Vertex(-0.5f, -0.5f, 0.0f); // left tail
	verticies[2] = new Vertex(-0.25f, -0.25f, 0.0f);
	verticies[3] = new Vertex(0.25f, -0.25f, 0.0f);
	verticies[4] = new Vertex(0.5f, -0.5f, 0.0f); // right tail
}
