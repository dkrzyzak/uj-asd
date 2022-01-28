#ifndef DICTIONARY
#define DICTIONARY

#include <iostream>
#include <cstring>
#include "LinkedList.hpp"

using namespace std;

template<class K, class V>
class Dict {
    using Pair = pair<K, V>;
    private:
    const static int hashGroups = 1009;
    List<Pair> table[hashGroups];

    unsigned int generateHash(const K& key) {
        unsigned int hash = 1;
        int prime = 31;

        for (const char& s : key) {
            hash = ((hash + (int)s) * prime) % hashGroups;
        }

        return hash;
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
            List<Pair>& cell = table[i];
            cell.clear();
        }

    };

    // Dodaje parę klucz-wartość do słownika
    bool insert(const Pair& p) {
        int hashValue = generateHash(p.first);
        List<Pair>& cell = table[hashValue];
        
        bool keyExists = false;
        
        auto el = cell.head.next;
        for (int i = 0; i < cell.size(); i++) {
            if (el->x.first == p.first) {
                keyExists = true;
                el->x.second = p.second;
                break;
            }
            el = el->next;
        }

        if (!keyExists) {
            Pair newPair(p.first, p.second);
            cell.push_back(newPair);
        }

        return keyExists;
    }; 

    // Sprawdza czy słownik zawiera klucz
    bool find(const K& k, int hashValue = 0) {
        if (hashValue == 0) {
            hashValue = generateHash(k);
        }

        List<Pair>& cell = table[hashValue];

        auto el = cell.head.next;
        for (int i = 0; i < cell.size(); i++) {
            if (el->x.first == k) {
                return true;
            }

            el = el->next;
        }

        return false;
    }

    // Zwraca wartość dla klucza
    V& operator[](const K& k) {
        int hashValue = generateHash(k);
        List<Pair>& cell = table[hashValue];

        auto el = cell.head.next;
        for (int i = 0; i < cell.size(); i++) {
            if (el->x.first == k) {
                return el->x.second;
            }

            el = el->next;
        }

        Pair newPair(k, V());
        cell.push_back(newPair);

        return cell.back().second;
    }

    // Usuwa parę od danym kluczu
    bool erase(const K& k) {
        int hashValue = generateHash(k);
        List<Pair>& cell = table[hashValue];

        auto el = cell.head.next;
        for (int i = 0; i < cell.size(); i++) {
            if (el->x.first == k) {
                cell.erase(i);
                return true;
            }

            el = el->next;
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
        cout << "# " << size() << " ";

        int smallestTableSize = 0;
        int biggestTableSize = 0;
        int classesCount = 0;

        for (int i = 0; i < hashGroups; i++) {
            int size = table[i].size();

            if (size > 0) {
                classesCount++;

                if (size > biggestTableSize) biggestTableSize = size;
                if (size < smallestTableSize) smallestTableSize = size;
            }

            
        }

        cout << classesCount << " " << smallestTableSize << " " << biggestTableSize << endl;
    }
};

#endif