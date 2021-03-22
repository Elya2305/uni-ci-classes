#include<iostream>

using namespace std;

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char col;
    unsigned row;

} Field;

void input(Field *field) {
    char letter;
    unsigned digit;

    cout << "Letter=";
    cin >> letter;
    field->col = letter;
    cout << "Digit=";
    cin >> digit;
    field->row = digit;
}

void output(Field *field) {
    cout << "Digit: " << field->row << " Letter: " << field->col;
}

int main() {
    Field *field = new Field();
    input(field);
    output(field);
}
