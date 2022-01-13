CO = g++
CFLAGS = -std=c++11 -Wall
DIR = Zestaw07

.PHONY: all clean tar

# $@ wstawia w miejsce zmiennej nazwę targetu
# $< wstawia w miejsce zmiennej pierwszy prerekwizyt
# $^ wstawia w miejsce zmiennej wszystkie prerekwizyty

%.x: %.o
	$(CO) $(CFLAGS) $^ -o $@

%.o: %.cpp Dict.hpp
	$(CO) $(CFLAGS) -c $<

all: Dict.x

run: Dict.x
	./Dict.x pairs.txt < input.txt > output.txt
	diff -s output.txt result.txt


clean:
	rm -f *.x *.out *.o

tar: clean
	cd ../; tar -cvzf Daniel_Krzyzak_$(DIR).tar.gz $(DIR)
