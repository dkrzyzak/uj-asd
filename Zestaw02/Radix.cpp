#include <vector>
#include <iostream>
#include "ArrayQueue.hpp"

using namespace std;

void radix(vector<int> &v) {
    Queue bins[10]; // jeden kosz (kolejka) na każdą cyfrę
    int divisor = 1;
    for (int currentDigit = 0; currentDigit < 10; currentDigit++) {
        for (const auto& number : v) { // wsadzanie odpowiednich elementow do odpowiednich koszy
            int digitValue = ((number/divisor) % 10);
            bins[digitValue].push(number);
        }

        int vectorIndex = 0;
        for (int b = 0; b < 10; b++) {
            while(!bins[b].empty()) {
                v[vectorIndex] = bins[b].pop();
                vectorIndex++;
            }
        }

        divisor *= 10;
    }
}

int main(int argc, char const *argv[]) {
    int x;
    vector<int> v;

    while(cin >> x) {
        v.push_back(x);
    }

    radix(v);

    for (const auto& i : v) {
        cout << i << endl;
    }

    return 0;
}

