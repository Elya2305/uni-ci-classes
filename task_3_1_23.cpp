#include<iostream>
#include <cstring>
#include <map>

using namespace std;

void printCommonChars(const string &str) {
    int maxCount = 0;
    string maxElement;
    bool notEqualAmountMax = false;

    int minCount = str.length();
    string minElement;
    bool notEqualAmountMin = false;

    for (char ch : str) {
        int counter = 0;
        for (char j : str) {
            if (ch == j) counter++;
        }
        if (counter > maxCount) {
            maxCount = counter;
            maxElement = ch;
        }
        if (counter < minCount) {
            minCount = counter;
            minElement = ch;
        }
        if (counter != minCount) {
            notEqualAmountMin = true;
        }
        if (counter != maxCount) {
            notEqualAmountMax = true;
        }
    }
    if (!notEqualAmountMin) {
        minElement = "* absent *";
    }
    if (!notEqualAmountMax) {
        maxElement = "* absent *";
    }
    cout << "Most common character - " << maxElement << "\n";
    cout << "Less common character - " << minElement << "\n";
}

int main() {
    string str;
    cin >> str;

    printCommonChars(str);
}
