
#define _CRT_SECURE_NO_WARNINGS
#include <GL/glut.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#include "ModelLoader.h"
#include "Cube.h"
#include "Wall.h"

#include "Terrain.h"
using namespace std;
float cameraX = 4.0f;
float cameraY = 1.0f;
float cameraZ = 10.0f;


int sectorX = 0;
int sectorY = 0;
int sectorZ = 0;

Model mdl(2, 1, 2);

bool RifleIsPicked = false;

int WallMap[5][5] = {
      2, 1, 1, 1 ,1,
      2, 0 ,0, 0, 0,
      2, 0, 0, 0, 0,
      2, 0, 0, 0, 0,
      2, 1, 1, 1, 1
};
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // ”становка камеры
    gluLookAt(cameraX, cameraY, cameraZ, cameraX, cameraY, cameraZ - 1.0f, 0.0f, 1.0f, 0.0f);
      // ”становка камеры
    /*gluLookAt(2, 6, 6,  // ѕозици€ камеры
        2, 0, 0,  // “очка, на которую смотрит камера
        0, 1, 0); // ¬ектор "вверх"*/

    //renderLandscape();
    Terrain terr;
    terr.render();
    // –ендеринг куба
    //renderCube(2,2,0);
    /*for (size_t i = 0; i < 5; i++)
    {
        //Cube cube(5, 2, i+3);
        Wall wall(false, 7, 1, i * 2);
        wall.render();
    }
    for (size_t i = 0; i < 5; i++)
    {
        //Cube cube(5, 2, i+3);
        Wall wall(false, -1, 1, i * 2);
        wall.render();
    }
    for (size_t i = 0; i < 5; i++)
    {
        //Cube cube(5, 2, i+3);
        Wall wall(true, i*2, 1, 0);
        wall.render();
    }*/

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
        {
            if (WallMap[i][j] == 1) {
                Wall wall(false, i * 2, 1, j * 2);//по сути раскидывает квадратики, превраща€ в карту. то есть задает каждому из них позицию. если убрать, то вс€ карта нарисуетс€ в одном квадрате 32*32 и мы увидим один квадрат
                wall.render();//рисуем квадратики на экран
                
            } //если встретили символ пробел, то рисуем 1й квадратик
            if (WallMap[i][j] == 2) {
                Wall wall(true, i * 2, 1, j * 2);//по сути раскидывает квадратики, превраща€ в карту. то есть задает каждому из них позицию. если убрать, то вс€ карта нарисуетс€ в одном квадрате 32*32 и мы увидим один квадрат
                wall.render();//рисуем квадратики на экран
            } //если встретили символ пробел, то рисуем 1й квадратик


          
        }
    //renderModel();
   
    if ((sectorX != 1 || sectorZ != 1) && !RifleIsPicked) {
        mdl.render();
    }
    else {
        RifleIsPicked = true;
        puts("You picked a modern assault rifle!\n");
    }

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    
    if (key == 'w' && sectorZ > 0) cameraZ -= 0.1f;
    if (key == 's') cameraZ += 0.1f;
    if (key == 'a' && sectorX > 0) cameraX -= 0.1f;
    if (key == 'd' && sectorX < 4) cameraX += 0.1f;
    glutPostRedisplay();
    sectorZ = cameraZ / 2;
    sectorX = cameraX / 2;
    printf("cam X: %d Y: %f Z: %d  \n", sectorX, cameraY, sectorZ);
}

void init() {
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0, 0.0, 0.0, 1.0); // ”станавливаем цвет фона в черный
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
        return -1; // ќшибка загрузки модели
    }*/
    if (!mdl.loadOBJ("ak19.obj")) {
        return -1; // ќшибка загрузки модели
    }
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}
