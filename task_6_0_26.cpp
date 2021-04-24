#include <iostream>
#include <fstream>

using namespace std;

void deleteLine(const char *fileName, int n) {
    ifstream is(fileName);
    ofstream ofs;
    ofs.open("temp.txt", ofstream::out);

    char c;
    int lineNo = 1;
    while (is.get(c)) {
        if (c == '\n'){
            lineNo++;
        }

        if (lineNo % n != 0) {
            ofs << c;
        }
    }

    ofs.close();
    is.close();

    remove(fileName);

    rename("temp.txt", fileName);
}

int main() {
    int n;
    cout << "N=";
    cin >> n;
    deleteLine("a.txt", n);
    return 0;
}