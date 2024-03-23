#ifndef back_H_INCLUDED
#define back_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

typedef struct
	{
        SDL_Surface *image;
        SDL_Rect poscam,poscam2,pos,pos2;
       // SDL_Rect cam[2];
        Mix_Music *music;
    }backgroundm;

void initBack_Multi(backgroundm *b);
void aficherBack_Multi(backgroundm b, SDL_Surface * screen);
void scrolling_Multi(backgroundm * b, int direction); 
void scrolling2_Multi(backgroundm * b, int direction);



#endif // DS_H_INCLUDED
