#include<iostream>
#include<vector>

using namespace std;

void print(std::vector<int> const &a) {
    std::cout << "The gray code numbers are : ";

    for (int i : a)
        std::cout << i << ' ';
}

vector<int> grayCode(int n) {
    vector<int> res(1, 0);
    while (n--) {
        for (int i = res.size() - 1; i >= 0; i--) {
            res[i] *= 2;
            res.push_back(res[i] + 1);
        }
    }
    return res;
}

int main() {
    int N;
    cout << "N=";
    cin >> N;

    print(grayCode(N));
}


