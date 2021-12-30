#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Dict.hpp"

using namespace std;

int main(int argc, char const *argv[]) {
    auto d = Dict<string, string>();

    pair<string, string> pr1("sram", "czasami");
    pair<string, string> pr2("gunwo", "ahh");
    pair<string, string> pr3("gunwooo", "ahh");
    
    d.insert(pr2);
    d.insert(pr3);
    
    cout << (d.insert(pr1) ? "element istnieje" : "element nie istnieje") << endl;
    cout << (d.insert(pr1) ? "element istnieje" : "element nie istnieje") << endl;
    cout << (d.find("sram") ? "znaleziono" : "nie znaleziono") << endl;
    cout << d.erase("sram") << endl;
    cout << d.find("sram") << endl;
    return 0;
}
