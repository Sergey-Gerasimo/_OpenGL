#include <GLFW/glfw3.h>
#include <unistd.h>
#include <GLUT/glut.h> 
#include <OpenGL/gl.h> 
#include <math.h> 
#include "../includes/Points.h"
#include "../includes/Object.h"
#include "../includes/Camera.h"
#include <iostream>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

int height = 700; 
int weith = 700;

std::ostream &operator<<(std::ostream &os, OGLTypes::POINTFLOAT &obj)
{
    return os << "Point( x=" << obj.getX() << ", y=" << obj.getY() << ", z=" << obj.getZ() << " );";
};

void moveCamera(GLFWwindow* window, OGLTypes::Camera &camera){
    double xPos = 0.0f;
    double yPos = 0.0f;
    float speed = 0.0;  
    float ugol = -camera.getAngleZ()/180 * M_PI;
    float upDownSpeed = 0; 
    OGLTypes::PointFloat3d pos; 
    pos = camera.getPosition();
    std::cout << pos << '\n';
    glfwGetCursorPos(window, &xPos, &yPos); 
    camera.setAngleZ((-180*(((weith / 2))/weith)-xPos));
    camera.setAngleX((-270*((yPos - (height / 2))/height)));
    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) speed = 0.1f; 
    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) speed = -0.1f;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {speed = 0.1f; ugol -= M_PI*0.5f;};
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {speed = 0.1f; ugol += M_PI*0.5f;};
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) {upDownSpeed = -0.1;}; 
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS) {upDownSpeed = 0.1;};
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {glfwTerminate(); exit(0);};
    camera.move2({sin(ugol) * speed, cos(ugol)*speed, upDownSpeed});

    
}  

void winResize(GLFWwindow* window, int width, int height){
    glfwGetWindowSize(window, &width, &height);
    float k = width / (float)height; 
    float sz = 0.1; 
    glLoadIdentity(); 
    glFrustum(-k*sz, k*sz, -sz, sz, sz*2, 100);

}

void show_world(float r, float g, float b){
    OGLTypes::PointFloat3d rect[] = {
        OGLTypes::PointFloat3d(1, 1, 0), 
        OGLTypes::PointFloat3d(1, -1, 0),
        OGLTypes::PointFloat3d(-1, -1, 0), 
        OGLTypes::PointFloat3d(-1, 1, 0)};
    float colors[] = {0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7};
    float normas[] = {
        1, 1, 3,
        1, -1, 3, 
        -1, -1, 3, 
        -1, 1, 3

    };
    for (float i = 0; i <20; i++)
        for (float j = 0; j < 20; j++)
        {
            glColor3f(r, g, b);
            OGLTypes::Object rectengle(rect, sizeof(rect)/ sizeof(rect[0]));
            rectengle.setNormals(normas);
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
    OGLTypes::Camera &camera = OGLTypes::Camera::instance(1000); 
    float colors[] = {
        0, 0, 0,
        0, 0, 1, 
        0, 1, 0,
        0, 1, 1,
        1, 0, 0, 
        1, 0, 1
    };

    float normas[] = {
        0, 0, 5, 
        1, 1, 3, 
        1, -1, 3, 
        -1, -1, 3, 
        -1, 1, 3,
        1, 1, 3

    };

    OGLTypes::PointFloat3d points[] = {
        OGLTypes::PointFloat3d(0, 0, 2), 
        OGLTypes::PointFloat3d(1, 1, 0),
        OGLTypes::PointFloat3d(1, -1, 0), 
        OGLTypes::PointFloat3d(-1, -1, 0), 
        OGLTypes::PointFloat3d(-1, 1, 0), 
        OGLTypes::PointFloat3d(1, 1, 0),

    };

    OGLTypes::Object obj(points, sizeof(points)/sizeof(points[0])); 
    obj.setNormals(normas);
    //obj.setColors(colors);
    obj.scale(10);
    glfwSetCursorPos(window,350,350);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_NORMALIZE);

    OGLTypes::PointFloat3d point_sun[] = {
        OGLTypes::PointFloat3d(0.2, 0.2, 0), 
        OGLTypes::PointFloat3d(0.2, -0.2, 0), 
        OGLTypes::PointFloat3d(-0.2, -0.2, 0),
        OGLTypes::PointFloat3d(-0.2, 0.2, 0),  
        OGLTypes::PointFloat3d(0.2, 0.2, 0.2), 
        OGLTypes::PointFloat3d(0.2, -0.2, 0.2), 
        OGLTypes::PointFloat3d(-0.2, -0.2, 0.2),
        OGLTypes::PointFloat3d(-0.2, 0.2, 0.2)
    };
    OGLTypes::Object sun (point_sun, 8);
    float theta = 0.0f; 
    float r = 10; 
    camera.place({-20, -20, -108});
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.7f, 1.0f, 0.7f, 0.0f);
        glPushMatrix();
                theta += 0.05f;
                float pos[] = {20, 20 , 0, 10.0f};
                glLightfv(GL_LIGHT0, GL_POSITION, pos);
                GLfloat angle = 90.0; 
                glLightfv(GL_LIGHT0, GL_SPOT_CUTOFF, &angle);
                angle = 24; 
                glLightfv(GL_LIGHT0, GL_SPOT_EXPONENT, &angle);
                sun.place({pos[0], pos[1], pos[2]});
                glColor3f(1, 1, 1);
                sun.draw();
                obj.place({40, 40, 0});
                obj.rotate(1, 0, 0, 1);
                camera.draw();
            glPushMatrix();
                glColorMaterial(GL_FRONT, GL_AMBIENT);
                glColorMaterial(GL_SHININESS, 128);
                glTranslatef(0, 0, 0);
                show_world(0.7, 0.3, 0.3);
            glPopMatrix();

            glPushMatrix();
                glColorMaterial(GL_FRONT, GL_SPECULAR); 
                glColorMaterial(GL_SHININESS, 32);
                glTranslatef(40, 0, 0);
                show_world(0.3, 0.7, 0.3);
            glPopMatrix();

            glPushMatrix();
                glColorMaterial(GL_FRONT, GL_DIFFUSE);
                glColorMaterial(GL_SHININESS, 64);
                //obj.draw();
                glTranslatef(0, 40, 0);
                show_world(0.7, 0.3, 0.7);
            glPopMatrix(); 

            glPushMatrix();
                glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
                glColorMaterial(GL_SHININESS, 0);
                glTranslatef(40, 40, 0);
                show_world(0.7, 0.7, 0.7);
            glPopMatrix(); 
        moveCamera(window, camera);
        glPopMatrix();
        glfwPollEvents();
        glfwSwapBuffers(window);
        usleep(1);
    }
    glfwTerminate();
    return 0;
}