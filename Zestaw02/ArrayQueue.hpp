#include <iostream>
#include <stdlib.h>

#ifndef ARRAYQUEUE
#define ARRAYQUEUE
#define DEFAULT_QUEUE_CAPACITY 20000

using namespace std;

class Queue {
    private:
        int *array;
        unsigned int head = 0;
        unsigned int tail = 0;
        unsigned int queueCapacity;
    public:
        // Konstruktor domyślny
        Queue() {
            array = (int*)calloc(sizeof(int), DEFAULT_QUEUE_CAPACITY);
            queueCapacity = DEFAULT_QUEUE_CAPACITY;
        }

        // Konstruktor z parametrem
        Queue(int capacity) {
            array = (int*)calloc(sizeof(int), capacity);
            queueCapacity = capacity;
        }

        // Destruktor
        ~Queue() {
            free(array);
            array = NULL;
        }

        // Wstawia element x do kolejki (także enqueue)
        void push(int x) {
            if (size() == queueCapacity) {
                throw out_of_range("Kolejka przepełniona");
            }

            array[tail++ % queueCapacity] = x;
        }

        // Usuwa element z kolejki i zwraca jego wartość (dequeue)
        int pop() {
            if (empty()) {
                throw out_of_range("EMPTY");
            }
            
            return array[head++ % queueCapacity];
        }

        // Zwraca liczbę elementów w kolejce
        int size() {
            return tail - head;
        }

        // Sprawdza czy kolejka jest pusta
        bool empty() {
            return size() == 0;
        }
};

#endif