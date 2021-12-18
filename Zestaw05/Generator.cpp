#include <stdlib.h> // srand, rand, atoi
#include <iostream> // cin, cout, endl
#include <time.h> // time

using namespace std;

int main(int argc, char const *argv[]) {
    srand(time(NULL));

    int n = atoi(argv[1]);
    int max = atoi(argv[2]);
    
    for (int i = 0; i < n; i++) {
        cout << (rand() % max) + 1 << endl;
    }
    
    return 0;
}
