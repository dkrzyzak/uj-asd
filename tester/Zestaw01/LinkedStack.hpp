#ifndef LINKED_STACK_H_
#define LINKED_STACK_H_

#include <iostream>
#include <stdexcept>

/*
template<class T>
class Node {
public:
    // Konstruktor elementu stosu
	Node(T data, Node *head) {
        mData = data;
        mPtrNext = head;
    }

	// Zwroc referencje elementu
    inline T& getValue() { return mData; }

	// Zwroc element na ktory wskazuje wskaznik next
    inline Node *getNext() { return mPtrNext; }

private:
    T mData;
    Node *mPtrNext = nullptr;
};
*/

template<class T>
struct Node {
    Node(const T& data, Node<T> *ptr) : mData(data), mPtrNext(ptr) {}
    Node(T&& data, Node<T> *ptr) : mData(std::move(data)), mPtrNext(ptr) {}
    T mData;
    Node<T> *mPtrNext;
};

template<class T>
class Stack {
public:    
    // Konstruktor
    Stack() = default;

    // Konstruktor kopiujacy
    Stack(const Stack& other) {
        // Zapisz rozmiar kopiowanego stosu
        mSize = other.mSize;
        Node<T> *temp = other.mPtrHead;
        Stack<T> tempStack;
        // Kopiuj wszystkie elementy do stosu
        // Najpierw skopiuj elementy do stosu tymczasowego ( kolejnosc elementow jest odwrocona )
        while(temp) {
            tempStack.push(temp->mData);
            temp = temp->mPtrNext;
        }
        // Nastepnie zapisz elementy ze stosu tymaczsowego do docelowego
        while(!tempStack.empty()) 
            push(tempStack.pop());
        printf("Copied [ COPY CONSTRUCTOR ]\n");
    }

    // Operator przypisania 
    Stack& operator=(const Stack& other) {
        // Sprawdz czy argument nie jest this
        if(this == &other)
            return *this;
        
        // Skopiuj rozmiar i pojemnosc stosu
        mSize = other.mSize;

        // usun elementy ze stosu
        clear();
        Node<T> *temp = other.mPtrHead;
        Stack<T> tempStack;
        // Kopiuj wszystkie elementy do stosu
        // Najpierw skopiuj elementy do stosu tymczasowego ( kolejnosc elementow jest odwrocona )
        while(temp) {
            tempStack.push(temp->mData);
            temp = temp->mPtrNext;
        }
        // Nastepnie zapisz elementy ze stosu tymaczsowego do docelowego
        while(!tempStack.empty()) 
            push(tempStack.pop());
        printf("Copied [ COPY ASSIGN OPERATOR ]\n");

        return *this;
    }

    // Konstruktor przenoszacy
    Stack(Stack&& other) noexcept {
        // Skopiuj wszystkie dane z rvalue, razem ze wskaznikiem do tablicy
        mSize = other.mSize;
        mPtrHead = other.mPtrHead;

        // Wyzeruj przeniesiony element
        other.mSize = 0;
        other.mPtrHead = nullptr;

        printf("Moved [ MOVE CONSTRUCTOR ]\n");
    }

    // operator przenoszacy
    Stack& operator=(Stack&& other) noexcept {
        // Sprawdz czy argument nie jest this
        if(this == &other)
            return *this;
        
        // Usun dotychczasowa tablice elementow
        clear();
        
        // Skopiuj wszystkie dane z rvalue, razem ze wskaznikiem do tablicy
        mSize = other.mSize;
        mPtrHead = other.mPtrHead;
        // Wyzeruj przeniesiony element
        other.mSize = 0;
        other.mPtrHead = nullptr;

        printf("Moved [ ASSIGN MOVE OPERATOR ]\n");

        return *this;
    }

    // Funkcja do wstawiania elementu na stos
    template<class U>
    void push(U&& x) {
		// Zakladamy ze nas stos jest nieskonczony (z tego powodu nie sprawdzamy czy stos jest pelny)
        if(!mPtrHead) {
            mPtrHead = new Node<T>(std::forward<U>(x), nullptr);
            mSize++;
        }
        else {
            mPtrHead = new Node<T>(std::forward<U>(x), mPtrHead);
            mSize++;
        }
    }
    
    // Funkcja do usuwania elementu ze stosu
    T pop() {
		// Jezeli stos jest pusty, wyrzuc wyjatek
        if(mSize == 0) {
            throw std::out_of_range("EMPTY");
        }
		// W przeciwnym wypadku usun element ze stosu
        else {
            Node<T> *temp = mPtrHead;
            mPtrHead = mPtrHead->mPtrNext;
            T value = std::move(temp->mData);
            delete temp;
            mSize--;
            return value;
        }
    }

    // Funkcja do zwracania referencji do elementu stosu
    T& top() {
		// Jezeli stos jest pusty, wyrzuc wyjatek
        if(mSize == 0) {
            throw std::out_of_range("EMPTY");
        }
        return mPtrHead->mData;
    }
    
    // Funkcja do zwracania rozmiaru stosu (ilosc elementow)
    inline uint32_t size() { return mSize; }
    
    // Fukcja do sprawdzenia czy stos jest pusty
    bool empty() {
        if(mSize == 0)
            return true;
        return false;
    }

    void display() {
        Node<T> *temp = mPtrHead;
        while(temp) {
            printf("%d ", temp->mData);
            temp = temp->mPtrNext;
        }
        printf("\n");
    } 

    void clear() {
        Node<T> *temp;
        while(mPtrHead) {
            temp = mPtrHead;
            mPtrHead = mPtrHead->mPtrNext;
            delete temp;
        }
    }

    ~Stack() {
        clear();
    }

private:
    uint32_t mSize = 0;
    Node<T> *mPtrHead = nullptr;
};  

#endif // LINKED_STACK_H_
