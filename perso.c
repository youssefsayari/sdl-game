#include "perso.h"
#include "enigmeSlim.h"
#include "Karim_Akkari_1A30.h"

void initPerso(Personne *p)
{ 

    p->sprite=IMG_Load("resources/image/perso_image.png");
    p->imageVie[0]=IMG_Load("resources/image/blood0.png");
    p->imageVie[1]=IMG_Load("resources/image/blood1.png");
    p->imageVie[2]=IMG_Load("resources/image/blood2.png");
    p->imageVie[3]=IMG_Load("resources/image/blood3.png");
    p->imageVie[4]=IMG_Load("resources/image/blood4.png");
    p->imageVie[5]=IMG_Load("resources/image/blood5.png");

    p->possprite.x=0;
    p->possprite.y=0;
    p->possprite.w=120;
    p->possprite.h=120;

    p->dir = 0;
    p->speed = 10;
    p->num = 0;
    p->key=0;
    p->deplacement=0;
    p->reponse=0;
    p->scoretxt=NULL;
    p->dy=10;

    p->pos.x = 0;
    p->pos.y = 548;//380;
    p->pos.w = 110;
    p->pos.h = 110;
    p->pos_score.x=1000;
    p->pos_score.y=20;

    p->collision=0;
    p->etat_vie=5;

    p->posvie.x=5;
    p->posvie.y=120; 
    p->police =TTF_OpenFont("resources/arial.ttf",30);   
 
    p->acceleration=0;
    p->vie=0;
    p->sauter=0;

}


void afficherPerso(Personne p, SDL_Surface *screen)
{
    SDL_BlitSurface(p.sprite,&p.possprite,screen,&p.pos);
    SDL_BlitSurface(p.imageVie[p.etat_vie],NULL,screen,&p.posvie);
    //SDL_Flip(screen);
}


void deplacerPerso (Personne *p,SDL_Surface* collisionMap)
{
     //p->speed=10;
     SDL_Rect poscopie= {p->pos.x,p->pos.y,p->pos.w,p->pos.h};
     Uint8 *keystates = SDL_GetKeyState( NULL );
        
        SDL_PumpEvents();

  if(p->key)
  {
       if( keystates[ SDLK_RIGHT ] )
         {
                    p->dir=0;//droit
                    p->pos.x+=p->speed;
                    //if(!collisionmap(p->dir,poscopie,collisionMap))
                    /*if(!collisionPP(poscopie,collisionMap))
                    {
                        
                        //poscopie.x+=p->speed;
                    }*/

         }
      if( keystates[ SDLK_LEFT ] )
         {
                    p->dir=1;//gauche
                    p->pos.x-=p->speed;
                    /*if(!collisionmap(p->dir,poscopie,collisionMap))
                    //if(!collisionPP(poscopie,collisionMap))
                    {
                        
                        poscopie.x-=p->speed;
                    }*/
         }
         
       if( keystates[ SDLK_DOWN] )
         {
                    p->dir=6;//down
                    p->pos.y+=p->speed;
                    p->sauter=1;
                    /*if(!collisionmap(p->dir,poscopie,collisionMap))
                    //if(!collisionPP(poscopie,collisionMap))
                    {
                        
                        poscopie.y+=p->speed;
                    }*/
         }
      if( keystates[ SDLK_UP] )
         {
                    p->dir=7;//up
                    p->pos.y-=p->speed;
                    p->sauter=1;
                   /* if(!collisionmap(p->dir,poscopie,collisionMap))
                    //if(!collisionPP(poscopie,collisionMap))
                    {
                        
                        poscopie.y-=p->speed;
                    }*/
         }
         
    } 


    if(p->pos.x <=0)
       p->pos.x = 0;

    if(p->pos.x >= 1300)
       p->pos.x=1300;

}

void animerPerso(Personne *p)
{
    int largeursprite=960;
 if(p->key)
 {
    if(p->possprite.x==(largeursprite-p->possprite.w))
        p->possprite.x=0;
    else
        p->possprite.x+=p->possprite.w;
 }
 else
    p->possprite.x=0;

  switch(p->dir)
  {
    case 0:
      //p->possprite.y=(p->dir)*(p->possprite.h);
      p->possprite.y=0;
    break;
    case 1:
       p->possprite.y=120;
    break;
    case 2:
       p->possprite.y=240;
    break;
    case 3:
       p->possprite.y=360;
    break;
    case 4:
       p->possprite.y=480;
    break;
  }
}

void updatePerso(Personne *p)
{
        if(p->collision == 30)
        {
            p->vie++;
            p->collision=0;
        }
        if(p->vie >= 5)
        {
            p->etat_vie--;
            p->vie=0;
        }
        if(p->reponse==1)
        {
            p->etat_vie++;
            p->reponse=0;
        }
        if(p->pos.x>0 && p->dir==0 && p->key==1)//pour augmenter le score
            p->score+=33;
     
}


void libererperso(Personne p)
{
    int i;


    SDL_FreeSurface(p.sprite);


    for(i=0;i<6;i++)
    {
        SDL_FreeSurface(p.imageVie[i]);
    }

        SDL_FreeSurface(p.scoretxt);
         TTF_CloseFont(p.police);

}

