#include <iostream>

#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include "AbstractList.hxx"

template <class T, int N>
class ArrayList : public AbstractList<T>
{
public:
    ArrayList()
    {
        arraySize = N;
        currentSize = 0;
        array = new T[arraySize];
    }

    ArrayList(ArrayList<T, N> const &other)
    {
        delete[] array;

        array = new T[other.arraySize];

        std::copy(other.array, other.array + other.arraySize, array);

        arraySize = other.arraySize;
        currentSize = other.currentSize;
    }

    ArrayList<T, N> &operator=(ArrayList<T, N> const &other)
    {

        if (this != &other)
        {
            delete[] array;

            array = new T[other.arraySize];

            std::copy(other.array, other.array + other.arraySize, array);

            arraySize = other.arraySize;
            currentSize = other.currentSize;
        }

        return *this;
    }

    ArrayList(ArrayList<T, N> &&other)
    {

        *this = std::move(other);
    }

    ArrayList<T, N> &operator=(ArrayList<T, N> const &&other)
    {

        if (this != &other)
        {
            delete[] array;

            array = new T[other.arraySize];

            array = std::move(other.array);

            arraySize = other.arraySize;
            currentSize = other.currentSize;
        }

        return *this;
    }

    ~ArrayList()
    {
        if (array != nullptr)
        {
            delete[] array;
        }
    }

    template <class U>
    void push_back(U &&x)
    {
        if (currentSize + 1 > arraySize)
            throw std::out_of_range("ArrayList overflow");

        array[currentSize] = std::forward<U>(x);

        currentSize++;
    }

    T pop_back()
    {
        if (currentSize == 0)
            throw std::out_of_range("ArrayList:pop_back underflow");

        T temp = array[currentSize - 1];
        currentSize--;

        return temp;
    }

    template <class U>
    void push_front(U &&x)
    {
        if (currentSize + 1 > arraySize)
            throw std::out_of_range("ArrayList overflow");

        for (int i = currentSize; i > 0; i--)
        {
            array[i] = array[i - 1];
        }
        currentSize++;

        array[0] = std::forward<U>(x);
    }

    T pop_front()
    {
        if (currentSize == 0)
            throw std::out_of_range("ArrayList:pop_front underflow");

        T temp = std::move(array[0]);

        for (int i = 0; i < currentSize; i++)
        {
            array[i] = array[i + 1];
        }

        currentSize--;

        return temp;
    }

    struct Iterator
    {
        T *ptr;

        Iterator(T *ptr) : ptr(ptr){};

        Iterator &operator++()
        {
            ptr++;
            return *this;
        }

        Iterator &operator++(int)
        {
            Iterator *temp = this;
            ptr++;

            return *temp;
        }

        Iterator &operator+(int x)
        {

            return *(this + x);
        }

        Iterator &operator--()
        {
            ptr--;
            return *this;
        }

        Iterator &operator--(int)
        {
            Iterator *temp = this;

            ptr--;

            return *temp;
        }

        bool operator==(const Iterator &b) const
        {
            return ptr == b.ptr;
        }

        bool operator!=(const Iterator &b) const
        {
            return !operator==(b);
        }

        T &operator*()
        {
            return *ptr;
        }
    };

    Iterator find(const T &x)
    {
        Iterator point = begin();

        while (point != end())
        {
            if (*point == x)
                return point;
            point++;
        }

        // or end()?
        return nullptr;
    }

    Iterator erase(Iterator x)
    {
        Iterator point = begin();

        while (point != end())
        {
            if (point == x)
            {
                currentSize -= 1;

                for (point; point != end(); point++)
                {
                    point = ++x;
                }

                return ++x;
            }

            point++;
        }

        return nullptr;
    }

    template <class U>
    Iterator insert(Iterator it, U &&x)
    {
        for (Iterator point = it; point != end(); point++)
        {
            (point + 1) = point;
        }

        it = std::forward<U>(x);
    }

    int remove(const T &x)
    {
        int count = 0;

        Iterator point = begin();
        Iterator last = end();

        while (point != last)
        {
            Iterator next = point;
            ++next;

            if (*point == x)
            {
                erase(point);
                count++;
            }

            point = next;
        }

        return count;
    }

    int size()
    {
        return currentSize;
    }

    bool empty()
    {
        return currentSize == 0;
    }

    Iterator begin()
    {
        return Iterator(array);
    }
    Iterator end()
    {
        return Iterator(array + currentSize);
    }

private:
    T *array;

    int arraySize;
    int currentSize;
};

#endif