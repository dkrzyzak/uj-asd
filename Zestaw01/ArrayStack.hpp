#ifndef ARRAYSTACK
#define ARRAYSTACK

class ArrayStack {
    private:
        int *array;
        int stackCapacity;
        int top;
    public:
        ArrayStack(int capacity); // Konstruktor. Argumentem jest rozmiar tablicy.
        ~ArrayStack();
        void push(int x); // Wstawia element na stos
        int pop(); // Usuwa element ze stosu i zwraca jego wartosc
        int size(); // Zwraca liczbe elementów na stosie
        bool empty(); // Sprawdza czy stos jest pusty
};

#endif