#include<iostream>
#include <cstring>

using namespace std;

void func(char *str) {
    std::string output;
    for (int i = 0; i < strlen(str); ++i) {
        if (str[i] == '+' && i + 1 < strlen(str) && isdigit(str[i + 1])) {
            continue;
        }
        output += str[i];
    }
    cout << output;
}


int main() {
    char arr[255];

    cin >> arr;

    func(arr);
}