#ifndef ARRAY_STACK_H_
#define ARRAY_STACK_H_

#include <iostream>
#include <stdexcept>

template<class T, uint32_t N>
class Stack {
public:
    // Konstruktor
    Stack() {
        // Stworz tablice N elementowa
        mPtrArray = new T[N];
    }

    // Konstruktor kopiujacy
    Stack(const Stack& other) {
        // Skopiuj rozmiar i pojemnosc stosu
        mSize = other.mSize;
        mCapacity = N;
        
        // Skopiuj kazdy element stosu 
        for(uint32_t i=0; i<mSize; i++) 
            mPtrArray[i] = other.mPtrArray[i];
        
        printf("Copied [ COPY CONSTRUCTOR ]\n");
    }

    // Operator przypisania
    Stack& operator=(const Stack& other) {
        // Sprawdz czy argument nie jest this
        if(this == &other)
            return *this;
        
        // Skopiuj rozmiar i pojemnosc stosu
        mSize = other.mSize;
        mCapacity = N;

        // Usun tablice elementow i stworz nowa
        delete [] mPtrArray;
        mPtrArray = new T[N];

        // Skopiuj kazdy element stosu
        for(uint32_t i=0; i<mSize; i++) 
            mPtrArray[i] = other.mPtrArray[i];
        
        printf("Copied [ ASSIGN COPY OPERATOR ]\n");
    
        return *this;
    }

    // Konstruktor przenoszacy
    Stack(Stack&& other) noexcept {
        // Skopiuj wszystkie dane z rvalue, razem ze wskaznikiem do tablicy
        mSize = other.mSize;
        mCapacity = N;
        mPtrArray = other.mPtrArray;

        // Wyzeruj przeniesiony element
        other.mSize = 0;
        other.mCapacity = 0;
        other.mPtrArray = nullptr;

        printf("Moved [ MOVE CONSTRUCTOR ]\n");
    }

    // operator przenoszacy
    Stack& operator=(Stack&& other) noexcept {
        // Sprawdz czy argument nie jest this
        if(this == &other)
            return *this;
        
        // Usun dotychczasowa tablice elementow
        delete [] mPtrArray;
        
        // Skopiuj wszystkie dane z rvalue, razem ze wskaznikiem do tablicy
        mSize = other.mSize;
        mCapacity = N;
        mPtrArray = other.mPtrArray;
        // Wyzeruj przeniesiony element
        other.mSize = 0;
        other.mCapacity = 0;
        other.mPtrArray = nullptr;

        printf("Moved [ ASSIGN MOVE OPERATOR ]\n");

        return *this;
    }

    // Funkcja wstawiajaca element na stos
    template<class U>
    void push(U&& x) {
        // Jezeli stos nie jest pelny, to dodaj element
        if(mSize < mCapacity) {
            mPtrArray[mSize] = std::forward<U>(x);
            mSize++;
        }
        // W przeciwnym wypadku, wyrzuc wyjatek
        else {
            throw std::out_of_range("FULL");
        }
    }

    // Funkcja do usuwania elementu ze stosu 
    T pop() {
        // Jezeli stos nie jest pusty, to usun element  
        if(mSize > 0) {
            mSize--;
            return mPtrArray[mSize];
        }
        // W przeciwnym wypadku, wyrzuc wyjatek 
        else {
            throw std::out_of_range("EMPTY");
        }
    }
    
	// Funkcja do zwracania referencji elementu 
    T& top() {
        // Jezeli stos nie jest pusty, zwroc referencje
        if(mSize > 0) {
            return &mPtrArray[mSize-1];
        }
        // W przeciwnym wypadku, wyrzuc wyjatek 
        throw std::out_of_range("EMPTY");
    }

    // Funkcja do zwracania rozmiaru stosu (ilosci elementow)
    inline uint32_t size() { return mSize; }
    
	// Funkcja do sprawdzania czy stos jest pusty 
    bool empty() {
        if(mSize == 0)
            return true;
        return false;
    }

    void display() {
        for(uint32_t i=0; i<mSize; i++)
            printf("%d ", mPtrArray[i]);
        printf("\n");
    } 

    ~Stack() {
        delete [] mPtrArray;
    }

private:
    uint32_t mSize = 0;
    uint32_t mCapacity = N;
    T *mPtrArray;
};

#endif // ARRAY_STACK_H_
