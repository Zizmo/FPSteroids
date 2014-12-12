#include "main.h"

static void RenderSceneCB()
{
	// clears frame buffer using the specified color
    glClear(GL_COLOR_BUFFER_BIT);

	// makes vertex data accessible by graphics pipeline
    glEnableVertexAttribArray(0);

	// binds buffer to a target to be used in executing commands
	// (what the buffer contains-- this case: an array of verticies, buffer object)
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

	// how to interpret data in the buffer
	// (attribute index, number of components in attribute [X, Y, Z]
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glDrawArrays(GL_POINTS, 0, 1);

    glDisableVertexAttribArray(0);

    glutSwapBuffers();
}

static void InitializeGlutCallbacks()
{
	// GLUT render callback
    glutDisplayFunc(RenderSceneCB);
}

static void CreateVertexBuffer()
{
	// make an array of vertices with one vertex
	Vertex* vertices[1];
	vertices[0] = new Vertex(0.0f, 0.0f, 0.0f);
    
	// generates buffers
	// (number of objects, address of buffer)
 	glGenBuffers(1, &VBO);

	// binds buffer to a target to be used in executing commands
	// (what the buffer contains-- this case: an array of verticies, buffer object)
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	// fills bound object with data
	// 
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}

int main(int argc, char** argv)
{
	// initializes GLUT
    glutInit(&argc, argv);

	// GLUT options: GLUT_DOUBLE for double buffering
	// GLUT_RGBA = color buffer
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);

	// specifies window parameters
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("FPSteroids");

    InitializeGlutCallbacks();

    // must be done after glut is initialized!
	// checks for errors (thanks, ogldev!)
    GLenum res = glewInit();
    if (res != GLEW_OK) {
      fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
      return 1;
    }

	// SPECIFY SHADERS, BUFFERS, FLAGS THAT AFFECT
	// RENDERING HERE (had so much trouble with that in school)

	// sets color used when clearing frame buffer
	// RGBA values between 0.0 and 1.0
	// (currently black)
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    CreateVertexBuffer();

	// GLUT begins its internal loop
	// listens to events and passes them via callbacks
    glutMainLoop();

    return 0;
}