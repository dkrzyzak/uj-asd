CO = g++
CFLAGS = -std=c++11
DIR = Zestaw02

.PHONY: all clean tar

# $@ wstawia w miejsce zmiennej nazwę targetu
# $< wstawia w miejsce zmiennej pierwszy prerekwizyt
# $^ wstawia w miejsce zmiennej wszystkie prerekwizyty

%.x: %.o
	$(CO) $(CFLAGS) $^ -o $@

%.o: %.cpp ArrayQueue.hpp LinkedQueue.hpp
	$(CO) $(CFLAGS) -c $<

all: Generator.x Queue.x Radix.x

clean:
	rm -f *.x *.out *.o

tar: clean
	cd ../; tar -cvzf Daniel_Krzyzak_$(DIR).tar.gz $(DIR)
