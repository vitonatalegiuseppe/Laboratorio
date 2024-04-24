/**
 * @mainpage Smart TV
 * Caso di studio di un software per una Smart TV che sia in grado di **suggerire programmi televisivi**.
 * - La Smart TV ha un unico utente utilizzatore
 * - L'utente può gestire i programmi televisivi della sua Smart TV
 * - L'utente può gestire le proprie preferenze relativamente ai programmi televisivi
 *
 * Per tutti i dettagli relativi al caso di studio fare riferimento alla traccia presente sul [portale ADA](https://elearning.di.uniba.it/mod/resource/view.php?id=26963)
 *
 * ---
 *
 * #### Traccia IV - Laboratorio di Informatica
 * - Vito Natale
 * - Alessandro Marra
 *
 * @file
 * @brief File principale del progetto Smart TV
 * @author Alessandro Marra
 * @author Vito Natale
 */

#include <stdio.h>
#include "definizioni.h"
#include "menu.h"

/// Entry point dell'applicativo
int main(void) {
	// servono su Windows sulla console di Eclipse a 64 bit per il buffer
	// http://wiki.eclipse.org/CDT/User/FAQ#Eclipse_console_does_not_show_output_on_Windows
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	FILE *file_programmi;
	FILE *file_utente;

	int scelta_menu = 0;

	printf("\t\tBENVENUTO NELLA SMART TV\n");

	file_programmi = fopen("Programmi.dat", "rb+");
	file_utente = fopen("Utente.dat", "rb+");

	if (file_programmi == NULL || file_utente == NULL) {

		printf("\n*********** Impossibile aprire il file************* \n\n");

	} else {

		while (scelta_menu != -1){
			scelta_menu = menu_principale(file_programmi, file_utente);
		}

		fclose(file_programmi);
		fclose(file_utente);
	}

	printf("\n\t++++++++++++++++++++++++++++++++++++++++\n");
	printf("\t\t\tArrivederci\n");
	printf("\t++++++++++++++++++++++++++++++++++++++++\n");

	return 0;

}
