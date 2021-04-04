#include<iostream>

using namespace std;

struct Journal {
    double price;
    int total;
};

Journal addJournal(double price, int total) {
    Journal *journal = new Journal();
    journal->total = total;
    journal->price = price;
    return *journal;
}

void printAvg(Journal journals[], int N) {
    int total = 0;
    double sum = 0;
    for (int i = 0; i < N; ++i) {
        if (journals[i].total < 10000) {
            total += 1;
            sum += journals[i].price;
        }
    }
    if (total != 0) {
        cout << "Avg = " << sum / total;
    } else {
        cout << "No journals";
    }
}

int main() {
    Journal journals[] = {
            addJournal(10, 100),
            addJournal(87, 10000),
            addJournal(1000, 19),
    };
    printAvg(journals, 3);
}