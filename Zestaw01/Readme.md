# Zestaw 1

## Instrukcja kompilacji
Aby skompilować dany program, nalezy wywołać komendę `make {NazwaProgramu}.x`, gdzie nazwa programu to
- Generator (program generujący dane wejściowe do programu Stack)
- Stack (program wykorzystujący implementację stosu i sprawdzający jej poprawność)
- ONP (program zamieniający zapis infixowy na zapis postfixowy przy użyciu stosu - dokładny opis działania algorytmu zawarty w komentarzach wewnątrz pliku ONP.cpp)

## Instrukcja użycia programów
## Generator.cpp
Program generuje N losowo wybranych operacji na stosie po wywołaniu i podaniu liczby N `./Generator.x N`
Operacje to 
- `A x` (add x) - dodanie na stos liczby x
- `D` (delete) - zdjęcie ze stosu najmłodszego elementu
- `S` (size) - podanie rozmiaru stosu

### Stack.cpp
Aby program zadziałał poprawnie, musimy najpierw mieć skompilowany program Generator (`Generator.x`)
Dane z programu Generator do programu Stack przekazujemy używając komendy `./Generator.x N | ./Stack.x` gdzie N jest obligatoryjną liczbą operacji które chcemy wykonać na stosie
Program zczytuje ze standardowego wyjścia zadane operacje, a następnie wykonuje je na implementacji stosu z pliku `ArrayStack.cpp`

## ONP.cpp
Program uruchamiamy komendą `./ONP.x`. Program po uruchomieniu prosi o wprowadzenie operacji matematycznej w zapisie infixowym,
a jako output, program zwraca tą samą operację, ale przekonwertowaną na zapis ONP.

Ważne jest aby każda operacja była otoczona nawiasami, tak żeby kolejność wykonywania działań nie musiała być dodatkowo weryfikowana przez program.

## Odpowiedzi na pytania

### Przykłady zastosowania stosu
- obliczanie wartości wyrażeń matematycznych w zapisie postfixowym (omawiane na lekcji)
- wykonywanie programu (dodawanie wykonywanych operacji na stos)
- edytory tekstowe - operacja ctrl + z - dodanie na stos kazdej kolejnej zmiany dokonanej przez uzytkownika, i "zdejmowanie" ich ze stosu w momencie naciśnięcia wymienionej kombinacji klawiszy
- przeglądarki internetowe - klawisz wstecz - przejścia między stronami dodają nowo otwartą stronę na stos, przejście wstecz usuwa stronę ze stosu

### Implementacja std::stack
`.pop()` nie zwraca wartości ani referencji do elementu, ponieważ nie zawsze jest to potrzebne, a zatem byłoby to nieefektywne (z punktu widzenia pamięci) i warto jest rozgraniczyć te dwie operacje, tak żeby mieć większą elastyczność podczas korzystania z tej implementacji
Jeśli chcemy pobrać wartość elementu będącego "na górze" stosu, to powinniśmy wywołać na stosie metodę `.top()`
