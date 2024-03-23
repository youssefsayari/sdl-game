#ifndef PERSO_H_INCLUDED
#define PERSO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

typedef struct 
{
   SDL_Surface *imageVie[6]; 
   SDL_Rect posvie;
   SDL_Surface *sprite;
   SDL_Rect pos;
   SDL_Rect possprite;
   SDL_Rect pos_score;
   SDL_Surface *scoretxt;
   TTF_Font *police;
int score;
int collision;
int collisionpp;
int deplacement;
int vie;
int num;
int dir;
int attack;
int speed;
int key;
float acceleration,dx;
int etat_vie;
int sauter;
int reponse;
int dy;
int level;
}Personne;


void initPerso(Personne *p);
void afficherPerso(Personne p, SDL_Surface *screengame);
void deplacerPerso (Personne *p,SDL_Surface* collisionMap);
void animerPerso (Personne* p);
void sauter(Personne* p,SDL_Surface* screen);
void updatePerso(Personne *p);
void libererperso(Personne p);
void KICCAS_GetKeyState(Personne *p,int direction);
void saut(Personne *p);

void initPerso1(Personne *p);
void initPerso2(Personne *p);
void KICCAS_GetKeyStateMulti(Personne *p,Personne *p2,int direction,int direction2);
void libererpersoMulti(Personne p);
void animerPersoMulti(Personne *p);
#endif // PERSO_H_INCLUDED

