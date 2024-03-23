#ifndef BACKGROUND_H_INCLUDED
#define BACKGROUND_H_INCLUDED

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct 
{
  SDL_Rect poscam;
  SDL_Rect pos;
  SDL_Surface *imageFond;
  int level;
  int speed;
}background;


void initBack(background *b,int level);
void afficherback(background b,SDL_Surface *screen);
void scrolling(background *b, int direction);
void libererback(background b);

#endif
