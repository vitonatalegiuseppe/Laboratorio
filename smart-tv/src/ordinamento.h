/**@file
 * @brief File contenente gli algoritmi di ordinamento
 *
 * In questo file sono contenuti gli algoritmi di ordinamento adeguati alle strutture dati del software
 *
 * @author Alessandro Marra
 * @author Vito Natale
 */

#ifndef ORDINAMENTO_H_
#define ORDINAMENTO_H_

/**
 * @brief Funzione booleana dell'algoritmo di ordinamento quickSort
 *
 * L'algoritmo è un algoritmo standard di ordinamento, adeguato per lavorare con la struttura dati ::programma_t
 */
void quickSort(programma_t* array, int low, int high);

/**
 * @brief Procedura standard facente parte dell'algoritmo di ordinamento ::quickSort
 *
 * La procedura è stata adeguata per lavorare con la struttura dati ::programma_t
 */
int partition(programma_t* array, int low, int high);

/**
 * @brief Funzione booleana standard facente parte dell'algoritmo di ordinamento ::quickSort
 *
 * La funzione è stata adeguata per lavorare con la struttura dati ::programma_t
 */
void swap(programma_t *a, programma_t *b);

/**
 * @brief Funzione booleana dell'algoritmo di ordinamento shellSort
 *
 * L'algoritmo è un algoritmo standard di ordinamento, adeguato per lavorare con la struttura dati ::suggerimento_t
 */
void shellSort(suggerimento_t* vett, int dim);

#endif /* ORDINAMENTO_H_ */
