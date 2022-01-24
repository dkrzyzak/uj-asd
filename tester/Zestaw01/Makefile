# Kompilator i jego flagi 
CXX				:= g++
CXX_FLAGS		:= -Wall -pedantic -O3

# Glowne pliki 
STACK			:= Stack
ONP				:= ONP
GENERATOR		:= Generator

# Testowanie 
#MOVE_SEMANTICS 		:= move_semantics


# Struktury 
LINKED_STACK	:= LinkedStack
ARRAY_STACK		:= ArrayStack
										# Testowanie
all: $(STACK).x $(ONP).x $(GENERATOR).x # $(MOVE_SEMANTICS).x

# Tworzenie plikow wykonywalnych 
%.x: %.o $(LINKED_STACK).hpp $(ARRAY_STACK).hpp
	$(CXX) $(CXX_FLAGS) $< -o $@ 

# Tworzenie plikow obiektowych 
%.o: %.cpp $(LINKED_STACK).hpp $(ARRAY_STACK).hpp
	$(CXX) $(CXX_FLAGS) $< -c -o $@

.PHONY: all clean

# Funkcja do usuwania elementow wykonywalnych
clean:
	rm *.x
