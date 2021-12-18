CO = g++
CFLAGS = -std=c++11
DIR = Zestaw01

.PHONY: all clean tar

# $@ wstawia w miejsce zmiennej nazwę targetu
# $< wstawia w miejsce zmiennej pierwszy prerekwizyt
# $^ wstawia w miejsce zmiennej wszystkie prerekwizyty


%.x: %.o ArrayStack.o
	$(CO) $(CFLAGS) $^ -o $@

%.o: %.cpp ArrayStack.hpp
	$(CO) $(CFLAGS) -c $<

all: Generator.x Stack.x ONP.x

clean:
	rm -f *.x *.out *.o

tar: clean
	cd ../; tar -cvzf Daniel_Krzyzak_$(DIR).tar.gz $(DIR)
