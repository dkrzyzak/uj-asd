#include <iostream>
#include <vector>

using namespace std;

template <class T>
void sort(vector<T>& v) {
    int j, tmp;
    for (int i = 1; i < v.size(); i++) {
        j = i;
        tmp = v[i];
        while (j > 0 && tmp < v[j - 1]) {
            v[j] = v[j - 1];
            j--;
        }
        v[j] = tmp;
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