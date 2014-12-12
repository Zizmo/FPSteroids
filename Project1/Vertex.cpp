#include "Vertex.h"

// default constructor
Vertex::Vertex(void): x(0.0f), y(0.0f), z(0.0f) { }

// constructor with coordinate params
Vertex::Vertex(GLfloat x, GLfloat y, GLfloat z): x(x), y(y), z(z) { }

// copy constructor
Vertex::Vertex(const Vertex& v): x(v.x), y(v.y), z(v.z) { }

// copy assignment operator
Vertex& Vertex::operator= (Vertex v)
{
	x = v.getX();
	y = v.getY();
	z = v.getZ();

	return *this;
}

// destructor
Vertex::~Vertex(void)
{
	std::cout << "Vertex destructor called." << std::endl;
}

// getters and setters
GLfloat Vertex::getX() { return x; }
GLfloat Vertex::getY() { return y; }
GLfloat Vertex::getZ() { return z; }

void Vertex::setX(GLfloat x) { this->x = x; }
void Vertex::setY(GLfloat y) { this->y = y; }
void Vertex::setZ(GLfloat z) { this->z = z; }

void Vertex::toString()
{
	std::cout << "<" << x << ", " << y << ", " << z << ">" << std::endl;
}




