#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

#include "Karim_Akkari_1A30.h"


void initmap(minimap *m, int level)
{
    char map[30];
    m->position_mini.x = 0;
    m->position_mini.y = 15;
    sprintf(map,"resources/image/minimap%d.png",level);
    m->sprite = IMG_Load(map);
    m->dot = IMG_Load("resources/image/Dot.png");
    m->posdot.x = 0;
    m->posdot.y = 67;
    m->level=level;
}

void afficherminimap(minimap m, SDL_Surface *screen)
{
    SDL_BlitSurface(m.sprite, NULL, screen, &m.position_mini);
    SDL_BlitSurface(m.dot,NULL,screen,&m.posdot);
}
void free_minimap(minimap m)
{
    SDL_FreeSurface(m.sprite);
    SDL_FreeSurface(m.dot);
}

void initialiser_temps(temps *t)
{
    t->texte = NULL;
    t->position.x = 1040;
    t->position.y = 73;
    t->police = NULL;
    t->police = TTF_OpenFont("resources/avocado.ttf", 30);
    strcpy(t->entree, "");
    (t->secondesEcoulees) = 0;
    time(&(t->t1)); //temps du debut
}

void afficher_temps(temps *t, SDL_Surface *screen)
{
    SDL_Color couleurnoir = {0, 0, 0};
    
    time(&(t->t2)); // temps actuel

    t->secondesEcoulees = t->t2 - t->t1;

    t->min = ((t->secondesEcoulees / 60) % 60);
    t->sec = ((t->secondesEcoulees) % 60);
    int millisecondes=SDL_GetTicks()%60;
    
    sprintf(t->entree, "TIME: %02d:%02d:%02d", t->min, t->sec, millisecondes);

    t->texte = TTF_RenderText_Blended(t->police, t->entree, couleurnoir);

    SDL_BlitSurface(t->texte, NULL, screen, &(t->position)); /* Blit du texte */
}

void free_temps(temps t)
{
    SDL_FreeSurface(t.texte);
    TTF_CloseFont(t.police);
}

SDL_Color GetPixel(SDL_Surface *Background, int x, int y)
{

    SDL_Color color;
    Uint32 col = 0;
    //Determine position

    char *pixelPosition = (char *)Background->pixels;
    //Offset by Y
    pixelPosition += (Background->pitch * y);
    //Offset by X
    pixelPosition += (Background->format->BytesPerPixel * x);
    //Copy pixel data
    memcpy(&col, pixelPosition, Background->format->BytesPerPixel);
    //Convert to color
    SDL_GetRGB(col, Background->format, &color.r, &color.g, &color.b);

    return (color);
}

int collisionPP(SDL_Rect posperso, SDL_Surface *Masque)
{
    SDL_Color test, couleurnoir = {0, 0, 0};

    SDL_Rect pos[8];
    pos[0].x = posperso.x;
    pos[0].y = posperso.y;
    pos[1].x = posperso.x + posperso.w / 2;
    pos[1].y = posperso.y;
    pos[2].x = posperso.x + posperso.w;
    pos[2].y = posperso.y;
    pos[3].x = posperso.x;
    pos[3].y = posperso.y + posperso.h / 2;
    pos[4].x = posperso.x;
    pos[4].y = posperso.y + posperso.h;
    pos[5].x = posperso.x + posperso.w / 2;
    pos[5].y = posperso.y + posperso.h;
    pos[6].x = posperso.x + posperso.w;
    pos[6].y = posperso.y + posperso.h;
    pos[7].x = posperso.x + posperso.w;
    pos[7].y = posperso.y + posperso.h / 2;
    int collision = 0, x, y;

    for (int i = 0; i < 8 && collision == 0; i++)
    {
        x = pos[i].x;
        y = pos[i].y;
        test = GetPixel(Masque, x, y);
        if(test.r == 255 && test.g == 255 && test.b == 255)
            collision = 1;
    }
    return collision;
}
int majminimap (Personne *p, minimap *m ,int camera ,int redimensionnement)
{
    int deplacement=0;

    if(camera != -1)
    {
       switch(camera)
    {
        case 0:
        m->posdot.x+=redimensionnement;
        break;
        case 1:
        m->posdot.x-=redimensionnement;
        break;
        case 6:
            //m->posdot.y-=redimensionnement;
            m->posdot.y-=redimensionnement;
        break;
        
        case 7:
           //m->posdot.y-=redimensionnement; 
           m->posdot.y+=redimensionnement;  
        break;
        
     }
        if(m->posdot.x<=0)
           m->posdot.x=0;
        if(m->posdot.x>=880)
          m->posdot.x=891;
        if(m->posdot.y<=15)
           m->posdot.y=15;
        if(m->posdot.y>=92)
          m->posdot.y=92;
          //deplacement=-1;
    }
            //si on arrive a la fin de l'ecran
        /*if(p->pos.x>=0 && p->pos.x<=600 || m->posdot.x<=58 && m->posdot.x>=0 ||m->posdot.x>=814 && m->posdot.x<=890)
            deplacement=1;*/
        if(m->posdot.x>=814 && m->posdot.x<=890 || m->posdot.x<=58 && m->posdot.x>=0)
            deplacement=1;

    return deplacement;
}

