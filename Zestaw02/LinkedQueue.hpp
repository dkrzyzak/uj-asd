#include <iostream>
#include <stdlib.h>

#ifndef LINKEDQUEUE
#define LINKEDQUEUE

using namespace std;

class Queue {
    private:
        struct Node {
            int x;
            Node *next;
        };

        int queueSize;
        Node *head;
        Node *tail;

        Node* createNode(int x) {
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->x = x;
            newNode->next = NULL;

            return newNode;
        }

    public:
        // Konstruktor domyślny
        Queue() {
            head = tail = NULL;
        }

        // Destruktor
        ~Queue() {
            while (!empty()) {
                Node *temp = head;
                head = head->next;
                free(temp);
            }

            tail = NULL;
        }

        // Wstawia element x do kolejki (także enqueue)
        void push(int x) {
            Node *newNode = createNode(x);
            queueSize++;

            if (empty()) {
                head = tail = newNode;
                return;
            }

            tail->next = newNode;
            tail = newNode;
        }

        // Usuwa element z kolejki i zwraca jego wartość (dequeue)
        int pop() {
            if (empty()) {
                throw out_of_range("EMPTY");
            }
            Node *temp = head;
            int value = temp->x;
            head = head->next;
            free(temp);
            
            if (head == NULL) {
                tail = NULL;
            }

            queueSize--;
            return value;
        }

        // Zwraca liczbę elementów w kolejce
        int size() {
            return queueSize;
        }

        // Sprawdza czy kolejka jest pusta
        bool empty() {
            return head == NULL;
        }
};

#endif
