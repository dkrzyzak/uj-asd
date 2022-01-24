#include <iostream>
#include <stdlib.h>
#include <time.h>

#define MIN_O 0
#define MAX_O 1000000

int main(int argc, char **argv) {
    
	uint32_t N;

	// Sprawdz czy podano argument wejsciowy
	if(argc != 2) {
		printf("Usage: %s ilosc_losowych_operacji\n", argv[0]);
		return -1;
	} 
	else {
		// Sprawdz czy podany element jest liczba
		int NoOperations = strtol(argv[1], nullptr, 10);
		if(NoOperations == 0) {
			printf("Niepoprawne dane\n");
			return -1;
		}
		N = NoOperations;
	}

  
    char OP[3] = {'A', 'D', 'S'};

    // Losowanie seeda
    srand(time(NULL));

    // Losowanie liczby z przedzialu [1 : argv[1]] 
    printf("%d\n", N);
    for(uint32_t i=0; i<N; i++) {
        switch(OP[rand()%3]) {
            case 'A':
                printf("A %d\n", rand() % (MAX_O + 1));
                break;
            
            case 'D':
                printf("D\n");
                break;

            case 'S':
                printf("S\n");
                break;
        }
    }
    return 0;   
}
