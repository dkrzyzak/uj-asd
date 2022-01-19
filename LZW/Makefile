CO = g++
CFLAGS = -std=c++11 -Wall
DIR = Zestaw07

.PHONY: all clean tar

# $@ wstawia w miejsce zmiennej nazwę targetu
# $< wstawia w miejsce zmiennej pierwszy prerekwizyt
# $^ wstawia w miejsce zmiennej wszystkie prerekwizyty

%.x: %.o
	$(CO) $(CFLAGS) $^ -o $@

%.o: %.cpp Dict.hpp LZW.hpp LinkedList.hpp FileOperations.hpp
	$(CO) $(CFLAGS) -c $<

all: LZW.x

BUFFER_SIZE = 16

runText: LZW.x
	./LZW.x test.txt c compressed.bin $(BUFFER_SIZE)
	./LZW.x compressed.bin d decompressed.txt $(BUFFER_SIZE)
	diff -s test.txt decompressed.txt
	ls -lh
	rm compressed.bin decompressed.txt

runPicture: LZW.x
	./LZW.x Wykres.png c Wykres-$(BUFFER_SIZE).bin $(BUFFER_SIZE)
	./LZW.x Wykres-$(BUFFER_SIZE).bin d Wykres-decompressed-$(BUFFER_SIZE).png $(BUFFER_SIZE)
	diff -s Wykres.png Wykres-decompressed-$(BUFFER_SIZE).png
	ls -lh
	rm Wykres-*

clean:
	rm -f *.x *.out *.o *.lzw

tar: clean
	cd ../; tar -cvzf Daniel_Krzyzak_$(DIR).tar.gz $(DIR)
