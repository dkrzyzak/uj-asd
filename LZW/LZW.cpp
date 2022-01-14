#include <iostream>
#include "Dict.hpp"
#include "LZW.hpp"

using namespace std;

int main(int argc, char const *argv[]) {
    char mode = 0;
    while (mode == 0) {
        cout << "Podaj tryb ('c' == kompresja, 'd' == dekompresja): ";
        cin >> mode;

        if (mode != 'c' && mode != 'd') {
            cout << "Niepoprawnie podany tryb." << endl;
        }
    }

    string filename;
    cout << "Podaj nazwę pliku: ";
    cin >> filename;

    if (mode == 'c') {
        LZWCompression::compressFromFile(filename);
    } 

    if (mode == 'd') {
        LZWCompression::decompressFromFile(filename);
    }

    

    return 0;
}
