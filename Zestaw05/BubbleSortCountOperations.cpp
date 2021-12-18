#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

template <class T> void sort(vector<T>& v) {
    int swapCount = 0;
    int compareCount = 0;

    bool swapped;
    for (int i = 0; i < v.size() - 1; i++) {
        swapped = false;
        for (int j = 0; j < v.size() - i - 1; j++) {
            compareCount++;
            if (v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);
                swapCount++;
                swapped = true;
            }
        }

        // IF no two elements were swapped by inner loop, then break
        if (swapped == false) break;
    }

    cout << compareCount << "  " << swapCount << endl;
}

int main(int argc, char const *argv[]) {
    int x;
    vector<int> v;

    while(cin >> x) {
        v.push_back(x);
    }

    sort<int>(v);

    return 0;
}