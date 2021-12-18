# Zestaw 2

## Instrukcja kompilacji
Aby skompilować wszystkie programy, należy wywołać komendę `make` w głównym folderze

## Instrukcja użycia programów
### Generator.cpp
Program generuje N losowo wybranych operacji na kolejce po wywołaniu go komendą `./Generator.x`
Operacje to 
- `A x` (add x) - dodanie do kolejki liczby x
- `D` (delete) - zdjęcie z kolejki najmłodszego elementu
- `S` (size) - podanie rozmiaru kolejki

### Queue.cpp
Dane z programu Generator do programu Queue przekazujemy używając komendy `./Generator.x | ./Queue.x`
Program wczytuje ze standardowego wejścia zadane operacje, a następnie wykonuje je na implementacji kolejki z pliku `ArrayQueue.cpp`

### Radix.cpp
Program uruchamiamy komendą `./Radix.x`. Program wczytuje ze standardowego wejścia ciąg nieujemnych liczb całkowitych z zakresu `[0, 10^9)`, a następnie sortuje je przy użyciu algorytmu sortowania pozycyjnego poznanego w trakcie zajęć

## Odpowiedzi na pytania

### Trzy sposoby obsługi cykliczności bufora (używając tablicy)
1. używając indexów write/tail i read/head z maskowaniem (mogą przyjmować wartości tylko [0, capacity - 1])
- wstawiając element, trafia on na pozycję `write`, a następnie `write` jest inkrementowane i maskowane
- wyciągając element, bierzemy go z pozycji `read` a następnie `read` inkrementujemy i maskujemy

2. Używając indexu read oraz zmiennej trzymającej bieżący rozmiar kolejki 

3. Używając indexów read i write bez maskowania (mogą przyjmować wartości naturalne)
- z każdym pushem zwiększamy zmienną `write` o 1, ale odczytując wartość z kolejki podajemy index `write % capacity`
- z każdym popem zwiększamy `read` o 1, ale odczytując wartość również maskujemy wartość `read`


write/tail wskazuje na index, pod który wstawić nowy element
read/head wskazuje na index, z którego odczytać kolejny element z kolejki

### Przykłady zastosowania kolejki
- strony z rezerwacjami biletów - użytkownik ma przydzielane unikalne id, które trafia do kolejki w momencie gdy wyrazi on chęć kupienia biletu. Użytkownicy po kolei mają szanse na zakup biletu, tak jak przy fizycznych kasach, aż do momentu kiedy liczba biletów się nie wyczerpie.
- różnego rodzaju bufory danych (dane wchodzą i wychodzą w kolejności pojawiania się)
- semafory (poznane na SO w zeszłym semestrze)
- większość serwerów - zasada First Come First Serve
- kolejkowanie tasków dla procesora
- call center - jeśli wszyscy konsultanci są zajęci, to każdy kolejny dzwoniący zostanie dodany do kolejki
- algorytm sortowania pozycyjnego

### `std::queue::emplace`
Funkcja ta, podobnie jak `std::queue::push` dodaje nowy element na koniec kolejki, ale w przeciwieństwie do push, emplace konstruuje ten element zamiast kopiować i wstawiać istniejący już element. Argumenty przyjmowane przez emplace, to argumenty które zostaną przekazane do konstruktora obiektu.

```cpp
class C {
    private:
    int value;

    public:
    C(int arg) {
        value = arg;
    }

    int getValue() {
        return value;
    }
};

int main(int argc, char const *argv[]) {
    queue<C> q;
    
    q.emplace(12); // 12 trafia do konstruktora klasy C i tworzony jest nowy obiekt tej klasy, który trafia na koniec kolejki 

    C obiektKlasyC = q.front(); // kopiujemy pierwszy element kolejki do zmiennej obiektKlasyC

    cout << obiektKlasyC.getValue(); // zwraca 12

    return 0;
}

```


### Skróty
- LIFO == Last In First Out - element który ostatni został dodany do struktury, pierwszy go opuszcza (np stos)
- FIFO == First In First Out - element który pierwszy został dodany do struktury, pierwszy go opuszcza (np kolejka)
