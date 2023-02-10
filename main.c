// Par Emmanuel DJULU PENGHE et Junior NGANAMODEÏ 
// BTS SN1 - Lycée La Providence (Amiens)

#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "fonctions.h"

    extern int calculPoints(Joueurs * TabJoueurs, int * tabJeu);

int main()
{
	Joueurs * TabJoueurs = NULL; // Tableau des joueurs

	printf("============= Bienvenue au jeu des 10000 =============\n");

	printf("\n1 - Commencer une partie !");
	printf("\n2 - Afficher les regles !\n");

	// Menu d'acceuil
	int nombreSaisi;
	printf("\nVeuillez saisir un chiffre entre 1 et 2 : ");
	scanf("%d", &nombreSaisi);

	// Boucle du jeu
	int nombreChoisi;
	do {

		if (nombreSaisi == 1) // On va lancer le jeu
		{
			system("CLS");

			int nbJoueurs = saisieJoueurs(&TabJoueurs);

			// Fonction qui va gérer le jeu
			Jeu(&TabJoueurs, nbJoueurs);

		}
		else if (nombreSaisi == 2) // On va afficher les règles
		{
			system("CLS");

		}

		nombreChoisi = NULL; // On remet à Null
	
		printf("\n\nVeux-tu rejouer ou quitter ? (1 ou 0) : ");
		scanf("%d", &nombreChoisi);


		if (nombreChoisi == 0)
		{
			printf("\n\n Merci ! A plus !");
		}

	} while (nombreChoisi != 0); // Vérification si fin du jeu

	



	return 0;
}
