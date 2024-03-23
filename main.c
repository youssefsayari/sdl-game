#include "header.h"

int main()
{
    int hauteur_fenetre = 768,
        largeur_fenetre = 1366;
        int k,z;
        int coins=get_coins();
        int bonus=0;
        int I;

	SDL_Surface *ecran = NULL;
	intro(&ecran);


    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);

    //FENETRE PRINCIPALE
    SDL_Surface *screen = NULL;
    screen = SDL_SetVideoMode(largeur_fenetre, hauteur_fenetre, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("GAME OF KICCAS",NULL);
    //afficher le menu
    int menu=-1;

    do
    {
	    menu=afficher_menu(screen,coins);
     switch (menu)
	   {
		  case 1:
               k=amelioration(screen);
            switch(k)
            {
               case 1:
                    z=nouv(screen);
                switch(z)
                {
                   case 1:
                      I=nouv2(screen);
                       switch(I)
                       {
                          case 1:
                             //pour la souris
                          break;
                          case 2:
                               ecran_Jeu_Mono(screen);
                          break;
                       }
                      break;
                   case 2:
                      ecran_Jeu_Multi(screen);
                      break;
                }
              break;
              case 2:
                    Resume(screen);
              break;
            }
			
		break;
		case 2:
			afficher_option(screen);
		break;
    case 3:
        bonus=tictactoe();
        if(bonus)
        {
          coins+=100;
          save_coins(coins);
        }
    break;
        case 4:
 			quitter(screen,&menu);
      break;

	}

    }
    while (menu!=0);

    SDL_Quit();

    return 0;
}
