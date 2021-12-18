#include <stdlib.h>
#include <iostream>
#include "ArrayStack.hpp"

using namespace std;

ArrayStack::ArrayStack(int capacity) {
    array = (int*)calloc(sizeof(int), capacity);
    stackCapacity = capacity;
    top = 0;
}

ArrayStack::~ArrayStack() {
    free(array);
    array = NULL;
}

void ArrayStack::push(int x) {
    if (top >= stackCapacity) {
        throw out_of_range("Stos przepełniony");
    }

    array[top++] = x;
}

int ArrayStack::pop() {
    if (top == 0) {
        throw out_of_range("EMPTY");
    }

    return array[--top];
}

int ArrayStack::size() {
    return top;
}

bool ArrayStack::empty() {
    return top == 0;
}
