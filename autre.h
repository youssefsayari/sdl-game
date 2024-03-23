#ifndef AUTRE_H_INCLUDED
#define AUTRE_H_INCLUDED

#include "perso.h"
#include "scrolling.h"
#include <SDL/SDL_ttf.h>
#include "Karim_Akkari_1A30.h"

typedef struct 
{
	SDL_Surface* image;
	SDL_Rect pos;

}obstacle;

void initObstacle(obstacle *ob);
void initmusic( Mix_Music **music,Mix_Chunk  **music1);
void initmusic1( Mix_Music **music,Mix_Chunk  **music1,Mix_Chunk  **effetsonore,int level);
int Get_EventDirection(int *done);
int Get_EventDirection2(int *done, int *direction2);
void afficher_infoPerso(Personne p,SDL_Surface *screen);
void afficher_coins(int coin,SDL_Surface *screen,TTF_Font *police);
void loadlevel(int level,Personne *p,minimap *m,background *b,SDL_Surface *ecran);
void loadlevel1(int level,Personne *p,minimap *m,background *b,Mix_Music **music,Mix_Chunk  **music1,Mix_Chunk  **effetsonore,SDL_Surface *ecran);

#endif
