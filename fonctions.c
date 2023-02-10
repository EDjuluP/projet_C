// Par Emmanuel DJULU PENGHE et Junior NGANAMODEÏ //
// BTS SN1 - Lycée La Providence (Amiens) //



#define _CRT_SECURE_NO_WARNINGS

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>

#include "fonctions.h"

int saisieJoueurs(Joueurs ** TabJoueurs)
{
	int nbJoueurs;
	int Joueurs;
	// Saisie des joueurs
	printf("Entrez le nombre de joueurs entre 2 et 6 :\n\n");
	scanf("%d", &nbJoueurs);

	// La boucle se repète tant que l'utilisateur saisit un chiffre inferieur a 2 ou superieur a 6
	while (nbJoueurs < 2 && nbJoueurs > 6)
	{
		printf("Entrez le nombre de joueurs entre 2 et 6 :\n\n");
		scanf("%d", &nbJoueurs);
	}

	*TabJoueurs = malloc(nbJoueurs * sizeof(Joueurs)); // On crée le tableau des joueurs

	for (int i = 0; i < nbJoueurs; i++)
	{
		char nom[20];
		// Demander aux joueurs d'entrer leurs noms
		printf("Entrez le nom du joueur %d:  ", i + 1);
		scanf("%s", nom);

		int joueurPresent = 0;
		
		
		for (int i = 0; i < nbJoueurs; i++) // On parcourt notre tableau de joueurs
		{
			if (strcmp(nom,  (*TabJoueurs)[i].nom) == 0)
			{
				joueurPresent = 1;
			
				break;
			}
		}

		while (joueurPresent == 1) // Tant qu'il est déjà présent
		{
			printf("\n\nNom deja existant ! Veuillez en saisir un autre SVP ! : ");
			scanf("%s", nom);

			// ON VA VERIFER QUIL EXISTE OU PAS
			joueurPresent = 0;

			for (int j = 0; j < nbJoueurs; j++) // On parcour notre tableau de joueur
			{
				if (strcmp(nom, *TabJoueurs) == 0)
				{
					joueurPresent = 1;
					break;
				}
			}
		}

		strcpy(*TabJoueurs, nom);
	}
}


void Jeu(Joueurs ** TabJoueurs, int nbJoueurs)
{
	int winner = 0;

	// Générer les scores de chaque joueur
	srand(time(NULL));

	int points = 0;
	//int scoreFinalJoueur = 0;

	do {

		for (int i = 0; i < nbJoueurs; i++)
		{




			int des[6]; // On fait un tableau pour stocker les valeurs des 6 dés 

			printf("\n %s, votre tirage donne : ", (*TabJoueurs)[i].nom);
			for (int j = 0; j < 6; j++) // On tire les valeurs des 6 dés
			{
				des[j] = rand() % 6 + 1;  // Entre 1 et 6

				printf("%d ", des[j]);
				
			}	



			int score = calculPoints(TabJoueurs, des);

			if (score == -1000) // S'il perd 1000 points
			{
				// On va verifier qu'il n'est pas déjà à 0 points
				if ((*TabJoueurs)[i].points != 0)
				{
					int result = (*TabJoueurs)[i].points + score; // On fait la soustraction des 1k points

					if (result >= 0)
					{
						(*TabJoueurs)[i].points -= 1000;
					}
					else
					{
						(*TabJoueurs)[i].points = 0;
					}
				}
			}
			else
			{
				(*TabJoueurs)[i].points += score; // On lui met son nombre de points
			}

			if (score == 1) // Si un joueur a gagné
			{
				winner = 1;
				(*TabJoueurs)[i].points += 99999; // Son score sera égal à l'infini (99999)

				printf("Vous avez gagné !");
				break;
			}
			else if ((*TabJoueurs)[i].points >= 10000) // Si score est supérieur ou égal à 10 000 pooints 
			{
				winner = 1;
				printf("\n Sur ce tour, votre score est de : %d points", score);
			}
			else
			{
				if (score == -1000)
				{
					printf("\n Sur ce tour, votre score est de : 0 point (Vous perdez 1000 points mais votre score ne peut pas etre inferieur a 0 !)");
				}
				else
				{
					printf("\n Sur ce tour, votre score est de : %d points", score);
				}
			}
		
				/*scoreFinalJoueur += (*TabJoueurs)[i].points;
				printf("\n %s, votre nouveau score est : %d\n\n", (*TabJoueurs)[i].nom, scoreFinalJoueur);
				*/
		}
		
		
		
	} while (winner != 1);
	// (scoreFinalJoueur< 10000);
}

