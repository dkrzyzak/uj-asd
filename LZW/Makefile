CO = g++
CFLAGS = -std=c++11 -Wall
DIR = LZW

.PHONY: all clean tar

# $@ wstawia w miejsce zmiennej nazwę targetu
# $< wstawia w miejsce zmiennej pierwszy prerekwizyt
# $^ wstawia w miejsce zmiennej wszystkie prerekwizyty

%.x: %.o
	$(CO) $(CFLAGS) $^ -o $@

%.o: %.cpp Dict.hpp LZW.hpp LinkedList.hpp FileOperations.hpp
	$(CO) $(CFLAGS) -c $<

all: LZW.x

# Poniżej znajdują się komendy używane do testowania poprawności programu LZW.x
# rozmiar bufora w bajtach
BUFFER_SIZE = 2

# Testowanie kompresji plików tekstowych
TEXT_FILE_NAME = test.txt

runText: LZW.x
	./LZW.x $(TEXT_FILE_NAME) c compressed.bin $(BUFFER_SIZE)
	./LZW.x compressed.bin d decompressed.txt $(BUFFER_SIZE)
	diff -s $(TEXT_FILE_NAME) decompressed.txt
	ls -lh
	rm compressed.bin decompressed.txt


# Testowanie kompresji plików graficznych
PIC_NAME = image
PIC_EXT = jpeg

runPicture: LZW.x
	./LZW.x $(PIC_NAME).$(PIC_EXT) c $(PIC_NAME)-$(BUFFER_SIZE).bin $(BUFFER_SIZE)
	./LZW.x $(PIC_NAME)-$(BUFFER_SIZE).bin d $(PIC_NAME)-decompressed-$(BUFFER_SIZE).$(PIC_EXT) $(BUFFER_SIZE)
	diff -s $(PIC_NAME).$(PIC_EXT) $(PIC_NAME)-decompressed-$(BUFFER_SIZE).$(PIC_EXT)
	ls -lh
	rm $(PIC_NAME)-*

clean:
	rm -f *.x *.out *.o *.lzw *.bin

tar: clean
	cd ../; tar -cvzf Daniel_Krzyzak_Projekt_$(DIR).tar.gz $(DIR)
