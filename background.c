#include "background.h"

void initBack_Multi(backgroundm * b)
{
    b->image=IMG_Load("resources/image/niveau1.png");
    
    b->poscam.x=0;
    b->poscam.y=0;
    b->poscam.h=768;
    b->poscam.w=683;
    b->pos.x = 0;
    b->pos.y = 0;
    b->pos.w = 1366;
    b->pos.h = 768;

    b->poscam2.x=0;//683;
    b->poscam2.y=0;
    b->poscam2.h=768;
    b->poscam2.w=683;
    b->pos2.x = 683;
    b->pos2.y = 0;
    b->pos2.w = 1366;//683;
    b->pos2.h = 768;

    b->music=Mix_LoadMUS("resources/sound/music1.mp3");
    Mix_PlayMusic(b->music, -1);

}


void aficherBack_Multi(backgroundm b, SDL_Surface * screen){
    SDL_Rect pos={683,82,650,400};
    SDL_Surface *trait;//ajout d"un trait separant les deux cameras
    trait=IMG_Load("resources/image/trait.png");//loadind trait.png
    /*SDL_BlitSurface(b.image , &b.camera, screen  , NULL);
    SDL_BlitSurface(b.image,&b.camera2,screen, &pos)*/
    SDL_BlitSurface(b.image,&b.poscam, screen,&b.pos);
    SDL_BlitSurface(b.image,&b.poscam2,screen,&b.pos2);
    SDL_BlitSurface(trait,NULL,screen, &pos);//affichage d trait

}

void scrolling_Multi(backgroundm * b, int direction)
{
    if(direction != -1)
 {
  if(direction == 0)
  {
    b->poscam.x+=10;
  }
  if(direction == 1)
  {
    b->poscam.x-=10;
  }
  if(direction == 2)
  {
    b->poscam.y-=0;
  }
  if(direction == 3)
  {
    b->poscam.y+=0;
  }
  /*if(b->poscam.x >= b->pos.w-b->poscam.w)
  {
    b->poscam.x = b->pos.w-b->poscam.w;
  }*/
  if(b->poscam.x <= 0)
  { 
    b->poscam.x = 0;
  }
} 

}

void scrolling2_Multi(backgroundm * b, int direction)
{   
  if(direction != -1)
{
  if(direction == 0)
  {
    b->poscam2.x+=10;
  }
  if(direction == 1)
  {
    b->poscam2.x-=10;
  }
  if(direction == 2)
  {
    b->poscam2.y-=0;
  }
  if(direction == 3)
  {
    b->poscam2.y+=0;
  }
  /*if(b->poscam2.x >= b->pos2.w-b->poscam2.w)
  {
    b->poscam2.x = b->pos2.w-b->poscam2.w;
  }*/
  if(b->poscam2.x <= 0)
  { 
    b->poscam2.x = 0;
  }
}
}