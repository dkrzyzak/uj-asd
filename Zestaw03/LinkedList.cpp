#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <string.h>
#include "LinkedList.hpp"

using namespace std;

int main(int argc, char** argv) {
    List linkedList = List();

    string operation;
    while (getline(cin, operation)) {
        if (atoi(operation.c_str()) != 0) {
            continue;
        }

        switch (operation[0]) {
            case 'F': {
                int number;
                char tmp;
                sscanf(operation.c_str(), "%s %d", &tmp, &number);

                linkedList.push_front(number);
            } break;

            case 'B': {
                int number;
                char tmp;
                sscanf(operation.c_str(), "%s %d", &tmp, &number);

                linkedList.push_back(number);
            } break;

            case 'f': {
                try {
                    int popped = linkedList.pop_front();
                    cout << popped << endl;
                } catch (const out_of_range& e) {
                    cout << e.what() << endl;
                }
            } break;

            case 'b': {
                try {
                    int popped = linkedList.pop_back();
                    cout << popped << endl;
                } catch (const out_of_range& e) {
                    cout << e.what() << endl;
                }
            } break;

            case 'R': {
                int x, y;
                char tmp;
                sscanf(operation.c_str(), "%s %d %d", &tmp, &x, &y);

                int xIndex = linkedList.find(x);
                if (xIndex == -1) {
                    cout << "FALSE" << endl;
                } else {
                    linkedList.erase(xIndex);
                    linkedList.insert(xIndex, y);
                    cout << "TRUE" << endl;
                }
            } break;

            case 'S': {
                int stackSize = linkedList.size();
                cout << stackSize << endl;
            } break;
        
            default:
                cout << "Niepoprawna operacja " << operation[0] << endl;
                break;
        }
    }

    return 0;
}