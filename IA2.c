#include "IA2.h"

void init_IA2(tic *ti)
{
	int i, j;
	for (i = 0; i < 9; i++)
	{
		ti->matrice_suivi[i] = 0;
	}
	for (i = 0; i < 9; i++)
	{
		ti->x[i] = IMG_Load("resources/image/X.png");
		ti->o[i] = IMG_Load("resources/image/O.png");
	}
	ti->failed = IMG_Load("resources/image/failed.jpg.png");
	ti->win = IMG_Load("resources/image/win.jpg.png");
	ti->back = IMG_Load("resources/image/IA2.jpg.png");
	ti->pos_back.x = 0;
	ti->pos_back.y = 0;
	ti->pos[0].x = 550;
	ti->pos[0].y = 230;
	ti->pos[0].w = 145;
	ti->pos[0].h = 145;

	ti->pos[1].x = 700;
	ti->pos[1].y = 230;
	ti->pos[1].w = 145;
	ti->pos[1].h = 145;

	ti->pos[2].x = 870;
	ti->pos[2].y = 230;
	ti->pos[2].w = 145;
	ti->pos[2].h = 145;

	ti->pos[3].x = 550;
	ti->pos[3].y = 370;
	ti->pos[3].w = 87;
	ti->pos[3].h = 89;

	ti->pos[4].x = 700;
	ti->pos[4].y = 360;
	ti->pos[4].w = 87;
	ti->pos[4].h = 89;

	ti->pos[5].x = 870;
	ti->pos[5].y = 360;
	ti->pos[5].w = 87;
	ti->pos[5].h = 89;

	ti->pos[6].x = 550;
	ti->pos[6].y = 510;
	ti->pos[6].w = 87;
	ti->pos[6].h = 89;

	ti->pos[7].x = 700;
	ti->pos[7].y = 510;
	ti->pos[7].w = 87;
	ti->pos[7].h = 89;

	ti->pos[8].x = 870;
	ti->pos[8].y = 510;
	ti->pos[8].w = 87;
	ti->pos[8].h = 89;
}
void afficher_tic(tic ti, SDL_Surface *ecran)
{
	SDL_BlitSurface(ti.back, NULL, ecran, NULL);
}
int aleatoire()
{
	int alea;
	srand(time(NULL));
	alea = 1 + rand() % 9;
	return alea;
}
int machine(tic *ti, int alea)
{
	if (ti->matrice_suivi[alea] == 1 || ti->matrice_suivi[alea] == -1)
	{
		alea++;
		
	}
	return alea;
}
void afficher_joueur(tic ti, SDL_Surface *ecran)
{
	int i;
	for (i = 0; i < 9; i++)
		if (ti.matrice_suivi[i] == 1)
			SDL_BlitSurface(ti.x[i], NULL, ecran, &(ti.pos[i]));
}
void afficher_machine(SDL_Surface *ecran, tic ti)
{
	int i;
	for (i = 0; i < 9; i++)
	{
		if (ti.matrice_suivi[i] == -1)
			SDL_BlitSurface(ti.o[i], NULL, ecran, &(ti.pos[i]));
	}
}
int evaluer(tic ti)
{
	int i, whowin = 0;
	if (ti.matrice_suivi[0] == 1 && ti.matrice_suivi[1] == 1 && ti.matrice_suivi[2] == 1)
	{
		whowin = 1;
	}
	if (ti.matrice_suivi[3] == 1 && ti.matrice_suivi[4] == 1 && ti.matrice_suivi[5] == 1)
	{
		whowin = 1;
	}
	if (ti.matrice_suivi[6] == 1 && ti.matrice_suivi[7] == 1 && ti.matrice_suivi[8] == 1)
	{
		whowin = 1;
	}
	if (ti.matrice_suivi[0] == 1 && ti.matrice_suivi[4] == 1 && ti.matrice_suivi[8] == 1)
	{
		whowin = 1;
	}
	if (ti.matrice_suivi[2] == 1 && ti.matrice_suivi[4] == 1 && ti.matrice_suivi[6] == 1)
	{
		whowin = 1;
	}
	if (ti.matrice_suivi[0] == 1 && ti.matrice_suivi[3] == 1 && ti.matrice_suivi[6] == 1)
	{
		whowin = 1;
	}
	if (ti.matrice_suivi[1] == 1 && ti.matrice_suivi[4] == 1 && ti.matrice_suivi[7] == 1)
	{
		whowin = 1;
	}
	if (ti.matrice_suivi[2] == 1 && ti.matrice_suivi[5] == 1 && ti.matrice_suivi[8] == 1)
	{
		whowin = 1;
	}

	if (ti.matrice_suivi[0] == -1 && ti.matrice_suivi[1] == -1 && ti.matrice_suivi[2] == -1)
	{
		whowin = -1;
	}
	if (ti.matrice_suivi[3] == -1 && ti.matrice_suivi[4] == -1 && ti.matrice_suivi[5] == -1)
	{
		whowin = -1;
	}
	if (ti.matrice_suivi[6] == -1 && ti.matrice_suivi[7] == -1 && ti.matrice_suivi[8] == -1)
	{
		whowin = -1;
	}
	if (ti.matrice_suivi[0] == -1 && ti.matrice_suivi[4] == -1 && ti.matrice_suivi[8] == -1)
	{
		whowin = -1;
	}
	if (ti.matrice_suivi[2] == -1 && ti.matrice_suivi[4] == -1 && ti.matrice_suivi[6] == -1)
	{
		whowin = -1;
	}
	if (ti.matrice_suivi[0] == -1 && ti.matrice_suivi[3] == -1 && ti.matrice_suivi[6] == -1)
	{
		whowin = -1;
	}
	if (ti.matrice_suivi[1] == -1 && ti.matrice_suivi[4] == -1 && ti.matrice_suivi[7] == -1)
	{
		whowin = -1;
	}
	if (ti.matrice_suivi[2] == -1 && ti.matrice_suivi[5] == -1 && ti.matrice_suivi[8] == -1)
	{
		whowin = -1;
	}

	return whowin;
}

