#include "Cube.h"

void Cube::render() {

    glBegin(GL_QUADS);
    // ������ �����
    glColor3f(1.0f, 0.0f, 0.0f); glVertex3f(-1.0f + x, -1.0f + y, -1.0f + z);
    glColor3f(0.0f, 1.0f, 0.0f); glVertex3f(1.0f + x, -1.0f + y, -1.0f + z);
    glColor3f(0.0f, 0.0f, 1.0f); glVertex3f(1.0f + x, 1.0f + y, -1.0f + z);
    glColor3f(1.0f, 1.0f, 0.0f); glVertex3f(-1.0f + x, 1.0f + y, -1.0f + z);
    // �������� �����
    glColor3f(1.0f, 0.0f, 1.0f); glVertex3f(-1.0f + x, -1.0f + y, 1.0f + z);
    glColor3f(0.0f, 1.0f, 1.0f); glVertex3f(1.0f +x , -1.0f + y, 1.0f + z);
    glColor3f(1.0f, 1.0f, 1.0f); glVertex3f(1.0f + x, 1.0f + y, 1.0f + z);
    glColor3f(0.5f, 0.5f, 0.5f); glVertex3f(-1.0f + x, 1.0f + y, 1.0f + z);
    // ����� �����
    glColor3f(1.0f, 0.5f, 0.0f); glVertex3f(-1.0f + x, -1.0f + y, -1.0f + z);
    glColor3f(0.0f, 1.0f, 0.5f); glVertex3f(-1.0f + x, -1.0f + y, 1.0f + z);
    glColor3f(0.0f, 0.5f, 1.0f); glVertex3f(-1.0f + x, 1.0f + y, 1.0f + z);
    glColor3f(1.0f, 0.0f, 0.5f); glVertex3f(-1.0f + x, 1.0f + y, -1.0f + z);
    // ������ �����
    glColor3f(0.5f, 1.0f, 0.0f); glVertex3f(1.0f +x , -1.0f + y, -1.0f + z);
    glColor3f(0.0f, 1.0f, 0.5f); glVertex3f(1.0f +x , -1.0f + y, 1.0f + z);
    glColor3f(0.0f, 0.5f, 1.0f); glVertex3f(1.0f +x , 1.0f + y, 1.0f + z);
    glColor3f(1.0f, 0.0f, 0.5f); glVertex3f(1.0f +x , 1.0f + y, -1.0f + z);
    // ������� �����
    glColor3f(0.5f, 0.5f, 0.5f); glVertex3f(-1.0f +x , 1.0f + y, -1.0f + z);
    glColor3f(0.5f, 0.5f, 0.5f); glVertex3f(1.0f +x , 1.0f + y, -1.0f + z);
    glColor3f(0.5f, 0.5f, 0.5f); glVertex3f(1.0f +x , 1.0f + y, 1.0f + z);
    glColor3f(0.5f, 0.5f, 0.5f); glVertex3f(-1.0f +x , 1.0f + y, 1.0f + z);
    // ������ �����
    glColor3f(0.5f, 0.5f, 0.5f); glVertex3f(-1.0f + x, -1.0f + y, -1.0f + z);
    glColor3f(0.5f, 0.5f, 0.5f); glVertex3f(1.0f + x, -1.0f + y, -1.0f + z);
    glColor3f(0.5f, 0.5f, 0.5f); glVertex3f(1.0f +x , -1.0f + y, 1.0f + z);
    glColor3f(0.5f, 0.5f, 0.5f); glVertex3f(-1.0f + x, -1.0f + y, 1.0f + z);
    glEnd();

}