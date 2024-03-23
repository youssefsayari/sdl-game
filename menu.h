#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "Karim_Akkari_1A30.h"
#include "perso.h"
#include "ennemi.h" 
#include "scrolling.h"

typedef struct{
	SDL_Surface *background;
	SDL_Surface *buttonyes[2];
	SDL_Surface *buttonno[2];
	SDL_Surface *button_s;
	SDL_Surface *button;
	SDL_Surface *texte1;
	SDL_Surface *texte2;
	SDL_Rect pos_button1,pos1;
	SDL_Rect pos_button2,pos2;
	int pos_selected;
}menu;


typedef struct
{
	SDL_Rect pos_perso;
	SDL_Rect pos_ennemi;
	SDL_Rect pos_cam;
	SDL_Rect pos_dot;
	int score;
	int etat_vie;
	temps t;
	int level;
}Game;


void init_menu(menu *m);
void init_menu_save(menu *m);
void afficher_menuu(menu *m,SDL_Surface *ecran);
void free_menu(menu *m);
int menu_save(menu *m,SDL_Surface *ecran,Game G);
int menu_game(menu *m,SDL_Surface *ecran);
Game chargement_Jeu();
Game updateGame(Personne p,ennemi e, minimap m,background b, temps t,int level);
void initResume(Personne *p,ennemi *e, minimap *m,background *b, temps *t,Game G);

#endif