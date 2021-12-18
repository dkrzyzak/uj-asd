#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
    int x;
    vector<int> v;

    while(cin >> x) {
        v.push_back(x);
    }

    for (int i = v.size() - 1; i >= 0; i--) {
        cout << v[i] << endl;
    }

    return 0;
}
