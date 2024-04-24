/*
 * comunicazione.c
 *
 *  Created on: 14 ago 2022
 *      Author: Sensei Tequila
 */

#include <stdio.h>
#include <string.h>
#include "definizioni.h"
#include "utility.h"


void stampa_menu_principale() {
	printf("\t++++++++++++++++++++++++++++++++++++++++\n");
	printf("\t1) Gestione programmi tv\n");
	printf("\t2) Gestione profilo utente \n");
	printf("\t3) Ricerca programma \n");
	printf("\t4) Valuta programma \n");
	printf("\t5) Suggerisci programma \n");
	printf("\t6) Ordinamento programmi \n");
	printf("\tInserire -1 per uscire \n");
}

void stampa_menu_programmi() {
	printf("\n\t++++++++++++++++++++++++++++++++++++++++\n");
	printf("\t1) Inserisci programma tv\n");
	printf("\t2) Modifica programma tv \n");
	printf("\t3) Elimina programma tv\n");
	printf("\t4) Leggi programmi tv\n");
	printf("\tInserire -1 per tornare al menu precedente \n");
}

void stampa_menu_utente() {
	printf("\n\t++++++++++++++++++++++++++++++++++++++++\n");
	printf("\t1) Visualizza profilo utente \n");
	printf("\t2) Modifica profilo utente \n");
	printf("\tInserire -1 per tornare al menu precedente \n");
}

void stampa_tipologie() {
	printf("\n");
	printf("\t1) Serie\n");
	printf("\t2) Documentari \n");
	printf("\t3) Film\n");
	printf("\t4) Intrattenimento\n");
	printf("\t5) Bambini\n");
	printf("\t6) Informazione\n");
}

void stampa_generi() {
	printf("\n");
	printf("\t1) Fantascienza\n");
	printf("\t2) Cucina \n");
	printf("\t3) Natura\n");
	printf("\t4) Sport\n");
	printf("\t5) Storico\n");
	printf("\t6) Horror\n");
	printf("\t7) Attualita'\n");
	printf("\t8) Comico \n");
	printf("\t9) Drammatico\n");
	printf("\t10) Fantasy\n");
	printf("\t11) Romantico\n");
}

void stampa_programma(const programma_t* programma) {
	printf("\n\tCODICE --> %d\n", programma->codice_programma);
	printf("\tTITOLO --> %s\n", programma->titolo);
	printf("\tTIPOLOGIA --> %s\n", nome_tipologia(programma->tipologia));
	printf("\tGENERE --> %s\n", nome_genere(programma->genere));
	printf("\tDESCRIZIONE --> %s\n", programma->descrizione);
	printf("\tVALUTAZIONE --> %d\n", programma->valutazione);
	printf("\tSUGGERITO --> %u\n", programma->suggerito);
}

void stampa_elenco_programmi(lista_programmi_t lista_programmi) {
	if (lista_programmi.numero_programmi > 0) {
		printf("\n\tNumero programmi trovati: %d\n", lista_programmi.numero_programmi);
		for (int i = 0; i < lista_programmi.numero_programmi; i++) {
			printf("\n\tElemento n. %d", (i + 1));
			stampa_programma(&lista_programmi.lista_programmi[i]);
		}
	} else {
		printf("\n\tNessun risultato trovato");
	}
	printf("\n");
}

void stampa_menu_modifica_programma(){
	printf("\n\t++++++++++++++++++++++++++++++++++++++++\n");
	printf("\tCosa vuoi modificare? \n");
	printf("\t1) Titolo programma tv\n");
	printf("\t2) Genere programma tv \n");
	printf("\t3) Tipologia programma tv\n");
	printf("\t4) Descrizione programma tv\n");
	printf("\tInserire -1 per tornare al menu precedente \n");
}

void stampa_menu_modifica_utente(){
	printf("\n\t++++++++++++++++++++++++++++++++++++++++\n");
	printf("\tCosa vuoi modificare? \n");
	printf("\t1) Nome utente \n");
	printf("\t2) Cognome utente \n");
	printf("\t3) Tipologie preferite \n");
	printf("\t4) Generi preferiti \n");
	// printf("\tInserire -1 per tornare al menu precedente \n");
}

void stampa_programma_suggerito(const suggerimento_t* suggerimento) {
	printf("\n\tCODICE --> %d\n", suggerimento->codice_programma);
	printf("\tTITOLO --> %s\n", suggerimento->titolo_programma);
	// printf("\tPUNTEGGIO --> %d\n", suggerimento->punteggio);
}

