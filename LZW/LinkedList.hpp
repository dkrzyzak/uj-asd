#ifndef LINKEDLIST
#define LINKEDLIST

#include <stdlib.h>
#include <math.h>
#include <iostream>

using namespace std;

class List {
private:
    struct Node {
        int x;
        Node *prev = nullptr;
        Node *next = nullptr;

        Node(): x(0) {};
        Node(int x): x(x) {};
    };

    Node guard;
    unsigned int listSize;

public:
    List() {
        guard.next = NULL;
        guard.prev = NULL;
        listSize = 0;
    }

    // Dołacza element na początek listy
    void push_front(int x) {
        auto newNode = new Node(x);

        // pusta lista
        if (guard.next == NULL) {
            guard.next = newNode;
            guard.prev = newNode;

            newNode->prev = &guard;
            newNode->next = &guard;
        } else {
            guard.next->prev = newNode;
            newNode->next = guard.next;

            newNode->prev = &guard;
            guard.next = newNode;
        }

        listSize++;
    }

    // Usuwa i zwraca element z początku listy
    int pop_front() {
        // pusta lista 
        if (guard.next == NULL) {
            throw out_of_range("EMPTY");
        }

        int x = guard.next->x;

        // jeden element na liście
        if (guard.next == guard.prev) {
            free(guard.next);
            guard.next = NULL;
            guard.prev = NULL;
        } else {
            // więcej elementow na liście
            Node* nodeToRemove = guard.next;
            guard.next = guard.next->next;
            delete nodeToRemove;
        }

        listSize--;
        return x;
    }

    // Dołacza element na koniec listy
    void push_back(int x) {
        auto newNode = new Node(x);

        // pusta lista
        if (guard.prev == NULL) {
            guard.next = newNode;
            guard.prev = newNode;

            newNode->prev = &guard;
            newNode->next = &guard;
        } else {
            // wstawiamy za ostatni element
            guard.prev->next = newNode;
            newNode->prev = guard.prev;

            // przepinamy końcowki
            newNode->next = &guard;
            guard.prev = newNode;
        }

        listSize++;
    }

    // Usuwa i zwraca element z końca listy
    int pop_back() {
        // pusta lista 
        if (empty()) {
            throw out_of_range("EMPTY");
        }

        int x = *(&(guard.prev)->x);

        // jeden element na liście
        if (guard.next == guard.prev) {
            free(guard.prev);
            guard.next = NULL;
            guard.prev = NULL;
        } else {
            // więcej elementow na liście
            Node* nodeToRemove = guard.prev;
            guard.prev = guard.prev->prev;
            delete nodeToRemove;
        }

        listSize--;
        return x;
    }

    int operator[](const int index) {
        int i = 0;

        Node* el = guard.next;
        while (i != index) {
            el = el->next;
            i++;
        }

        return el->x;
    }

    // Zwraca liczbę elementów w liscie
    int size() {
        return listSize;
    }

    // Zwraca true gdy lista jest pusta
    bool empty() {
        return listSize == 0;
    }

    // Czyści listę
    void clear() {
        Node* el = guard.next;

        for (int i = 0; i < listSize; i++) {
            el = el->next;
            delete el->prev;
        }

        guard.next = NULL;
        guard.prev = NULL;
    }

    // Zwraca pozycje pierwszego elementu o wartości x
    int find(int x) {
        if (empty()) {
            return -1;
        }

        Node* el = guard.next;
        for (int i = 0; i < listSize; i++) {
            if (el->x == x) {
                return i;
            }

            el = el->next;
        }

        return -1;
    }

    // Usuwa i zwraca element na pozycji i
    int erase(int i) {
        if (i >= listSize) {
            throw out_of_range("Lista nie ma tylu elementow");
        }

        Node* el;
        for (int index = 0; index <= i; index++) {
            if (index == 0) {
                el = guard.next;
            } else {
            el = el->next;
            }
        }

        int value = el->x;
        el->prev->next = el->next;
        el->next->prev = el->prev;
        delete el;
        listSize--;

        return value;
    }

    // Wstawia element x przed pozycje i
    void insert(int i, int x) {
        Node* el;
        for (int index = 0; index <= i; index++) {
            if (index == 0) {
                el = guard.next;
            } else {
                el = el->next;
            }
        }

        auto newNode = new Node(x);

        newNode->prev = el->prev;
        el->prev->next = newNode;
        el->prev = newNode;
        newNode->next = el;

        listSize++;
    }

    // Usuwa wystąpienia x i zwraca ich liczbę
    int remove(int x) {
        int xCount = 0;
        int index;
        while ((index = find(x)) != -1) {
            erase(index);
            xCount++;
        }

        return xCount;
    }

    void print() {
        Node* el = guard.next;
        for (int i = 0; i < listSize; i++) {
            cout << el->x << endl;
            el = el->next;
        }
    }
};

#endif