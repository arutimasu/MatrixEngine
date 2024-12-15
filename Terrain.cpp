#include "Terrain.h"
void Terrain::render() {
    const unsigned int MapSize = 5; // ������ �����
    int Zoom = 2; // ���������� ��� ������ ���������
    int x, y;

    for (int i = 0; i < MapSize - 1; i++) {
        for (int j = 0; j < MapSize - 1; j++) {
            x = i * Zoom;
            y = j * Zoom;

            glBegin(GL_TRIANGLE_STRIP);
            glColor3f(0.0f, 1.0f, 0.0f); // ������ ���� ��� ���������

            // ����� Z - ������
            glVertex3f(x, HeightMap[i][j], y);         // ������ ����� ����
            glVertex3f(x + Zoom, HeightMap[i + 1][j], y); // ������ ������ ����
            glVertex3f(x, HeightMap[i][j + 1], y + Zoom); // ������� ����� ����
            glVertex3f(x + Zoom, HeightMap[i + 1][j + 1], y + Zoom); // ������� ������ ����

            glEnd();
        }
    }
}