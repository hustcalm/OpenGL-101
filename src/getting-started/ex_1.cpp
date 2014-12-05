#include <GL/glfw.h>
#include <cstdlib>
#include <iostream>

// Called when the window is resized
void GLFWCALL window_resized(int width, int height);

// Called for keyboard events
void GLFWCALL keyboard(int key, int action);

int main () {
    // Initialize GLFW
    if ( !glfwInit()) {
        std::cerr << "Failed to initialize GLFW! I'm out!" << std::endl;
        exit(-1);
    }

    // Open a window and attach an OpenGL rendering context to the window surface
    if( !glfwOpenWindow(800, 600, 8, 8, 8, 0, 0, 0, GLFW_WINDOW)) {
        std::cerr << "Failed to open a window! I'm out!" << std::endl;
        glfwTerminate();
        exit(-1);
    }

    // Register a callback function for keyboard pressed events
    glfwSetKeyCallback(keyboard);

    // Register a callback function for window resize events
    glfwSetWindowSizeCallback( window_resized );    

    // Print the OpenGL version
    int major, minor, rev;
    glfwGetGLVersion(&major, &minor, &rev);
    std::cout << "OpenGL - " << major << "." << minor << "." << rev << std::endl;   

    // Create a rendering loop
    int running = GL_TRUE;
    while(running) {
        // Use red to clear the screen
        glClearColor(1, 0, 0, 1);       
        glClear(GL_COLOR_BUFFER_BIT);

        // Swap front and back buffers
        glfwSwapBuffers();

        // Pool for events
        glfwPollEvents();
        // Check if the window was closed
        running = glfwGetWindowParam(GLFW_OPENED);
    }

    // Terminate GLFW
    glfwTerminate();

    return 0;
}

// Called when the window is resized
void GLFWCALL window_resized(int width, int height) {
    glClearColor(1, 0, 0, 1);   
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers();
}

// Called for keyboard events
void GLFWCALL keyboard(int key, int action) {
    if(key == 'Q' && action == GLFW_PRESS) {
        glfwTerminate();
        exit(0);
    }
}
