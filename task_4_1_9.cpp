#include <cstdio>
#include <iostream>

using namespace std;

struct T {
    unsigned key;
    char data[10];
};

void printStruct(T *t) {
    cout << "Found data by key: " << t->key << "\n";
}

void search(unsigned key) {
    struct T *object;

    FILE *file = fopen("output", "rb");

    if (file != NULL) {
        while (!feof(file)) {
            fread(&object, sizeof(struct T), 1, file);
            if (object->key == key) {
                printStruct(object);
                break;
            }
        }
        fclose(file);
    }
}

void readStruct(const char *filename) {
    struct T *object;

    FILE *file = fopen(filename, "rb");

    if (file != NULL) {
        while (!feof(file)) {
            fread(&object, sizeof(struct T), 1, file);
            printStruct(object);
        }
        fclose(file);
    }
}

void removeByKey(unsigned key) {
    FILE *fileResult = fopen("result", "wb");

    FILE *file = fopen("output", "rb");

    struct T *object;

    if (file == NULL && fileResult == NULL) {
        return;
    }

    while (!feof(file)) {
        cout << "Reading... " << object->key << "\n";
        fread(&object, sizeof(struct T), 1, file);
        if (object->key != key) {
            fwrite(&object, sizeof(struct T), 1, fileResult);
        }
    }
    fclose(file);
    fclose(fileResult);

    readStruct("result");
}


void initData() {
    char emptyData[10];

    int totalObjects;
    cout << "Input total objects\n";
    cin >> totalObjects;

    FILE *file = fopen("output", "wb");
    for (int i = 0; i < totalObjects; ++i) {
        cout << "Key for object " << i + 1 << "=";
        T *object = new T();
        cin >> object->key;
        *object->data = *emptyData;

        if (file != NULL) {
            fwrite(&object, sizeof(struct T), 1, file);
            fclose(file);
        }
    }
}


int main() {
    initData();

    search(11);
    removeByKey(10);
}
