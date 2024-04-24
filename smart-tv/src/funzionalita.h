/**@file
 * @brief File contenente gli algoritmi utili per la realizzazione delle funzionalità del software
 * Algoritmi di ricerca, algoritmi di ordinamento
 * @author Alessandro Marra
 * @author Vito Natale
 */

#ifndef FUNZIONALITA_H_
#define FUNZIONALITA_H_

#include <stdio.h>
#include "definizioni.h"


/**
 * @brief Metodo di lettura dei programmi televisivi da file
 *
 * La funzione legge tutti i programmi televisivi presenti nel file @p *file_programmi e li stampa utilizzando la funzione ::stampa_programma
 *
 * @param *file_programmi Puntatore del file
 */
void stampa_elenco_programmi_da_file(FILE *file_programmi);


/**
 * @brief Metodo di inserimento di programma televisivi all'interno del file
 *
 * All'utente vengono richiesti tutti i dettagli del programma televisivo da inserire.
 * Il programma acquisito viene salvato all'interno del @p *file_programmi
 *
 * @param *file_programmi Puntatore del file
 */
void inserisci_programma(FILE *file_programmi);


/**
 * @brief Metodo di modifica dei programmi televisivi da file
 *
 * La funzione consente di effettuare la ricerca di un programma (per titolo e descrizione) tramite ::ricerca_programmi.
 * Viene acquisito il codice del programma da modificare.
 * Tramite un sottomenu dedicato (::stampa_menu_modifica_programma) vengono richieste le informazioni da modificare
 * Il programma modificato viene aggiornato all'interno del @p *file_programmi
 *
 * @param *file_programmi Puntatore del file
 */
void modifica_programma(FILE *file_programmi);


/**
 * @brief Metodo di eliminazione dei programmi televisivi da file
 *
 * La funzione consente di effettuare la ricerca di un programma (per titolo e descrizione) tramite ::ricerca_programmi.
 * Viene acquisito il codice del programma da eliminare e viene aggiornato il file dei programmi.
 *
 * @param *file_programmi Puntatore del file
 */
void elimina_programma(FILE *file_programmi);

/**
 * @brief Funzione booleana di ordinamento programmi
 *
 * La funzione acquisisce l'elenco completo dei programmi dal @p file_programmi*
 * Applica l'algoritmo ::quickSort per ordinarli
 * Utilizza il metodo ::stampa_programma per la visualizzazione della lista ordinata
 *
 * @param *file_programmi Puntatore al file dei programmi
 */
void ordinamento_programmi(FILE *file_programmi);


/**
 * @brief Funzione booleana di valutazione programma televisivo
 *
 * La funzione consente di effettuare la ricerca di un programma (per titolo e descrizione) tramite ::ricerca_programmi.
 * Viene acquisito il codice del programma da valutare.
 * Il programma valutato viene aggiornato all'interno del @p *file_programmi
 *
 * @param *file_programmi Puntatore del file
 */
void valuta_programma(FILE *file_programmi);


/**
 * @brief Funzione booleana di suggerimento programmi televisivi
 *
 * La funzione applica un criterio di priorità incrociando le preferenze utente e le caratteristiche dei programmi non ancora suggeriti.
 * La lista programmi suggeriti viene mostrata all'utente (::stampa_programma_suggerito)
 * L'utente può scegliere se contrassegnare uno dei programmi come visionato (non sarà più suggerito successivamente)
 *
 * @param *file_programmi Puntatore al file dei programmi
 * @param *file_utente Puntatore al file degli utenti
 */
void suggerimento_programmi(FILE *file_programmi, FILE *file_utente);

/**
 * @brief Funzione booleana di visione programma televisivo
 *
 * L'utente può scegliere se contrassegnare uno dei programmi come visionato (non sarà più suggerito successivamente)
 *
 * @param *file_programmi Puntatore al file dei programmi
 * @param lista_programmi_suggeriti Elenco dei programmi suggeriti dai quali scegliere il programma da visionare
 */
void richiedi_visione_suggerimento(FILE *file_programmi, lista_programmi_suggeriti_t lista_programmi_suggeriti);

/**
 * @brief Procedura di ricerca dei programmi televisivi
 *
 * La funzione acquisisce una stringa che verrà ricercata all'interno di titolo e descrizione dei programmi presenti sul file.
 * La ricerca è tipo case insensitive e funzione su sottostringhe.
 * Viene restituita una struttura dati ::lista_programmi_t contenente la lista dei programmi trovati ed il numero di elementi di cui è composta la lista dei risultati.
 * Questa procedura è generica e viene utilizzata in funzionalità differenti (ricerca programmi, modifica programma, eliminazione programma, valutazione programma)
 *
 * @param *file_programmi Puntatore al file dei programmi
 * @return Lista dei programmi trovati
 */
lista_programmi_t ricerca_programmi(FILE *file_programmi);


/**
 * @brief Metodo di visualizzaione del profilo utente
 *
 * La funzione legge il profilo dell'utente dal file @p file_utente e presenta le informazioni tramite ::stampa_utente
 *
 * @param *file_utente Puntatore al file degli utenti
 */
void visualizza_utente(FILE *file_utente);

/**
 * @brief Metodo di modifica del profilo utente
 *
 * La funzione propone un sottomenu dedicato (::stampa_menu_modifica_utente) che consente all'utente di modificare uno dei campi del profilo utente
 * Il profilo utente modificato viene aggiornato all'interno del @p *file_utente
 *
 * @param *file_utente Puntatore al file degli utenti
 */
void modifica_utente(FILE *file_utente);


#endif /* FUNZIONALITA_H_ */
