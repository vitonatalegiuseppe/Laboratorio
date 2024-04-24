/*
 * controlli.c
 *
 *  Created on: 14 ago 2022
 *      Author: Sensei Tequila
 */

#include <stdio.h>
#include "definizioni.h"
#include "utility.h"


// questa funzione verifica se, all'interno del file programmi, esiste già il programma col codice inserito
unsigned short int verifica_esistenza_codice_in_file_programmi(int* codice, FILE *file_programmi) {
	programma_t programma = {0, "", 0, 0, "", 0};
	unsigned short int esiste_codice = 0;

	leggi_record(file_programmi, codice, sizeof(programma_t), &programma);

	if (programma.codice_programma != 0){
		esiste_codice = 1;
		printf("\tScelta non valida. Codice già in uso. Inserire un valore diverso da %d\n\n", *codice);
	}else{
		esiste_codice = 0;
	}

	return esiste_codice;
}

// questa funzione verifica se, all'interno della lista di programmi, esiste già il programma col codice inserito
unsigned short int verifica_esistenza_codice_in_lista_programmi(int* codice, const lista_programmi_t *lista_programmi) {

	unsigned short int esiste_codice = 0;
	unsigned short int i = 0;

	while (esiste_codice == 0 && i < lista_programmi->numero_programmi) {
		if (lista_programmi->lista_programmi[i].codice_programma == *codice){
			esiste_codice = 1;
		}
		i++;
	}

	return esiste_codice;
}

// questa funzione verifica se, all'interno della lista di programmi suggeriti, esiste già il programma col codice inserito
unsigned short int verifica_esistenza_codice_in_lista_suggeriti(int* codice, const lista_programmi_suggeriti_t *lista_programmi) {

	unsigned short int esiste_codice = 0;
	unsigned short int i = 0;

	while (esiste_codice == 0 && i < lista_programmi->numero_programmi) {
		if (lista_programmi->lista_programmi[i].codice_programma == *codice){
			esiste_codice = 1;
		}
		i++;
	}

	return esiste_codice;
}

// questa funzione verifica se, all'interno di un array di interi, esiste già il numero inserito
unsigned short int verifica_esistenza_codice_in_array(int* codice, int* array, int dimensione_array) {

	unsigned short int esiste_codice = 0;
	unsigned short int i = 0;

	while (esiste_codice == 0 && i < dimensione_array) {
		if (array[i] == *codice){
			esiste_codice = 1;
		}
		i++;
	}

	return esiste_codice;
}
