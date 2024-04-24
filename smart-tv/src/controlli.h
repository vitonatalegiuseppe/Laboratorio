/**@file
 * @brief File contenente tutti i metodi di validazione degli input dell'utente
 *
 * In questo file sono contenuti dei metodi che effettuano dei controlli di validità dei dati,
 * necessari per un corretto funzionamento del software.
 *
 * @author Alessandro Marra
 * @author Vito Natale
 */

#ifndef CONTROLLI_H_
#define CONTROLLI_H_

#include "definizioni.h"


/**
 * @brief Procedura che verifica se il codice inserito è già presente nel file programmi
 *
 * @param *codice Codice da verificare
 * @param *file_programmi Riferimento al file dei programmi
 * @return Restituisce 1 se il codice è già presente all'interno del file, altrimenti 0
 */
unsigned short int verifica_esistenza_codice_in_file_programmi(int* codice, FILE *file_programmi);

/**
 * @brief Procedura che verifica se il codice inserito è già presente nella lista dei programmi
 *
 * @param *codice Codice da verificare
 * @param *lista_programmi Lista programmi
 * @return Restituisce 1 se il codice è già presente all'interno della lista, altrimenti 0
 */
unsigned short int verifica_esistenza_codice_in_lista_programmi(int* codice, const lista_programmi_t *lista_programmi);

/**
 * @brief Procedura che verifica se il codice inserito è già presente nella lista dei programmi suggeriti
 *
 * @param *codice Codice da verificare
 * @param *lista_programmi Lista programmi suggeriti
 * @return Restituisce 1 se il codice è già presente all'interno della lista, altrimenti 0
 */
unsigned short int verifica_esistenza_codice_in_lista_suggeriti(int* codice, const lista_programmi_suggeriti_t *lista_programmi);

/**
 * @brief Procedura che verifica se il codice inserito è già presente nell'array
 *
 * @param *codice Codice da verificare
 * @param *array Array di interi
 * @param dimensione_array Dimensione dell'array
 * @return Restituisce 1 se il codice è già presente all'interno dell'array, altrimenti 0
 */
unsigned short int verifica_esistenza_codice_in_array(int* codice, int* array, int dimensione_array);

#endif /* CONTROLLI_H_ */
