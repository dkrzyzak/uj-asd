#include <iostream>

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "AbstractList.hxx"

template <class T>
class LinkedList : public AbstractList<T>
{
public:
    struct Node
    {
        T value;

        Node *prev;
        Node *next;
    };

    LinkedList()
    {

        guard = new Node;

        guard->prev = nullptr;
        guard->next = nullptr;
    }

    LinkedList(LinkedList<T> const &other)
    {

        guard = new Node;

        if (other.guard->next == nullptr)
            guard->next = guard->prev = nullptr;

        else
        {
            guard->prev = guard->next = nullptr;

            for (auto &a : other)
            {
                push_back(a);
            }
        }
    }

    LinkedList<T> &operator=(LinkedList<T> const &other)
    {

        if (this != &other)
        {
            guard = new Node;

            if (other.guard->next == nullptr)
                guard->next = guard->prev = nullptr;

            else
            {
                guard->prev = guard->next = nullptr;

                for (auto &a : other)
                {
                    push_back(a);
                }
            }
        }

        return *this;
    }

    LinkedList(LinkedList<T> &&other)
    {

        *this = std::move(other);
    }

    LinkedList<T> &operator=(LinkedList<T> const &&other)
    {

        if (this != &other)
        {
            if (other.guard->next == nullptr)
                guard->next = guard->prev = nullptr;
            else
            {
                clear();

                Node *temp = other.guard->next;

                guard = std::move(guard);
                guard->next = std::move(other.guard->next);
                guard->prev = std::move(other.guard->prev);

                Node *currentHead = guard->next;

                other.guard->next = nullptr;
                other.guard->prev = nullptr;

                temp = guard->next->next;

                // deep kopia
                while (temp != nullptr)
                {
                    currentHead = std::move(temp);
                    currentHead->next = std::move(temp->next);

                    currentHead->prev = std::move(temp->prev);

                    temp->next = nullptr;
                    temp->prev = nullptr;

                    temp = currentHead->next;
                }
                guard->prev = currentHead;
            }
        }

        return *this;
    }

    ~LinkedList()
    {
        clear();
    }

    template <class U>
    void push_front(U &&x)
    {

        Node *fresh = new Node;

        fresh->value = std::forward<U>(x);
        fresh->prev = nullptr;
        fresh->next = guard->next;

        if (guard->next != nullptr)
        {
            guard->next->prev = fresh;
        }

        if (guard->prev == nullptr)
        {
            guard->prev = fresh;
        }
        guard->next = fresh;
    }

    T pop_front()
    {
        if (empty())
            throw std::out_of_range("List is empty");

        Node *toDelete = guard->next;
        int temp = toDelete->value;

        if (guard->next->next != nullptr)
        {
            guard->next->next->prev = nullptr;
        }
        guard->next = guard->next->next;

        if (toDelete == guard->prev)
        {
            guard->next = guard->prev = nullptr;
        }

        delete toDelete;

        return temp;
    }

    template <class U>
    void push_back(U &&x)
    {
        Node *fresh = new Node;

        fresh->value = std::forward<U>(x);
        fresh->next = nullptr;
        fresh->prev = guard->prev;

        if (guard->prev != nullptr)
        {
            guard->prev->next = fresh;
        }

        if (guard->next == nullptr)
        {
            guard->next = fresh;
        }
        guard->prev = fresh;
    }

    T pop_back()
    {

        if (empty())
            throw std::out_of_range("List is empty");

        Node *toDelete = guard->prev;
        int temp = toDelete->value;

        if (guard->prev->prev != nullptr)
        {
            guard->prev->prev->next = nullptr;
        }
        guard->prev = guard->prev->prev;

        if (toDelete == guard->next)
        {
            guard->next = guard->prev = nullptr;
        }

        delete toDelete;

        return temp;
    }

    struct Iterator
    {
    public:
        Node *ptr;

        Iterator(Node *ptr_) : ptr(ptr_){};

        Iterator &operator++()
        {
            ptr = ptr->next;
            return *this;
        }

        Iterator &operator++(int)
        {
            Iterator *temp = this;

            ptr = ptr->next;

            return *temp;
        }

        Iterator &operator--()
        {
            ptr = ptr->prev;
            return *this;
        }

        Iterator &operator--(int)
        {
            Iterator *temp = this;

            ptr = ptr->prev;

            return *temp;
        }

        bool operator==(const Iterator &b)
        {
            return ptr == b.ptr;
        }

        bool operator!=(const Iterator &b)
        {
            return !operator==(b);
        }

        T &operator*()
        {
            return ptr->value;
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

        // or nullptr?
        return end();
    }

    // usuwa cala liste
    void clear()
    {
        Node *current = guard->next;

        while (current)
        {
            Node *next = current->next;

            delete current;

            current = next;
        }
    }

    Iterator erase(Iterator x)
    {
        Iterator point = begin();
        Node *toDelete = nullptr;

        while (point != end())
        {
            if (point == x)
            {
                toDelete = point.ptr;

                break;
            }

            point++;
        }

        if (toDelete != nullptr)
        {
            // jezeli jest 1 element -> zerujemy wskazniki
            if (guard->next == guard->prev)
            {
                guard->next = guard->prev = nullptr;
            }
            else
            {
                // jezeli usuwana pozycja jest head -> zmien head na kolejną komórkę. w kolejnej komórce ustaw poprzedni element na nullptr
                if (point.ptr == guard->next)
                {
                    guard->next = point.ptr->next;
                    guard->next->prev = nullptr;
                }
                // jezeli nie jest głową -> zmien nastepną komórkę w elemencie poprzedzającym
                else
                {
                    point.ptr->prev->next = point.ptr->next;
                }

                // jezeli usuwana pozycja jest ogonem -> zmien zmien ogon na poprzednią komórkę. w poprzedni komórce ustaw kolejny element na nullptr
                if (point.ptr == guard->prev)
                {
                    guard->prev = point.ptr->prev;
                    guard->prev->next = nullptr;
                }
                // jezeli nie jest ogonem -> zmien poprzednią komórkę w elemencie następnym na element poprzedzający usuwaną komórkę
                else
                {
                    point.ptr->next->prev = point.ptr->prev;
                }
            }

            delete toDelete;

            return end();
        }

        return end();
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
        int count = 0;
        for (Node *current = guard->next; current != nullptr; current = current->next)
        {
            count++;
        }

        return count;
    }

    bool empty()
    {
        return guard->next == nullptr;
    }

    Iterator begin() const
    {
        return Iterator(guard->next);
    }
    Iterator end() const
    {
        if (guard->next == nullptr)
        {
            return Iterator(guard->next);
        }
        return Iterator(guard->prev->next);
    }

private:
    // head = next, prev = tail
    Node *guard;
};

#endif