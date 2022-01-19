#include <iostream>
#include <string>
#include "Dict.hpp"
#include "LZW.hpp"

using namespace std;

int runWithoutArgs();
int runWithArgs(char const *argv[]);

string instructions = R"(Program do kompresji LZW.

Nie podając żadnych argumentów, zostaniesz preprowadzony przez proces krok po kroku.

Możesz też od razu podać argumenty - będą wymagane 3, w następującej kolejności:
- nazwa pliku źródłowego
- tryb kompresji (c jak kompresja / d jak dekompresja)
- nazwa pliku wyjściowego
- rozmiar bufora w bitach (ilość bitów wykorzystywanych do zapisu jednej liczby)

np. ./LZW.x test.txt c compressed.lzw 32
)";

int main(int argc, char const *argv[]) {
    switch (argc) {
        case 1:
            runWithoutArgs();
            break;

        case 5:
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
    cout << "Podaj nazwę pliku źródłowego: ";
    cin >> sourceFilename;

    string destinationFilename;
    cout << "Podaj nazwę pliku wyjściowego (skompresowanego): ";
    cin >> destinationFilename;

    int bufferSizeInBits;
    cout << "Rozmiar bufora w bitach (domyślnie 32): ";
    cin >> bufferSizeInBits;

    int bufferSizeInBytes = bufferSizeInBits / 8;

    if (mode == 'c') {
        LZWCompression::compressFromFile(sourceFilename, destinationFilename, bufferSizeInBytes);
    } 

    if (mode == 'd') {
        LZWCompression::decompressFromFile(sourceFilename, destinationFilename, bufferSizeInBytes);
    }
    
    return 0;
}

int runWithArgs(char const *argv[]) {
    string sourceFilename = argv[1];
    char mode = argv[2][0];
    string destinationFilename = argv[3];
    int bufferSizeInBytes = atoi(argv[4]) / 8;

    if (mode == 'c') {
        LZWCompression::compressFromFile(sourceFilename, destinationFilename, bufferSizeInBytes);
    } 

    if (mode == 'd') {
        LZWCompression::decompressFromFile(sourceFilename, destinationFilename, bufferSizeInBytes);
    }

    return 0;
}
