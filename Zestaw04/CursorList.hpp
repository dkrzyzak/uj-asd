#ifndef CURSORLIST
#define CURSORLIST

#include <stdlib.h>
#include <math.h>
#include <iostream>

#define MAX_LIST_SIZE 1000

using namespace std;

class List {
    private:
    struct Node {
        int x;
        int next; // index kolejnego węzła
    };

    Node arr[MAX_LIST_SIZE];
    int head; // index pierwszego węzła
    int tail; // index ostatniego węzła
    int arrSize; // rozmiar listy
    int spare; // index pierwszego nieużytego elementu tablicy

    bool isFull() {
        return arrSize >= MAX_LIST_SIZE;
    }

    public:
    List() {
        // związanie w listę nieużytych węzłów
        for (int i = 0; i < MAX_LIST_SIZE - 1; i++) {
            arr[i].x = 0;
            arr[i].next = i + 1;
        }

        arr[MAX_LIST_SIZE - 1].x = 0;
        arr[MAX_LIST_SIZE - 1].next = -1;
        arrSize = 0;
        spare = 0;
        tail = -1;
        head = -1;
    }

    ~List() {
        clear();
    }

    void push_front(int x) {
        if (isFull()) {
            throw out_of_range("Lista przepełniona");
        }

        int currentSpare = spare;
        
        spare = arr[spare].next;

        arr[currentSpare].x = x;
        arr[currentSpare].next = head;
        
        head = currentSpare;
        
        if (arrSize == 0) {
            tail = currentSpare;
        }

        arrSize++;
    }

    int pop_front() {
        if (empty()) {
            throw out_of_range("EMPTY");
        }

        int valueFront = arr[head].x;
        int currentHead = head;
        head = arr[head].next;

        arr[currentHead].x = 0;
        arr[currentHead].next = spare;
        
        spare = currentHead;

        arrSize--;

        if (empty()) {
            tail = -1;
        }

        return valueFront;
    }


    void push_back(int x) {
        if (isFull()) {
            throw out_of_range("Lista przepełniona");
        }

        int currentSpare = spare;
        spare = arr[spare].next;

        arr[currentSpare].x = x;
        arr[currentSpare].next = -1;

        if (tail != -1) arr[tail].next = currentSpare;
        tail = currentSpare;
        
        if (arrSize == 0) {
            head = currentSpare;
        }

        arrSize++;
    }

    int pop_back() {
        if (empty()) {
            throw out_of_range("EMPTY");
        }

        int valueBack = arr[tail].x;
        int currentTail = tail;

        int prev = tail;
        int idx = head;

        while(idx != currentTail) {
            if (arr[idx].next == currentTail) {
                prev = idx;
            }

            idx = arr[idx].next;
        }

        tail = prev;
        arr[tail].next = -1;

        arr[currentTail].x = 0;
        arr[currentTail].next = spare;
        spare = currentTail;

        arrSize--;

        if (empty()) {
            tail = -1;
            head = -1;
        }

        return valueBack;
    }

    int size() {
        return arrSize;
    }

    bool empty() {
        return arrSize == 0;
    }
    void clear() {
        for (int i = 0; i < MAX_LIST_SIZE - 1; i++) {
            arr[i].x = 0;
            arr[i].next = i + 1;
        }

        arr[MAX_LIST_SIZE - 1].x = 0;
        arr[MAX_LIST_SIZE - 1].next = -1;
        
        arrSize = 0;
        spare = 0;
        tail = -1;
        head = -1;
    }

    // Zwraca pozycje pierwszego elementu o wartości x
    int find(int x) {
        int idx = head;
        int tmp = 0;

        while(idx != -1) {
            if (arr[idx].x == x) {
                return tmp;
            }

            tmp++;
            idx = arr[idx].next;
        }

        return -1;
    }

    // Usuwa i zwraca element na pozycji i
    int erase(int i) {
        int idx = head;
        int tmp = 0;
        int prev;

        if (i == 0) {
            return pop_front();
        }

        while (tmp != i) {
            // musimy zapamiętać index poprzedniego elementu
            if (tmp == i - 1) {
                prev = idx;
            }

            idx = arr[idx].next;
            tmp++;
        }

        if (arr[idx].next == -1) {
            tail = prev;
        }

        int value = arr[idx].x;
        arr[prev].next = arr[idx].next;
        
        arr[idx].x = 0;
        arr[idx].next = spare;
        spare = idx;

        arrSize--;

        return value;
    }

    // Wstawia element x przed pozycję i
    void insert(int i, int x) {
        if (isFull()) {
            throw out_of_range("Lista przepełniona");
        }

        int idx = head;
        int tmp = 0;
        int prev;

        if (i == 0) {
            return push_front(x);
        }
        
        while (tmp != i) {
            if (tmp == i - 1) {
                prev = idx;
            }

            tmp++;
            idx = arr[idx].next;
        }

        int currentSpare = spare;

        spare = arr[spare].next;

        arr[currentSpare].x = x;
        arr[currentSpare].next = idx;
        arr[prev].next = currentSpare;

        arrSize++;
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

    void print() {
        int idx = head;
        while (idx != -1) {
            cout << arr[idx].x << "->";
            idx = arr[idx].next;
        }
        cout << endl;

        idx = spare;
        while (idx != -1) {
            cout << idx << "->";
            idx = arr[idx].next;
        }

        cout << endl << "spare: " << spare << endl;
        cout << "arrSize: " << arrSize << endl;
        cout << "head: " << head << endl;
        cout << "tail: " << tail << endl << endl;
    }
};

#endif