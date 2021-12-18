#include <iostream>
#include <vector>

using namespace std;

template <class T>
void sort(vector<T>& v) {
    int vSize = v.size();
    for (int j = 0; j < vSize - 1; ++j) {
        int min = j;
        for (int i = j + 1; i < vSize; ++i) {
            if (v[min] > v[i]) {
                min = i;
            }
        }
        if (min != j) swap(v[j], v[min]);
    }
}

int main(int argc, char const* argv[]) {
    int x;
    vector<int> v;

    while (cin >> x) {
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