#include <iostream>
#include <string>
#include "FileOperations.hpp"

using namespace std;

int runWithoutArgs();
int runWithArgs(char const *argv[]);

string instructions = R"(Program do kompresji LZW.

Nie podając żadnych argumentów, zostaniesz preprowadzony przez proces krok po kroku.

Możesz też od razu podać argumenty - będą wymagane 4, w następującej kolejności:
- nazwa pliku źródłowego
- tryb algorytmu (c jak kompresja / d jak dekompresja)
- nazwa pliku wyjściowego
- rozmiar bufora w bajtach (ilość bajtów wykorzystywanych do zapisu jednej liczby)

np. ./LZW.x test.txt c compressed.lzw 2
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

    int bufferSizeInBytes;
    cout << "Rozmiar bufora w bajtach (domyślnie 4): ";
    cin >> bufferSizeInBytes;

    if (mode == 'c') {
        File::compressFromFile(sourceFilename, destinationFilename, bufferSizeInBytes);
    } 

    if (mode == 'd') {
        File::decompressFromFile(sourceFilename, destinationFilename, bufferSizeInBytes);
    }
    
    return 0;
}

int runWithArgs(char const *argv[]) {
    string sourceFilename = argv[1];
    char mode = argv[2][0];
    string destinationFilename = argv[3];
    int bufferSizeInBytes = atoi(argv[4]);

    if (mode == 'c') {
        File::compressFromFile(sourceFilename, destinationFilename, bufferSizeInBytes);
    }

    if (mode == 'd') {
        File::decompressFromFile(sourceFilename, destinationFilename, bufferSizeInBytes);
    }

    return 0;
}
