#include<iostream>

#define N 4
#define M 3
using namespace std;

void printArr(int arr[N][M]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

void sortInDesc(int num[M]) {
    int temp;
    for (int i = 0; i <= M; i++) {
        for (int j = i + 1; j <= M; j++) {
            if (num[i] < num[j]) {
                temp = num[j];
                num[j] = num[i];
                num[i] = temp;
            }
        }
    }
}


/**
 * function for new indexes of max values, e.g. {10, 8, 11} (that comes from original 2-d array) turns to {1, 2, 0},
 * because {10 (0), 8 (1), 11 (2)} -> {11 (0), 10 (1), 8 (2)} -> {10 (1), 8(2), 11(0)}
 *
 * these new indexes are used to sort an original 2-d array
 * */
void funNewIndexes(int max[M]) {
    int maxWithIndexes[M][2] = {{0, max[0]},
                                {1, max[1]},
                                {2, max[2]}};
    sortInDesc(max);
    int newIndexes[M];
    for (int i = 0; i < M; ++i) {
        int num = maxWithIndexes[i][1];
        for (int j = 0; j < M; ++j) {
            if (max[j] == num) {
                newIndexes[i] = j;
            }
        }
    }
    for (int i = 0; i < M; ++i) {
        max[i] = newIndexes[i];
    }
}

void func(int arr[N][M]) {
    int maxVal[M];

    for (int i = 0; i < M; ++i) {
        int max = arr[i][0];
        for (int j = 0; j < N; ++j) {
            if (arr[j][i] >= max) {
                max = arr[j][i];
            }
        }
        maxVal[i] = max;
    }
    funNewIndexes(maxVal); // {10, 8, 11}; -> {1, 2, 0} new indexes
    int newArr[N][M];

    for (int i = 0; i < M; ++i) {
        int indexToInsert = maxVal[i];
        for (int j = 0; j < N; ++j) {
            newArr[j][indexToInsert] = arr[j][i];
        }
    }

    printArr(newArr);
}


int main() {
    int arr[N][M] = {
            {3,  2, 1},
            {4,  2, -1},
            {7,  3, 5},
            {10, 8, 11}
    };
    func(arr);
}