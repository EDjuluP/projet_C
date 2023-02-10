// Par Emmanuel DJULU PENGHE et Junior NGANAMODEÏ
// BTS SN1 - Lycée La Providence (Amiens)


typedef struct {

	char nom[20];
	int nbjoueur;
	int points;

}Joueurs;

int saisieJoueurs(Joueurs ** TabJoueurs);
void Jeu(Joueurs ** TabJoueurs, int nbJoueurs);
int calculPoints(Joueurs ** TabJoueurs, int * tabDes);
void AffichageScore(Joueurs * TabJoueurs, int nbJoueur, int winner);
