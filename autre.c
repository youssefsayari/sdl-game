#include "autre.h"
#define droite 0
#define gauche 1
#define haut 2

void initObstacle(obstacle *ob)
{
    ob->image = IMG_Load("resources/image/ligne.png");
	ob->pos.x = 700;
	ob->pos.y = 250; 
	ob->pos.w = ob->image->w;
	ob->pos.h = ob->image->h;
}
void initmusic1( Mix_Music **music,Mix_Chunk  **music1,Mix_Chunk  **effetsonore,int level)
{
  char effects[30];
  char sound[30];
  sprintf(effects,"resources/sound/effect%d.wav",level);
  sprintf(sound,"resources/sound/song%d.mp3",level);
	Mix_AllocateChannels(2);
	*music1 = Mix_LoadWAV("resources/sound/ClicDeSouris.wav");
        *music = Mix_LoadMUS(sound);
        *effetsonore=Mix_LoadWAV(effects);
}
void initmusic( Mix_Music **music,Mix_Chunk  **music1)
{
	Mix_AllocateChannels(2);
	*music1 = Mix_LoadWAV("resources/sound/ClicDeSouris.wav");
    *music = Mix_LoadMUS("resources/sound/cinematic music.mp3");
}
int Get_EventDirection(int *done)
{
	SDL_Event event;
	int dir=-1;

	if(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_QUIT:
				 dir = -2;
				break;
			}
		}

        Uint8 *keystates = SDL_GetKeyState( NULL );
        
        SDL_PumpEvents();
        
                if( keystates[ SDLK_ESCAPE ] || keystates[ SDLK_q ])
                {
                    dir = -2;
                }
                if( keystates[ SDLK_RIGHT ] )
                {
                    dir=0;//droit
                }
                if( keystates[ SDLK_LEFT ] )
                {
                    dir=1;//gauche
                }
                /*if( keystates[ SDLK_RIGHT ] && keystates[ SDLK_k ] )
                {
                    dir=2;//attaque a droite
                }
                if( keystates[ SDLK_LEFT ] && keystates[ SDLK_k ] )
                {
                    dir=3;//attaque a gauche
                }
                if( keystates[ SDLK_RIGHT ] && keystates[ SDLK_j ] )
                {
                    dir=4;//courrir a droite
                }
                if( keystates[ SDLK_LEFT ] && keystates[ SDLK_j ] )
                {
                    dir=5;//courrir a gauche
                }
                if( keystates[ SDLK_UP ] && keystates[ SDLK_RIGHT ] )
                {
                    dir=6;//saut a droite
                }
                if( keystates[ SDLK_UP ] && keystates[ SDLK_LEFT ] )
                {
                    dir=7;//saut a gauche
                }*/
                if( keystates[ SDLK_UP ])
                {
                    dir=6;
                }
                if( keystates[ SDLK_DOWN ])
                {
                    dir=7;
                }


	return dir;
}
int Get_EventDirection2(int *done,int *direction2)
{
	SDL_Event event;
	int dir=-1;
	*direction2=-1;

	if(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_QUIT:
				done = 0;
				break;
		        case SDL_KEYDOWN:
		            switch (event.key.keysym.sym) 
                    {
                    	case SDLK_RIGHT:
                    	     dir = 0; 
                              //p->key=1;
                    	break;
                    	case SDLK_LEFT:
                    	     dir = 1;
                    	    // p->key=1;
                    	break;
                    	case SDLK_d:
                    	     *direction2 = 0; 
                              //p->key=1;
                    	break;
                    	case SDLK_q:
                    	     *direction2 = 1;
                    	    // p->key=1;
                    	case SDLK_a:
                    		//p->key=1;
                    	     dir = 2;
                    	break;
                    	case SDLK_ESCAPE:
                    	     *done=0;
                    	   break;
                    }
				break;
			}
		}

	return dir;
}

void afficher_infoPerso(Personne p,SDL_Surface *screen)
{
     char score[20];

    SDL_Color couleurnoir = {0,0,0};//{90, 220, 177};
    
    sprintf(score,"SCORE: %d",p.score);

    p.scoretxt = TTF_RenderText_Blended(p.police,score,couleurnoir);

    SDL_BlitSurface(p.scoretxt, NULL, screen, &(p.pos_score)); /* Blit du texte */

}

void afficher_coins(int coin,SDL_Surface *screen,TTF_Font *police)
{
     char coins[20];
     SDL_Surface *cointxt=NULL;
     SDL_Rect pos={1150,15};

    SDL_Color couleurnoir = {0, 0, 0};
    
    sprintf(coins,"COINS: %d",coin);

    cointxt = TTF_RenderText_Blended(police,coins,couleurnoir);

    SDL_BlitSurface(cointxt, NULL, screen, &pos); /* Blit du texte */

}

void loadlevel1(int level,Personne *p,minimap *m,background *b,Mix_Music **music,Mix_Chunk  **music1,Mix_Chunk  **effetsonore,SDL_Surface *ecran)
{
    char intro[35];

    SDL_Surface *niveau=NULL;
    SDL_Rect pos={0,0};

    if(level==4)
    {
       niveau= IMG_Load("resources/image/THE_END.png");
       SDL_BlitSurface(niveau,NULL,ecran,&pos);
       SDL_Flip(ecran);
       SDL_Delay(4000);

       SDL_FreeSurface(niveau);
    }
    else
    {
        sprintf(intro,"resources/image/intro_level%d.png",level);
        niveau= IMG_Load(intro);

        SDL_BlitSurface(niveau,NULL,ecran,&pos);
        SDL_Flip(ecran);
        SDL_Delay(3000);

        m->sprite = IMG_Load(intro);
        initBack(b,level);
        initmap(m,level);
        initmusic1(music,music1,effetsonore,level);
        printf("%d",level);
        p->pos.x=0;
        p->pos.y=380;
        p->etat_vie=5;
    }

    
}
void loadlevel(int level,Personne *p,minimap *m,background *b,SDL_Surface *ecran)
{
    char intro[35];

    SDL_Surface *niveau=NULL;
    SDL_Rect pos={0,0};

    if(level==4)
    {
       niveau= IMG_Load("resources/image/THE_END.png");
       SDL_BlitSurface(niveau,NULL,ecran,&pos);
       SDL_Flip(ecran);
       SDL_Delay(4000);

       SDL_FreeSurface(niveau);
    }
    else
    {
        sprintf(intro,"resources/image/intro_level%d.png",level);
        niveau= IMG_Load(intro);

        SDL_BlitSurface(niveau,NULL,ecran,&pos);
        SDL_Flip(ecran);
        SDL_Delay(3000);

        m->sprite = IMG_Load(intro);
        initBack(b,level);
        initmap(m,level);
        printf("%d",level);
        p->pos.x=0;
        p->pos.y=380;
        p->etat_vie=5;
    }

    
}
