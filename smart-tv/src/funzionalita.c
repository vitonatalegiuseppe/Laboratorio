/*
 * funzionalita_programmi.c
 *
 *  Created on: 14 ago 2022
 *      Author: Sensei Tequila
 */
#include "funzionalita.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "definizioni.h"
#include "controlli.h"
#include "comunicazione.h"
#include "utility.h"
#include "ordinamento.h"
#include "menu.h"

void stampa_elenco_programmi_da_file(FILE *file_programmi) {
	programma_t programma = {0, "", 0, 0, "", 0, 0 };
	int indice = 1;

	leggi_record(file_programmi, &indice, sizeof(programma_t), &programma);

	while (!feof(file_programmi)) {
		if (programma.codice_programma != 0) {
			stampa_programma(&programma);
		}
		indice++;
		leggi_record(file_programmi, &indice, sizeof(programma_t), &programma);
	}

	printf("\n\t***************File Terminato******************\n\n");
}

void inserisci_programma(FILE *file_programmi) {
	programma_t programma = { 0, "", 0, 0, "", 0, 0 };
	unsigned short int ripeti = 0;
	unsigned short int esiste_codice = 0;
	int scelta = 0;

	do {
		printf("\n\tInserisci i dati del programma: \n");
		do {
			acquisisci_numero("\tCODICE PROGRAMMA: \t ", &programma.codice_programma, NUMERO_MIN_CODICE_PROGRAMMA, NUMERO_MAX_CODICE_PROGRAMMA);
			esiste_codice = verifica_esistenza_codice_in_file_programmi(&programma.codice_programma, file_programmi);
		} while (esiste_codice == 1);

		acquisisci_stringa("\tTITOLO PROGRAMMA: \t ", programma.titolo, LUNGHEZZA_MAX_TITOLO_PROGRAMMA);

		// Inserimento tipologia
		printf("\tTIPOLOGIA PROGRAMMA: \t ");
		stampa_tipologie();
		acquisisci_numero("\tQuale scegli?", &scelta, 1, NUMERO_TIPOLOGIE_PROGRAMMA);
		programma.tipologia = scelta;

		// Inserimento genere
		printf("\tGENERE PROGRAMMA: \t ");
		stampa_generi();
		acquisisci_numero("\tQuale scegli?", &scelta, 1, NUMERO_GENERI_PROGRAMMA);
		programma.genere = scelta;

		acquisisci_stringa("\tDESCRIZIONE PROGRAMMA: \t", programma.descrizione, LUNGHEZZA_MAX_DESCRIZIONE_PROGRAMMA);

		programma.valutazione = 0;
		programma.suggerito = 0;

		printf("\t****************Programma Inserito*******************\n");
		stampa_programma(&programma);

		scrivi_record(file_programmi, &programma.codice_programma, sizeof(programma_t), &programma);

		ripeti = ripeti_operazione("\n\tVuoi inserire un nuovo programma? (s/n): \t");
	} while (ripeti == 1);

	printf("\t***************Inserimento Terminato******************\n\n");
}

void modifica_programma(FILE *file_programmi){
	programma_t programma = { 0, "", 0, 0, "", 0, 0 };
	int scelta = 0;
	int genere = 0;
	int tipologia = 0;
	int codice;
	unsigned short int programma_esiste = 0;
	lista_programmi_t lista_programmi_cercati;

	do {
		lista_programmi_cercati = ricerca_programmi(file_programmi);
		stampa_elenco_programmi(lista_programmi_cercati);
	} while (lista_programmi_cercati.numero_programmi == 0);


	do {
		acquisisci_numero_con_condizione_di_uscita("\n\tInserisci il codice del programma televisivo da modificare "
				"(-1 per terminare):\t", &codice, NUMERO_MIN_CODICE_PROGRAMMA, NUMERO_MAX_CODICE_PROGRAMMA);

		if (codice != -1) {

			programma_esiste = verifica_esistenza_codice_in_lista_programmi(&codice, &lista_programmi_cercati);

			if (programma_esiste == 1) {

				stampa_menu_modifica_programma();
				acquisisci_numero_con_condizione_di_uscita("\tQuale scegli (-1 per terminare)?", &scelta, RISPOSTA_MIN_MENU, RISPOSTA_MAX_MENU_MODIFICA_PROGRAMMI);

				leggi_record(file_programmi, &codice, sizeof(programma_t), &programma);

				switch(scelta){
				case 1:
					acquisisci_stringa("\n\tInserisci il nuovo titolo: \t ", programma.titolo, LUNGHEZZA_MAX_TITOLO_PROGRAMMA);
					break;
				case 2:
					stampa_generi();
					acquisisci_numero("\tQuale scegli?", &genere, 1, NUMERO_GENERI_PROGRAMMA);
					programma.genere = genere;
					break;
				case 3:
					stampa_tipologie();
					acquisisci_numero("\tQuale scegli?", &tipologia, 1, NUMERO_TIPOLOGIE_PROGRAMMA);
					programma.tipologia = tipologia;
					break;
				case 4:
					acquisisci_stringa("\n\tInserisci la nuova descrizione: \t", programma.descrizione, LUNGHEZZA_MAX_DESCRIZIONE_PROGRAMMA);
					break;
				}

				scrivi_record(file_programmi, &codice, sizeof(programma_t), &programma);

				printf("\t******Programma televisivo modificato con successo!*****\n");
				stampa_programma(&programma);

			} else {
				printf("\n\tATTENZIONE: il codice inserito non è presente tra i programmi ricercati.");
			}
		}
	// se codice è -1 -> devo uscire dal ciclo
	// se il programma non esiste (programma_esiste == 0) => devo stare nel ciclo
	} while (codice != -1 && programma_esiste == 0);

	printf("\n");
}

