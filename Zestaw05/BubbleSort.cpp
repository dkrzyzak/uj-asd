#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

template <class T> void sort(vector<T>& v) {
    bool swapped;
    int vSize = v.size();
    for (int i = 0; i < vSize - 1; i++) {
        swapped = false;
        for (int j = 0; j < vSize - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);
                swapped = true;
            }
        }

        if (swapped == false) break;
    }
}

int main(int argc, char const *argv[]) {
    int x;
    vector<int> v;

    while(cin >> x) {
        v.push_back(x);
    }

    // benchmark mode
    if (argc > 1) {
        auto start = chrono::system_clock::now();

        sort(v);

        auto end = chrono::system_clock::now();
        auto elapsed = (end - start).count() * 0.001;
        cout << v.size() << " " << elapsed << endl;

        return 0;
    }

    sort(v);
    
    for (const auto& i : v) {
        cout << i << endl;
    }

    return 0;
}