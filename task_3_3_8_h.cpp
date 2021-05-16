#include<iostream>


using namespace std;

int **fillArr(int **arr, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            arr[i][j] = rand() % 100; // in the range 0 to 99
        }
    }
    return arr;
}

int **fillRowArr(int **arr, int row, int col) {
    for (int i = 0; i < col; ++i) {
        arr[row][i] = rand() % 100;
    }
    return arr;
}

void printArr(int **arr, int N, int M) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

int **alloc_memory(int n, int m) {
    int **arr = (int **) malloc(n * sizeof(int *));
    for (int i = 0; i < n; ++i) {
        arr[i] = (int *) calloc(m, sizeof(int));
    }
    return arr;
}

void free_memory(int **arr, int n) {
    for (int i = 0; i < n; ++i) {
        free(arr[i]);
    }
    free(arr);
}

int rowWithMinNorm(int **arr, int n, int m) {
    int minNorm = -1;
    int row = 0;
    for (int i = 0; i < n; ++i) {
        int temp = 0;
        for (int j = 0; j < m; ++j) {
            temp += arr[i][j] * arr[i][j];
        }
        if (temp <= minNorm || minNorm == -1) {
            minNorm = temp;
            row = i;
        }
    }
    return row;
}


int main() {
    int row, col;

    row = 2;
    col = 3;

    int **array;


    array = alloc_memory(row, col);
    array = fillArr(array, row, col);

    cout << "Array before inserting: " << "\n";
    printArr(array, row, col);

    int minRow = rowWithMinNorm(array, row, col);
    cout << "row to insert: " << minRow + 1 << endl;

    int **newArray = alloc_memory(row + 1, col);

    int rowNew = 0;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            newArray[rowNew][j] = array[i][j];
        }
        if (rowNew == minRow) {
            fillRowArr(newArray, minRow + 1, col);
        }
        rowNew++;
    }


    cout << "Array after inserting: " << "\n";
    printArr(newArray, row + 1, col);
    free_memory(array, row);
    free_memory(newArray, row);
}
