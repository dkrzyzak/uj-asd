CO = g++
CFLAGS = -std=c++11 -Wall
DIR = Zestaw07

.PHONY: all clean tar

# $@ wstawia w miejsce zmiennej nazwę targetu
# $< wstawia w miejsce zmiennej pierwszy prerekwizyt
# $^ wstawia w miejsce zmiennej wszystkie prerekwizyty

%.x: %.o
	$(CO) $(CFLAGS) $^ -o $@

%.o: %.cpp Dict.hpp LZW.hpp LinkedList.hpp
	$(CO) $(CFLAGS) -c $<

all: LZW.x

run: LZW.x
	./LZW.x

clean:
	rm -f *.x *.out *.o

tar: clean
	cd ../; tar -cvzf Daniel_Krzyzak_$(DIR).tar.gz $(DIR)
