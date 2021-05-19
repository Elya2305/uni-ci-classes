#include "Matrix3.h"
#include "iostream"

using namespace std;

int main() {
    Matrix3 matrix{Vector3{7, 1, 3}, Vector3{2, 4, 5}, Vector3{1, 5, 1}};

    cout << matrix.det();
    matrix.multiplyByVector(Vector3{1, 2, 3});
    matrix.abs();

}
