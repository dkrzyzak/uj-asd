# Zestaw 4

## Instrukcja kompilacji
Aby skompilować wszystkie programy, należy wywołać komendę `make` w głównym folderze

## Instrukcja użycia programów
### Generator.cpp
Program generuje N losowo wybranych operacji na kolejce po wywołaniu go komendą `./Generator.x`
Operacje to 
- `F x` - wstaw liczbę 0 ≤ x ≤ 10^3 na początek listy (ang. front)
- `B x` - wstaw liczbę 0≤ x ≤10^3 na koniec listy (ang.back)
- `f` - usuń z listy pierwszy element i go wypisz, jeśli lista jest pusta wypisz “EMPTY”
- `b` - usuń z listy ostatni element i go wypisz, jeśli lista jest pusta wypisz “EMPTY”
- `R x y` - jeżeli x nie jest obecny w liście wypisz FALSE, w przeciwnym razie zastąp pierwsze
wystąpienie wartości x przez y i wypisz TRUE (ang. replace)
- `S` - wypisz rozmiar listy

### ArrayList.cpp
Dane z programu Generator do programu ArrayList.cpp przekazujemy używając komendy `./Generator.x | ./ArrayList.x`
Program wczytuje ze standardowego wejścia zadane operacje, a następnie wykonuje je na implementacji listy z pliku `ArrayList.hpp`

### CursorList.cpp
Dane z programu Generator do programu CursorList.cpp przekazujemy używając komendy `./Generator.x | ./CursorList.x`
Program wczytuje ze standardowego wejścia zadane operacje, a następnie wykonuje je na implementacji listy z pliku `CursorList.hpp`

## Odpowiedzi na pytania

Jakie są zalety implementacji wskaźnikowej, a jakie implementacji tablicowej? Jakie są zalety implementacji kursorowej?

Implementacji tablicowej:
- zajmuje mniej miejsca w pamięci (w przypadku wskaźnikowej każdy element trzyma też adres kolejnego i poprzedniego elementu)
- szybciej możemy przeszukać listę (jeśli z góry znamy jej rozmiar, bo wtedy każdy kolejny index jest oddalony o stałą jednostkę pamięci od drugiego)

Implementacji wskaźnikowej:
- dynamiczny rozmiar - nie musimy z góry definiować ile max. elementów będzie przetrzymywać lista
- operacje wstawiania zarówno na początek jak i na koniec listy są rzędu O(1)
- wstawianie elementu do środka jest względnie mało kosztowne (w przypadku tablicowej musimy zoffsetować całą tablicę o 1 w prawo od wstawianego miejsca)

Implementacji kursorowej:
- operacje wstawiania zarówno na początek jak i na koniec listy są rzędu O(1)
- wstawianie elementu do środka jest względnie mało kosztowne (nie musimy kopiować całej tablicy na prawo od wstawianego indeksu, a jedynie musimy dotrzeć do tego indeksu i następnie przepiąć odpowiednie wskaźniki)
- zajmuje mniej miejsca w pamięci niż lista wskaźnikowa