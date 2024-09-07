#include <GLFW/glfw3.h>
#include <unistd.h>
#include <GLUT/glut.h> 
#include <OpenGL/gl.h> 
#include <math.h> 
#include "../includes/Points.h"
#include "../includes/Object.h"



void moveCamera(GLFWwindow* window){
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) glRotatef(-1, 1, 0, 0);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) glRotatef(1, 1, 0, 0);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) glRotatef(1, 0, 0, 1);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) glRotatef(-1, 0, 0, 1);

}

int main(void)
{
    float alpha = 0.0f; 
    int height = 700; 
    int weith = 700; 

    GLFWwindow* window;
    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(height, weith, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();  
    glFrustum(-1, 1, -1, 1, 2, 80); // перспективная проекция 
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0, -1, -5);
    glEnable(GL_DEPTH_TEST);

    float colors[] = {
        0, 0, 0,
        0, 0, 1, 
        0, 1, 0,
        0, 1, 1,
        1, 0, 0, 
        1, 0, 1
    };

    OGLTypes::PointFloat3d points[] = {
        OGLTypes::PointFloat3d(0, 0, 2), 
        OGLTypes::PointFloat3d(1, 1, 0),
        OGLTypes::PointFloat3d(1, -1, 0), 
        OGLTypes::PointFloat3d(-1, -1, 0), 
        OGLTypes::PointFloat3d(-1, 1, 0), 
        OGLTypes::PointFloat3d(1, 1, 0),

    };

    OGLTypes::Object obj(points, colors, sizeof(points)/sizeof(points[0])); 
    OGLTypes::Object obj2(points, colors, sizeof(points)/sizeof(points[0]));
    obj.move2(OGLTypes::Vector3d(1, 1, 0));
    
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.7f, 1.0f, 0.7f, 0.0f);

        obj.draw();
        obj2.draw();

        moveCamera(window); 
        
        glfwPollEvents();
        glfwSwapBuffers(window);
        usleep(1);
    }

    glfwTerminate();
    return 0;
}