#include<iostream>
#include <cstdio>

using namespace std;

void logError(string msg, string filename) {
    cout << msg << " " << filename;
}

int createFile(const char *filename, int *mas, int n) {
    FILE *fp;
    fp = fopen(filename, "wb");
    if (fp == NULL) {
        logError("Error while creating file", filename);
        return -1;
    }
    int res = fwrite(mas, n, sizeof(int), fp);
    fclose(fp);
    return res;
}

void readFile(const char *filename, int n) {
    FILE *fp;
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        logError("Error while reading file", filename);
        return;
    }
    int x = 0;
    int k = 0;
    while (!feof(fp)) {
        int r = fread(&x, sizeof(int), 1, fp);
        if (r == 0) {
            break;
        }
        k++;
        cout << "x[" << k << "] = " << x << "\n";
    }
    fclose(fp);
}


void createFileFromEvenArray(const char *filename, int n) {
    int arr[n];
    int total = 0;

    FILE *fp;
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        logError("Error while creating file", filename);
        return;
    }
    int x = 0;
    int k = 0;
    while (!feof(fp)) {
        int r = fread(&x, sizeof(int), 1, fp);
        if (r == 0) {
            break;
        }
        if (x % 2 == 0) {
            arr[k] = x;
            total++;
        } else {
            arr[k] = -1;
        }
        k++;
    }
    fclose(fp);


    int copyEven[total];
    int j = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] != -1) {
            copyEven[j++] = arr[i];
        }
    }
    createFile("G.txt", copyEven, total);
    readFile("G.txt", total);
}

int main() {
    int n;
    cout << "n=";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cout << "arr[" << i << "]=";
        cin >> arr[i];
    }
    createFile("F.txt", arr, n);
    createFileFromEvenArray("F.txt", n);
}
