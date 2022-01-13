# Zestaw 7

## Instrukcja kompilacji
Aby skompilować wszystkie programy, należy wywołać komendę `make` w głównym folderze

## Instrukcja użycia programów
### Dict.hpp
Implementacja słownika, którego implementacja spełnia następujące założenia:

• Funkcja insert zwraca true jeżeli dodano nową parę lub false jeżeli para o danym kluczu już istnieje w słowniku
• Funkcja find zwraca true jeżeli para o kluczu k znajduje się w słowniku
• Operator [] zwraca referencję do nowej lub istniejącej wartości odpowiadającej kluczowi
• Funkcja erase zwraca true jeżeli usunięto parę o danym kluczu
• Funkcja buckets wypisuje na standardowe wyjście: znak ‘#’, liczbę elementów w słowniku,
liczbę klas, rozmiar najkrótszej i najdłuższej listy w klasach. Wszystkie wartości mają być wypisane w jednej linii zakończonej znakiem końca linii i oddzielone spacją.

Program Dict.x powinien wczytać do słownika Dict<std::string, std::string> pary słów z pliku o nazwie podanej jako argument linii komend (argv[1]).
Następnie wczytać słowa (klucze) ze standardowego wejścia. Jeżeli para o danym kluczu istnieje w słowniku należy wypisać odpowiadającą mu wartość, a w przeciwnym wypadku wypisać -.


### Dict.cpp
Program który wykorzystuje napisaną implementację słownika.


