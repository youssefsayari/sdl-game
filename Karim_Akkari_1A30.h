#ifndef Karim_Akkari_1A30_H_
#define Karim_Akkari_1A30_H_
#include <time.h>
#include "perso.h"

typedef struct
{
	SDL_Rect position_mini;
	SDL_Surface *sprite;
	SDL_Surface *dot;
	SDL_Rect posdot;
	int deplacement;
	int level;
} minimap;

typedef struct temps
{
	SDL_Surface *texte;
	SDL_Rect position;
	TTF_Font *police;
	char entree[100];
	int secondesEcoulees;
	SDL_Color couleurBlanche;
	time_t t1, t2;
	int min, sec;
}temps;

void initmap(minimap *m,int level);
void afficherminimap(minimap m, SDL_Surface *screen);
void free_minimap(minimap m);
int majminimap (Personne *p, minimap *m ,int camera ,int redimensionnement);

void initialiser_temps(temps *t);
void afficher_temps(temps *t, SDL_Surface *ecran);
void free_temps(temps t);

SDL_Color GetPixel(SDL_Surface *Background, int x, int y);
int collisionPP(SDL_Rect posperso, SDL_Surface *Masque);
void initCollisionMap(SDL_Surface **collisionmap);
int collisionmap (int d, SDL_Rect pos,SDL_Surface *collisionMap);
void freecollisionmap(SDL_Surface *collisionmap);

//multiplayer

void initmap1(minimap *m,int level);
void initmap2(minimap *m,int level);
void initialiser_tempsm(temps *t);
int majminimap2(Personne *p, minimap *m ,int camera ,int redimensionnement);

#endif
