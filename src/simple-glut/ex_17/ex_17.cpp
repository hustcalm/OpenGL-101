#include <GL/glew.h>
#include <GL/glfw.h>
#include <GL/glut.h>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>

// Called when the window is resized
void GLFWCALL window_resized(int width, int height);

// Called for keyboard events
void keyboard(int key, int action);

// Render scene
void display();

int main (int argc, char** argv) {
    // Initialize GLUT
    glutInit(&argc, argv);
    //glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	// Initialize GLFW
	if ( !glfwInit()) {
		std::cerr << "Failed to initialize GLFW! I'm out!" << std::endl;
		exit(-1);
	}

	// Use OpenGL 3.2 core profile
    /*
	glfwOpenWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwOpenWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, 3);
	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, 2);
    */

	// Open a window and attach an OpenGL rendering context to the window surface
	if( !glfwOpenWindow(500, 500, 8, 8, 8, 0, 0, 0, GLFW_WINDOW)) {
		std::cerr << "Failed to open a window! I'm out!" << std::endl;
		glfwTerminate();
		exit(-1);
	}

	// Register a callback function for window resize events
	glfwSetWindowSizeCallback( window_resized );

	// Register a callback function for keyboard pressed events
	glfwSetKeyCallback(keyboard);	

	// Print the OpenGL version
	int major, minor, rev;
	glfwGetGLVersion(&major, &minor, &rev);
	std::cout << "OpenGL - " << major << "." << minor << "." << rev << std::endl;

	// Initialize GLEW
	glewExperimental = GL_TRUE;
	if(glewInit() != GLEW_OK) {
		std::cerr << "Failed to initialize GLEW! I'm out!" << std::endl;
		glfwTerminate();
		exit(-1);
	}

	// Create a rendering loop
	int running = GL_TRUE;

	while(running) {
		// Display scene
		display();

		// Pool for events
		glfwPollEvents();
		// Check if the window was closed
		running = glfwGetWindowParam(GLFW_OPENED);
	}

	// Terminate GLFW
	glfwTerminate();

	return 0;
}

// Render scene
void display() {
	glClear(GL_COLOR_BUFFER_BIT);

    // Draw the teapot
    glutSolidTeapot(0.1);

	// Swap front and back buffers
	glfwSwapBuffers();
}

// Called when the window is resized
void GLFWCALL window_resized(int width, int height) {
	// Use red to clear the screen
	//glClearColor(1, 0, 0, 1);

	// Set the viewport
	glViewport(0, 0, width, height);

	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers();
}

// Called for keyboard events
void keyboard(int key, int action) {
	if(key == 'Q' && action == GLFW_PRESS) {
		glfwTerminate();
		exit(0);
	}
}

