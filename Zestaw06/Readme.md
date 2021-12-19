# Zestaw 6

## Instrukcja kompilacji
Aby skompilować wszystkie programy, należy wywołać komendę `make` w głównym folderze

## Instrukcja użycia programów
### BinaryTree.hpp
Implementacja drzewa binarnego, na którym można wykonać następujące operacje:
- insert(x) - wstawia element x do drzewa
- search(x), searchRecursive(x) - sprawdza czy element należy do drzewa, zwraca wskaźnik do węzła lub nullptr. Napisać wersję iteracyjną i rekurencyjną
- size() - zwraca liczbę węzłów
- minimum() - zwraca wartość najmniejszego elementu
- maximum() - zwraca wartość największego elementu
- depth() - zwraca wysokość drzewa
- inorder(), preorder(), postorder() - wypisuje zawartość wszystkich węzłów odpowiednio w porządku inorder, preorder i postorder. Wykorzystać rekurencje.

### BinaryTree.cpp
Program który wykorzystuje napisaną implementację drzewa binarnego.
#### Dane wejściowe należy do niego dostarczyć w następującej postaci:
- W pierwszym wierszu znajduje się liczba całkowita n
- W kolejnych n wierszach znajdują się liczby, które należy wstawić do drzewa BST - zgodnie z
jego własnością.

#### Program wypisuje na standardowe wyjście
- W pierwszej linii wypisać liczbę elementów (size), wysokość drzewa (depth), element minimalny (minimum) i element maksymalny (maximum).
- W kolejnych n liniach wypisać elementy w porządku preorder (preorder).
- W ostatnich 9-ciu liniach dla liczb od 1 do 9 wypisać “Yes”, gdy należy ona do drzewa lub “No” w przeciwnym wypadku (search).

## Pytania
- Jakie operacje są relatywnie szybko wykonywane na drzewie BST,porównaj złożoności czasowe z innymi strukturami danych.
- Na czym polega iteracyjne przechodzenie drzewa bez użycia rekurencji?
- W jaki sposób można użyć drzewo BST do sortowania elementów? Wskaż podobieństwo do wcześniej poznanego algorytmu sortowania. Omów wady takiego rozwiązania.
- Na czym polega przechodzenie drzewa preorder?
- Na czym polega przechodzenie drzewa inorder? Jaka będzie kolejność wypisywanych elementów?
- Na czym polega przechodzenie drzewa postorder,