void elimina_programma(FILE *file_programmi) {

	programma_t programma = { 0, "", 0, 0, "", 0, 0 };

	int codice = 0;
	unsigned short int programma_esiste = 0;
	lista_programmi_t lista_programmi_cercati;

	do {
		lista_programmi_cercati = ricerca_programmi(file_programmi);
		stampa_elenco_programmi(lista_programmi_cercati);
	} while (lista_programmi_cercati.numero_programmi == 0);

	do {
		acquisisci_numero_con_condizione_di_uscita("\tInserire il codice del programma televisivo da eliminare "
				"(-1 per terminare): \t", &codice, NUMERO_MIN_CODICE_PROGRAMMA, NUMERO_MAX_CODICE_PROGRAMMA);

		if (codice != -1) {

			programma_esiste = verifica_esistenza_codice_in_lista_programmi(&codice, &lista_programmi_cercati);

			if (programma_esiste == 1) {
				scrivi_record(file_programmi, &codice, sizeof(programma_t), &programma);
				printf("\t******Programma televisivo eliminato con successo!*****\n\n");

			} else {
				printf("\n\tATTENZIONE!! Il codice inserito non è presente tra i programmi ricercati.");
			}
		}
	} while (codice != -1 && programma_esiste == 0);
}

void valuta_programma(FILE *file_programmi) {
	programma_t programma = { 0, "", 0, 0, "", 0, 0 };

	int codice = 0;
	unsigned short int programma_esiste = 0;
	lista_programmi_t lista_programmi_cercati;

	do {
		lista_programmi_cercati = ricerca_programmi(file_programmi);
		stampa_elenco_programmi(lista_programmi_cercati);
	} while (lista_programmi_cercati.numero_programmi == 0);

	do {
		acquisisci_numero_con_condizione_di_uscita("\tInserire il codice del programma televisivo da valutare "
				"(-1 per terminare):\t", &codice, NUMERO_MIN_CODICE_PROGRAMMA, NUMERO_MAX_CODICE_PROGRAMMA);

		if (codice != -1) {

			programma_esiste = verifica_esistenza_codice_in_lista_programmi(&codice, &lista_programmi_cercati);

			if (programma_esiste == 1) {

				leggi_record(file_programmi, &codice, sizeof(programma_t), &programma);

				acquisisci_numero("\tInserisci la valutazione da 1 a 5: \t", &programma.valutazione, VALUTAZIONE_MINIMA, VALUTAZIONE_MASSIMA);

				scrivi_record(file_programmi, &codice, sizeof(programma_t), &programma);

				printf("\t******Programma televisivo valutato con successo!*****\n");
				stampa_programma(&programma);

			} else {
				printf("\tATTENZIONE, il codice inserito non è presente tra i programmi ricercati. \n");
			}
		}
	} while (codice != -1 && programma_esiste == 0);

	printf("\n");
}

