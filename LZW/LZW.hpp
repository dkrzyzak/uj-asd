#ifndef LZWCOMPRESSION
#define LZWCOMPRESSION

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Dict.hpp"
#include "LinkedList.hpp"

using namespace std;

class LZWCompression {
    using CompressDict = Dict<string, int>;
    using CompressPair = pair<string, int>;

    using DecompressDict = Dict<int, string>;
    using DecompressPair = pair<int, string>;

    private:

    static void fillDictWithAsciiChars(CompressDict* dict) {
        for (int i = 0; i <= 255; i++) {
            string ch = string(1, char(i));
            dict->insert(CompressPair(ch, i));
        }
    }

    static void fillDictWithAsciiChars(DecompressDict* dict) {
        for (int i = 0; i <= 255; i++) {
            string ch = string(1, char(i));
            dict->insert(DecompressPair(i, ch));
        }
    }

    static void saveToFile(string decompressed) {
        ofstream outputStream("decompressed.lzw");
        outputStream << decompressed;

        outputStream.close();
    }

    static void saveToFile(List& compressedList) {
        ofstream outputStream("compressed.lzw");
        outputStream << compressedList.print();

        outputStream.close();
    }

    public:

    static void compressFromFile(string fileName) {
        ifstream nameFileout(fileName, ifstream::in);
        stringstream buffer;

        buffer << nameFileout.rdbuf();
        string fileContent = buffer.str();

        compress(fileContent);
    }

    static void decompressFromFile(string fileName) {
        ifstream nameFileout(fileName, ifstream::in);

        List compressed = List();
        string line;
        while (getline(nameFileout, line)) {
            compressed.push_back(stoi(line));
        }

        decompress(compressed);
    }

    static void compress(string input) {
        auto dict = CompressDict();
        fillDictWithAsciiChars(&dict);

        string current = string(1, input[0]);
        string next = "";
        unsigned int code = 256;
        List output = List();

        int inputLength = input.length();
        for (int i = 0; i < inputLength; i++) {
            if (i != inputLength - 1) {
                next += input[i + 1];
            }

            // para jest już w słowniku
            if (dict.find(current + next)) {
                current += next;
            } else {
                output.push_back(dict[current]);
                dict.insert(CompressPair(current + next, code++));
                current = next;
            }

            next = "";
        }

        output.push_back(dict[current]);

        output.print();

        saveToFile(output);
    };

    static void decompress(List compressed) {
        auto dict = DecompressDict();
        fillDictWithAsciiChars(&dict);

        int old = compressed[0];
        int n;
        string s = dict[old];
        string c = string(1, s[0]);
        string output = s;

        int count = 256;
        int compressedListSize = compressed.size();
        for (int i = 0; i < compressedListSize - 1; i++) {
            n = compressed[i + 1];

            if (!dict.find(n)) {
                s = dict[old];
                s = s + c;
            } else {
                s = dict[n];
            }

            output += s;
            c = string(1, s[0]);
            dict.insert(DecompressPair(count, dict[old] + c));
            count++;
            old = n;
        }

        cout << "Decompressed: " << output << endl;
        saveToFile(output);
    };
};

#endif
