#include "scrolling.h"

void initBack(background *b,int level)
{
  char background[30];
  sprintf(background,"resources/image/niveau%d.png",level);
  b->imageFond = IMG_Load(background);
  b->poscam.x = 0;
  b->poscam.y = 0;
  b->poscam.w = 1366;
  b->poscam.h = 768;
  b->pos.x = 0;
  b->pos.y = 0;
  b->pos.w = 8904;
  b->pos.h = 768;
  b->speed=10;
  b->level=level;
}

void afficherback(background b,SDL_Surface *screen)
{
  SDL_BlitSurface(b.imageFond,&b.poscam,screen,&b.pos);
}

void scrolling(background *b, int direction)
{
  if(direction != -1)
 {
  switch(direction)
  {
    case 0:
        b->poscam.x+=b->speed;
    break;
    case 1:
        b->poscam.x-=0;//b->speed;
    break;
    case 2:
        b->poscam.y-=0;
    break;
    case 3:
        b->poscam.y+=0;
    break;
  }

  if(b->poscam.x >= b->pos.w-b->poscam.w)
      b->poscam.x = b->pos.w-b->poscam.w;
  if(b->poscam.x <= 0)
      b->poscam.x = 0;
 }
}

void libererback(background b)
{
    SDL_FreeSurface(b.imageFond);
}
