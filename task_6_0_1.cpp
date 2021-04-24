#include <iostream>
#include <cctype>

using namespace std;

int func(string &str) {
    int total = 0;
    if (str.empty()) {
        return 0;
    }
    string start;
    start = str[0];

    for (int i = 0; i < str.size(); ++i) {
        if (isspace(str[i]) && not isspace(str[i - 1])) {
            if (start[0] == str[i - 1]) {
                total++;
            }
        }
        if (i == str.size() - 1) {
            if (start[0] == str[i]) {
                total++;
            }
        }
        if (not isspace(str[i]) && isspace(str[i - 1])) {
            start = str[i];
        }
    }
    return total;
}

int main() {
    string test1 = " mama   papap   dad";
    string test2 = "mama   papap   dad";
    string test3 = "mama   papap   dad   ";

    cout << "Test #1: " << func(test1) << "\n";
    cout << "Test #2: " << func(test2) << "\n";
    cout << "Test #3: " << func(test3) << "\n";
}