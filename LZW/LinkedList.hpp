#ifndef LINKEDLIST
#define LINKEDLIST

#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <sstream>

using namespace std;

template<class T>
class List {
private:
    struct Node {
        T x;
        Node *prev = nullptr;
        Node *next = nullptr;

        Node(): x() {};
        Node(T x): x(x) {};
    };

    unsigned int listSize;

public:
    Node head;

    List() {
        head.next = NULL;
        head.prev = NULL;
        listSize = 0;
    }

    // Dołacza element na początek listy
    void push_front(T x) {
        auto newNode = new Node(x);

        // pusta lista
        if (head.next == NULL) {
            head.next = newNode;
            head.prev = newNode;

            newNode->prev = &head;
            newNode->next = &head;
        } else {
            head.next->prev = newNode;
            newNode->next = head.next;

            newNode->prev = &head;
            head.next = newNode;
        }

        listSize++;
    }

    // Usuwa i zwraca element z początku listy
    T pop_front() {
        // pusta lista 
        if (head.next == NULL) {
            throw out_of_range("EMPTY");
        }

        T x = head.next->x;

        // jeden element na liście
        if (head.next == head.prev) {
            free(head.next);
            head.next = NULL;
            head.prev = NULL;
        } else {
            // więcej elementow na liście
            Node* nodeToRemove = head.next;
            head.next = head.next->next;
            delete nodeToRemove;
        }

        listSize--;
        return x;
    }

    // Dołacza element na koniec listy
    void push_back(T x) {
        auto newNode = new Node(x);

        // pusta lista
        if (head.prev == NULL) {
            head.next = newNode;
            head.prev = newNode;

            newNode->prev = &head;
            newNode->next = &head;
        } else {
            // wstawiamy za ostatni element
            head.prev->next = newNode;
            newNode->prev = head.prev;

            // przepinamy końcowki
            newNode->next = &head;
            head.prev = newNode;
        }

        listSize++;
    }

    // Usuwa i zwraca element z końca listy
    T pop_back() {
        // pusta lista 
        if (empty()) {
            throw out_of_range("EMPTY");
        }

        T x = head.prev->x;

        // jeden element na liście
        if (head.next == head.prev) {
            free(head.prev);
            head.next = NULL;
            head.prev = NULL;
        } else {
            // więcej elementow na liście
            Node* nodeToRemove = head.prev;
            head.prev = head.prev->prev;
            delete nodeToRemove;
        }

        listSize--;
        return x;
    }

    T operator[](const int index) {
        int i = 0;

        Node* el = head.next;
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
        Node* el = head.next;

        for (int i = 0; i < listSize; i++) {
            el = el->next;
            delete el->prev;
        }

        head.next = NULL;
        head.prev = NULL;
    }

    // Zwraca pozycje pierwszego elementu o wartości x
    int find(T x) {
        if (empty()) {
            return -1;
        }

        Node* el = head.next;
        for (int i = 0; i < listSize; i++) {
            if (el->x == x) {
                return i;
            }

            el = el->next;
        }

        return -1;
    }

    // Usuwa i zwraca element na pozycji i
    T erase(int i) {
        if (i >= listSize) {
            throw out_of_range("Lista nie ma tylu elementow");
        }

        Node* el;
        for (int index = 0; index <= i; index++) {
            if (index == 0) {
                el = head.next;
            } else {
            el = el->next;
            }
        }

        T value = el->x;
        el->prev->next = el->next;
        el->next->prev = el->prev;
        delete el;
        listSize--;

        return value;
    }

    // Wstawia element x przed pozycje i
    void insert(int i, T x) {
        Node* el;
        for (int index = 0; index <= i; index++) {
            if (index == 0) {
                el = head.next;
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
    int remove(T x) {
        int xCount = 0;
        int index;
        while ((index = find(x)) != -1) {
            erase(index);
            xCount++;
        }

        return xCount;
    }

    T& back() {
        return head.prev->x;
    }

    string print() {
        stringstream ss;
        Node* el = head.next;
        for (int i = 0; i < listSize; i++) {
            ss << el->x << endl;
            el = el->next;
        }

        return ss.str();
    }
};

#endif