#include <queue>
#include <iostream>
#include <functional>
#include <vector>

using namespace std;

class Auto {
private:
    string title;
    string model;
    string number;
    string ownerId;
public:
    Auto() {}

    void input();

    void output();

    const string &getTitle() const;

    const string &getModel() const;

    const string &getNumber() const;

    string getOwnerId() const;

};

const string &Auto::getTitle() const {
    return title;
}

const string &Auto::getModel() const {
    return model;
}

const string &Auto::getNumber() const {
    return number;
}

string Auto::getOwnerId() const {
    return ownerId;
}

void Auto::input() {
    cout << "Title:";
    cin >> title;
    cout << "Model:";
    cin >> model;
    cout << "Number:";
    cin >> number;
    cout << "ownerId:";
    cin >> ownerId;
}

void Auto::output() {
    cout << "Auto{title=" << title << ", model=" << model << ", number=" << number << ", ownerId=" << ownerId;
}

void searchByModel(string model, vector<Auto> autos) {
    bool found = false;
    for (int i = 0; i < autos.size(); ++i) {
        Auto a = autos.at(i);
        if (a.getModel() == model) {
            found = true;
            a.output();
        }
    }
    if (!found) {
        cout << "No cars with model " << model << " found" << endl;
    }
}


int main() {
    vector<Auto> autos;

    Auto a1, a2, a3;
    a1.input();
    a2.input();
    a3.input();

    autos.push_back(a1);
    autos.push_back(a2);
    autos.push_back(a3);

    searchByModel("pezgo", autos);
}