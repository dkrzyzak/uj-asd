# Projekt zaliczeniowy - kompresja LZW

<style> body {text-align: justify} </style>

## 1. Intuicja działania algorytmu
Jest to kompresja bezstratna, a zatem żadne dane nie "giną" w procesie kompresji. Do kompresji wykorzystywany jest słownik.
Można porównać sposób działania algorytmu do tego w jaki sposób ludzie komunikują się na co dzień.

Dane do kompresji są czytane "as they go", algorytm przechodzi przez nie tylko raz, nie cofając się przy tym.
Podczas "czytania" konstruowany jest słownik zawierający pojedyncze znaki oraz grupy znaków, które pojawiają się w ciągu danych.
Jeśli algorytm napotka na ciąg znaków, który już wcześniej się pojawił, to dokonuje kompresji. Zamienia go na wartość liczbową odpowiadającą jej wartości liczbowej zapisanej w słowniku. Jeśli napotka na ciąg którego jeszcze nie ma w słowniku, to dodaje go do słownika i przypisuje mu unikalną wartość liczbową.

Słownik nie jest zapisywany razem z danymi. Dzięki temu że algorytm "nie cofa się", możemy zrekonstruować słownik odczytując z powrotem skompresowane dane, na takiej samej zasadzie. W rezultacie otrzymamy zdekompresowany ciąg znaków, który będzie identyczny (kompresja bezstratna) względem danych przed skompresowaniem.

Na podstawie zasady działania możemy wywnioskować, że algorytm będzie najbardziej efektywny dla dużej liczby powtarzających się danych. W przypadku danych całkowicie losowych kompresja może być (i najprawdopodobniej będzie) nieefektywna. W najgorszym wypadku będzie miał miejsce proces odwrotny do kompresji (patrz punkt 4).

___

## 2. Pliki w projekcie
- Dict.hpp - implementacja słownika
- LinkedList.hpp - implementacja listy wiązanej
- LZW.hpp - implementacja algorytmów kompresji i dekompresji LZW
- FileOperations.hpp - "nakładka" na implementację algorytmów, pozwalająca na operacje na plikach (kompresję do plików i dekompresję z plików)
- LZW.cpp - główny plik wykonywalny, instrukcja wykonywania poniżej

Oprócz tego standardowo Makefile i Readme.md

___

## 3. Instrukcja uruchomienia projektu
W pierwszej kolejności musimy skompilować projekt używając komendy `make` w folderze z projektem.
W wyniku kompilacji otrzymamy plik wykonywalny `LZW.x`.

Plik możemy uruchomić nie podając żadnych argumentów, wtedy zostaniemy przeprowadzeni przez kompresji/dekompresji proces krok po kroku.

Możesz też od razu podać argumenty - będą wymagane 4, w następującej kolejności:
- nazwa pliku źródłowego
- tryb algorytmu (c jak kompresja / d jak dekompresja)
- nazwa pliku wyjściowego
- rozmiar bufora w bajtach (ilość bajtów wykorzystywanych do zapisu jednej liczby)

np. `./LZW.x test.txt c compressed.lzw 2`

Dla tego przykładu dane z pliku test.txt zostaną skompresowane do pliku binarnego o nazwie compressed.lzw; do zapisu jednej liczby będziemy używać dwóch bajtów (uwaga patrz punkt 4).


Żeby następnie zdekompresować ten plik powinniśmy wykonać program LZW.x z następującymi argumentami:

`./LZW.x compressed.lzw d plikZdekompresowany.txt 2`


Ważne jest żeby ilość bajtów na których zapisujemy jedną liczbę była taka sama w przypadku kompresji i dekompresji! W przeciwnym wypadku danych nie uda się poprawnie zdekompresować!

___

## 4. Potencjalne wady implementacyjne
Główna wada dotyczy zapisu skompresowanych danych do pliku binarnego.

Zapisując liczby do pliku w trybie binarnym, używając `std::ostream::write`, musimy podać dwa argumenty wywołania funkcji.
Pierwszym z nich jest zapisywana liczba a drugim jest rozmiar bufora (w **bajtach**), czyli wielkość która informuje kompilator na ilu **bajtach** chcemy zapisać daną liczbę. Widzimy problem. 

Załóżmy że w ciągu liczbowym reprezentującym skompresowane dane, nie wystąpi liczba, której reprezentacja binarna przekraczałaby 12 znaków. Mimo tego nadal musimy zaokrąglić rozmiar bufora w górę do najbliższej wielokrotności liczby 8, czyli do każdej z liczb dostajemy padding rozmiaru co najmniej 4 bitów. 

Można ten problem obejść w niespecjalnie zgrabny, ale efektywny sposób, stosując operacje bitowe, natomiast z racji na poziom skomplikowania tego przedsięwzięcia, zdecydowałem się nie implementować rozwiązania tego problemu, a jedynie zostawić notatkę, że jest to *known issue*.

Z tego jednak względu warto mieć na uwadze, że mogą mieć miejsce sytuacje w których "skompresowany" plik będzie ważył więcej niż oryginalny, co jest sprzeczne z ideą kompresji. 

