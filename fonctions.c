#define _CRT_SECURE_NO_WARNINGS

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>

#include "fonctions.h"

void Jeu(Joueurs * TabJoueurs)
{
	int nbJoueur = saisiJoueurs(TabJoueurs); // Saisi des joueurs

	// generer les scores de chaque joueur

	
	srand(time(NULL));

	int des[6]; // On fait un tableau pour stocker les valeurs des 6 dés 

	for (int i = 0; i < nbJoueur; i++)
	{
		printf("\nVotre tirage donne : ");
		for (int j = 0; j < 6; j++) // On tire les valeurs des 6 dés
		{
			des[j] = rand() % 6 + 1;  // Entre 1 et 6

			printf("%d ", des[j]);
		}
		getchar();
	}
	
}

int saisieJoueurs(Joueurs * TabJoueurs)
{
	int nbjoueur;

	printf("Entrez le nombre de joueur entre 2 et 6\n\n");
	scanf("%d", &nbjoueur);

	// la boucle se repète tant que l'utilisateur saisit un chiffre inferieur a 2 ou superieur a 6
	while (nbjoueur < 2 && nbjoueur > 6)
	{
		printf("Entrez le nombre de joueur entre 2 et 6\n\n");
		scanf("%d", &nbjoueur);
	}

	TabJoueurs[nbjoueur]; // On créer le tableau des joueurs

	for (int i = 0; i < nbjoueur; i++)
	{
		// demander aux joueurs d'entrer leurs noms

		printf("Entrez le nom du joueur %d:  ", i + 1);
		scanf("%s", TabJoueurs[i].nom);
	}

	return nbjoueur;
}


int calculPoints(Joueurs * TabJoueurs, int * tabJeu)
{
	int scoreJoueur = 0;
	int tabDes[6] = { 0,0,0,0,0,0 };

	for (int i = 0; i < 6; i++)
	{
		if (tabJeu[i] == 1)
		{
			tabDes[0] += 1;
			scoreJoueur = 100;
		}
		else if (tabJeu[i] = 2)
		{
			tabDes[1] += 2;
		}
		else if (tabJeu[i] = 3)
		{
			tabDes[2] = 3;
		}
		else if (tabJeu[i] = 4)
		{
			tabDes[3] += 4;
		}
		else if (tabJeu[i] = 5)
		{
			tabDes[4] += 5;
		}
		else if (tabJeu[i] = 5)
		{
			tabDes[5] += 6;
		}
	}

	if (tabDes[0] == 6)
	{
		scoreJoueur = 1;
	}
	else if (tabDes[1] == 12 || tabDes[2] == 18 || tabDes[3] == 24 || tabDes[4] == 30 || tabDes[5] == 36)
	{
		scoreJoueur += 1000 * tabJeu[0];
	}

	for (int i = 0; i < 6; i++)
	{
		if (tabJeu[i] == 1 && tabDes[0] == 3 || tabDes[0] == 4 || tabDes[0] == 5)
		{
			scoreJoueur += 1000;
			tabDes[0] = 0;
		}
		else
		{
			if (tabJeu[i] == 2 && tabDes[1] == 6 || tabDes[1] == 8 || tabDes[1] == 10)
			{
				scoreJoueur += 100 * tabJeu[i];
				tabDes[1] = 0;
			}
			else if (tabJeu[i] == 3 && tabJeu[2] == 9 || tabDes[2] == 12 || tabDes[2] == 15)
			{
				scoreJoueur += 100 * tabJeu[i];
				tabDes[2] = 0;
			}
			else if (tabJeu[i] == 4 && tabDes[3] == 12 || tabDes[3] == 16 || tabDes[3] == 20)
			{
				scoreJoueur += 100 * tabJeu[i];
				tabDes[3] = 0;
			}
			else if (tabJeu[i] == 5 && tabDes[4] == 15 || tabDes[4] == 20 || tabDes[4] == 25)
			{
				scoreJoueur += 100 * tabJeu[i];
				tabDes[4] = 0;
			}
			else if (tabJeu[i] == 6 && tabDes[2] == 18 || tabDes[2] == 24 || tabDes[2] == 30)
			{
				scoreJoueur += 100 * tabJeu[i];
				tabDes[5] = 0;
			}
		}
	}

	if (scoreJoueur == 0)
	{
		scoreJoueur -= 1000;
	}

	return scoreJoueur;
}



void AffichageScore(Joueurs * TabJoueurs, int nbJoueur, int winner)
{
	if (winner == 1) // Si un gagnant
	{

	}
}

