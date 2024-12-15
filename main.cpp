
#define _CRT_SECURE_NO_WARNINGS
#include <GL/glut.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#include "ModelLoader.h"
#include "Cube.h"
#include "Terrain.h"
using namespace std;
float cameraX = 0.0f;
float cameraY = 3.0f;
float cameraZ = 10.0f;

Model mdl(2, 2, 2);

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Установка камеры
    gluLookAt(cameraX, cameraY, cameraZ, cameraX, cameraY, cameraZ - 1.0f, 0.0f, 1.0f, 0.0f);
      // Установка камеры
    /*gluLookAt(2, 6, 6,  // Позиция камеры
        2, 0, 0,  // Точка, на которую смотрит камера
        0, 1, 0); // Вектор "вверх"*/

    //renderLandscape();
    Terrain terr;
    terr.render();
    // Рендеринг куба
    //renderCube(2,2,0);
    for (size_t i = 0; i < 5; i++)
    {
        Cube cube(5, 2, i+3);
        cube.render();
    }

    //renderModel();
   
    mdl.render();

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 'w') cameraZ -= 0.1f;
    if (key == 's') cameraZ += 0.1f;
    if (key == 'a') cameraX -= 0.1f;
    if (key == 'd') cameraX += 0.1f;
    glutPostRedisplay();
    printf("X: %f Y: %f Z:%f\n", cameraX, cameraY, cameraZ);
}

void init() {
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0, 0.0, 0.0, 1.0); // Устанавливаем цвет фона в черный
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (float)width / (float)height, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    setlocale(LC_ALL, "");
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    
    glutCreateWindow("Simple OpenGL Camera with GLUT ");

    /*if (!loadOBJ("electropole.obj")) {
        return -1; // Ошибка загрузки модели
    }*/
    if (!mdl.loadOBJ("ak19.obj")) {
        return -1; // Ошибка загрузки модели
    }
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}
