#include<iostream>

using namespace std;

struct Rational {
    int numerator;
    unsigned int denominator;
};

void inputRational(Rational &rational, int numerator, int denominator) {
    rational.numerator = numerator;
    rational.denominator = denominator;
}

float num(Rational r1) {
    return (float) r1.numerator / r1.denominator;
}

float sum(Rational r1, Rational r2) {
    return ((float) r1.numerator / r1.denominator) + ((float) r2.numerator / r2.denominator);
}

float mul(Rational r1, Rational r2) {
    return ((float) r1.numerator / r1.denominator) * ((float) r2.numerator / r2.denominator);
}

void cut(Rational r) {
    int max = r.denominator > r.numerator ? r.denominator : r.numerator;
    for (int i = 2; i < max; ++i) {
        if (r.numerator % i == 0 && r.denominator % i == 0) {
            r.numerator = r.numerator / i;
            r.denominator = r.denominator / i;
        }
    }
    cout << r.numerator << "/" << r.denominator;
}

void compare(Rational r1, Rational r2) {
    if (num(r1) > num(r2)) {
        cout << r1.numerator << "/" << r1.denominator << " > " << r2.numerator << "/" << r2.denominator << "\n";
    } else if (num(r2) < num(r1)) {
        cout << r1.numerator << "/" << r1.denominator << " < " << r2.numerator << "/" << r2.denominator << "\n";
    } else {
        cout << r2.numerator << "/" << r2.denominator << " = " << r1.numerator << "/" << r1.denominator << "\n";
    }
}

int main() {
    Rational *r1 = new Rational();
    inputRational(*r1, 6, 9);

    Rational *r2 = new Rational();
    inputRational(*r2, 1, 3);

    cout << "Sum: " << sum(*r1, *r2) << "\n";
    cout << "Multiplication: " << mul(*r1, *r2) << "\n";
    compare(*r1, *r2);


    cut(*r1);
}