//multiplayer

void initmap1(minimap *m,int level)
{
    char map[30];
    sprintf(map,"resources/image/minimap%d.png",level);
    m->sprite = IMG_Load(map);
    m->position_mini.x = 50;
    m->position_mini.y = 10;
    m->dot = IMG_Load("resources/image/Dotm1.png");
    m->posdot.x = 63;
    m->posdot.y = 30;
}
void initmap2(minimap *m,int level)
{
    char map[30];
    sprintf(map,"resources/image/minimap%d.png",level);
    m->sprite = IMG_Load(map);
    m->position_mini.x = 840;
    m->position_mini.y = 10;
    m->dot = IMG_Load("resources/image/Dotm1.png");
    m->posdot.x = 871;
    m->posdot.y = 30;
}

void initialiser_tempsm(temps *t)
{
    t->texte = NULL;
    t->position.x = 600;
    t->position.y = 20;
    t->police = NULL;
    t->police = TTF_OpenFont("resources/avocado.ttf", 40);
    strcpy(t->entree, "");
    (t->secondesEcoulees) = 0;
    time(&(t->t1)); //temps du debut
}

int majminimap2(Personne *p, minimap *m ,int camera ,int redimensionnement)
{
    int deplacement=0;

    if(camera != -1)
    {
        if (camera==0)
        m->posdot.x+=redimensionnement;

        else if (camera==1)
        m->posdot.x-=redimensionnement;

        else if(camera==2)
        m->posdot.y-=redimensionnement;

        if(m->posdot.x<=0)
          m->posdot.x=0;
        if(m->posdot.x>=880)
          m->posdot.x=880;
    }
            //si on arrive a la fin de l'ecran
        if(m->posdot.x>=814 && m->posdot.x<=890 || m->posdot.x<=58 && m->posdot.x>=0)
        {
            deplacement=1;
        }

    return deplacement;
}

void initCollisionMap(SDL_Surface **collisionMap)
{
    (*collisionMap) = IMG_Load("resources/image/masque1.png");
}

int collisionmap (int d, SDL_Rect pos,SDL_Surface *collisionMap)
{
    SDL_Color couleur;
    int colx=pos.x;
    int coly=pos.y;

    if (d == 6)
    {
        couleur = GetPixel(collisionMap, colx + 35,coly - 49);
    }
    else if (d == 7)
    {
        couleur = GetPixel(collisionMap, colx + 35, coly + 59);
    }
    else if (d == 0)
    {
        couleur = GetPixel(collisionMap, colx + 40, coly + 54);
    }
    else if (d == 1)
    {
        couleur = GetPixel(collisionMap, colx - 30, coly + 54);
    }
    return ((couleur.r == 255 && couleur.g == 255 && couleur.b == 255) );

}

void freecollisionmap(SDL_Surface *collisionmap)
{
    SDL_FreeSurface(collisionmap);
}