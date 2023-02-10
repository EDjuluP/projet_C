// Par Emmanuel DJULU PENGHE et Junior NGANAMODEÏ
// BTS SN1 - Lycée La Providence (Amiens)


typedef struct {

	char nom[20];
	int numJoueur;
	int points;

}Joueurs;

int saisieJoueurs(Joueurs ** TabJoueurs);
void Jeu(Joueurs ** TabJoueurs, int nbJoueurs);
int calculPoints(Joueurs ** TabJoueurs, int * tabJeu);
void AffichageScore(Joueurs * TabJoueurs, int nbJoueurs, int winner);
