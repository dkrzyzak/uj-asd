#include <iostream>

#ifndef CURSOR_LIST_H
#define CURSOR_LIST_H

#include "AbstractList.hxx"

template <class T, int N>
class CursorList : public AbstractList<T>
{
    struct Node
    {
        T x;
        int next;
    };

private:
    Node array[N + 1];

    int head;
    int tail;
    int spare;

    int maxSize;

public:
    CursorList()
    {
        maxSize = N + 1;

        head = 0;
        tail = 0;
        spare = 0;

        init_cursor_space();
    }

    CursorList(CursorList<T, N> const &other)
    {
        delete[] array;

        array = new T[other.maxSize];

        std::copy(other.array, other.array + other.maxSize, array);

        maxSize = other.maxSize;
        head = other.head;
        tail = other.tail;
        spare = other.spare;
    }

    CursorList<T, N> &operator=(CursorList<T, N> const &other)
    {
        if (this != &other)
        {
            delete[] array;

            array = new T[other.maxSize];

            std::copy(other.array, other.array + other.maxSize, array);

            maxSize = other.maxSize;
            head = other.head;
            tail = other.tail;
            spare = other.spare;
        }

        return *this;
    }

    CursorList(CursorList<T, N> &&other)
    {
        *this = std::move(other);
    }

    CursorList<T, N> &operator=(CursorList<T, N> const &&other)
    {

        if (this != &other)
        {
            delete[] array;
            array = new Node[maxSize];

            *this = std::move(other);

            maxSize = std::move(other.maxSize);
            head = std::move(other.head);
            tail = std::move(other.tail);
            spare = std::move(other.spare);
        }

        return *this;
    }

    void init_cursor_space()
    {
        for (int i = 0; i < maxSize; i++)
        {
            array[i].next = i + 1;
        }

        // jako end
        array[0].next = 0;
        array[maxSize - 1].next = 0;
        spare = 1;
    }

    T delete_node(int current)
    {

        T temp = array[current].x;
        if (current == head)
        {
            if (tail == head)
                tail = 0;
            head = array[current].next;
        }
        else
        {
            int prev = head;
            while (array[prev].next != current)
                prev = array[prev].next;

            array[prev].next = array[current].next;

            if (current == tail)
                tail = prev;
        }

        if (spare == -1)
        {
            spare = current;
        }
        else
        {
            array[findLastFree()].next = current;
        }
        array[current].next = 0;

        return temp;
    }

    int findLastFree()
    {
        int free = spare;
        while (array[free].next != 0)
            free = array[free].next;

        return free;
    }
    int push_after(int index, T value)
    {
        int freshIndex = get_spare();

        array[freshIndex].x = value;
        array[freshIndex].next = array[index].next;
        array[index].next = array[freshIndex].next;

        return freshIndex;
    }

    int push_before(int index, T value)
    {
        int freshIndex = get_spare();

        array[freshIndex].x = value;
        array[freshIndex].next = -1;
        array[index].next = freshIndex;

        return freshIndex;
    }

    int get_spare()
    {
        if (spare == 0)
        {
            return 0;
        }
        else
        {
            int fresh = spare;

            spare = array[fresh].next;

            return fresh;
        }
    }

    bool is_full()
    {
        return spare == 0;
    }

    template <class U>
    void push_front(U &&x)
    {
        if (is_full())
            throw std::out_of_range("CursorList overflow");

        int temp = get_spare();

        array[temp].next = head;
        array[temp].x = std::forward<U>(x);

        if (tail == 0)
        {
            tail = temp;
        }

        head = temp;
    }

    T pop_front()
    {
        if (head == 0)
            throw std::out_of_range("CursorList:pop_front underflow");

        return delete_node(head);
    }

    template <class U>
    void push_back(U &&x)
    {
        if (is_full())
            throw std::out_of_range("CursorList overflow");

        int temp = get_spare();

        if (tail != 0)
        {
            array[tail].next = temp;
        }
        else
        {
            head = temp;
        }

        array[temp].next = 0;
        array[temp].x = std::forward<U>(x);
        tail = temp;
    }

    T pop_back()
    {
        if (tail == 0)
            throw std::out_of_range("CursorList:pop_back underflow");

        return delete_node(tail);
    }

    struct Iterator
    {
        int index;
        Node *body;

        Iterator(int index, Node *body) : index(index), body(body){};

        Iterator &operator++()
        {
            int nextIndex = body[index].next;
            index = nextIndex;

            return *this;
        }

        Iterator &operator++(int)
        {
            Iterator *temp = this;

            int nextIndex = body[index].next;
            index = nextIndex;

            return *temp;
        }

        bool operator==(const Iterator &b) const
        {
            return index == b.index;
        }

        bool operator!=(const Iterator &b) const
        {
            return !operator==(b);
        }

        T &operator*()
        {
            return body[index].x;
        }
    };

    Iterator find(const T &x)
    {
        if (empty())
            return end();

        Iterator point = begin();

        while (point != end())
        {
            if (*(point) == x)
                return point;
            point++;
        }

        // or? throw std::runtime_error("value not found");
        return end();
    }

    Iterator erase(Iterator x)
    {
        delete_node(x.index);

        return ++x;

        throw std::runtime_error("value not found");
    }

    template <class U>
    Iterator insert(Iterator it, U &&x)
    {
        if (is_full())
            throw std::out_of_range("overflow");

        int tempval = it.elem->x;
        int tempnext = it.elem->next;

        int fresh = push_before(it.index, x);
        array[fresh].next = tempnext;

        return new Iterator(fresh, array[fresh], this);
    }

    int remove(const T &x)
    {
        int count = 0;

        Iterator point = begin();
        Iterator last = end();

        while (point != last)
        {
            if (*point == x)
            {
                erase(point);
                count++;
            }

            point++;
        }

        return count;
    }

    int size()
    {
        if (empty())
            return 0;

        int count = 0;

        auto point = begin();
        while (point != end())
        {
            count++;
            point++;
        }

        return count;
    }

    bool empty()
    {
        return head == 0;
    }

    Iterator begin()
    {
        return Iterator(head, array);
    }
    Iterator end()
    {
        int end = 0;

        return Iterator(end, array);
    }
};

#endif
