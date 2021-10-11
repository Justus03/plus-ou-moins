# define PC_FACILE 100 // PC mean Pre-processor Constant...
# define PC_MOYEN 1000
# define PC_DIFFICILE 10000
# define PC_COUP_F 7
# define PC_COUP_M 10
# define PC_COUP_D 15
# ifndef __PLUS_MOINS_H__
# define __PLUS_MOINS_H__

void menu(int var);
int noyauP_M(int nbr_joueur,int nbr_mystere,int *boolean);
struct joueur
{
  char nom[50];
  char prenom[50];
  char difficulty[10];
  int nbr_coup;
};
typedef struct joueur S_joueur;
int plus_moins(int choix_jeu,S_joueur *player); // this function returns a boolean.1 for winning and 0 for losing
void save_player(S_joueur *player);
void save_score(S_joueur *player);
void view_score();

# endif
