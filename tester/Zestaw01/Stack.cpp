#include "ArrayStack.hpp"

#define MAX 1000000

int main() {
    int n, value;
    char op;
    Stack<uint32_t, MAX> stack;
    std::cin >> n;
    for(int i=0; i<n; i++) {
        std::cin >> op;
        try {
            switch(op) {
            case 'A':
                std::cin >> value;
                stack.push(value);
                break;

            case 'D':
                std::cout << stack.pop() << std::endl;
		break;

            case 'S':
                std::cout << stack.size() << std::endl;
                break;

            }
        }
	
        catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }

}
