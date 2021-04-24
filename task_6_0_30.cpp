#include <iostream>
#include <fstream>

using namespace std;

int getTotalLines(const char *fileName) {
    int numLines = 0;
    ifstream in(fileName);
    string unused;
    while (getline(in, unused))
        ++numLines;
    return numLines;
}

void mergeFilesInternal(const char *fileName1, const char *fileName2) {
    ofstream ofs;
    ofs.open("temp.txt", ofstream::out);

    ifstream is1(fileName1);
    ifstream is2(fileName2);

    string line1;
    string line2;
    while (getline(is1, line1)) {
        ofs << line1;
        if (getline(is2, line2)) {
            ofs << line2;
        }
        ofs << "\n";
    }
    ofs.close();
    is1.close();
    is2.close();

    remove(fileName1);
    rename("temp.txt", fileName1);
}

void mergeFiles(const char *fileName1, const char *fileName2) {
    int totalLines1 = getTotalLines(fileName1);
    int totalLines2 = getTotalLines(fileName2);

    if (totalLines1 > totalLines2) {
        mergeFilesInternal(fileName1, fileName2);
    } else {
        mergeFilesInternal(fileName2, fileName1);
    }
}

int main() {
    mergeFiles("1.txt", "2.txt");
}