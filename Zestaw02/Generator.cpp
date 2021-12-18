#include <stdlib.h> // srand, rand, atoi
#include <iostream> // cin, cout, endl
#include <time.h> // time

using namespace std;

int generateNumber() {
    return rand() % 1000000;
}

string generateOperation() {
    int n = rand() % 3;

    if (n == 2) {
        return "A " + to_string(generateNumber());
    }

    if (n == 1) {
        return "D";
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
