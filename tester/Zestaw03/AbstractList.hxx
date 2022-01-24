#include <iostream>

#ifndef ABSTRACT_LIST
#define ABSTRACT_LIST

template <class T>
class AbstractList
{
public:
    template <class U>
    void push_front(U &&x);

    T pop_front();

    template <class U>
    void push_back(U &&x);

    T pop_back();

    struct Iterator;

    Iterator find(const T &x);

    Iterator erase(Iterator x);

    template <class U>
    Iterator insert(Iterator it, U &&x);

    int remove(const T &x);

    int size();

    bool empty();

    Iterator begin();

    Iterator end();
};

#endif