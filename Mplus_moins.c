# include<stdio.h>
# include<stdlib.h>
# include<time.h>
/******************************/
# include"plus_moins.h"

int main(int argc,char *argv[])
{
  int choix1=0,choix2=0,choix3=0,boolean=0;
  S_joueur player;
  
  srand(time(NULL));
  do
    {
      menu(0);
      do
	{
	  printf("Quel est votre choix ?:\n");
	  scanf("%d", &choix1);
	}while(choix1<1 || choix1>5);
      switch(choix1)
	{
	case 1:
	  menu(choix1);
	  do
	    {
	      printf("Quel est votre choix ?:\n");
	      scanf("%d", &choix2);
	    }while(choix2<1 || choix2>3);
	  switch(choix2)
	    {
	    case 1:
	      boolean=plus_moins(choix2,&player);
	      if(boolean)
		{
		  printf("Voulez-vous enregistrer votre score???\n");
		  do
		    {
		      printf("\t1.OUI\n\t2.NON\n");
		      scanf("%d",&choix3);
		    }while(choix3!=1&&choix3!=2);
		  switch(choix3)
		    {
		    case 1:
		      save_player(&player);
		      save_score(&player);
		      break;
		    case 2:
		      printf("Oki! Votre score ne sera pas enregistré...\nA BIENTOT!!!\n");
		      break;
		    }
		}
	      else
		{
		  printf("PERDU !!!\nVous n'avez pas réussi à trouver le nombre mystere\navec le nombre de coups à votre dispositions...\n");
		}
	      break;
	    case 2:
	      boolean=plus_moins(choix2,&player);
	      if(boolean)
		{
		  printf("Voulez-vous enregistrer votre score???\n");
		  do
		    {
		      printf("\t1.OUI\n\t2.NON\n");
		      scanf("%d",&choix3);
		    }while(choix3!=1&&choix3!=2);
		  switch(choix3)
		    {
		    case 1:
		      save_player(&player);
		      save_score(&player);
		      break;
		    case 2:
		      printf("Oki! Votre score ne sera pas enregistré...\nA BIENTOT!!!\n");
		      break;
		    }
		}
	      else
		{
		  printf("PERDU !!!\nVous n'avez pas réussi à trouver le nombre mystere\navec le nombre de coups à votre dispositions...\n");
		}
	      break;
	    case 3:
	      boolean=plus_moins(choix2,&player);
	      if(boolean)
		{
		  printf("Voulez-vous enregistrer votre score???\n");
		  do
		    {
		      printf("\t1.OUI\n\t2.NON\n");
		      scanf("%d",&choix3);
		    }while(choix3!=1&&choix3!=2);
		  switch(choix3)
		    {
		    case 1:
		      save_player(&player);
		      save_score(&player);
		      break;
		    case 2:
		      printf("Oki! Votre score ne sera pas enregistré...\nA BIENTOT!!!\n");
		      break;
		    }
		}
	      else
		{
		  printf("PERDU !!!\nVous n'avez pas réussi à trouver le nombre mystere\navec le nombre de coups à votre dispositions...");
		}
	      break;
	    }
	  break;
	case 2:
	  menu(choix1);
	  break;
	case 3:
	  menu(choix1);
	  view_score();
	  break;
	case 4:
	  menu(choix1);
	  break;
	case 5:
	  menu(choix1);
	  break;
	}
    }while(choix1!=5);

  return 0;
}
