#ifndef LZWFILES
#define LZWFILES

#include <iostream>
#include <fstream>
#include "LZW.hpp"
#include "LinkedList.hpp"

using namespace std;

class File {
    private:
    static void saveToFile(string decompressed, string destinationFileName) {
        ofstream outputStream(destinationFileName);
        outputStream << decompressed;

        outputStream.close();
    }

    static void saveToFile(List& compressedList, string destinationFileName) {
        ofstream outputStream(destinationFileName);
        outputStream << compressedList.print();

        outputStream.close();
    }

    static void saveToFile(List& compressedList, string destinationFileName, int bufferSizeInBytes) {
        ofstream outputStream(destinationFileName, ios::out | ios::binary);
        
        int value;
        int listSize = compressedList.size();

        for (int i = 0; i < listSize; i++) {
            value = compressedList.pop_front();
            outputStream.write(reinterpret_cast<const char* >(&value), bufferSizeInBytes);
        }

        outputStream.close();
    }

    public:

    static void compressFromFile(string sourceFileName, string destinationFileName, int bufferSizeInBytes) {
        ifstream nameFileout(sourceFileName, ifstream::in);
        stringstream buffer;

        buffer << nameFileout.rdbuf();
        string fileContent = buffer.str();

        List compressedList = LZWCompression::compress(fileContent);
        saveToFile(compressedList, destinationFileName, bufferSizeInBytes);

        // odkomentuj żeby zapisać jako tekst
        // saveToFile(compressedList, destinationFileName);
    }

    static void decompressFromFile(string sourceFileName, string destinationFileName, int bufferSizeInBytes) {
        ifstream nameFileout(sourceFileName, ios::in | ios::binary);

        List compressed = List();

        int output;
        while(true) {
            nameFileout.read(reinterpret_cast< char* >(&output), bufferSizeInBytes);

            if (nameFileout.eof()) {
                break;
            }

            compressed.push_back(output);
        }

        string decompressedOutput = LZWCompression::decompress(compressed);
        saveToFile(decompressedOutput, destinationFileName);
    }

    static void decompressFromFile(string sourceFileName, string destinationFileName) {
        ifstream nameFileout(sourceFileName, ifstream::in);

        List compressed = List();
        string line;
        while (getline(nameFileout, line)) {
            compressed.push_back(stoi(line));
        }

        string decompressedOutput = LZWCompression::decompress(compressed);
        saveToFile(decompressedOutput, destinationFileName);
    }
};

#endif
