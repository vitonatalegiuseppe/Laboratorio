#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "definizioni.h"
#include "utility.h"


// mantengo il nome della funzione in inglese solo in questo caso per coerenza con l'algoritmo standard
void swap(programma_t *a, programma_t *b) {
	programma_t t = *a;
	*a = *b;
	*b = t;
}

// mantengo il nome della funzione in inglese solo in questo caso per coerenza con l'algoritmo standard
int partition(programma_t* array, int low, int high) {

	// elemento pivot utilizzato per fare i confronti successivi
	programma_t pivot = array[high];
	char *pivot_in_minuscolo = converti_in_minuscolo(pivot.titolo, LUNGHEZZA_MAX_TITOLO_PROGRAMMA);
	char *titolo_elemento_corrente_in_minuscolo;

	int i = (low - 1);

	for (int j = low; j < high; j++) {

		// converto il titolo del programma corrente in minuscolo
		// in modo da fare i confronti tra stringhe tutte minuscole
		titolo_elemento_corrente_in_minuscolo = converti_in_minuscolo(array[j].titolo, LUNGHEZZA_MAX_TITOLO_PROGRAMMA);

		/// strcmp ritorna un valore minore di zero se la prima stringa è minore della seconda
		/// - su Windows viene ritornato -1
		/// - su Mac OS viene ritornato un valore negativo pari alla differenza (numerica) tra i primi 2 caratteri differenti
		/// es. comparando "Spiderman 2" con "Una settimana da Dio"
		/// abbiamo la differenza tra i primi caratteri: "S" < "U" di 2 posizioni
		/// su Windows il valore restituito è un generico -1
		/// su Mac OS il valore restituito è -2
		if (strcmp(titolo_elemento_corrente_in_minuscolo, pivot_in_minuscolo) < 0) {
			i++;
			swap(&array[i], &array[j]);
		}

		free(titolo_elemento_corrente_in_minuscolo);
	}

	swap(&array[i + 1], &array[high]);

	free(pivot_in_minuscolo);

	return (i + 1);
}

// mantengo il nome della funzione in inglese solo in questo caso per coerenza con l'algoritmo standard
void quickSort(programma_t* array, int low, int high) {
	if (low < high) {

		int pivot = partition(array, low, high);

		quickSort(array, low, pivot - 1);

		quickSort(array, pivot + 1, high);
	}
}

// mantengo il nome della funzione in inglese solo in questo caso per coerenza con l'algoritmo standard
void shellSort(suggerimento_t* vett, int dim) {
	int i, j, gap, k, a[5];
	suggerimento_t x;
	a[0]=9; a[1]=5; a[2]=3; a[3]=2; a[4]=1; // a = vettore dei gap
	for (k = 0; k < 5; k++) { // ciclo ripetuto per tutti i gap
		gap = a[k];
		for(i = gap; i < dim; i++) {
			x = vett[i];
			for(j = i-gap; (x.punteggio > vett[j].punteggio) && (j >= 0); j = j-gap) {
				vett[j+gap] = vett[j];
				vett[j] = x; // scambio elementi
			}
		}
	}
}
