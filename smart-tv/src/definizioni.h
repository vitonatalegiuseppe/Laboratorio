/**@file
 * @brief File contenente la definizione di tutte le definizioni utili per una corretta implementazione del software
 *
 * Strutture dati (struct), enumerazioni (enum) e costanti (define)
 *
 * @author Alessandro Marra
 * @author Vito Natale
 */

#ifndef DEFINIZIONI_H_
#define DEFINIZIONI_H_

#include <stdio.h>
#include <stdlib.h>

/**
 *  @def VALUTAZIONE_MINIMA
 *  Valutazione minima applicabile ad un programma
 */
#define VALUTAZIONE_MINIMA 1

/**
 *  @def VALUTAZIONE_MASSIMA
 *  Valutazione massima applicabile ad un programma
 */
#define VALUTAZIONE_MASSIMA 5

/**
 *  @def RISPOSTA_MIN_MENU
 *  Risposta minima che può assumere qualsiasi menu
 */
#define RISPOSTA_MIN_MENU 1

/**
 *  @def RISPOSTA_MAX_MENU_PRINCIPALE
 *  Risposta massima che può assumere il menu principale
 */
#define RISPOSTA_MAX_MENU_PRINCIPALE 6

/**
 *  @def RISPOSTA_MAX_MENU_PROGRAMMI
 *  Risposta massima che può assumere il menu di gestione dei programmi
 */
#define RISPOSTA_MAX_MENU_PROGRAMMI 4

/**
 *  @def RISPOSTA_MAX_MENU_UTENTI
 *  Risposta massima che può assumere il menu di gestione dell'utente
 */
#define RISPOSTA_MAX_MENU_UTENTI 2

/**
 *  @def RISPOSTA_MAX_MENU_SUGGERIMENTI
 *  Risposta massima che può assumere il sottomenu di suggerimento dei programmi
 */
#define RISPOSTA_MAX_MENU_SUGGERIMENTI 2

/**
 *  @def RISPOSTA_MAX_MENU_MODIFICA_PROGRAMMI
 *  Risposta massima che può assumere il sottomenu di modifica dei programmi
 */
#define RISPOSTA_MAX_MENU_MODIFICA_PROGRAMMI 4

/**
 *  @def RISPOSTA_MAX_MENU_MODIFICA_UTENTI
 *  Risposta massima che può assumere il sottomenu di modifica dell'utente
 */
#define RISPOSTA_MAX_MENU_MODIFICA_UTENTI 4

/**
 *  @def NUMERO_MIN_CODICE_PROGRAMMA
 *  Numero minimo che può assumere il codice identificativo univoco del programma televisivo
 */
#define NUMERO_MIN_CODICE_PROGRAMMA 1

/**
 *  @def NUMERO_MAX_CODICE_PROGRAMMA
 *  Numero massimo che può assumere il codice identificativo univoco del programma televisivo
 */
#define NUMERO_MAX_CODICE_PROGRAMMA 999

/**
 *  @def LUNGHEZZA_MAX_TITOLO_PROGRAMMA
 *  Lunghezza massima del titolo del programma televisivo
 */
#define LUNGHEZZA_MAX_TITOLO_PROGRAMMA 31

/**
 *  @def LUNGHEZZA_MAX_DESCRIZIONE_PROGRAMMA
 *  Lunghezza massima della descrizione del programma televisivo
 */
#define LUNGHEZZA_MAX_DESCRIZIONE_PROGRAMMA 51

/**
 *  @def LUNGHEZZA_MAX_NOME_UTENTE
 *  Lunghezza massima del nome dell'utente utilizzatore della Smart TV
 */
#define LUNGHEZZA_MAX_NOME_UTENTE 21

/**
 *  @def LUNGHEZZA_MAX_COGNOME_UTENTE
 *  Lunghezza massima del cognome dell'utente utilizzatore della Smart TV
 */
