#include <iostream>
#include <list>
#include <cstring>
#include <unordered_map>

using namespace std;

template<class K, class V>
class Dict {
    using Pair = pair<K, V>;
    private:
    const static int hashGroups = 100;
    list<Pair> table[hashGroups];
    hash<K> hasher;
    V fallbackValue;

    int hashFunction(const K& key, int hashTableSize = hashGroups) {
        return hasher(key) % hashTableSize;
    }

    void resize() {
        list<Pair> oldData[hashGroups];
        copy(begin(table), end(table), begin(oldData));

        int newHashGroupSize = hashGroups * 2;
        table = new list<Pair>[newHashGroupSize];

        for (int i = 0; i < hashGroups; i++) {
            auto& cell = oldData[i];

            for (auto bIterator = begin(cell); bIterator != end(cell); bIterator++) {
                int index = hashFunction(bIterator->first, newHashGroupSize);
                table[index].emplace_back(bIterator->first, bIterator->second);
            }
        }
    
    }

    public:
    // Konstruktor
    Dict() {

    };

    ~Dict() {
        clear();
    }

    // Czyści słownik
    void clear() {
        for (int i = 0; i < hashGroups; i++) {
            list<Pair> cell = table[i];
            cell.clear();
        }
    
    };

    // Dodaje parę klucz-wartość do słownika
    bool insert(const Pair& p) {
        int hashValue = hashFunction(p.first);
        auto& cell = table[hashValue];
        
        bool keyExists = false;
        for (auto bIterator = begin(cell); bIterator != end(cell); bIterator++) {
            if (bIterator->first == p.first) {
                keyExists = true;
                bIterator->second = p.second;
                break;
            }
        }

        if (!keyExists) {
            cell.emplace_back(p.first, p.second);
        }

        // double loadFactor = (double)size() / (double)hashGroups;
        // cout << "load factor: " << loadFactor << endl;
        // if (loadFactor > 0.75) {
        //     resize();
        // }

        return keyExists;
    }; 

    // Sprawdza czy słownik zawiera klucz
    bool find(const K& k) {
        int hashValue = hashFunction(k);
        auto& cell = table[hashValue];
      
        for (auto bIterator = begin(cell); bIterator != end(cell); bIterator++) {
            if (bIterator->first == k) {
                return true;
            }
        }

        return false;
    }

    // Zwraca wartość dla klucza
    V& operator[](const K& k) {
        int hashValue = hashFunction(k);
        auto& cell = table[hashValue];
      
        for (auto bIterator = begin(cell); bIterator != end(cell); bIterator++) {
            if (bIterator->first == k) {
                return bIterator->second;
            }
        }
        
        cell.emplace_back(k, nullptr);
        return fallbackValue;
    }

    // Usuwa parę od danym kluczu
    bool erase(const K& k) {
        int hashValue = hashFunction(k);
        auto& cell = table[hashValue];
        
        for (auto bIterator = begin(cell); bIterator != end(cell); bIterator++) {
            if (bIterator->first == k) {
                bIterator = cell.erase(bIterator);
                cout << "Pair removed" << endl;
                return true;
            }
        }

        return false;
    }

    // Zwraca liczbę par
    int size() {
        int sum = 0;
        for (int i = 0; i < hashGroups; i++) {
            sum += table[i].size();
        }

        return sum;
    } 

    // Sprawdza czy słownik jest pusty
    bool empty() {
        return size() == 0;
    }; 

    // Wypisuje informację o słowniku (patrz poniżej)
    void buckets() {
        
    }
};
