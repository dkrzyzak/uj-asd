#include <iostream>
#include <string>
#include "ArrayStack.hpp"

using namespace std;

int main(int argc, char const *argv[]) {
    string infix;
    getline(cin, infix); //getline, bo używając samego cin spacja jest znakiem terminującym
    string postfix;
    ArrayStack onpStack = ArrayStack(infix.size());

    for(string::size_type i = 0; i < infix.size(); i++) {
        switch (infix[i]) {
            // nawias otwierający wrzucamy na stos
            case '(':
                onpStack.push((int)infix[i]);
                break;
            
            // jeśli napotkamy nawias zamykający, to zaczynamy zrzucać operatory ze stosu
            case ')':
                // robimy tak dopoki nie trafimy na nawias otwierajacy
                char operation;
                while((operation = (char)onpStack.pop()) != '(') {
                    // spacja przed operatorem
                    postfix += ' ';
                    postfix += operation;
                }
                break;
            
            case '+':
            case '-':
            case '*':
            case '/':
                postfix += ' ';
                onpStack.push((int)infix[i]);
                break;

            // pomijamy spacje
            case ' ':
                break;

            default:
                // liczby dopisujemy od razu do stringa wyjściowego
                postfix += infix[i];
                break;
        }
    }

    // gdy skończymy iterować po znakach ze stringa wejściowego, to musimy jeszcze zrzucić ze stosu ewentualne pozostałe tam operatory
    while(!onpStack.empty()) {
        char operation = onpStack.pop();
        if (operation != '(') {
            postfix += operation;
        }
    }

    cout << postfix << endl;

    return 0;
}
