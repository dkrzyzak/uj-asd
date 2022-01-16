#include <iostream>
#include <string>
#include "Dict.hpp"
#include "LZW.hpp"

using namespace std;

int runWithoutArgs();
int runWithArgs(char const *argv[]);

string instructions = R"(Program do kompresji LZW.

Nie podając żadnych argumentów, zostaniesz preprowadzonx przez proces krok po kroku.

Możesz też od razu podać argumenty - będą wymagane 3, w następującej kolejności:
- nazwa pliku źródłowego
- tryb kompresji (c jak kompresja / d jak dekompresja)
- nazwa pliku wyjściowego

np. ./LZW.x test.txt c compressed.lzw
)";

int main(int argc, char const *argv[]) {
    switch (argc) {
        case 1:
            runWithoutArgs();
            break;

        case 4:
            runWithArgs(argv);
            break;

        default:
            cout << instructions << endl;
            break;
    }

    return 0;
}

int runWithoutArgs() {
    char mode = 0;
    while (mode == 0) {
        cout << "Podaj tryb ('c' == kompresja, 'd' == dekompresja): ";
        cin >> mode;

        if (mode != 'c' && mode != 'd') {
            cout << "Niepoprawnie podany tryb." << endl;
        }
    }

    string sourceFilename;
    cout << "Podaj nazwę pliku do kompresji: ";
    cin >> sourceFilename;

    string destinationFilename;
    cout << "Podaj nazwę pliku wyjściowego (skompresowanego): ";
    cin >> destinationFilename;

    if (mode == 'c') {
        LZWCompression::compressFromFile(sourceFilename, destinationFilename);
    } 

    if (mode == 'd') {
        LZWCompression::decompressFromFile(sourceFilename, destinationFilename);
    }
    
    return 0;
}

int runWithArgs(char const *argv[]) {
    string sourceFilename = argv[1];
    char mode = argv[2][0];
    string destinationFilename = argv[3];

    if (mode == 'c') {
        LZWCompression::compressFromFile(sourceFilename, destinationFilename);
    } 

    if (mode == 'd') {
        LZWCompression::decompressFromFile(sourceFilename, destinationFilename);
    }

    return 0;
}