void stampa_utente(const utente_t* utente) {
	unsigned int i = 0;

	printf("\n\tNOME --> %s\n", utente->nome);
	printf("\tCOGNOME --> %s\n", utente->cognome);
	printf("\tTIPOLOGIE PREFERITE --> ");
	for (i = 0; i < NUMERO_MAX_TIPOLOGIE_PREFERITE_UTENTE; i++) {
		if (utente->tipologie_preferite[i] != 0) {
			printf("%s ", nome_tipologia(utente->tipologie_preferite[i]));
		}
	}
	printf("\n");
	printf("\tGENERI PREFERITI --> ");
	for (i = 0; i < NUMERO_MAX_GENERI_PREFERITI_UTENTE; i++) {
		if (utente->generi_preferiti[i] != 0) {
			printf("%s ", nome_genere(utente->generi_preferiti[i]));
		}
	}
	printf("\n\n");
}

void acquisisci_numero_con_condizione_di_uscita(char *testo, int *input, int numero_minimo, int numero_massimo) {

	int c;
	int input_valido;

	do {
		// necessario per evitare il warning "format string is not a string literal (potentially insecure) [-Wformat-security]"
		printf("%s \t", testo);

		setvbuf(stdin, NULL, _IONBF, 0);
		input_valido = scanf("%d", input);

		if (*input != -1 && (input_valido != 1 || *input < numero_minimo || *input > numero_massimo)) {
			printf("\tATTENZIONE! Valore errato. Inserisci un valore nell'intervallo [%d-%d] oppure -1. Riprovare.\n", numero_minimo, numero_massimo);
		}

		while ( (c = getchar()) != '\n' && c != EOF ) { }

	} while (*input != -1 && (input_valido != 1 || *input < numero_minimo || *input > numero_massimo));
}

void acquisisci_numero(char *testo, int *input, int numero_minimo, int numero_massimo) {

	int c;
	int input_valido;

	do {
		// necessario per evitare il warning "format string is not a string literal (potentially insecure) [-Wformat-security]"
		printf("%s \t", testo);

		setvbuf(stdin, NULL, _IONBF, 0);
		input_valido = scanf("%d", input);

		if (input_valido != 1 || *input < numero_minimo || *input > numero_massimo) {
			printf("\tATTENZIONE! Il numero digitato non rientra nell'intervallo [%d-%d]. Riprovare.\n", numero_minimo, numero_massimo);
		}

		while ( (c = getchar()) != '\n' && c != EOF ) { }

	} while ((input_valido != 1 || *input < numero_minimo || *input > numero_massimo));
}

void acquisisci_stringa(char *testo, char *input, int lunghezza_massima) {

	int risultato_acquisizione = 0;
	char *stringa_acquisita = calloc(lunghezza_massima, sizeof(char));

	do {
		// necessario per evitare il warning "format string is not a string literal (potentially insecure) [-Wformat-security]"
		printf("%s", testo);

		setvbuf(stdin, NULL, _IONBF, 0);
		risultato_acquisizione = scanf("%[^\n]s", stringa_acquisita);

		if (strlen(stringa_acquisita) == 0) {
			printf("\tATTENZIONE! L'input non può essere vuoto. Riprovare\n");
		} else if (strlen(stringa_acquisita) > (lunghezza_massima - 1)) {
			printf("\tATTENZIONE! L'input supera la lunghezza massima consentita [%d]. Riprovare.\n", (lunghezza_massima - 1));
		} else {
			stringa_acquisita[lunghezza_massima] = '\0';
		}

		int c;
		while ( (c = getchar()) != '\n' && c != EOF ) { }

	} while (risultato_acquisizione == 0 || strlen(stringa_acquisita) == 0 || (strlen(stringa_acquisita) > (lunghezza_massima - 1)));

	strcpy(input, stringa_acquisita);
}

unsigned short int ripeti_operazione(char* testo) {

	char* scelta;
	char* scelta_in_minuscolo;

	unsigned int risposta_corretta = 0; // di default non abbiamo nessuna risposta ed entriamo nel while la prima volta
	unsigned short int risposta_fornita = 0;

	do {
		// ogni volta che entriamo nel ciclo, allochiamo la memoria per memorizzare la scelta
		// utilizziamo calloc perché
		// "calloc() allocates the memory and also initializes every byte in the allocated memory to 0."
		scelta = (char *) calloc(1, sizeof(char));
		scelta_in_minuscolo = (char *) calloc(1, sizeof(char));

		acquisisci_stringa(testo, scelta, 2); // max 1 carattere, più terminatore stringa
		scelta_in_minuscolo = converti_in_minuscolo(scelta, 1);
		if ((strcmp(scelta_in_minuscolo, "s") == 0) || (strcmp(scelta_in_minuscolo, "n") == 0)) {
			risposta_corretta = 1;
			// risposta_fornita è true (1) quando la scelta dell'utente è "s"
			// infatti (strcmp(scelta_in_minuscolo, "s")) sarà uguale a 0
			// e (0 == 0) è true (1)
			risposta_fornita = (strcmp(scelta_in_minuscolo, "s") == 0);
		} else {
			printf("\tATTENZIONE: Devi inserire solo s o n \n");
		}

		// alla fine del ciclo, liberiamo la memoria allocata
		free(scelta);
		free(scelta_in_minuscolo);

	} while (risposta_corretta == 0);

	return risposta_fornita;
}

