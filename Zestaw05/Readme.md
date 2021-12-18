# Zestaw 5

## Instrukcja kompilacji
Aby skompilować wszystkie programy, należy wywołać komendę `make` w głównym folderze

## Instrukcja użycia programów
### Generator.cpp
Program generuje N losowo wybranych liczb z przedziału 1 do MAX po wywołaniu go komendą `./Generator.x N MAX`

### BubbleSort.cpp
Program wczytuje dane wejściowe ze standardowego wejścia do wektora przechowującego dane typu int. Następnie wczytane dane są sortowane funkcją sort, która implementuje algorytm sortowania bąbelkowego. Następnie na wyjściu jest zwracany posortowany wektor - elementy wypisywane są w kolejności niemalejącej.

### BubbleSortCountOperations.cpp 
Zmodyfikowana wersja algorytmu sortowania bąbelkowego, która na wyjściu zwraca tylko ilość wykonanych dominujących operacji

### InsertionSort.cpp
Program wczytuje dane wejściowe ze standardowego wejścia do wektora przechowującego dane typu int. Następnie wczytane dane są sortowane funkcją sort, która implementuje algorytm sortowania przez wstawianie. Następnie na wyjściu jest zwracany posortowany wektor - elementy wypisywane są w kolejności niemalejącej.

### SelectionSort.cpp
Program wczytuje dane wejściowe ze standardowego wejścia do wektora przechowującego dane typu int. Następnie wczytane dane są sortowane funkcją sort, która implementuje algorytm sortowania przez wybieranie. Następnie na wyjściu jest zwracany posortowany wektor - elementy wypisywane są w kolejności niemalejącej.


## Programy pomocniczne

### benchmark.sh
Skrypt w bashu, który uruchamia 3 algorytmy sortowania 100-krotnie w pętli, z każdą iteracją zwiększając ilość danych wejściowych o 100. Program na końcu wykonywania wpisuje wyniki (czas sortowania dla rozmiaru danych wejściowych) do pliku tekstowego
Zakres losowanych danych jest zawsze ten sam: od 1 do 10^6

### average.sh
Skrypt w bashu generujący dwa pliki (liczba operacji, czas wykonywania dla zbioru 1000 danych), z których potem liczona jest złożoność średnia oraz wrażliwość.

### drawGraph.py
Kod do rysowania wykresu na podstawie danych wygenerowanych przez benchmark

### complexity.py
Kod do szybkiego wyliczania złożoności oraz wrażliwości zestawu danych z pliku

### Reverse.cpp
Program do szybkiego odwracania tablicy - przydatny do odwracania gotowych posortowanych danych poprzez
`./Reverse.x < sortedData > sortedReversedData`

## Odpowiedzi na pytania
Złożoność obliczeniowa dla sortowania bąbelkowego

Optymistyczna (dla posortowanej tablicy) - pętla zostanie wykonana tylko raz, nie zostanie wykonane żadna podmiana;
ilość porównań - O(n)
ilość zamian - O(1) (a dokładniej 0)

Pesymistyczna (dla tablicy która jest posortowana, ale malejąco)
ilość porównań - O((n^2/2) - (n/2)) -> O(n^2)
ilość podmian - również O(n^2)

Średnia (oczekiwana) dla zestawu danych wejściowych rozmiaru 1000:
Złożoność oczekiwana operacji porównywania:  4864.44
Złożoność oczekiwana operacji zamieniania:  2420.96

Miara wrażliwości pesymistycznej dla zestawu danych wejściowych rozmiaru 1000 wyniosła  6.066999999999999