void ordinamento_programmi(FILE *file_programmi) {
	programma_t programma = {0, "", 0, 0, "", 0, 0};

	lista_programmi_t lista_programmi_ordinamento = {};

	// indice utilizzato per il corretto posizionamento per la lettura dal file
	int indice = 1;

	leggi_record(file_programmi, &indice, sizeof(programma_t), &programma);

	while(!feof(file_programmi)) {

		if (programma.codice_programma != 0) {

			alloca_memoria_programmi(&lista_programmi_ordinamento);

			lista_programmi_ordinamento.lista_programmi[lista_programmi_ordinamento.numero_programmi] = programma;
			lista_programmi_ordinamento.numero_programmi++;
		}

		indice++;
		leggi_record(file_programmi, &indice, sizeof(programma_t), &programma);
	}

	quickSort(lista_programmi_ordinamento.lista_programmi, 0, lista_programmi_ordinamento.numero_programmi - 1);

	printf("\n\t****** ELENCO PROGRAMMI ORDINATO ALFABETICAMENTE per TITOLO *****\n");

	stampa_elenco_programmi(lista_programmi_ordinamento);

	// questo controllo è necessario perché il free non può agire se non è stata allocata nessun'area di memoria
	if (lista_programmi_ordinamento.numero_programmi > 0) {
		free(lista_programmi_ordinamento.lista_programmi);
	}
}

void suggerimento_programmi(FILE *file_programmi, FILE *file_utente) {

	programma_t programma = {0, "", 0, 0, "", 0, 0};
	utente_t utente = {"", "", {0, 0, 0}, {0, 0, 0, 0, 0}};
	unsigned int i = 0;
	suggerimento_t programma_casuale = {0,"",0};
	short int punteggio = 0;
	int indice_programma_casuale = 0;
	int indice_utente_unico = 1;
	int indice_programmi = 1;
	int numero_massimo_suggerimenti = 0;

	// questa lista rappresenta l'elenco dei programmi che vengono suggeriti in base al punteggio calcolato
	lista_programmi_suggeriti_t lista_programmi_suggeriti = {};

	// questa lista rappresenta l'elenco dei programmi che non hanno punteggio per essere suggeriti
	// ma che potrebbero essere aggiunti all'elenco suggeriti se non si arriva al numero minimo stabilito
	lista_programmi_suggeriti_t lista_programmi_non_suggeriti = {};


	leggi_record(file_utente, &indice_utente_unico, sizeof(utente_t), &utente);
	leggi_record(file_programmi, &indice_programmi, sizeof(programma_t), &programma);

	while(!feof(file_programmi)) {

		// mi assicuro che il programma non sia già stato suggerito e che sia un programma valido
		if (programma.suggerito == 0 && programma.codice_programma != 0) {

			punteggio = calcola_punteggio(&utente, &programma);

			if (punteggio > 0) {

				alloca_memoria_programmi_suggeriti(&lista_programmi_suggeriti);

				inserisci_suggerimento(&lista_programmi_suggeriti, programma.codice_programma, programma.titolo, punteggio);
			} else {

				// mettiamo in un nuovo array la restante parte di programmi non suggeriti, ma potenzialmente suggeribili in maniera casuale
				alloca_memoria_programmi_suggeriti(&lista_programmi_non_suggeriti);

				inserisci_suggerimento(&lista_programmi_non_suggeriti, programma.codice_programma, programma.titolo, punteggio);
			}
		}

		indice_programmi++;
		leggi_record(file_programmi, &indice_programmi, sizeof(programma_t), &programma);
	}

	// il numero massimo dei programmi che è possibile suggerire equivale al minimo tra:
	// - NUMERO_MAX_PROGRAMMI_SUGGERITI (costante = 10)
	// - la somma tra programmi con punteggio > 0 e la restante parte non già suggerita
	numero_massimo_suggerimenti = min(NUMERO_MAX_PROGRAMMI_SUGGERITI, (lista_programmi_suggeriti.numero_programmi + lista_programmi_non_suggeriti.numero_programmi));

	while (lista_programmi_suggeriti.numero_programmi < numero_massimo_suggerimenti) {

		indice_programma_casuale = genera_numero_casuale(0, lista_programmi_non_suggeriti.numero_programmi - 1);
		programma_casuale = lista_programmi_non_suggeriti.lista_programmi[indice_programma_casuale];

		alloca_memoria_programmi_suggeriti(&lista_programmi_suggeriti);

		// assegnamo un punteggio pari a 0, in modo da avere i programmi random sempre in coda dopo l'ordinamento
		inserisci_suggerimento(&lista_programmi_suggeriti, programma_casuale.codice_programma, programma_casuale.titolo_programma, 0);

		// aggiorniamo l'array di programmi suggeribili, in modo tale da non avere duplicati nel ciclo successivo
		lista_programmi_non_suggeriti = rimuovi_programma_suggerito(lista_programmi_non_suggeriti, indice_programma_casuale);
	}

	if (lista_programmi_suggeriti.numero_programmi > 0) {
		shellSort(lista_programmi_suggeriti.lista_programmi, lista_programmi_suggeriti.numero_programmi);

		for (i = 0; i < numero_massimo_suggerimenti; i++) {
			stampa_programma_suggerito(&lista_programmi_suggeriti.lista_programmi[i]);
		}

		richiedi_visione_suggerimento(file_programmi, lista_programmi_suggeriti);
	} else {
		// in questa casistica si può rientrare solo ed esclusivamente se
		// - non esiste nessun programma nel file dei programmi
		// oppure
		// - tutti i programmi del file sono già stati suggeriti
		printf("\n\t***ATTENZIONE: non è stato trovato nessun programma!***\n");
	}
}

