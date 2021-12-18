#ifndef LINKEDLIST
#define LINKEDLIST

#include <stdlib.h>
#include <math.h>
#include <iostream>

#define MAX_LIST_SIZE 1000

using namespace std;

class List {
private:
    struct Node {
        int x;
        Node *prev;
        Node *next;
    };

    Node guard;
    unsigned int listSize;

    Node* createNode(int x) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->x = x;
        newNode->next = NULL;
        newNode->prev = NULL;

        return newNode;
    }

public:
    List() {
        guard.next = NULL;
        guard.prev = NULL;
        listSize = 0;
    }

    // Dołacza element na początek listy
    void push_front(int x) {
        // przepełniona lista
        if (listSize == MAX_LIST_SIZE) {
            throw out_of_range("FULL");
        }

        Node* newNode = createNode(x);

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
            free(nodeToRemove);
        }

        listSize--;
        return x;
    }

    // Dołacza element na koniec listy
    void push_back(int x) {
        // przepełniona lista
        if (listSize == MAX_LIST_SIZE) {
            throw out_of_range("FULL");
        }

        Node* newNode = createNode(x);

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
            free(nodeToRemove);
        }

        listSize--;
        return x;
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
            free(el->prev);
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
        free(el);
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

        Node* newNode = createNode(x);

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
};

#endif