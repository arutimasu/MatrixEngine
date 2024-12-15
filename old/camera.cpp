
#include <GL/glut.h>
#include <iostream>

float cameraX = 0.0f;
float cameraY = 0.0f;
float cameraZ = 3.0f;

void renderCube() {
    glBegin(GL_QUADS);
    // Задняя грань
    glColor3f(1.0f, 0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
    glColor3f(0.0f, 1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
    glColor3f(0.0f, 0.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
    glColor3f(1.0f, 1.0f, 0.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
    // Передняя грань
    glColor3f(1.0f, 0.0f, 1.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
    glColor3f(0.0f, 1.0f, 1.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
    glColor3f(1.0f, 1.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
    glColor3f(0.5f, 0.5f, 0.5f); glVertex3f(-1.0f,  1.0f,  1.0f);
    // Левые грань
    glColor3f(1.0f, 0.5f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
    glColor3f(0.0f, 1.0f, 0.5f); glVertex3f(-1.0f, -1.0f,  1.0f);
    glColor3f(0.0f, 0.5f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
    glColor3f(1.0f, 0.0f, 0.5f); glVertex3f(-1.0f,  1.0f, -1.0f);
    // Правые грань
    glColor3f(0.5f, 1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
    glColor3f(0.0f, 1.0f, 0.5f); glVertex3f( 1.0f, -1.0f,  1.0f);
    glColor3f(0.0f, 0.5f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
    glColor3f(1.0f, 0.0f, 0.5f); glVertex3f( 1.0f,  1.0f, -1.0f);
    // Верхняя грань
    glColor3f(0.5f, 0.5f, 0.5f); glVertex3f(-1.0f, 1.0f, -1.0f);
    glColor3f(0.5f, 0.5f, 0.5f); glVertex3f( 1.0f, 1.0f, -1.0f);
    glColor3f(0.5f, 0.5f, 0.5f); glVertex3f( 1.0f, 1.0f, 1.0f);
    glColor3f(0.5f, 0.5f, 0.5f); glVertex3f(-1.0f, 1.0f, 1.0f);
    // Нижняя грань
    glColor3f(0.5f, 0.5f, 0.5f); glVertex3f(-1.0f, -1.0f, -1.0f);
    glColor3f(0.5f, 0.5f, 0.5f); glVertex3f( 1.0f, -1.0f, -1.0f);
    glColor3f(0.5f, 0.5f, 0.5f); glVertex3f( 1.0f, -1.0f, 1.0f);
    glColor3f(0.5f, 0.5f, 0.5f); glVertex3f(-1.0f, -1.0f, 1.0f);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Установка камеры
    gluLookAt(cameraX, cameraY, cameraZ, cameraX, cameraY, cameraZ - 1.0f, 0.0f, 1.0f, 0.0f);

    // Рендеринг куба
    renderCube();

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 'w') cameraZ -= 0.1f;
    if (key == 's') cameraZ += 0.1f;
    if (key == 'a') cameraX -= 0.1f;
    if (key == 'd') cameraX += 0.1f;
    glutPostRedisplay();
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
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Simple OpenGL Camera with GLUT");

    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
    }
