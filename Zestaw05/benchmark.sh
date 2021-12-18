#!/bin/bash

rm -f results*.txt

for i in {1..100}; do
    ./Generator.x $((i * 200)) 100000 | ./BubbleSort.x 1 >> resultsBS.txt
done

for i in {1..100}; do
    ./Generator.x $((i * 200)) 100000 | ./InsertionSort.x 1 >> resultsIS.txt
done

for i in {1..100}; do
    ./Generator.x $((i * 200)) 100000 | ./SelectionSort.x 1 >> resultsSS.txt
done
