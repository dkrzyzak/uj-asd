#include <iostream>
#include <random>

const int OPERATION_LIST[6] = {'F', 'B', 'f', 'b', 'R', 'S'};

thread_local std::mt19937_64 gen{std::random_device{}()};

int random(int min, int max)
{
    return std::uniform_int_distribution<int>{min, max}(gen);
}

int main(int argc, char *argv[])
{
    int n = random(1, 1000000);
    std::cout << n << std::endl;

    int randomInt;
    char operation;

    for (int i = 0; i < n; i++)
    {
        randomInt = random(0, 5);

        operation = OPERATION_LIST[randomInt];
        std::cout << operation;

        if (operation == 'F' || operation == 'B' || operation == 'b' || operation == 'f')
            std::cout << " " << (int)random(0, 1e3);
        else if (operation == 'R')
            std::cout << " " << (int)random(0, 1e3) << " " << (int)random(0, 1e3);

        std::cout << std::endl;
    }
}
