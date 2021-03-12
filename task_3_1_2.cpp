#include<iostream>

using namespace std;

int main() {
    string str;
    cin >> str;

    int totalComma = 0;
    int firstComma = -1;
    int lastComma = -1;
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == ',') {
            totalComma++;
            if (firstComma == -1) {
                firstComma = i;
            }
            lastComma = i;
        }
    }

    cout << "Total commas = " << totalComma << "\n";
    if (firstComma != -1) {
        cout << "First comma's index = " << firstComma << "\n";
        cout << "Last comma's index = " << lastComma << "\n";
    }
};