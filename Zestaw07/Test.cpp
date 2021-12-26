#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Dict.hpp"

using namespace std;

int main(int argc, char const *argv[]) {
    auto d = Dict<string, string>();

    pair<string, string> pr("sram", "czasami");
    
    cout << (d.insert(pr) ? "element istnieje" : "element nie istnieje") << endl;
    cout << (d.insert(pr) ? "element istnieje" : "element nie istnieje") << endl;
    cout << (d.find("sram") ? "znaleziono" : "nie znaleziono") << endl;
    cout << d.erase("sram") << endl;
    cout << d.find("sram") << endl;
    return 0;
}
