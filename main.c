// Par Emmanuel DJULU PENGHE et Junior NGANAMODEÏ
// BTS SN1 - Lycée La Providence (Amiens)



#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "fonctions.h"



int main(int argc, char ** argv)
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

			// On va ensuite afficher les règles

			printf("Voici les regles du jeu des 10000 !\n\n");

			// Nombre de joueurs min - max
			printf("Nombre de des : 6\n\n");

			// Nombre de joueurs min - max
			printf("Nombre de joueurs : de 2 a 6 \n\n");

			// Regle et but du jeu
			printf("Regles du jeu :\n\n");
			printf("Lorsque un joueur atteint ou depasse 10 000 points, il est considere comme\n");
			printf("temporairement gagnant mais on finit le tour pour permettre a un autre joueur de\n");
			printf("surpasser ce score.\n\n");

			printf("On lance les des d'un coup. On additionne les points de chaque lancer.\n\n");

			printf("Si on ne fait aucun point lors d un lancer des des, on ne marque aucun point, on\n");
			printf("perd meme 1000 points a 6 des. Cependant, on ne peut devenir negatif et on\n");
			printf("descend a 0.\n\n");

			// Barème (Combinaisons)
			printf("Bareme :\n\n");

			printf("   Combinaison   |  Nombre de points\n");
			printf("ou valeur de de  |\n");
			printf("	1	 |	100\n");
			printf("	5	 |	50\n");
			printf("      3 des	 |  100 * la valeur du de\n");
			printf("    identiques	 |\n");
			printf("      1+1+1	 |  1000\n");
			printf("      6 des	 |  1000 * la valeur du de\n");
			printf("    identiques	 |\n");
			printf("   1+1+1+1+1+1	 |  Partie gagnee\n");

			Sleep(3000);
		}

		nombreChoisi = NULL; // On remet à Null
	
		printf("\n\nVeux-tu rejouer ou quitter ? (Oui = 1 ou  Non = 0) : ");
		scanf("%d", &nombreChoisi);




		if (nombreChoisi == 0)
		{
			printf("\n\n Merci ! A plus !");
		}

	} while (nombreChoisi != 0); // Vérification si fin du jeu

	



	return 0;
}
