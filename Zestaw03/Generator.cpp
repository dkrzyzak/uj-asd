#include <stdlib.h> // srand, rand, atoi
#include <iostream> // cin, cout, endl
#include <time.h> // time

using namespace std;

int generateNumber() {
    return rand() % 1000;
}

string generateOperation() {
    int n = rand() % 6;

    if (n == 5) {
        return "F " + to_string(generateNumber());
    }

    if (n == 4) {
        return "B " + to_string(generateNumber());
    }

    if (n == 3) {
        return "f";
    }

    if (n == 2) {
        return "b";
    }

    if (n == 1) {
        return "R " + to_string(generateNumber()) + " " + to_string(generateNumber());
    }

    return "S";
}

int main(int argc, char const *argv[]) {
    srand(time(NULL));

    // najpierw liczba operacji
    int operationsCount = generateNumber();
    cout << operationsCount << endl;
    
    // potem same operacje
    for (int i = 0; i < operationsCount; i++) {
        cout << generateOperation() << endl;
    }
    
    return 0;
}
