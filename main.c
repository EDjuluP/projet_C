// ce fichier regroupe des fonctions permettant l'execution du jeu des 10000

#define _CRT_SECURE_NO_WARNINGS

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>

#include "fonctions.h"

int main()
{
	Joueurs * tabJoueurs = NULL; // Tableau des joueurs

	printf("============= Bienvenue au jeu des 10000 =============\n");

	printf("\n1 - Commencer une partie !");
	printf("\n2 - Regarder les regles !\n");

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

			// Fonction qui va gérer le jeu
			Jeu(&tabJoueurs);
		}
		else if (nombreSaisi == 2) // On va afficher les règles
		{
			system("CLS");

			// On va ensuite afficher les règles
		}

		nombreChoisi = NULL; // On remet à Null

		printf("\n\nVeux-tu rejouer ou quitter ? (1 ou 0) : ");
		scanf("%d", &nombreChoisi);

		if (nombreChoisi == 1) // Si le joueur veux rejouer
		{
			free(tabJoueurs); // On libere la mémoire
		}
		else if (nombreChoisi == 0)
		{
			printf("\n\n Merci ! A plus !");
		}

	} while (nombreChoisi != 0); // Vérification si fin du jeu

	return 0;
}
