#include<iostream>
#include <cstring>

using namespace std;

bool validate(string str) {
    string buff;
    string res;
    for (char i : str) {
        if (i == '(' || i == ')') {
            buff += i;
        }
        if (buff.length() == 2) {
            if (!(buff[0] == '(' && buff[1] == ')')) {
                return false;
            } else {
                buff = "";
            }
        }
        if ((buff.length() == 1 && buff[0] == '(') || i == ')') {
            continue;
        }
        res += i;
    }
    if (buff.length() != 0) return false;

    cout << "Result " << res << "\n";
    return true;
}

int main() {
    string a;
    cin >> a;

    cout << validate(a);

}