void richiedi_visione_suggerimento(FILE *file_programmi, lista_programmi_suggeriti_t lista_programmi_suggeriti) {

	programma_t programma = {0, "", 0, 0, "", 0, 0};

	unsigned short int programma_esiste = 0;
	int codice = 0;

	do {
		acquisisci_numero_con_condizione_di_uscita("\n\tInserire il codice del programma televisivo che vuoi visionare "
				"(-1 per tornare indietro): \t", &codice, NUMERO_MIN_CODICE_PROGRAMMA, NUMERO_MAX_CODICE_PROGRAMMA);

		if (codice != -1) {

			programma_esiste = verifica_esistenza_codice_in_lista_suggeriti(&codice, &lista_programmi_suggeriti);

			if (programma_esiste == 1) {

				leggi_record(file_programmi, &codice, sizeof(programma_t), &programma);
				programma.suggerito = 1;
				scrivi_record(file_programmi, &codice, sizeof(programma_t), &programma);

				stampa_programma(&programma);

				printf("\t******Programma televisivo visionato con successo!*****\n\n");

				// questo controllo è necessario perché il free non può agire se non è stata allocata nessun'area di memoria
				if (lista_programmi_suggeriti.numero_programmi > 0) {
					free(lista_programmi_suggeriti.lista_programmi);
				}
			} else {
				printf("\tATTENZIONE: il codice inserito non è presente tra i programmi suggeriti. \n");
			}
		}
	} while (codice != -1 && programma_esiste == 0);
}

lista_programmi_t ricerca_programmi(FILE *file_programmi) {
	programma_t programma = { 0, "", 0, 0, "", 0, 0 };
	int indice = 1;

	lista_programmi_t lista_programmi_trovati = {};

	char* titolo_in_minuscolo;
	char* descrizione_in_minuscolo;

	// la lunghezza massima della parola da ricercare non può essere più lunga del titolo
	char *parola = (char *) calloc(LUNGHEZZA_MAX_TITOLO_PROGRAMMA, sizeof(char));
	char *parola_in_minuscolo = (char *) calloc(LUNGHEZZA_MAX_TITOLO_PROGRAMMA, sizeof(char));

	acquisisci_stringa("\n\tInserisci la parola che verrà ricercata su titolo e descrizione "
			"dei programmi televisivi: ", parola, LUNGHEZZA_MAX_TITOLO_PROGRAMMA);
	parola_in_minuscolo = converti_in_minuscolo(parola, LUNGHEZZA_MAX_TITOLO_PROGRAMMA);

	leggi_record(file_programmi, &indice, sizeof(programma_t), &programma);

	while(!feof(file_programmi)) {

		// converto titolo e descrizione in minuscolo ed assegno il valore a delle variabili
		// in modo che al termine del ciclo sia possibili liberarne la memoria allocata
		titolo_in_minuscolo = converti_in_minuscolo(programma.titolo, LUNGHEZZA_MAX_TITOLO_PROGRAMMA);
		descrizione_in_minuscolo = converti_in_minuscolo(programma.descrizione, LUNGHEZZA_MAX_DESCRIZIONE_PROGRAMMA);

		// ottimizzo la ricerca evitando di fare operazioni su programmi che non hanno il codice valido
		if (programma.codice_programma != 0) {

			if (strstr(titolo_in_minuscolo, parola_in_minuscolo) || strstr(descrizione_in_minuscolo, parola_in_minuscolo)) {

				alloca_memoria_programmi(&lista_programmi_trovati);

				lista_programmi_trovati.lista_programmi[lista_programmi_trovati.numero_programmi] = programma;
				lista_programmi_trovati.numero_programmi++;
			}
		}

		free(titolo_in_minuscolo);
		free(descrizione_in_minuscolo);

		indice++;
		leggi_record(file_programmi, &indice, sizeof(programma_t), &programma);
	}

	free(parola);
	free(parola_in_minuscolo);

	return lista_programmi_trovati;
}

