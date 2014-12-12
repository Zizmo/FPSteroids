/**
  * Vertex.h
  *
  * This class defines a vertex on a 3D coordinate plane to be rendered.
  */
#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>
#include <GL\x86\include\GL\freeglut.h>

class Vertex
{
public:
	Vertex(void); // default constructor
	Vertex(GLfloat x, GLfloat y, GLfloat z); // constructor with coordinate params
	Vertex(const Vertex& v); // copy constructor
	Vertex& operator= (Vertex v); // copy assignment operator
	~Vertex(void); // destructor

	// getters n' setters
	GLfloat getX();
	GLfloat getY();
	GLfloat getZ();

	void setX(GLfloat x);
	void setY(GLfloat y);
	void setZ(GLfloat z);

	void toString(); // outputs coordinates for debugging
private:
	GLfloat x, y, z;
};

#endif // VERTEX_H

