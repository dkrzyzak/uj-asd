#ifndef ARRAYLIST
#define ARRAYLIST

#include <stdlib.h>
#include <math.h>
#include <iostream>

#define MAX_LIST_SIZE 1000

using namespace std;

class List {
    private:
    int arr[MAX_LIST_SIZE];
    int head = 0;

    bool isFull() {
        return head == MAX_LIST_SIZE;
    }

    public:
    List() {

    }

    void push_front(int x) {
        if (isFull()) {
            throw out_of_range("Lista przepełniona");
        }

        for (int i = head; i > 0; i--) {
            arr[i] = arr[i - 1];
        }

        arr[0] = x;
        head++;
    }

    int pop_front() {
        if (empty()) {
            throw out_of_range("EMPTY");
        }

        int valueFront = arr[0];

        for (int i = 0; i < head - 1; i++) {
            arr[i] = arr[i + 1];
        }

        head--;
        return valueFront;
    }


    void push_back(int x) {
        if (isFull()) {
            throw out_of_range("Lista przepełniona");
        }

        arr[head++] = x;
    }

    int pop_back() {
        if (empty()) {
            throw out_of_range("EMPTY");
        }

        return arr[--head];
    }

    int size() {
        return head;
    }

    bool empty() {
        return head == 0;
    }

    void clear() {
        for (int i = 0; i < head; i++) {
            arr[i] = 0;
        }
    }

    // Zwraca pozycje pierwszego elementu o wartości x
    int find(int x) {
        for (int i = 0; i < head; i++) {
            if (arr[i] == x) return i;
        }

        return -1;
    }

    // Usuwa i zwraca element na pozycji i
    int erase(int i) {
        int value = arr[i];

        for (int idx = i; idx < head - 1; idx++) {
            arr[idx] = arr[idx + 1];
        }

        head--;
        return value;
    }

    // Wstawia element x przed pozycję i
    void insert(int i, int x) {
        for (int idx = head; idx > i; idx--) {
            arr[idx] = arr[idx - 1];
        }

        arr[i] = x;
        head++;
    }

    // Usuwa wystąpienia x i zwraca ich liczbę
    int remove(int x) {
        int count = 0;
        int index;
        while ((index = find(x)) != -1) {
            erase(index);
            count++;
        }

        return count;
    }
};

#endif