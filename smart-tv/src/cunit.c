/* Il file risulta commentato per evitare di dare problemi su computer senza CUnit
 * Eseguibile su Windows decommentando ed impostando correttamente il main

#include <stdio.h>
#include <stdlib.h>
#include "CUnit/Basic.h"
#include "utility.h"
#include "controlli.h"
#include "definizioni.h"
#include "menu.h"


int init_suite_utility(void){
	return 0;
}

int clean_suite_utility(void){
	return 0;
}

void test_converti_in_minuscolo() {
	char* parola_vuota = "";
	CU_ASSERT_STRING_EQUAL(converti_in_minuscolo(parola_vuota, strlen(parola_vuota)), "");

	char* parola_normale = "Mario";
	CU_ASSERT_STRING_EQUAL(converti_in_minuscolo(parola_normale, strlen(parola_normale)), "mario");

	char* parola_lunga = "Precipitevolissimevolmente";
	CU_ASSERT_STRING_EQUAL(converti_in_minuscolo(parola_lunga, strlen(parola_lunga)), "precipitevolissimevolmente");

	char* parola_con_spazi = "Sono Alessandro Marra e suono LA CHITARRA";
	CU_ASSERT_STRING_EQUAL(converti_in_minuscolo(parola_con_spazi, strlen(parola_con_spazi)), "sono alessandro marra e suono la chitarra");

	char* parola_diversa = "1";
	CU_ASSERT_STRING_NOT_EQUAL(converti_in_minuscolo(parola_diversa, strlen(parola_diversa)), "uno");

	char* stringa_vuota = "";
	char* spazio = " ";
	CU_ASSERT_STRING_NOT_EQUAL(converti_in_minuscolo(stringa_vuota, strlen(stringa_vuota)), spazio);

	CU_ASSERT_STRING_EQUAL(
		converti_in_minuscolo("VitoGiuseppeNatale", 18),
		converti_in_minuscolo("vITOgIUSEPPEnATALE", 18)
	);
}

void test_nome_tipologia() {
	tipologia_e tipologia_nulla;
	CU_ASSERT_STRING_EQUAL(nome_tipologia(tipologia_nulla), "Nessuna tipologia selezionata");

	tipologia_e tipologia_esistente = FILM;
	CU_ASSERT_STRING_EQUAL(nome_tipologia(tipologia_esistente), "Film");

	tipologia_e tipologia_esistente_numerica = 5;
	CU_ASSERT_STRING_EQUAL(nome_tipologia(tipologia_esistente_numerica), "Bambini");

	tipologia_e tipologia_errata = (tipologia_e) "TIPOLOGIA_ERRATA";
	CU_ASSERT_STRING_EQUAL(nome_tipologia(tipologia_errata), "Nessuna tipologia selezionata");
}

void test_nome_genere() {
	genere_e genere_nullo;
	CU_ASSERT_STRING_EQUAL(nome_genere(genere_nullo), "Nessun genere selezionato");

	genere_e genere_esistente = ROMANTICO;
	CU_ASSERT_STRING_EQUAL(nome_genere(genere_esistente), "Romantico");

	genere_e genere_esistente_numerico = 9;
	CU_ASSERT_STRING_EQUAL(nome_genere(genere_esistente_numerico), "Drammatico");

	genere_e genere_errato = (genere_e) "GENERE_ERRATO";
	CU_ASSERT_STRING_EQUAL(nome_genere(genere_errato), "Nessun genere selezionato");
}

void test_aggiungi_valutazione() {
	short int punteggio;

	punteggio = 0;
	aggiungi_valutazione(&punteggio, 5);
	CU_ASSERT(punteggio == 2);

	punteggio = 0;
	aggiungi_valutazione(&punteggio, 3);
	CU_ASSERT(punteggio == 0);

	punteggio = 0;
	aggiungi_valutazione(&punteggio, 1);
	CU_ASSERT(punteggio == -2);

	punteggio = 0;
	aggiungi_valutazione(&punteggio, 0);
	CU_ASSERT(punteggio == 0);

	punteggio = 0;
	aggiungi_valutazione(&punteggio, -5);
	CU_ASSERT(punteggio == 0);

	punteggio = 0;
	aggiungi_valutazione(&punteggio, 99);
	CU_ASSERT(punteggio == 0);
}

void test_calcola_punteggio() {
	// utente con preferenze
	// tipologia = SERIE
	// genere = ROMANTICO
	utente_t utente_1 = { "Alessandro", "Marra", {SERIE}, {ROMANTICO} };

	// utente con preferenze
	// tipologia = SERIE, FILM, DOCUMENTARI
	// genere = ROMANTICO, HORROR, NATURA
	utente_t utente_2 = { "Vito", "Natale", {SERIE, FILM, DOCUMENTARI}, {ROMANTICO, HORROR, NATURA} };

	// utente senza preferenze
	// tipologia = nessuna
	// genere = nessuno
	utente_t utente_3 = { "Ciccio", "Pasticcio", {}, {} };


	// programma: SERIE - ROMANTICO - 5 stelle
	programma_t programma_1 = { 1, "Titolo 1", SERIE, ROMANTICO, "Descrizione programma 1", 5, 0 };

	// programma: FILM - ROMANTICO - 0 stelle
	programma_t programma_2 = { 2, "Titolo 2", FILM, ROMANTICO, "Descrizione programma 2", 0, 0 };

	// programma: SERIE - HORROR - 0 stelle
	programma_t programma_3 = { 3, "Titolo 3", SERIE, HORROR, "Descrizione programma 3", 0, 0 };

	// programma: DOCUMENTARI - NATURA - 0 stelle
	programma_t programma_4 = { 4, "Titolo 4", DOCUMENTARI, NATURA, "Descrizione programma 4", 0, 0 };

	// programma: DOCUMENTARI - NATURA - 1 stella
	programma_t programma_5 = { 5, "Titolo 5", DOCUMENTARI, NATURA, "Descrizione programma 5", 1, 0 };

	// programma inserito scorrettamente: senza genere e senza tipologia - 0 stelle
	programma_t programma_6 = { 6, "", 0, 0, "", 0, 0 };

	CU_ASSERT_EQUAL(calcola_punteggio(&utente_1, &programma_1), 4);
	CU_ASSERT_EQUAL(calcola_punteggio(&utente_1, &programma_2), 1);
	CU_ASSERT_EQUAL(calcola_punteggio(&utente_1, &programma_3), 1);
	CU_ASSERT_EQUAL(calcola_punteggio(&utente_1, &programma_4), 0);
	CU_ASSERT_EQUAL(calcola_punteggio(&utente_1, &programma_5), -2);
	CU_ASSERT_EQUAL(calcola_punteggio(&utente_1, &programma_6), 0);

	CU_ASSERT_EQUAL(calcola_punteggio(&utente_2, &programma_1), 4);
	CU_ASSERT_EQUAL(calcola_punteggio(&utente_2, &programma_2), 2);
	CU_ASSERT_EQUAL(calcola_punteggio(&utente_2, &programma_3), 2);
	CU_ASSERT_EQUAL(calcola_punteggio(&utente_2, &programma_4), 2);
	CU_ASSERT_EQUAL(calcola_punteggio(&utente_2, &programma_5), 0);
	CU_ASSERT_EQUAL(calcola_punteggio(&utente_2, &programma_6), 0);

	CU_ASSERT_EQUAL(calcola_punteggio(&utente_3, &programma_1), 2);
	CU_ASSERT_EQUAL(calcola_punteggio(&utente_3, &programma_2), 0);
	CU_ASSERT_EQUAL(calcola_punteggio(&utente_3, &programma_3), 0);
	CU_ASSERT_EQUAL(calcola_punteggio(&utente_3, &programma_4), 0);
	CU_ASSERT_EQUAL(calcola_punteggio(&utente_3, &programma_5), -2);
	CU_ASSERT_EQUAL(calcola_punteggio(&utente_3, &programma_6), 0);
}

void test_min(){
   int zero = 0;
   int uno = 1;
   int meno_uno = -1;

   CU_ASSERT(min(zero, uno) == 0);
   CU_ASSERT(min(uno, zero) == 0);
   CU_ASSERT(min(zero, meno_uno) == -1);
   CU_ASSERT(min(meno_uno, zero) == -1);
   CU_ASSERT(min(uno, meno_uno) == -1);
   CU_ASSERT(min(meno_uno, uno) == -1);

   CU_ASSERT(min(zero, zero) == 0);
   CU_ASSERT(min(uno, uno) == 1);
   CU_ASSERT(min(meno_uno, meno_uno) == -1);
}


int init_suite_controlli(void){
	return 0;
}

int clean_suite_controlli(void){
	return 0;
}

void test_verifica_esistenza_codice_in_lista_programmi() {

	lista_programmi_t lista_programmi;
	lista_programmi.lista_programmi = calloc(3, sizeof(programma_t));
	lista_programmi.numero_programmi = 3;

	programma_t programma_1 = { 1, "Titolo 1", SERIE, ROMANTICO, "Descrizione programma 1", 5, 0 };
	programma_t programma_2 = { 2, "Titolo 2", FILM, ROMANTICO, "Descrizione programma 2", 0, 0 };
	programma_t programma_3 = { 3, "Titolo 3", SERIE, HORROR, "Descrizione programma 3", 0, 0 };

	lista_programmi.lista_programmi[0] = programma_1;
	lista_programmi.lista_programmi[1] = programma_2;
	lista_programmi.lista_programmi[2] = programma_3;

	int codice_meno_1 = -1;
	int codice_0 = 0;
	int codice_1 = 1;
	int codice_1000 = 1000;

	CU_ASSERT_FALSE(verifica_esistenza_codice_in_lista_programmi(&codice_meno_1, &lista_programmi));
	CU_ASSERT_FALSE(verifica_esistenza_codice_in_lista_programmi(&codice_0, &lista_programmi));
	CU_ASSERT_TRUE(verifica_esistenza_codice_in_lista_programmi(&codice_1, &lista_programmi));
	CU_ASSERT_FALSE(verifica_esistenza_codice_in_lista_programmi(&codice_1000, &lista_programmi));

	free(lista_programmi.lista_programmi);
}

void test_verifica_esistenza_codice_in_lista_suggeriti() {

	lista_programmi_suggeriti_t lista_suggeriti;
	lista_suggeriti.lista_programmi = calloc(3, sizeof(suggerimento_t));
	lista_suggeriti.numero_programmi = 3;

	suggerimento_t suggerito_1 = { 1, "Titolo 1", 0 };
	suggerimento_t suggerito_2 = { 2, "Titolo 2", 0 };
	suggerimento_t suggerito_3 = { 3, "Titolo 3", 0 };

	lista_suggeriti.lista_programmi[0] = suggerito_1;
	lista_suggeriti.lista_programmi[1] = suggerito_2;
	lista_suggeriti.lista_programmi[2] = suggerito_3;

	int codice_meno_1 = -1;
	int codice_0 = 0;
	int codice_1 = 1;
	int codice_1000 = 1000;

	CU_ASSERT_FALSE(verifica_esistenza_codice_in_lista_suggeriti(&codice_meno_1, &lista_suggeriti));
	CU_ASSERT_FALSE(verifica_esistenza_codice_in_lista_suggeriti(&codice_0, &lista_suggeriti));
	CU_ASSERT_TRUE(verifica_esistenza_codice_in_lista_suggeriti(&codice_1, &lista_suggeriti));
	CU_ASSERT_FALSE(verifica_esistenza_codice_in_lista_suggeriti(&codice_1000, &lista_suggeriti));

	free(lista_suggeriti.lista_programmi);
}

void test_verifica_esistenza_codice_in_array() {

	int dimensione_array = 5;
	int array[] = { 1, 2, 3, 4, 5 };

	int codice_meno_1 = -1;
	int codice_0 = 0;
	int codice_1 = 1;
	int codice_5 = 5;
	int codice_6 = 6;
	int codice_1000 = 1000;

	CU_ASSERT_FALSE(verifica_esistenza_codice_in_array(&codice_meno_1, array, dimensione_array));
	CU_ASSERT_FALSE(verifica_esistenza_codice_in_array(&codice_0, array, dimensione_array));
	CU_ASSERT_TRUE(verifica_esistenza_codice_in_array(&codice_1, array, dimensione_array));
	CU_ASSERT_TRUE(verifica_esistenza_codice_in_array(&codice_5, array, dimensione_array));
	CU_ASSERT_FALSE(verifica_esistenza_codice_in_array(&codice_6, array, dimensione_array));
	CU_ASSERT_FALSE(verifica_esistenza_codice_in_array(&codice_1000, array, dimensione_array));

}

int test(void) {

	CU_initialize_registry();

	CU_pSuite suite_utility = CU_add_suite("Suite_utility", init_suite_utility, clean_suite_utility);

	CU_add_test(suite_utility, "test_converti_in_minuscolo", test_converti_in_minuscolo);
	CU_add_test(suite_utility, "test_nome_tipologia", test_nome_tipologia);
	CU_add_test(suite_utility, "test_nome_genere", test_nome_genere);
	CU_add_test(suite_utility, "test_aggiungi_valutazione", test_aggiungi_valutazione);
	CU_add_test(suite_utility, "test_calcola_punteggio", test_calcola_punteggio);
	CU_add_test(suite_utility, "test_min", test_min);

	CU_pSuite suite_comunicazione = CU_add_suite("Suite_controlli", init_suite_controlli, clean_suite_controlli);

	CU_add_test(suite_comunicazione, "test_verifica_esistenza_codice_in_lista_programmi", test_verifica_esistenza_codice_in_lista_programmi);
	CU_add_test(suite_comunicazione, "test_verifica_esistenza_codice_in_lista_suggeriti", test_verifica_esistenza_codice_in_lista_suggeriti);
	CU_add_test(suite_comunicazione, "test_verifica_esistenza_codice_in_array", test_verifica_esistenza_codice_in_array);

	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();

	return CU_get_error();

}

*/