void visualizza_utente(FILE *file_utente) {
	utente_t utente = { "", "", { 0, 0, 0 }, { 0, 0, 0, 0, 0 } };
	int indice_utente_unico = 1;

	leggi_record(file_utente, &indice_utente_unico, sizeof(utente_t), &utente);

	stampa_utente(&utente);

	printf("\t***************File Terminato******************\n\n");
}

void modifica_utente(FILE *file_utente){

	utente_t utente = { "", "", { 0, 0, 0 }, { 0, 0, 0, 0, 0 } };
	int indice_utente_unico = 1;

	leggi_record(file_utente, &indice_utente_unico, sizeof(utente_t), &utente);

	stampa_utente(&utente);

	int scelta = 0;
	unsigned int i = 0;
	unsigned short int esiste_codice = 0;

	int tipologie_selezionate[NUMERO_MAX_TIPOLOGIE_PREFERITE_UTENTE] = {0};
	int generi_selezionati[NUMERO_MAX_GENERI_PREFERITI_UTENTE] = {0};

	stampa_menu_modifica_utente();
	acquisisci_numero_con_condizione_di_uscita("\tQuale scegli (-1 per uscire)?", &scelta, 1, RISPOSTA_MAX_MENU_MODIFICA_UTENTI);

	switch(scelta){
	case 1:
		acquisisci_stringa("\tNOME UTENTE: ", utente.nome, LUNGHEZZA_MAX_NOME_UTENTE);
		break;
	case 2:
		acquisisci_stringa("\tCOGNOME UTENTE: ", utente.cognome, LUNGHEZZA_MAX_COGNOME_UTENTE);
		break;
	case 3:
		printf("\tTIPOLOGIE PREFERITE (fino a un massimo di %d scelte)\n", NUMERO_MAX_TIPOLOGIE_PREFERITE_UTENTE);
		i = 0;
		scelta = 0;
		esiste_codice = 0;

		do {
			stampa_tipologie();
			acquisisci_numero_con_condizione_di_uscita("\tQuale scegli (-1 per terminare)?", &scelta, 1, NUMERO_TIPOLOGIE_PROGRAMMA);
			if (scelta != -1) {
				esiste_codice = verifica_esistenza_codice_in_array(&scelta, tipologie_selezionate, NUMERO_MAX_TIPOLOGIE_PREFERITE_UTENTE);
				if (esiste_codice == 0) {
					tipologie_selezionate[i] = scelta;
					utente.tipologie_preferite[i] = scelta;
					i++;
				} else {
					printf("\n\tATTENZIONE: la tipologia selezionata è già presente tra le tipologie preferite.\n");
				}
			} else {
				// quando l'utente digita -1, mi assicuro di resettare le altre eventuali tipologie preferite presenti
				// in modo tale da non mantenere dati sporchi (e potenzialmente errati) all'interno del file
				while (i < NUMERO_MAX_TIPOLOGIE_PREFERITE_UTENTE) {
					utente.tipologie_preferite[i++] = 0;
				}
			}
		} while (scelta != -1 && (esiste_codice == 1 || i < NUMERO_MAX_TIPOLOGIE_PREFERITE_UTENTE));

		break;
	case 4:
		printf("\tGENERI PREFERITI (fino a un massimo di %d scelte)\n", NUMERO_MAX_GENERI_PREFERITI_UTENTE);
		i = 0;
		scelta = 0;
		esiste_codice = 0;

		do {
			stampa_generi();
			acquisisci_numero_con_condizione_di_uscita("\tQuale scegli (-1 per terminare)?", &scelta, 1, NUMERO_GENERI_PROGRAMMA);
			if (scelta != -1) {
				esiste_codice = verifica_esistenza_codice_in_array(&scelta, generi_selezionati, NUMERO_MAX_GENERI_PREFERITI_UTENTE);
				if (esiste_codice == 0) {
					generi_selezionati[i] = scelta;
					utente.generi_preferiti[i] = scelta;
					i++;
				} else {
					printf("\n\tATTENZIONE: il genere selezionato è già presente tra i generi preferiti.\n");
				}
			} else {
				// quando l'utente digita -1, mi assicuro di resettare gli altri eventuali generi preferiti presenti
				// in modo tale da non mantenere dati sporchi (e potenzialmente errati) all'interno del file
				while (i < NUMERO_MAX_GENERI_PREFERITI_UTENTE) {
					utente.generi_preferiti[i++] = 0;
				}
			}
		} while (scelta != -1 && (esiste_codice == 1 || i < NUMERO_MAX_GENERI_PREFERITI_UTENTE));

		break;
	}

	scrivi_record(file_utente, &indice_utente_unico, sizeof(utente_t), &utente);

	printf("\t******Profilo utente modificato con successo!*****\n");
	stampa_utente(&utente);

}
