#include <iostream>
#include "Dict.hpp"
#include "LZW.hpp"

using namespace std;

int main(int argc, char const *argv[]) {
    LZWCompression::compress("thisisthe");

    return 0;
}
