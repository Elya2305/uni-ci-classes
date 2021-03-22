#include<iostream>

using namespace std;

struct Point {
    double x;
    double y;
};
struct Rectangle {
    Point p1;
    Point p2;
};

void input(Point *field) {
    char x;
    unsigned y;

    cout << "X=";
    cin >> x;
    field->x = x;
    cout << "Y=";
    cin >> y;
    field->y = y;
}

void input(Rectangle *rec, Point *p1, Point *p2) {
    rec->p1 = *p1;
    rec->p2 = *p2;
}

void print(Rectangle *rec) {
    cout << rec->p1.x << " " << rec->p1.y <<
         " " << rec->p2.x << " " << rec->p2.y;
}

int main() {
    Point *p1 = new Point();
    Point *p2 = new Point();

    Rectangle *rec = new Rectangle();
    input(p1);
    input(p2);

    input(rec, p1, p2);

    print(rec);
    delete p1;
    delete p2;
    delete rec;
};