void saut(Personne *p)
{
    p->dy=8;

    /*if(p->sauter==1) 
    {
        p->pos.y-=p->speed*(2);
    }
    else if(p->sauter==2)
    {
        p->pos.y-=p->speed*(2);
        p->pos.x+=p->speed*(2);
    }
    else if(p->sauter==3)
    {
        p->pos.y-=p->speed*(2);
        p->pos.x-=p->speed*(2);
    }*/
     
            p->dy += 5;
            p->pos.y += p->dy;

        if(p->pos.y<100)
        {
            p->pos.y=100;
        }
        if(p->pos.y>548)
        {
                p->pos.y = 548;
        }


}

void KICCAS_GetKeyState(Personne *p,int direction)
{
        if(direction == -1)
        {
            p->key=0;
            p->sauter=0;
        }
        else
            {
                p->key=1;
                if(direction ==0 || direction ==1)
                   p->dir=direction;
                else
                {
                    if(direction==6)
                    {
                        p->dir=0;
                        p->sauter=2;
                    }
                    if(direction==7)
                    {
                        p->dir=1;
                        p->sauter=3;
                    }
                    if(direction==8)
                    {
                        p->sauter=1;
                    }
                }

            }
}

void initPerso1(Personne * p)
{ 


    p->dir = 0;
    p->speed = 10;
    p->num = 0;
    p->key=0;
    p->deplacement=0;
    p->reponse=0;

    p->sprite=IMG_Load("resources/image/perso_image.png");
    p->possprite.x=0;
    p->possprite.y=0;
    p->possprite.w=120;
    p->possprite.h=120;

    p->pos.x = 300;
    p->pos.y = 510;
    p->pos_score.x=5;
    p->pos_score.y=100;
    //p->pos.w = p->image[0][0]->w;
    //p->pos.h = p->image[0][0]->h;

     p->imageVie[0]=IMG_Load("resources/image/blood0.png");
    p->imageVie[1]=IMG_Load("resources/image/blood1.png");
    p->imageVie[2]=IMG_Load("resources/image/blood2.png");
    p->imageVie[3]=IMG_Load("resources/image/blood3.png");
    p->imageVie[4]=IMG_Load("resources/image/blood4.png");
    p->imageVie[5]=IMG_Load("resources/image/blood5.png");
    p->etat_vie=3;
    p->collision=0;


    p->posvie.x=5;
    p->posvie.y=130;
    p->police =TTF_OpenFont("resources/arial.ttf",40);    
 

    p->acceleration=0;
    p->score=0;
    p->vie=0;
    p->sauter=-1;

}

void initPerso2(Personne * p)
{ 

    p->dir = 0;
    p->speed = 10;
    p->num = 0;
    p->key=0;
    p->deplacement=0;
    p->reponse=0;

    p->sprite=IMG_Load("resources/image/perso_image.png");
    p->possprite.x=0;
    p->possprite.y=0;
    p->possprite.w=120;
    p->possprite.h=120;

    p->pos.x = 900;
    p->pos.y = 510;
    p->pos_score.x=905;
    p->pos_score.y=100;
    //p->pos.w = p->image[0][0]->w;
    //p->pos.h = p->image[0][0]->h;

    //CHARGEMENT DES IMAGE DE VIE
   p->imageVie[0]=IMG_Load("resources/image/blood0.png");
    p->imageVie[1]=IMG_Load("resources/image/blood1.png");
    p->imageVie[2]=IMG_Load("resources/image/blood2.png");
    p->imageVie[3]=IMG_Load("resources/image/blood3.png");
    p->imageVie[4]=IMG_Load("resources/image/blood4.png");
    p->imageVie[5]=IMG_Load("resources/image/blood5.png");
    p->etat_vie=3;
    
    p->collision=0;

    p->posvie.x=750;
    p->posvie.y=130;
    p->police =TTF_OpenFont("resources/arial.ttf",40);    
 
    p->acceleration=0;
    p->score=0;
    p->vie=0;
    p->sauter=-1;

}


void KICCAS_GetKeyStateMulti(Personne *p,Personne *p2,int direction,int direction2)
{
        if(direction == -1)
            p->key=0;
        else
            {
                p->key=1;
                p->dir=direction;
            }
        if(direction2 == -1)
            p2->key=0;
        else
            {
                p2->key=1;
                p2->dir=direction2;
            }
}

void libererpersoMulti(Personne p)
{
    int i;


    SDL_FreeSurface(p.sprite);

    for(i=0;i<6;i++)
    {
        SDL_FreeSurface(p.imageVie[i]);
    }

         TTF_CloseFont(p.police);

}
void animerPersoMulti(Personne *p)
{
     int largeursprite=960;
if(p->key)
{   
    if(p->possprite.x==(largeursprite-p->possprite.w))
        p->possprite.x=0;
    else
        p->possprite.x+=p->possprite.w;

    p->possprite.y=(p->dir)*(p->possprite.h);
}
else
    p->possprite.x=0;
}
