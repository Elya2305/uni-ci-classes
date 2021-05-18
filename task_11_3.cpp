
#include "iostream"
#include "algorithm"

using namespace std;


class IndexOutOfBoundsException : public exception {
public:
    const char *what() const throw() {
        return "Index is out of bounds";
    }
};

int randomInt(int min, int max) {
    return rand() % max + min;
}

template<class T>
class BlackBox {
private:
    T *arr;
    int length;
    int nextIndex;
public:
    BlackBox();

    BlackBox(T *arr, int length);

    ~BlackBox();

    void push(T val);

    void print();

    T pop();

    int size();

    T xPop();
};


template<class T>
BlackBox<T>::BlackBox() {
    arr = new T[100];
    for (int i = 0; i < 100; i++){
        arr[i] = 0;
    }
    length = 100;
    nextIndex = 0;
}

template<class T>
BlackBox<T>::BlackBox(T *arr, int length) {
    this->arr = arr;
    this->length = length;
    this->nextIndex = 0;
}

template<class T>
BlackBox<T>::~BlackBox() {
    delete[] arr;
}

template<class T>
void BlackBox<T>::push(T val) {
    T *newArr;
    if (nextIndex == length) {
        length = length + 10;
        newArr = new T[length];
        for (int i = 0; i < nextIndex; i++){
            newArr[i] = arr[i];
        }
        for (int j = nextIndex; j < length; j++) {
            newArr[j] = 0;
        }
        delete[] arr;
        arr = newArr;
    }
    arr[nextIndex++] = val;
}

template<class T>
int BlackBox<T>::size() {
    return length;
}

template<class T>
T BlackBox<T>::pop() {
    if (nextIndex == 0) {
        throw IndexOutOfBoundsException();
    }
    T *newArr = new T[length];
    T toDelete;
    int indexToRemove = randomInt(0, nextIndex - 1);

    int newIndex = 0;
    for (int i = 0; i < nextIndex; ++i) {
        if (i == indexToRemove) {
            toDelete = arr[i];
            continue;
        } else {
            newArr[newIndex++] = arr[i];
        }
    }
    for (int j = newIndex; j < length; j++) {
        newArr[j] = 0;
    }
    delete arr;
    this->nextIndex--;

    return toDelete;
}

template<class T>
T BlackBox<T>::xPop() {
    return arr[randomInt(0, nextIndex - 1)];
}

template<class T>
void BlackBox<T>::print() {
    for (int i = 0; i < nextIndex; ++i) {
        cout << "arr[" << i << "]=" << arr[i] << endl;
    }
}


int main() {
    BlackBox<int> b{};

    b.push(12);
    b.push(10);
    b.push(13);

    b.pop();
    b.xPop();
    b.print();
}