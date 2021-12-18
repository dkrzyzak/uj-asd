#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <string.h>
#include "LinkedQueue.hpp"

#define MAX_STACK_SIZE 1000000

using namespace std;

int main(int argc, char** argv) {
    Queue arrQueue = Queue();

    string operation;
    while (getline(cin, operation)) {
        if (atoi(operation.c_str()) != 0) {
            continue;
        }

        switch (operation[0]) {
            case 'A': {
                int number;
                char tmp;
                sscanf(operation.c_str(), "%s %d", &tmp, &number);

                arrQueue.push(number);
            } break;
            case 'D': {
                try {
                    int popped = arrQueue.pop();
                    cout << popped << endl;
                } catch (const out_of_range& e) {
                    cout << e.what() << endl;
                }
            } break;
            case 'S': {
                int stackSize = arrQueue.size();
                cout << stackSize << endl;
            } break;
            default:
                cout << "Niepoprawna operacja " << operation[0] << endl;
                break;
        }
    }

    return 0;
}