#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;

/**
 * distance between coordinates
 * */
double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) * 1.0);
}

/**
 * @return total coordinates
 * */
int countTotalCoordinates(ifstream &f) {
    int totalCoordinates = 0;
    string coordinates;
    while (!f.eof()) {
        f >> coordinates;
        totalCoordinates++;
    }
    return totalCoordinates;
}

/**
 * @return array of coordinates
 * e.g [[1,2],[2,3],[3,4]]
 * */
double **getCoordinates(ifstream &f, int totalCoordinates) {
    double **numCoordinates = new double *[totalCoordinates];
    for (int i = 0; i < totalCoordinates; ++i) {
        numCoordinates[i] = new double[3];
    }

    int index = 0;
    f.clear();
    f.seekg(0, ios::beg);

    string coordinates;
    while (!f.eof() && index < totalCoordinates) {
        f >> coordinates;
        string str1(1, coordinates[1]);
        string str2(1, coordinates[3]);

        numCoordinates[index][0] = stod(str1);
        numCoordinates[index][1] = stod(str2);
        index++;
    }
    return numCoordinates;
}

/**
 * @return array of length of lines by coordinates sorted by asc
 *
 * e.g. [[1.41421, 0, 1], [1.41421, 1, 2], [2.82843, 0, 2]], where 0,1,2 - indexes of coordinates
 *
 * */
double **getLengthOfCoordinates(int totalCoordinates, int totalPairs, double **numCoordinates) {
    double **lengthIndexes = new double *[totalPairs];
    for (int i = 0; i < totalCoordinates; ++i) {
        lengthIndexes[i] = new double[3];
    }

    int index = 0;

    for (int i = 0; i < totalCoordinates; ++i) {
        for (int j = i + 1; j < totalCoordinates; ++j) {
            lengthIndexes[index][0] = distance(numCoordinates[i][0], numCoordinates[i][1], numCoordinates[j][0],
                                               numCoordinates[j][1]);
            lengthIndexes[index][1] = i;
            lengthIndexes[index][2] = j;
            index++;
        }
    }


    for (int i = 0; i < totalCoordinates; ++i) {
        for (int j = i + 1; j < totalCoordinates; ++j) {
            if (lengthIndexes[i][0] > lengthIndexes[j][0]) {
                swap(lengthIndexes[i], lengthIndexes[j]);
            }
        }
    }

    return lengthIndexes;
}


int main() {
    ifstream f;
    f.open("task_5_30.txt", ios::in);
    if (f.bad()) {
        cout << "Can't read file";
        return -1;
    }

    int totalCoordinates = countTotalCoordinates(f);

    double **numCoordinates = getCoordinates(f, totalCoordinates);

    int totalPairs = ((1 + totalCoordinates - 1) * (totalCoordinates - 1)) / 2;

    double **lengthIndexes = getLengthOfCoordinates(totalCoordinates, totalPairs, numCoordinates);

    ofstream fResult;
    fResult.open("result.txt", ios_base::out);
    if (fResult.bad()) {
        std::cout << "Can't create file";
    }

    for (int i = 0; i < totalPairs; ++i) {
        int point1 = lengthIndexes[i][1];
        int point2 = lengthIndexes[i][2];
        fResult << "(" << numCoordinates[point1][0] << ", " << numCoordinates[point1][1] << ") "
                << "(" << numCoordinates[point2][0] << ", " << numCoordinates[point2][1] << ")"
                << " Length = " << lengthIndexes[i][0] << "\n";
    }

    f.close();
    fResult.close();
}