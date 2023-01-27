typedef struct {

	char nom[20];
	int nbjoueur;
	int score;

}Joueurs;

int saisiJoueurs(Joueurs ** TabJoueurs);
void Jeu(Joueurs ** TabJoueurs);
int calculPoints(Joueurs ** TabJoueurs, int * tabDes);
void AffichageScore(Joueurs * TabJoueurs, int nbJoueur, int winner);
