#include <GLFW/glfw3.h>
#include <unistd.h>
#include <GLUT/glut.h> 
#include <OpenGL/gl.h> 
#include <math.h> 
#include "../includes/Points.h"
#include "../includes/Object.h"
#include "../includes/Camera.h"
#include <iostream>

int height = 700; 
int weith = 700;



void moveCamera(GLFWwindow* window, OGLTypes::Camera &camera){
    double xPos = 0.0f;
    double yPos = 0.0f;
    float speed = 0.0;  
    float ugol = -camera.getAngleZ()/180 * M_PI;
    float upDownSpeed = 0; 

    glfwGetCursorPos(window, &xPos, &yPos); 
    camera.setAngleZ((-180*(((weith / 2))/weith)-xPos));
    camera.setAngleX((-270*((yPos - (height / 2))/height)));
    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) speed = 0.1f; 
    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) speed = -0.1f;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {speed = 0.1f; ugol -= M_PI*0.5f;};
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {speed = 0.1f; ugol += M_PI*0.5f;};
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) {upDownSpeed = -0.1;}; 
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS) {upDownSpeed = 0.1;};
    camera.move2({sin(ugol) * speed, cos(ugol)*speed, upDownSpeed});

    
}  

void winResize(GLFWwindow* window, int width, int height){
    glfwGetWindowSize(window, &width, &height);
    float k = width / (float)height; 
    float sz = 0.1; 
    glLoadIdentity(); 
    glFrustum(-k*sz, k*sz, -sz, sz, sz*2, 100);

}

void show_world(){
    OGLTypes::PointFloat3d rect[] = {
        OGLTypes::PointFloat3d(1, 1, 0), 
        OGLTypes::PointFloat3d(1, -1, 0),
        OGLTypes::PointFloat3d(-1, -1, 0), 
        OGLTypes::PointFloat3d(-1, 1, 0)};
    float colors[] = {0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7};
    for (float i = 0; i <80; i++)
        for (float j = 0; j < 80; j++)
        {
            if (((int)i + (int)j)%2)
                glColor3f(0.5, 0.5, 0.5f);
            else 
                glColor3f(0.7, 0.7, 0.7);

            OGLTypes::Object rectengle(rect, sizeof(rect)/ sizeof(rect[0]));
            rectengle.place({i*2, j*2,  0});
            rectengle.draw();
        }
}

int main(void)
{
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
    glfwSetCursorPos(window,350,350);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
    OGLTypes::Camera &camera = OGLTypes::Camera::instance(); 
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

    OGLTypes::Object obj(points, sizeof(points)/sizeof(points[0]), colors); 
    glfwSetCursorPos(window,350,350);
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.7f, 1.0f, 0.7f, 0.0f);
        moveCamera(window, camera); 
        glPushMatrix();
            camera.draw();
            show_world();
            obj.rotate(1, 0, 0, 1);
            obj.draw();
        glPopMatrix();
        glfwPollEvents();
        glfwSwapBuffers(window);
        usleep(1);
    }

    glfwTerminate();
    return 0;
}