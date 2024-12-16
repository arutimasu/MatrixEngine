
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

    // ��������� ������
    gluLookAt(cameraX, cameraY, cameraZ, cameraX, cameraY, cameraZ - 1.0f, 0.0f, 1.0f, 0.0f);
      // ��������� ������
    /*gluLookAt(2, 6, 6,  // ������� ������
        2, 0, 0,  // �����, �� ������� ������� ������
        0, 1, 0); // ������ "�����"*/

    //renderLandscape();
    Terrain terr;
    terr.render();
    // ��������� ����
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
                Wall wall(false, i * 2, 1, j * 2);//�� ���� ����������� ����������, ��������� � �����. �� ���� ������ ������� �� ��� �������. ���� ������, �� ��� ����� ���������� � ����� �������� 32*32 � �� ������ ���� �������
                wall.render();//������ ���������� �� �����
                
            } //���� ��������� ������ ������, �� ������ 1� ���������
            if (WallMap[i][j] == 2) {
                Wall wall(true, i * 2, 1, j * 2);//�� ���� ����������� ����������, ��������� � �����. �� ���� ������ ������� �� ��� �������. ���� ������, �� ��� ����� ���������� � ����� �������� 32*32 � �� ������ ���� �������
                wall.render();//������ ���������� �� �����
            } //���� ��������� ������ ������, �� ������ 1� ���������


          
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
    glClearColor(0.0, 0.0, 0.0, 1.0); // ������������� ���� ���� � ������
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
        return -1; // ������ �������� ������
    }*/
    if (!mdl.loadOBJ("ak19.obj")) {
        return -1; // ������ �������� ������
    }
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}
