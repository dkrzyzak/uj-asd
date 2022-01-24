#include "LinkedStack.hpp"
#include <sstream>

// Funkcja sprawdzajaca priorytet operatora
int priorytet(const char& op) {
    if(op == '(')
        return 0;
    if(op == '+' || op == '-')
        return 1;
    return 2;
}

int main() {
    std::string Line, element, result = "";
	
	// Wczytaj linie
    std::getline(std::cin, Line);
    std::stringstream sstream(Line);
    
    Stack <std::string> stack;
    
	// Za pomoca sstream i delimitera podziel linie z wejscia na pojedyncze operatory i liczby
    while(std::getline(sstream, element, ' ')) {
        // Jeżeli znak to ( zapisz go na stos
        if(element[0] == '(') {
            stack.push("(");
        }
		
        // W przeciwnym wypadku ->
        else {
            
			// Jeżeli znak to ) zdejmuj ze stosu dopóki nie dojdziesz do (
            if(element[0] == ')') {
                while(stack.top()[0] != '(') {
                    //std::cout << stack.pop() << " ";
                    result += stack.pop() + ' ';
                }
                
				// Usun ( ze stosu
                stack.pop();
            }
            
			// W przeciwnym wypadku ->
            else {
                
				// Jeżeli znak jest operatorem to
                if(element[0] == '+' || element[0] == '-' || element[0] == '*' || element[0] == '/') {
                    
					// Jeżeli stos nie jest pusty to
                    while(!stack.empty()) {
                        
						// Jeżeli operator ma priorytet wyższy niż ten na stosie to przerwij pętle
                        if(priorytet(element[0]) == 2 || (priorytet(element[0]) > priorytet(stack.top()[0]))) {
                            break;
                        }
                        
						// Zdejmuj operatory ze stosu
                        result += stack.pop() + ' ';
                        //std::cout << stack.pop() << " ";
                    }
                    
					// Wstaw nowy operator na stos
                    stack.push(element);
                }
                
				// W przeciwnym wypadku ->
                else {
                    
					// Wypisz znak
                    //std::cout << element << " ";
                    result += element;
                    result += ' ';
                }
            }
        }
    }
    result = result.substr(0, result.length()-1);
    std::cout << result << std::endl;
    std::cout << result.length();
    return 0;
}
