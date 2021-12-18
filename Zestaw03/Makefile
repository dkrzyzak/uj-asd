CO = g++
CFLAGS = -std=c++11
DIR = Zestaw03

.PHONY: all clean tar

# $@ wstawia w miejsce zmiennej nazwę targetu
# $< wstawia w miejsce zmiennej pierwszy prerekwizyt
# $^ wstawia w miejsce zmiennej wszystkie prerekwizyty

%.x: %.o
	$(CO) $(CFLAGS) $^ -o $@

%.o: %.cpp LinkedList.hpp
	$(CO) $(CFLAGS) -c $<

all: Generator.x LinkedList.x

clean:
	rm -f *.x *.out *.o

tar: clean
	cd ../; tar -cvzf Daniel_Krzyzak_$(DIR).tar.gz $(DIR)
