# include<stdio.h>
# include<stdlib.h>
# include<time.h>
# include<string.h>
/******************************/
# include"plus_moins.h"

void menu(int var)
{
  if(var==0) // menue principale
    {
      printf("*********************\n");
      printf("*** PLUS OU MOINS ***\n");
      printf("*********************\n");
      printf("\t1.Jouer\n\t2.Aide\n\t3.scores\n\t4.Apropos du jeu\n\t5.Quitter\n");
    }
  else if(var==1) // niveau de difficulté
    {
      printf("*************\n");
      printf("*** JOUER ***\n");
      printf("*************\n");
      printf("\t1.Facile\n\t2.Moyen\n\t3.Difficile\n");
    }
  else if(var==2) // aide
    {
      printf("************\n");
      printf("*** AIDE ***\n");
      printf("************\n");
      printf("\tLe but du jeu est de deviner un nombre choisi par l'ordinateur.\n\tLe nombre à déviner sera plus ou moins grand selon le niveau \n\tde difficulté que vous aurez choisi. Des indices vous sont don-\n\tnés à fin de vous aidé à trouver le nombre.\n");
    }
  else if(var==3) // scores
    {
      printf("**************\n");
      printf("*** SCORES ***\n");
      printf("**************\n");
    }
  else if(var==4) // apropos du jeu
    {
      printf("**********************\n");
      printf("*** APROPOS DU JEU ***\n");
      printf("**********************\n");
      printf("\tAUTHEUR: justus\n\tDATE: 09/09/2021\n\tEMAIL: simporekevin07@gmail.com\n");
    }
  else // quitter
    {
      printf("***************\n");
      printf("*** QUITTER ***\n");
      printf("***************\n");
      printf("\tMerci d'avoir utiliser notre programme...\nA bientot !!!\n");
    }
  
}

int plus_moins(int choix_jeu, S_joueur *player)
{
  int boolean=0,nbr_mystere=0,nbr_joueur=0;

  switch(choix_jeu)
    {
    case 1:
      strcpy(player->difficulty,"facile");
      break;
    case 2:
      strcpy(player->difficulty,"moyen");
      break;
    case 3:
      strcpy(player->difficulty,"difficile");
      break;
    case 4:
      strcpy(player->difficulty,"multijoueur");
    }
  switch(choix_jeu)
    {
    case 1:
      nbr_mystere=rand()%PC_FACILE+1;
      printf("Vous avez choisi le niveau facile!!!\nLe nombre mystere dans ce niveau est compris entre 1 et 100\nVous disposez de %d coups\n",PC_COUP_F);
      do
	{
	  printf("Quel est le nombre?:\n");
	  scanf("%d",&nbr_joueur);
	  player->nbr_coup=noyauP_M(nbr_joueur,nbr_mystere,&boolean);
	}while(!boolean && player->nbr_coup<=PC_COUP_F);
      break;
    case 2:
      nbr_mystere=rand()%PC_MOYEN+1;
      printf("Vous avez choisi le niveau moyen!!!\nLe nombre mystere dans ce niveau est compris entre 1 et 1000\nVous disposez de %d coups\n",PC_COUP_M);
      do
	{
	  printf("Quel est le nombre?:\n");
	  scanf("%d",&nbr_joueur);
	  player->nbr_coup=noyauP_M(nbr_joueur,nbr_mystere,&boolean);
	}while(!boolean && player->nbr_coup<=PC_COUP_M);
      break;
    case 3:
      nbr_mystere=rand()%PC_DIFFICILE+1;
      printf("Vous avez choisi le niveau difficile!!!\nLe nombre mystere dans ce niveau est compris entre 1 et 10000\nVous disposez de %d coups\n",PC_COUP_D);
      do
	{
	  printf("Quel est le nombre?:\n");
	  scanf("%d",&nbr_joueur);
	  player->nbr_coup=noyauP_M(nbr_joueur,nbr_mystere,&boolean);
	}while(!boolean && player->nbr_coup<=PC_COUP_D);
      break;
    }

  return boolean;
}

int noyauP_M(int nbr_joueur,const int nbr_mystere,int *boolean)
{
  static int coup_actuel=1;
  
  if(nbr_mystere<nbr_joueur)
    printf("C'est moins que ça\n");
  else if(nbr_mystere>nbr_joueur)
    printf("C'est plus que ça\n");
  else
    {
      printf("Felicitation vous avez trouvez le nombre mystere en %d coup(s)\n",coup_actuel);
      *boolean=1;
    }
  return coup_actuel++;
}

void save_player(S_joueur *player)
{
  printf("Quel est votre nom?\n");
  scanf("%s",player->nom);
  printf("Quel est votre prenom?\n");
  scanf("%s",player->prenom);
}

void save_score(S_joueur *player)
{
  FILE *score=NULL;
  score=fopen("../files/scores.txt","a");

  if(score)
    {
      fprintf(score,"Joueur:\n\tnom:%s\n\tprenom:%s\n\tniveau:%s\n\tcoup(s):%d\n",player->nom,player->prenom,player->difficulty,player->nbr_coup);
      fclose(score);
      printf("Votre score à bien été enregistré.\n");
    }
  else
    printf("Une eureur c'est produite lors de l'enregistrement de votre score.\nVeuillez reessayer...\n");
}

void view_score()
{
  FILE *score=NULL;
  score=fopen("../files/scores.txt","r");

  if(score)
    {
      int caract=0;
      do
	{
	  caract=fgetc(score);
	  printf("%c",caract);
	}while(caract!=EOF);
      fclose(score);
    }
  else
    printf("Une eureur c'est produite lors de l'ouverture du fichier score.txt...\n");
}
