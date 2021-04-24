#include<iostream>
#include<algorithm>

using namespace std;

string removeChar(string &str, char ch) {
    str.erase(remove(str.begin(), str.end(), ch), str.end());
    return str;
}

int main() {
    string str;
    string ch;
    cout << "Input a string\n";
    cin >> str;

    cout << "Input a char you want to delete\n";
    cin >> ch;

    cout << "Result: " <<  removeChar(str, ch[0]);
}
