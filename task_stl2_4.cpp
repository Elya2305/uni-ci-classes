#include <iostream>
#include <map>


using namespace std;

/**
 * values of map are given as an example and may not match the original size
 * */
map<int, int> initMap() {

    map<int, int> numLen = {
            {1,4},{2,3},{3, 3},{4,6},{5,4},{6,5},{7,3},{8,5},{9,6},
            {11,10},{12,10}, {13,10}, {14,10}, {15,10}, {16,10}, {17,10}, {18,10}, {19,10},
            {10,6},{20,8},{30,8},{40,5},{50,7},{60,7},{70,7},{80,7},{90,7},
            {100,3},{200,6},{300,6},{400,6},{500,6},{600,6},{700,6},{800,6},{900,6},
            {1000,6}, {2000,6}, {3000,6},{4000,6},{5000,6},{7000,6},{8000,6},{9000,6},
            {10000,10}
    };
    return numLen;
}



int countLen(int num) {
    int original = num;
    map<int, int> numLen = initMap();
    int dec = 1;
    int totalLn = 0;
    while (num > 0) {
        int a = num % 10 * dec;
        num = num / 10;
        dec *= 10;
        if (a == 10) { // cases for 11-19, e.g. num = 113
            totalLn = numLen.at(a + original % 10);
        } else {
            totalLn += numLen.at(a);
        }
    }
    return totalLn;
}

int main() {
    cout << countLen(113) << endl;
    cout << countLen(253) << endl;
    cout << countLen(2213) << endl;
}