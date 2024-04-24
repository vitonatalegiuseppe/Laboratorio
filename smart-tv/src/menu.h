/**@file
 * @brief File contenente le logiche di visualizzazione dei menu utente
 *
 * In questo file sono contenuti i metodi necessari a gestire menu e sottomenu del software
 *
 * @author Alessandro Marra
 * @author Vito Natale
 */

#ifndef MENU_H_
#define MENU_H_

/**
 * @brief Metodo di gestione del menu principale
 *
 * La funzione stampa il menu principale tramite il metodo ::stampa_menu_principale
 * E' la prima funzionalità ad entrare in funzione all'avvio del programma
 * Gestisce la scelta selezionata richiamando la relativa funzionalità
 * Gestisce la condizione di uscita per la chiusura del programma
 *
 * @param *file_programmi Puntatore al file dei programmi
 * @param *file_utente Puntatore al file degli utenti
 * @return Restituisce la voce di menu selezionata dall'utente
 */
int menu_principale(FILE *file_programmi,  FILE *file_utente);

/**
 * @brief Metodo di gestione del sottomenu programmi
 *
 * La funzione stampa il sottomenu dei programmi tramite il metodo ::stampa_menu_programmi
 * Gestisce la scelta selezionata richiamando la relativa funzionalità
 *
 * @param *file_programmi Puntatore al file dei programmi
 */
void menu_programmi(FILE *file_programmi);

/**
 * @brief Metodo di gestione del sottomenu utente
 *
 * La funzione stampa il sottomenu della gestione utente tramite il metodo ::stampa_menu_utente
 * Gestisce la scelta selezionata richiamando la relativa funzionalità
 *
 * @param *file_utente Puntatore al file degli utenti
 */
void menu_utente(FILE *file_utente);

#endif /* MENU_H_ */
