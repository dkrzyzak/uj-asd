CO = g++
CFLAGS = -std=c++11 -Wall
DIR = Zestaw04

.PHONY: all clean tar

# $@ wstawia w miejsce zmiennej nazwę targetu
# $< wstawia w miejsce zmiennej pierwszy prerekwizyt
# $^ wstawia w miejsce zmiennej wszystkie prerekwizyty

%.x: %.o
	$(CO) $(CFLAGS) $^ -o $@

%.o: %.cpp ArrayList.hpp CursorList.hpp
	$(CO) $(CFLAGS) -c $<

all: Generator.x ArrayList.x CursorList.x

clean:
	rm -f *.x *.out *.o

tar: clean
	cd ../; tar -cvzf Daniel_Krzyzak_$(DIR).tar.gz $(DIR)
