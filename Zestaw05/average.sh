#!/bin/bash

rm -f average*.txt

for i in {1..100}; do
    ./Generator.x 1000 100000 | ./BubbleSortCountOperations.x >> averageComplexityForBS.txt
done

for i in {1..100}; do
    ./Generator.x 1000 100000 | ./BubbleSort.x 1 >> averageTimeForBS.txt
done
