#ifndef ENIGME_H_INCLUDED
#define ENIGME_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <math.h>
#include <time.h>

typedef struct{
	SDL_Surface *background;
	SDL_Surface *back;
	SDL_Surface *question;
	SDL_Surface *reponses[4];
	SDL_Surface *button[2];

	int pos_selected;
	SDL_Rect pos_back;
	SDL_Rect pos_question;
	SDL_Rect pos_reponse1;
	SDL_Rect pos_reponse2;
	SDL_Rect pos_reponse3;
	int num_question;

	SDL_Rect pos_reponse1txt;
	SDL_Rect pos_reponse2txt;
	SDL_Rect pos_reponse3txt;
	int vrai_reponse;
	int positionVraiReponse;
	Mix_Chunk *sound;

}Enigme;

void generer_enigme(Enigme *e);
void afficher_enigme(Enigme *e,SDL_Surface *ecran);
int test_enigme(Enigme *e);
int jouer_enigme(Enigme *e,SDL_Surface*ecran);
void free_enigme(Enigme *e);
int verify_enigme(Enigme *e,SDL_Surface*ecran);

#endif