int calculPoints(Joueurs * TabJoueurs, int * tabJeu)
{

	// Dans cette partie, nous allons identifier les différentes combinaisons
	// et effectuer les calculs de points en fonction de ces combinaisons
	// pour ensuite attribuer les scores à chaque joueur.



	int scoreJoueur = 0;

	// On crée un tableau de 6 cases
	// Il va nous permettre de déterminer les fois où un dé se répète
	// Dès qu'un chiffre apparaît, il est additionné au tableau

	int tabDes[6] = { 0,0,0,0,0,0 }; 

	for (int i = 0; i < 6; i++)
	{
		if (tabJeu[i] == 1) //Si un dé est égale à 1
		{
			tabDes[0] += 1; // On ajoute 1 à la 1ère case du tableau des dès
			scoreJoueur += 100; // On augmente le score de 100 car il y a un dé de valeur 1
		}
		else if (tabJeu[i] == 2)
		{
			tabDes[1] += 2; // On ajoute 2 à la 2ème case du tableau des dès
		}
		else if (tabJeu[i] == 3)
		{
			tabDes[2] = 3; // On ajoute 3 à la 3ème case du tableau des dès
		}
		else if (tabJeu[i] == 4)
		{
			tabDes[3] += 4; // On ajoute 4 à la 4ème case du tableau des dès
		}
		else if (tabJeu[i] == 5)
		{
			tabDes[4] += 5; // On ajoute 5 à la 5ème case du tableau des dès
			scoreJoueur += 50; // On augmente le score de 50 car il y a un dé de valeur 5
		}
		else if (tabJeu[i] == 6)
		{
			tabDes[5] += 6; // On ajoute 6 à la 6ème case du tableau des dès
		}
	}

	// On s'intéresse ici à la combinaison : 6 dès identiques
	if (tabDes[0] == 6) // Si le joueur obtient la combinaison gagnante : six 1 
	{
		scoreJoueur = 1; // Victoire !
	}
	else if (tabDes[1] == 12 || tabDes[2] == 18 || tabDes[3] == 24 || tabDes[4] == 30 || tabDes[5] == 36)
	{
		scoreJoueur += 1000 * tabJeu[0]; // 1000 fois la valeur du dé
	}


	for (int i = 0; i < 6; i++)
	{
		// On s'intéresse à la combinaison : 3 dès identiques (minimum)
		
		if (tabJeu[i] == 1 && tabDes[0] == 3 || tabDes[0] == 4 || tabDes[0] == 5)
		{
			scoreJoueur += 1000;
			tabDes[0] = 0; // on réinitialise à 0 afin que le compilateur ne reprenne pas en compte ce qu'il a calculé précédemment
		}
		else
		{
			if (tabJeu[i] == 2 && tabDes[1] == 6 || tabDes[1] == 8 || tabDes[1] == 10)
			{
				scoreJoueur += 100 * tabJeu[i]; // 100 fois la valeur du dé
				tabDes[1] = 0; // on réinitialise à 0 afin que le compilateur ne reprenne pas en compte ce qu'il a calculé précédemment
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

	if (scoreJoueur == 0) // Si le joueur n'obtient aucune combinaison ou aucun point, il perd 1000 points
	{
		scoreJoueur -= 1000;
	}

	return scoreJoueur; // Le compilateur renvoie le score du joueur
}



void AffichageScore(Joueurs * TabJoueurs, int nbJoueurs, int winner)
{    

	if (winner == 1) // Si il y a un gagnant
	{
		int scoreWinner = 0, indexWinner = 0; // Pour trier le tableau des scores dans l'ordre croissant
		int *finalScores; // Pointeur pour allocation dynamique
		finalScores = malloc(nbJoueurs * sizeof(int)); // On crée un tableau d'une taille égale au nombre de joueurs

		for (int j = 0; j < nbJoueurs; j++) // Pour avoir le numéro du joueur ayant le plus de point donc le gagnant
		{
			if (TabJoueurs[j].points > scoreWinner) // On cherche le score max et son index
			{
				scoreWinner = TabJoueurs[j].points;
				indexWinner = j;
			}
		}

		// Ensuite on annonce le nom du gagnant avec son nombre de points
		printf("\n\nLe gagnant de la partie est %s avec un total : %d points !!!\n", TabJoueurs[indexWinner].points, TabJoueurs[indexWinner].points);

		// Et on affiche le classement final
		for (int i = 0; i < nbJoueurs; i++)
		{
			printf("\n%s -> Score : %d\n", TabJoueurs[i].nom, TabJoueurs[i].points);
		}

	}
	else
	{
		printf("\n\nVoici les scores actuel :\n");
		for (int i = 0; i < nbJoueurs; i++)
		{
			printf("\n%s -> Score : %d\n", TabJoueurs[i].nom, TabJoueurs[i].points);
		}
	}
}
