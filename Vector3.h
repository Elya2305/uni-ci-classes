#ifndef TEST_VECTOR3_H
#define TEST_VECTOR3_H


class Vector3 {
private:
    int x;
    int y;
    int z;


public:
    Vector3(int x, int y, int z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    int getX() const;

    int getY() const;

    int getZ() const;
};


#endif
