#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

#include "./ArrayList.hxx"

void parseNumbers(int howMuch, std::string input, int *storage)
{
    int i = 0;

    input = input.substr(2);

    std::stringstream stream(input);

    while (i != howMuch)
    {
        stream >> storage[i];
        i++;
        if (!stream)
            break;
    }
}

int main(int argc, char *argv[])
{
    const int size = 1000;
    // inaczej nie czyta np. 1e6 tylko interpretuje jako 1. double naprawia ten problem
    double n;

    std::cin >> n;

    // parametry z template muszą byc zdefiniowane at compile-time
    ArrayList<int, size> l1;
    std::string input;

    int storage[2] = {-1, -1};

    int i = -1;
    while (i < n)
    {
        std::getline(std::cin, input);

        char operation = input[0];

        if (operation == 'F')
        {
            parseNumbers(1, input, storage);
            try
            {
                l1.push_front(storage[0]);
            }
            catch (const std::out_of_range &err)
            {
                // skip
            }
        }
        else if (operation == 'B')
        {
            parseNumbers(1, input, storage);

            try
            {
                l1.push_back(storage[0]);
            }
            catch (const std::out_of_range &err)
            {
                // skip
            }
        }
        else if (operation == 'f')
        {
            if (l1.empty())
                std::cout << "EMPTY" << std::endl;
            else
                std::cout << l1.pop_front() << std::endl;
        }
        else if (operation == 'b')
        {
            if (l1.empty())
                std::cout << "EMPTY" << std::endl;
            else
                std::cout << l1.pop_back() << std::endl;
        }
        else if (operation == 'R')
        {
            parseNumbers(2, input, storage);

            auto pos = l1.find(storage[0]);

            if (pos == nullptr)
                std::cout << "FALSE" << std::endl;
            else
            {
                *pos = storage[1];
                std::cout << "TRUE" << std::endl;
            }
        }
        else if (operation == 'S')
        {
            std::cout << l1.size() << std::endl;
        }

        i++;
    }
}