#define LUNGHEZZA_MAX_COGNOME_UTENTE 21

/**
 *  @def NUMERO_MAX_TIPOLOGIE_PREFERITE_UTENTE
 *  Numero massimo di tipologie (di programmi televisivi) preferite che l'utente può salvare nel proprio profilo
 */
#define NUMERO_MAX_TIPOLOGIE_PREFERITE_UTENTE 3

/**
 *  @def NUMERO_MAX_GENERI_PREFERITI_UTENTE
 *  Numero massimo di generi (di programmi televisivi) preferiti che l'utente può salvare nel proprio profilo
 */
#define NUMERO_MAX_GENERI_PREFERITI_UTENTE 5

/**
 *  @def NUMERO_MAX_PROGRAMMI_SUGGERITI
 *  Numero massimo di programmi che vengono suggeriti dalla funzione suggerisci all'utente
 */
#define NUMERO_MAX_PROGRAMMI_SUGGERITI 10

/**
 *  @enum tipologia_e
 *  Elenco di tutte le possibili tipologie di un programma televisivo
 */
typedef enum {
	SERIE = 1, ///< Serie
	DOCUMENTARI, ///< Documentari
	FILM, ///< Film
	INTRATTENIMENTO, ///< Intrattenimento
	BAMBINI, ///< Bambini
	INFORMAZIONE ///< Informazione
} tipologia_e;

/**
 *  @def NUMERO_TIPOLOGIE_PROGRAMMA
 *  Numero totale delle tipologie di programmi televisivi presenti nel sistema
 */
#define NUMERO_TIPOLOGIE_PROGRAMMA 6


/**
 *  @enum genere_e
 *  Elenco di tutti i possibili generi di un programma televisivo
 */
typedef enum {
	FANTASCIENZA = 1, ///< Fantascienza
	CUCINA, ///< Cucina
	NATURA, ///< Natura
	SPORT, ///< Sport
	STORICO, ///< Storico
	HORROR, ///< Horror
	ATTUALITA, ///< Attualità
	COMICO, ///< Comico
	DRAMMATICO, ///< Drammatico
	FANTASY, ///< Fantasy
	ROMANTICO ///< Romantico
} genere_e;

/**
 *  @def NUMERO_GENERI_PROGRAMMA
 *  Numero totale dei generi di programmi televisivi presenti nel sistema
 */
#define NUMERO_GENERI_PROGRAMMA 11


/** @struct utente_t
 *  @brief Questa struttura dati rappresenta l'utente unico utilizzatore della Smart TV
 */
typedef struct {
	/// Nome dell'utente (lunghezza massima ::LUNGHEZZA_MAX_NOME_UTENTE)
	char nome[LUNGHEZZA_MAX_NOME_UTENTE];

	/// Cognome dell'utente (lunghezza massima ::LUNGHEZZA_MAX_COGNOME_UTENTE)
	char cognome[LUNGHEZZA_MAX_COGNOME_UTENTE];

	/// Elenco delle tipologie preferite dall'utente (numero massimo ::NUMERO_MAX_TIPOLOGIE_PREFERITE_UTENTE)
	tipologia_e tipologie_preferite[NUMERO_MAX_TIPOLOGIE_PREFERITE_UTENTE];

	/// Elenco dei generi preferiti dall'utente (numero massimo ::NUMERO_MAX_GENERI_PREFERITI_UTENTE)
	genere_e generi_preferiti[NUMERO_MAX_GENERI_PREFERITI_UTENTE];

} utente_t;

/** @struct programma_t
 *  @brief Questa struttura dati rappresenta il programma televisivo presente sulla Smart TV
 */
