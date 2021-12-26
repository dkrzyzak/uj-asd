#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Dict.hpp"

using namespace std;

int main(int argc, char const *argv[]) {
    auto d = Dict<string, string>();
    string fileName = argv[1];

    ifstream fileStream(fileName);

    string line;
    while (getline(fileStream, line)) {
        stringstream ss;
        ss << line;
        string key, value;
        ss >> key >> value;

        pair<string, string> p(key, value);
        d.insert(p);
    }

    string key;
    while (cin >> key) {
        if (d.find(key)) {
            cout << d[key] << endl;
        } else {
            cout << "-" << endl;
        }
    }

    return 0;
}
