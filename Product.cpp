#include "Product.h"
#include<iostream>
#include <fstream>

void Product::print() {
    cout << this->title << " " << this->price << endl;

}

const string &Product::getTitle() const {
    return title;
}

void Product::printAll() {
    fstream file;
    file.open("products.dat", ios::in | ios::binary);
    if (!file) {
        cout << "Error in opening file...\n";
    }
    Product product;

    while (file.read((char *) &product, sizeof(product))) {
        product.print();
    }
    file.close();
}

bool Product::findByTitle(string title) {
    fstream file;
    file.open("products.dat", ios::in | ios::binary);
    if (!file) {
        cout << "Error in opening file...\n";
    }

    Product product;

    bool found = false;
    while (file.read((char *) &product, sizeof(product))) {
        if (product.getTitle() == title) {
            cout << "Found!" << endl;
            product.print();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "No product with title " << title << endl;
        return false;
    }

    file.close();
    return true;
}

void Product::buyByTitle(string title) {
    if (!findByTitle(title)) {
        cout << title << " is not present" << endl;
        return;
    }
    fstream file;
    file.open("products.dat", ios::in | ios::binary);

    fstream tempFile;
    file.open("temp.dat", ios::out | ios::binary | ios_base::app);

    if (!file || !tempFile) {
        cout << "Error in opening file...\n";
    }
    Product product;

    while (file.read((char *) &product, sizeof(product))) {
        if (product.getTitle() != title) {
            tempFile.write((char *) &product, sizeof(product));
        }
    }
    remove("products.dat");
    rename("temp.dat", "products.dat");

    cout << title << " was successfully bought and removed!" << endl;
    file.close();
    tempFile.close();
}

void Product::writeToBinFile(Product &p) {
    fstream file;
    file.open("products.dat", ios::out | ios::binary | ios_base::app);
    if (!file) {
        cout << "Error in creating file...\n";
    }

    file.write((char *) &p, sizeof(p));
    file.close();
}

void Product::changePrice() {
    this->price = this->price * 0.2 + this->price;
}
