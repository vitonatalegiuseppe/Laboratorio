/*
 * menu.c
 *
 *  Created on: 14 ago 2022
 *      Author: Sensei Tequila
 */

#include <stdio.h>
#include "comunicazione.h"
#include "controlli.h"
#include "definizioni.h"
#include "menu.h"
#include "funzionalita.h"


int menu_principale(FILE *file_programmi, FILE *file_utente){

	int scelta = 0;
	lista_programmi_t lista_programmi;

	stampa_menu_principale();
	acquisisci_numero_con_condizione_di_uscita("\tQuale scegli?", &scelta, RISPOSTA_MIN_MENU, RISPOSTA_MAX_MENU_PRINCIPALE);

	switch (scelta) {
	case 1: // gestione programmi
		menu_programmi(file_programmi);
		break;
	case 2: // gestione utente
		menu_utente(file_utente);
		break;
	case 3: // ricerca programmi
		lista_programmi = ricerca_programmi(file_programmi);
		stampa_elenco_programmi(lista_programmi);
		break;
	case 4: // valuta programma
		valuta_programma(file_programmi);
		break;
	case 5:
		suggerimento_programmi(file_programmi, file_utente);
		break;
	case 6: // ordinamento programmi
		ordinamento_programmi(file_programmi);
		break;
	case -1:
		// la scelta -1 viene gestita da smart-tv ed è la condizione di uscita dal programma
		break;
	}

	return scelta;
}

void menu_programmi(FILE *file_programmi){
	int scelta = 0;

	stampa_menu_programmi();
	acquisisci_numero_con_condizione_di_uscita("\tQuale scegli?", &scelta, RISPOSTA_MIN_MENU, RISPOSTA_MAX_MENU_PROGRAMMI);

	switch(scelta){
	case 1:
		inserisci_programma(file_programmi);
		break;
	case 2:
		modifica_programma(file_programmi);
		break;
	case 3:
		elimina_programma(file_programmi);
		break;
	case 4:
		stampa_elenco_programmi_da_file(file_programmi);
		break;
	case -1:
		printf("\n");
		break;
	}
}

void menu_utente(FILE *file_utente){
	int scelta = 0;

	stampa_menu_utente();
	acquisisci_numero_con_condizione_di_uscita("\tQuale scegli?", &scelta, RISPOSTA_MIN_MENU, RISPOSTA_MAX_MENU_UTENTI);

	switch(scelta){
	case 1:
		visualizza_utente(file_utente);
		break;
	case 2:
		modifica_utente(file_utente);
		break;
	case -1:
		printf("\n");
		break;
	}
}