typedef struct {
	/// Codice identificativo univoco del programma
	int codice_programma;

	/// Titolo del programma televisivo (lunghezza massima ::LUNGHEZZA_MAX_TITOLO_PROGRAMMA)
	char titolo[LUNGHEZZA_MAX_TITOLO_PROGRAMMA];

	/// Tipologia del programma, enumerativo, di tipo tipologia_e
	tipologia_e tipologia;

	/// Genere del programma, enumerativo, di tipo genere_e
	genere_e genere;

	/// Descrizione del programma televisivo (lunghezza massima ::LUNGHEZZA_MAX_DESCRIZIONE_PROGRAMMA)
	char descrizione[LUNGHEZZA_MAX_DESCRIZIONE_PROGRAMMA];

	/// Valutazione data dall'utente al programma, da 0 a 5
	int valutazione;

	/// Flag che indica se il programma è già stato suggerito dalla Smart TV e consultato dall'utente
	unsigned int suggerito;

} programma_t;


/** @struct lista_programmi_t
 *  @brief Questa struttura dati rappresenta una lista di programmi ed il numero di elementi di cui è composta
 */
typedef struct {
	/// Lista dei programmi (struttura dati dinamica di tipo ::programma_t*)
	programma_t* lista_programmi;

	/// Numero di programmi presenti nella lista
	int numero_programmi;

} lista_programmi_t;


/** @struct suggerimento_t
 *  @brief Questa struttura dati rappresenta il programma che può suggerito per l'utente
 */
typedef struct {
	/// Codice identificativo univoco del programma
	int codice_programma;

	/// Titolo del programma televisivo (lunghezza massima ::LUNGHEZZA_MAX_TITOLO_PROGRAMMA)
	char titolo_programma[LUNGHEZZA_MAX_TITOLO_PROGRAMMA];

	/// Contatore utilizzato per l'ordinamento con cui presentare i programmi suggeriti
	short int punteggio;

} suggerimento_t;


/** @struct lista_programmi_suggeriti_t
 *  @brief Questa struttura dati rappresenta una lista di programmi suggeriti ed il numero di elementi di cui è composta
 */
typedef struct {
	/// Lista dei programmi suggeriti (struttura dati dinamica di tipo ::suggerimento_t*)
	suggerimento_t* lista_programmi;

	/// Numero di programmi presenti nella lista
	int numero_programmi;

} lista_programmi_suggeriti_t;


/**
 *  @def PUNTEGGIO_TIPOLOGIA
 *  Valore da assegnare al programma se la tipologia del programma rientra tra le tipologie preferite dell’utente
 */
#define PUNTEGGIO_TIPOLOGIA 1

/**
 *  @def PUNTEGGIO_GENERE
 *  Valore da assegnare al programma se il genere del programma rientra tra i generi preferiti dell’utente
 */
#define PUNTEGGIO_GENERE 1

/**
 *  @def PUNTEGGIO_VALUTAZIONE_5
 *  Valore da assegnare al programma se la valutazione del programma è 5
 */
#define PUNTEGGIO_VALUTAZIONE_5 2

/**
 *  @def PUNTEGGIO_VALUTAZIONE_4
 *  Valore da assegnare al programma se la valutazione del programma è 4
 */
#define PUNTEGGIO_VALUTAZIONE_4 1

/**
 *  @def PUNTEGGIO_VALUTAZIONE_3
 *  Valore da assegnare al programma se la valutazione del programma è 3
 */
#define PUNTEGGIO_VALUTAZIONE_3 0

/**
 *  @def PUNTEGGIO_VALUTAZIONE_2
 *  Valore da assegnare al programma se la valutazione del programma è 2
 */
#define PUNTEGGIO_VALUTAZIONE_2 -1

/**
 *  @def PUNTEGGIO_VALUTAZIONE_1
 *  Valore da assegnare al programma se la valutazione del programma è 1
 */
#define PUNTEGGIO_VALUTAZIONE_1 -2

/**
 *  @def PUNTEGGIO_VALUTAZIONE_0
 *  Valore da assegnare al programma se la valutazione del programma è 0
 */
#define PUNTEGGIO_VALUTAZIONE_0 0


#endif /* DEFINIZIONI_H_ */
