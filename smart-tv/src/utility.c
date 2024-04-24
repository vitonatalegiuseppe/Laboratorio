/*
 * utility.c
 *
 *  Created on: 14 ago 2022
 *      Author: Sensei Tequila
 */
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "definizioni.h"
#include "time.h"

void leggi_record(FILE *file, int *id, size_t dimensione_struct, void *data) {
	rewind(file);
	fseek(file, (*id - 1) * dimensione_struct, SEEK_SET);
	fread(data, dimensione_struct, 1, file);
}

void scrivi_record(FILE *file, int *id, size_t dimensione_struct, void *data) {
	rewind(file);
	fseek(file, (*id - 1) * dimensione_struct, SEEK_SET);
	fwrite(data, dimensione_struct, 1, file);
}

char* converti_in_minuscolo(char *parola, int lunghezza){
	char *parola_in_minuscolo = (char *) calloc(lunghezza, sizeof(char));

	unsigned int i;
	for (i = 0; i <= lunghezza; i++) {
		parola_in_minuscolo[i] = tolower(parola[i]);
	}

	return parola_in_minuscolo;
}

const char* nome_tipologia(tipologia_e tipologia)
{
   switch (tipologia)
   {
	   case SERIE:
		   return "Serie";
	   case DOCUMENTARI:
		   return "Documentari";
	   case FILM:
		   return "Film";
	   case INTRATTENIMENTO:
		   return "Intrattenimento";
	   case BAMBINI:
		   return "Bambini";
	   case INFORMAZIONE:
		   return "Informazione";
	   default:
	   	   return "Nessuna tipologia selezionata";
   }
}

const char* nome_genere(genere_e genere)
{
   switch (genere)
   {
	   case FANTASCIENZA:
		   return "Fantascienza";
	   case CUCINA:
		   return "Cucina";
	   case NATURA:
		   return "Natura";
	   case SPORT:
		   return "Sport";
	   case STORICO:
		   return "Storico";
	   case HORROR:
		   return "Horror";
	   case ATTUALITA:
		   return "Attualità";
	   case COMICO:
		   return "Comico";
	   case DRAMMATICO:
		   return "Drammatico";
	   case FANTASY:
		   return "Fantasy";
	   case ROMANTICO:
		   return "Romantico";
	   default:
	   	   return "Nessun genere selezionato";
   }
}

void aggiungi_valutazione(short int *punteggio, int valutazione) {
	switch (valutazione) {
	case 5:
		*punteggio = *punteggio + PUNTEGGIO_VALUTAZIONE_5;
		break;
	case 4:
		*punteggio = *punteggio + PUNTEGGIO_VALUTAZIONE_4;
		break;
	case 3:
		*punteggio = *punteggio + PUNTEGGIO_VALUTAZIONE_3;
		break;
	case 2:
		*punteggio = *punteggio + PUNTEGGIO_VALUTAZIONE_2;
		break;
	case 1:
		*punteggio = *punteggio + PUNTEGGIO_VALUTAZIONE_1;
		break;
	default:
		*punteggio = *punteggio + PUNTEGGIO_VALUTAZIONE_0;
	}
}

int calcola_punteggio(const utente_t *utente, const programma_t *programma) {

	short int punteggio = 0;
	unsigned int i;

	for (i = 0; i < NUMERO_MAX_TIPOLOGIE_PREFERITE_UTENTE; i++) {
		if (programma->tipologia != 0 && programma->tipologia == utente->tipologie_preferite[i]) {
			punteggio = punteggio + PUNTEGGIO_TIPOLOGIA;
		}
	}

	for (i = 0; i < NUMERO_MAX_GENERI_PREFERITI_UTENTE; i++) {
		if (programma->genere != 0 && programma->genere == utente->generi_preferiti[i]) {
			punteggio = punteggio + PUNTEGGIO_GENERE;
		}
	}

	aggiungi_valutazione(&punteggio, programma->valutazione);

	return punteggio;
}

int genera_numero_casuale(int min, int max) {
	int seed = time(NULL);
	int cod;
	srand(seed);

	cod = rand() % (max - min + 1) + min;

	return cod;
}

int min(int a, int b) {
	int result = a;

	if (b < a) {
		result = b;
	}

	return result;
}

lista_programmi_suggeriti_t rimuovi_programma_suggerito(lista_programmi_suggeriti_t lista, int indice_da_rimuovere) {

	int i = 0;
	int j = 0;
	int nuova_dimensione = lista.numero_programmi - 1;

	lista_programmi_suggeriti_t lista_aggiornata = {};
	lista_aggiornata.lista_programmi = calloc(nuova_dimensione, sizeof(suggerimento_t));
	for (i = 0; i < lista.numero_programmi; i++) {
		if (i != indice_da_rimuovere) {
			lista_aggiornata.lista_programmi[j++] = lista.lista_programmi[i];
		}
	}
	lista_aggiornata.numero_programmi = nuova_dimensione;

	return lista_aggiornata;
}

void alloca_memoria_programmi(lista_programmi_t *lista) {
	size_t memoria_da_allocare = (lista->numero_programmi + 1) * sizeof(programma_t);
	if (lista->numero_programmi == 0) {
		lista->lista_programmi = (programma_t*) malloc(memoria_da_allocare);
	} else {
		lista->lista_programmi = (programma_t*) realloc(lista->lista_programmi, memoria_da_allocare);
	}
}

void alloca_memoria_programmi_suggeriti(lista_programmi_suggeriti_t *lista) {
	size_t memoria_da_allocare = (lista->numero_programmi + 1) * sizeof(suggerimento_t);
	if (lista->numero_programmi == 0) {
		lista->lista_programmi = (suggerimento_t*) malloc(memoria_da_allocare);
	} else {
		lista->lista_programmi = (suggerimento_t*) realloc(lista->lista_programmi, memoria_da_allocare);
	}
}

void inserisci_suggerimento(lista_programmi_suggeriti_t *lista, int codice, char *titolo, short int punteggio) {
	lista->lista_programmi[lista->numero_programmi].codice_programma = codice;
	strcpy(lista->lista_programmi[lista->numero_programmi].titolo_programma, titolo);
	lista->lista_programmi[lista->numero_programmi].punteggio = punteggio;
	lista->numero_programmi++;
}