int tictactoe()
{
        SDL_Surface *mouse2 = IMG_Load("resources/image/curseur3.png");
        SDL_Rect pos_mouse2;

	tic ti;
	int continuer = 1, touch = 0, whoplay = 0, alea = 1, whowin = 0;
        SDL_Surface *ecran;
    ecran = SDL_SetVideoMode(1366,768, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("GAME OF KICCAS",NULL);
        int xmouse = 700, ymouse = 500;
	SDL_Event event;
	init_IA2(&ti);
	while (continuer)
	{           
                SDL_GetMouseState(&xmouse, &ymouse);
 
        pos_mouse2.x = xmouse;
        pos_mouse2.y = ymouse;
		afficher_tic(ti, ecran);
		afficher_joueur(ti, ecran);
		afficher_machine(ecran, ti);
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				continuer = 0;
				break;
			case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
                case SDLK_ESCAPE: 
                    continuer = 0;
                    break;
            }
            break;

				if (whoplay == 0)
				{
				case SDL_MOUSEBUTTONDOWN:
					if ((event.button.x >= ti.pos[0].x) && (event.button.x <= (ti.pos[0].x + ti.pos[0].w)) && (event.button.y >= ti.pos[0].y) && (event.button.y <= (ti.pos[0].y + ti.pos[0].h)))
					{
						ti.matrice_suivi[0] = 1;
						whoplay = 1;
					}
					if ((event.button.x >= ti.pos[1].x) && (event.button.x <= (ti.pos[1].x + ti.pos[1].w)) && (event.button.y >= ti.pos[1].y) && (event.button.y <= (ti.pos[1].y + ti.pos[1].h)))
					{
						whoplay = 1;
						ti.matrice_suivi[1] = 1;
					}
					if ((event.button.x >= ti.pos[2].x) && (event.button.x <= (ti.pos[2].x + ti.pos[2].w)) && (event.button.y >= ti.pos[2].y) && (event.button.y <= (ti.pos[2].y + ti.pos[2].h)))
					{
						ti.matrice_suivi[2] = 1;
						whoplay = 1;
					}
					if ((event.button.x >= ti.pos[3].x) && (event.button.x <= (ti.pos[3].x + ti.pos[3].w)) && (event.button.y >= ti.pos[3].y) && (event.button.y <= (ti.pos[3].y + ti.pos[3].h)))
					{
						ti.matrice_suivi[3] = 1;
						whoplay = 1;
					}
					if ((event.button.x >= ti.pos[4].x) && (event.button.x <= (ti.pos[4].x + ti.pos[4].w)) && (event.button.y >= ti.pos[4].y) && (event.button.y <= (ti.pos[4].y + ti.pos[4].h)))
					{
						ti.matrice_suivi[4] = 1;
						whoplay = 1;
					}
					if ((event.button.x >= ti.pos[5].x) && (event.button.x <= (ti.pos[5].x + ti.pos[5].w)) && (event.button.y >= ti.pos[5].y) && (event.button.y <= (ti.pos[5].y + ti.pos[5].h)))
					{
						ti.matrice_suivi[5] = 1;
						whoplay = 1;
					}
					if ((event.button.x >= ti.pos[6].x) && (event.button.x <= (ti.pos[6].x + ti.pos[6].w)) && (event.button.y >= ti.pos[6].y) && (event.button.y <= (ti.pos[6].y + ti.pos[6].h)))
					{
						ti.matrice_suivi[6] = 1;
						whoplay = 1;
					}
					if ((event.button.x >= ti.pos[7].x) && (event.button.x <= (ti.pos[7].x + ti.pos[7].w)) && (event.button.y >= ti.pos[7].y) && (event.button.y <= (ti.pos[7].y + ti.pos[7].h)))
					{
						ti.matrice_suivi[7] = 1;
						whoplay = 1;
					}
					if ((event.button.x >= ti.pos[8].x) && (event.button.x <= (ti.pos[8].x + ti.pos[8].w)) && (event.button.y >= ti.pos[8].y) && (event.button.y <= (ti.pos[8].y + ti.pos[8].h)))
					{
						ti.matrice_suivi[8] = 1;
						whoplay = 1;
					}
					break;
				}
			}
		}
		if (whoplay == 1)
		{
			SDL_Delay(500);
			whoplay = 0;
			alea = aleatoire();
			alea = machine(&ti, alea);
			ti.matrice_suivi[alea] = -1;
		}
		whowin = evaluer(ti);
		switch (whowin)
		{
		case 1:
			SDL_BlitSurface(ti.win, NULL, ecran, NULL);
                        SDL_Flip(ecran);
                        SDL_Delay(2000);
			return 1;
			break;
		case -1:
			SDL_BlitSurface(ti.failed, NULL, ecran, NULL);
                        SDL_Flip(ecran);
                        SDL_Delay(2000);
			return 0;
			break;
		}
		SDL_Delay(30);
                 SDL_BlitSurface(mouse2, NULL, ecran, &pos_mouse2);
		SDL_Flip(ecran);
	}

	SDL_FreeSurface(ecran);
	SDL_FreeSurface(ti.back);
	SDL_FreeSurface(ti.win);
	SDL_FreeSurface(ti.failed);
	return 0;
	//SDL_Quit();
}
