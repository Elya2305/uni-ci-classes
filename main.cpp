#include "Product.h"

using namespace std;

int main() {
    Toy t = Toy{"ball", 1.2};
    Food f = Food{"tomato's", 12};
    Technic tech = Technic{"phone", 113};

    Product::writeToBinFile(t);
    Product::writeToBinFile(f);
    Product::writeToBinFile(tech);
    Product::findByTitle("phone");
    Product::buyByTitle("tomato's");
    Product::findByTitle("tomato's");
}