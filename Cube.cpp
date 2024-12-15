#include "Cube.h"

void Cube::render() {

    glBegin(GL_QUADS);
    // Задняя грань
    glColor3f(1.0f, 0.0f, 0.0f); glVertex3f(-1.0f + x, -1.0f + obj_y, -1.0f + obj_z);
    glColor3f(0.0f, 1.0f, 0.0f); glVertex3f(1.0f + x, -1.0f + obj_y, -1.0f + obj_z);
    glColor3f(0.0f, 0.0f, 1.0f); glVertex3f(1.0f + x, 1.0f + obj_y, -1.0f + obj_z);
    glColor3f(1.0f, 1.0f, 0.0f); glVertex3f(-1.0f + x, 1.0f + obj_y, -1.0f + obj_z);
    // Передняя грань
    glColor3f(1.0f, 0.0f, 1.0f); glVertex3f(-1.0f + x, -1.0f + obj_y, 1.0f + obj_z);
    glColor3f(0.0f, 1.0f, 1.0f); glVertex3f(1.0f +x , -1.0f + obj_y, 1.0f + obj_z);
    glColor3f(1.0f, 1.0f, 1.0f); glVertex3f(1.0f + x, 1.0f + obj_y, 1.0f + obj_z);
    glColor3f(0.5f, 0.5f, 0.5f); glVertex3f(-1.0f + x, 1.0f + obj_y, 1.0f + obj_z);
    // Левые грань
    glColor3f(1.0f, 0.5f, 0.0f); glVertex3f(-1.0f + x, -1.0f + obj_y, -1.0f + obj_z);
    glColor3f(0.0f, 1.0f, 0.5f); glVertex3f(-1.0f + x, -1.0f + obj_y, 1.0f + obj_z);
    glColor3f(0.0f, 0.5f, 1.0f); glVertex3f(-1.0f + x, 1.0f + obj_y, 1.0f + obj_z);
    glColor3f(1.0f, 0.0f, 0.5f); glVertex3f(-1.0f + x, 1.0f + obj_y, -1.0f + obj_z);
    // Правые грань
    glColor3f(0.5f, 1.0f, 0.0f); glVertex3f(1.0f +x , -1.0f + obj_y, -1.0f + obj_z);
    glColor3f(0.0f, 1.0f, 0.5f); glVertex3f(1.0f +x , -1.0f + obj_y, 1.0f + obj_z);
    glColor3f(0.0f, 0.5f, 1.0f); glVertex3f(1.0f +x , 1.0f + obj_y, 1.0f + obj_z);
    glColor3f(1.0f, 0.0f, 0.5f); glVertex3f(1.0f +x , 1.0f + obj_y, -1.0f + obj_z);
    // Верхняя грань
    glColor3f(0.5f, 0.5f, 0.5f); glVertex3f(-1.0f +x , 1.0f + obj_y, -1.0f + obj_z);
    glColor3f(0.5f, 0.5f, 0.5f); glVertex3f(1.0f +x , 1.0f + obj_y, -1.0f + obj_z);
    glColor3f(0.5f, 0.5f, 0.5f); glVertex3f(1.0f +x , 1.0f + obj_y, 1.0f + obj_z);
    glColor3f(0.5f, 0.5f, 0.5f); glVertex3f(-1.0f +x , 1.0f + obj_y, 1.0f + obj_z);
    // Нижняя грань
    glColor3f(0.5f, 0.5f, 0.5f); glVertex3f(-1.0f + x, -1.0f + obj_y, -1.0f + obj_z);
    glColor3f(0.5f, 0.5f, 0.5f); glVertex3f(1.0f + x, -1.0f + obj_y, -1.0f + obj_z);
    glColor3f(0.5f, 0.5f, 0.5f); glVertex3f(1.0f +x , -1.0f + obj_y, 1.0f + obj_z);
    glColor3f(0.5f, 0.5f, 0.5f); glVertex3f(-1.0f + x, -1.0f + obj_y, 1.0f + obj_z);
    glEnd();

}