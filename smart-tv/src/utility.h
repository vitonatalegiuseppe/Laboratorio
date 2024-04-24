/**@file
 * @brief File contenente i metodi di utilità
 *
 * In questo file sono contenuti metodi di utilità necessari per un corretto funzionamento del software.
 *
 * Metodi di lettura e scrittura su file
 * Metodi di conversione
 * Metodi di decodifica di enum
 *
 * @author Alessandro Marra
 * @author Vito Natale
 */

#ifndef UTILITY_H_
#define UTILITY_H_

#include "definizioni.h"


/**
 * @brief Metodo di lettura di un record da un file
 *
 * Questa funzione serve a generalizzare l'operazione di lettura di un record dall'interno di un file
 * Oltre al riferimento del file (@p *file) e al riferimento dell'oggetto (@p *data),
 * vengono richiesti in input alcuni dati necessari per il corretto posizionamento all'interno del file
 * - l'identificativo univoco intero dell'oggetto da scrivere (@p *id)
 * - la dimensione della struttura dati (@p dimensione_struct)
 *
 * @param *file Puntatore del file
 * @param *id Identificativo univoco intero dell'oggetto
 * @param dimensione_struct Dimensione della struttura dati
 * @param *data Puntatore all'oggetto da scrivere all'interno del file
 */
void leggi_record(FILE *file, int *id, size_t dimensione_struct, void *data);

/**
 * @brief Metodo di inserimento di un record ad un file
 *
 * Questa funzione serve a generalizzare l'operazione di aggiunta di un record all'interno di un file
 * Oltre al riferimento del file (@p *file) e al riferimento dell'oggetto (@p *data),
 * vengono richiesti in input alcuni dati necessari per il corretto posizionamento all'interno del file
 * - l'identificativo univoco intero dell'oggetto da scrivere (@p *id)
 * - la dimensione della struttura dati (@p dimensione_struct)
 *
 * @param *file Puntatore del file
 * @param *id Identificativo univoco intero dell'oggetto
 * @param dimensione_struct Dimensione della struttura dati
 * @param *data Puntatore all'oggetto da scrivere all'interno del file
 */
void scrivi_record(FILE *file, int *id, size_t dimensione_struct, void *data);


/**
 * @brief Funzione di conversione stringa in minuscolo
 *
 * Data in input una stringa e la sua lunghezza, restituisce una nuova stringa convertita in minuscolo
 *
 * @param *parola Stringa da convertire
 * @param lunghezza Lunghezza della stringa da convertire
 * @return Stringa convertita in minuscolo
 */
char* converti_in_minuscolo(char *parola, int lunghezza);

/**
 * @brief Funzione di conversione di una tipologia televisiva in stringa
 *
 * Converte una tipologia televisiva di tipo ::tipologia_e in stringa
 *
 * @param tipologia Tipologia del programma da convertire
 * @return Tipologia in formato stringa
 */
const char* nome_tipologia(tipologia_e tipologia);

/**
 * @brief Funzione di conversione di un genere televisivo in stringa
 *
 * Converte una genere televisivo di tipo ::genere_e in stringa
 *
 * @param genere Genere del programma da convertire
 * @return Genere in formato stringa
 */
const char* nome_genere(genere_e genere);

/**
 * @brief Funzione booleana di calcolo punteggio in base alla valutazione del programma
 *
 * Questa funzione implementa l'assegnazione di un punteggio ad un programma in base alla sua valutazione
 * Questa logica viene richiamata dalla procedura di calcolo dei programmi suggeriti (::calcola_punteggio)
 * 5 stelle -> +2 punti
 * 4 stelle -> +1 punto
 * 3 stelle -> +0 punti
 * 2 stelle -> -1 punti
 * 1 stella -> -2 punti
 *
 * @param *punteggio Riferimento al punteggio da modificare
 * @param valutazione Valutazione del programma televisivo
 */
void aggiungi_valutazione(short int *punteggio, int valutazione);

/**
 * @brief Procedura per il calcolo del punteggio utile per i suggerimenti
 *
 * Questa funzione serve a determinare la priorità con la quale suggerire un programma
 * Tiene conto delle preferenze utente, che vengono incrociate con le caratteristiche del programma (tipologia e genere)
 * Si tiene conto inoltre della valutazione del programma, la cui logica è demandata a ::aggiungi_valutazione
 *
 * @param *utente Utente
 * @param *programma Programma televisivo
 * @return Punteggio del programma
 */
int calcola_punteggio(const utente_t *utente, const programma_t *programma);

/**
 * @brief Procedura di generazione di un numero casuale
 *
 * La funzione genera un numero intero casuale compreso tra @p min e @p max
 *
 * @param min Numero minimo
 * @param max Numero massimo
 * @return Numero generato
 */
int genera_numero_casuale(int min, int max);

/**
 * @brief Procedura di calcolo del minimo tra due numeri
 *
 * La funzione restituisce il numero minimo tra due numeri @p a e @p b
 *
 * @param a Primo numero
 * @param b Secondo numero
 * @return Numero minimo
 */
int min(int a, int b);

/**
 * @brief Procedura di rimozione di un programma suggerito da una lista
 *
 * La funzione prende in input una lista di programmi suggeriti e l'indice del programma da rimuovere
 * Viene generata e restituita una nuova lista avente la lunghezza decrementata e l'elemento rimosso
 *
 * @param lista Lista di programmi suggeriti
 * @param indice_da_rimuovere Indice del programma da rimuovere dalla lista
 * @return Lista aggiornata
 */
lista_programmi_suggeriti_t rimuovi_programma_suggerito(lista_programmi_suggeriti_t lista, int indice_da_rimuovere);

/**
 * @brief Funzione booleana di allocazione memoria ad una ::lista_programmi_t
 *
 * La funzione prende in input una lista di programmi e ne incrementa l'allocazione (realloc) per contenere un nuovo programma_t
 * Se la lista non contiene elementi, la funzione si occupa di allocare la memoria (calloc) la prima volta
 *
 * @param *lista Lista di programmi
 */
void alloca_memoria_programmi(lista_programmi_t *lista);

/**
 * @brief Funzione booleana di allocazione memoria ad una ::lista_programmi_suggeriti_t
 *
 * La funzione prende in input una lista di programmi suggeriti e ne incrementa l'allocazione (realloc) per contenere un nuovo suggerito_t
 * Se la lista non contiene elementi, la funzione si occupa di allocare la memoria (calloc) la prima volta
 *
 * @param *lista Lista di programmi suggeriti
 */
void alloca_memoria_programmi_suggeriti(lista_programmi_suggeriti_t *lista);

/**
 * @brief Funzione booleana di inserimento di un suggerimento in una lista di programmi suggeriti
 *
 * La funzione prende in input una lista di programmi suggeriti e ne incrementa l'allocazione (realloc) per contenere un nuovo suggerito_t
 * Se la lista non contiene elementi, la funzione si occupa di allocare la memoria (calloc) la prima volta
 *
 * @param *lista Lista di programmi suggeriti
 * @param codice Codice del programma da inserire
 * @param *titolo Titolo del programma da inserire
 * @param punteggio Punteggio del programma suggerito
 */
void inserisci_suggerimento(lista_programmi_suggeriti_t *lista, int codice, char *titolo, short int punteggio);


#endif /* UTILITY_H_ */
