CO = g++
CFLAGS = -std=c++11 -Wall
DIR = Zestaw05

.PHONY: all clean tar

# $@ wstawia w miejsce zmiennej nazwę targetu
# $< wstawia w miejsce zmiennej pierwszy prerekwizyt
# $^ wstawia w miejsce zmiennej wszystkie prerekwizyty

%.x: %.o
	$(CO) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(CO) $(CFLAGS) -c $<

all: Generator.x BubbleSort.x InsertionSort.x SelectionSort.x Reverse.x BubbleSortCountOperations.x

clean:
	rm -f *.x *.out *.o

tar: clean
	cd ../; tar --disable-copyfile -cvzf Daniel_Krzyzak_$(DIR).tar.gz $(DIR)
