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

int **deleteRow(int **array, int rowToDel, int row, int col) {
    delete[] array[rowToDel];
    int **tmp = new int *[row - 1];
    int tmpI = 0;
    for (int i = 0; i < col; ++i)
        if (i != rowToDel)
            tmp[tmpI++] = array[i];
    delete[] array;
    array = tmp;
    return array;
}


int main() {
    int row, col;

    cout << "n=";
    cin >> row;
    cout << "m=";
    cin >> col;

    int **array;

    array = alloc_memory(row, col);
    array = fillArr(array, row, col);

    cout << "Array before deleting: " << "\n";
    printArr(array, row, col);

    int toDel[row];

    for (int i = 0; i < row; ++i) {
        bool del = false;
        for (int j = 0; j < col; ++j) {
            if (array[i][j] == 0) {
                del = true;
            }
        }
        toDel[i] = del ? i : -1;
    }

    for (int i = 0; i < row; ++i) {
        if (toDel[i] != -1) {
            array = deleteRow(array, toDel[i], row, col);
        }
    }

    cout << "Array after deleting: " << "\n";
    printArr(array, row, col);
    free_memory(array, row);
}
