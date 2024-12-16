
#include <GL/glut.h>
class Wall {
public:
    Wall(bool is_horizontal, int x, int y, int z) {
        this->is_horizontal = is_horizontal;
        this->x = x;
        this->y = y;
        this->z = z;
    }
    void render();
private:
    bool is_horizontal;
    int x, y, z;
};