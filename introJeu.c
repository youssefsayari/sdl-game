#include "header.h"
#include "introJeu.h"

void intro_Mono(SDL_Surface *ecran)
{
	char introName[30];

	SDL_Surface *intro[6];
	SDL_Rect pos;
	int num=0;
	pos.x=0;
	pos.y=0;
	int i=0;
	for(i=0 ; i<5 ;i++)
    { 
        sprintf(introName,"resources/image/Intro_0%d.png",i+1);
        intro[i] = IMG_Load(introName);
    }
      intro[5] = IMG_Load("resources/image/1 joueur.png");
	SDL_Event event;


	SDL_FillRect(ecran, NULL, SDL_MapRGB((ecran)->format, 0, 0, 0));

	do
	{
		i=0;
	  while (i!=128)
	  {
		SDL_SetAlpha (intro[num], SDL_SRCALPHA, i);
		SDL_BlitSurface(intro[num], NULL, (ecran), &pos);
		SDL_Flip(ecran);
		i++;
		if(SDL_PollEvent(&event))
		switch(event.type)
		 {
		 	case SDL_KEYDOWN:
		 	switch (event.key.keysym.sym)
		 	{
		 		case SDLK_RETURN:
		 		i=128;
		 		break;
		 	}
		 }
	  }
	  num++;

	}while(num!=6);
	

	for(i=0;i<6;i++)
	SDL_FreeSurface(intro[i]);

}

void intro_Multi(SDL_Surface *ecran)
{
	char introName[30];

	SDL_Surface *intro[6];
	SDL_Rect pos;
	int num=0;
	pos.x=0;
	pos.y=0;
	int i=0;
	for(i=0 ; i<5 ;i++)
    { 
        sprintf(introName,"resources/image/Intro_0%d.png",i+1);
        intro[i] = IMG_Load(introName);
    }
      intro[5] = IMG_Load("resources/image/2 joueurs.png");
	SDL_Event event;


	SDL_FillRect(ecran, NULL, SDL_MapRGB((ecran)->format, 0, 0, 0));

	do
	{
		i=0;
	  while (i!=128)
	  {
		SDL_SetAlpha (intro[num], SDL_SRCALPHA, i);
		SDL_BlitSurface(intro[num], NULL, (ecran), &pos);
		SDL_Flip(ecran);
		i++;
		if(SDL_PollEvent(&event))
		switch(event.type)
		 {
		 	case SDL_KEYDOWN:
		 	switch (event.key.keysym.sym)
		 	{
		 		case SDLK_ESCAPE:
		 		i=128;
		 		break;
		 	}
		 }
	  }
	  num++;

	}while(num!=5);
	
	for(i=0;i<6;i++)
	SDL_FreeSurface(intro[i]);

}