#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "intro.h"
#include "fonction.h"
#include "option.h"
#include "gfxutils.h"
#include "quitter.h"
#include "stdinc.h"
#include "defs.h"

#include "scrolling.h"
#include "ennemi.h"
#include "perso.h"
#include "autre.h"
#include "Karim_Akkari_1A30.h"
#include "enigmeSlim.h"
#include "amelioration.h"
#include "background.h"
#include "enigme.h"
#include "menu.h"
#include "introJeu.h"
#include "IA2.h"

void ecran_Jeu_Mono(SDL_Surface *screengame);
void ecran_Jeu_Multi(SDL_Surface *screengame);
void Resume(SDL_Surface *screengame);

#endif
