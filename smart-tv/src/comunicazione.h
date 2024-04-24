/**@file
 * @brief File contenente tutti i metodi di input / output delle informazioni
 *
 * In questo file sono presenti le stampe di tutti i menu e delle strutture dati (output)
 * Sono inoltre presenti i metodi di acquisizione degli input con programmazione difensiva (input)
 *
 * @author Alessandro Marra
 * @author Vito Natale
 */

#ifndef COMUNICAZIONE_H_
#define COMUNICAZIONE_H_

#include "definizioni.h"

/**
 * @brief Funzione booleana di stampa del menu principale
 */
void stampa_menu_principale();

/**
 * @brief Funzione booleana di stampa del menu di Gestione programmi
 */
void stampa_menu_programmi();

/**
 * @brief Funzione booleana di stampa del menu di Gestione utente
 */
void stampa_menu_utente();

/**
 * @brief Funzione booleana di stampa dei dati dell'utente
 * @param *utente Puntatore all'utente da stampare
 */
void stampa_utente(const utente_t* utente);

/**
 * @brief Funzione booleana di stampa del menu di Modifica programma televisivo
 */
void stampa_menu_modifica_programma();

/**
 * @brief Funzione booleana di stampa del menu di Modifica utente
 */
void stampa_menu_modifica_utente();

/**
 * @brief Funzione booleana di stampa dell'elenco tipologie di programmi televisivi
 */
void stampa_tipologie();

/**
 * @brief Funzione booleana di stampa dell'elenco generi di programmi televisivi
 */
void stampa_generi();

/**
 * @brief Funzione booleana di stampa di un programma televisivo
 * @param *programma Puntatore al programma da stampare
 */
void stampa_programma(const programma_t* programma);

/**
 * @brief Funzione booleana di stampa di un elenco di programmi televisivi
 * @param lista_programmi Lista dei programmi da stampare
 */
void stampa_elenco_programmi(lista_programmi_t lista_programmi);

/**
 * @brief Funzione booleana di stampa di un programma suggerito
 * @param *suggerimento Puntatore al programma suggerito da stampare
 */
void stampa_programma_suggerito(const suggerimento_t* suggerimento);

/**
 * @brief Funzione booleana che richiede all'utente se ripetere l'operazione
 * @param *testo Testo da mostrare all'utente
 * @return Restituisce 1 se l'utente ha digitato "s"
 */
unsigned short int ripeti_operazione(char* testo);

/**
 * @brief Funzione booleana di acquisizione di una stringa in input
 *
 * Questa funzione implementa la programmazione difensiva per l'acquisizione di una stringa in input
 * Si occupa di verificare che la stringa sia correttamente inserita
 * e si assicura di mantenere il buffer pulito per le acquisizioni successive
 * La stringa acquisita serve a popolare la variabile @p *input passata per riferimento (puntatore)
 * La @p lunghezza_massima è necessaria per la programmazione difensiva
 *
 * @param *testo Testo da mostrare all'utente
 * @param *input Variabile da popolare con la stringa acquisita
 * @param lunghezza_massima Lunghezza massima della stringa da acquisire
 */
void acquisisci_stringa(char *testo, char *input, int lunghezza_massima);

/**
 * @brief Funzione booleana di acquisizione di un numero in input
 *
 * Questa funzione implementa la programmazione difensiva per l'acquisizione di un numero in input
 * Si occupa di verificare che il numero sia valido e compreso tra @p numero_minimo e @p numero_massimo
 * Il numero acquisito serve a popolare la variabile @p *input passata per riferimento (puntatore).
 *
 * @param *testo Testo da mostrare all'utente
 * @param *input Variabile da popolare con la stringa acquisita
 * @param numero_minimo Numero minimo valido
 * @param numero_massimo Numero massimo valido
 */
void acquisisci_numero(char *testo, int *input, int numero_minimo, int numero_massimo);

/**
 * @brief Funzione booleana di acquisizione di un numero in input, con condizione di uscita
 *
 * Implementazione identica alla funzione ::acquisisci_numero
 * Questa funzione consente la digitazione del numero -1, che il chiamante può utilizzare come condizione di uscita
 *
 * @param *testo Testo da mostrare all'utente
 * @param *input Variabile da popolare con la stringa acquisita
 * @param numero_minimo Numero minimo valido
 * @param numero_massimo Numero massimo valido
 */
void acquisisci_numero_con_condizione_di_uscita(char *testo, int *input, int numero_minimo, int numero_massimo);


#endif /* COMUNICAZIONE_H_ */
