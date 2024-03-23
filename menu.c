#include "menu.h"


void init_menu_save(menu *m)
{
	m->pos_selected=0;
	m->background= IMG_Load("resources/image/backsave.png");
	m->buttonyes[0]= IMG_Load("resources/image/oui_nonclique.png");
	m->buttonyes[1]= IMG_Load("resources/image/oui_clique.png");
	m->buttonno[0]= IMG_Load("resources/image/non_nonclique.png");
	m->buttonno[1]= IMG_Load("resources/image/non_clique.png");

	m->pos_button1.x=100+316;
	m->pos_button1.y=300+136;
	m->pos1.x=153;
	m->pos1.y=320;
	m->pos_button2.x=380+316;
	m->pos_button2.y=300+136;
	m->pos2.x=450;
	m->pos2.y=320;

}

void afficher_menuu(menu *m,SDL_Surface *ecran)
{
	int y=0;
	int n=0;
	SDL_Rect pos={336,136};

	switch(m->pos_selected)
	{
		case 1:
			y=1;
			n=0;
		break;
		case 2:
            y=0;
            n=1;
		break;
		case 0:
		    y=0;
		    n=0;
		break;
	}
			SDL_BlitSurface(m->background, NULL, ecran,&pos);
	        SDL_BlitSurface(m->buttonyes[y], NULL, ecran, &m->pos_button1);
			SDL_BlitSurface(m->buttonno[n], NULL, ecran, &m->pos_button2);
			SDL_Flip(ecran);
	        SDL_Delay(100);
}



void free_menu(menu *m)
{
	SDL_FreeSurface(m->background);
	SDL_FreeSurface(m->buttonyes[0]);
	SDL_FreeSurface(m->buttonyes[1]);
	SDL_FreeSurface(m->buttonno[0]);
	SDL_FreeSurface(m->buttonno[1]);
}


int menu_save(menu *m,SDL_Surface *ecran,Game G)
{
	int continuer=1;
	SDL_Event event;
	int test=0,state=0;

	while(continuer)
	{	
		afficher_menuu(m,ecran);
		if(SDL_PollEvent(&event))
		{
			switch (event.type)
			{
				case SDL_KEYDOWN:

					switch(event.key.keysym.sym)
					{
						case SDLK_ESCAPE:
						continuer=0;
						break;
						case SDLK_RIGHT:
						   if(m->pos_selected==2)
						    m->pos_selected=1;
						   else if(m->pos_selected==1)
						   	m->pos_selected=2;
						   else
						   	m->pos_selected=2;
						break;
						case SDLK_LEFT:
						   if(m->pos_selected==2)
						    m->pos_selected=1;
						   else if(m->pos_selected==1)
						   	m->pos_selected=2;
						   else
						   	m->pos_selected=1;
						break;
						case SDLK_RETURN:
						   if(m->pos_selected==2)
						   {
						   	   test=0;
						   }
						   else if(m->pos_selected==1)
						   {
						   	    FILE* f=fopen("resources/file/save.bin","wb");
							    fwrite(&G,sizeof(Game),1,f);
							    fclose(f);
							    test=1;
						   }
						   SDL_Delay(1000);
						   continuer=0;
						break;
					}
					
				break;
				case SDL_QUIT:
				 continuer=0;
				break;
			}
		}
	}

	free_menu(m);
	return test;

}


Game chargement_Jeu()
{
	Game G;

     FILE* f=fopen("resources/file/save.bin","rb");
	     fread(&G,sizeof(Game),1,f);
	     fclose(f);

	 return G;
}

Game updateGame(Personne p,ennemi e, minimap m,background b, temps t,int level)
{
    Game G;

    G.pos_perso=p.pos;
	G.pos_ennemi=e.pos;
	G.pos_cam=b.poscam;
	G.pos_dot=m.posdot;
	G.score=p.score;
	G.etat_vie=p.etat_vie;
	G.level=level;

	return G;
}

void initResume(Personne *p,ennemi *e, minimap *m,background *b, temps *t,Game G)
{
    p->pos=G.pos_perso;
	e->pos=G.pos_ennemi;
	b->poscam=G.pos_cam;
	m->posdot=G.pos_dot;
	p->score=G.score;
	p->etat_vie=G.etat_vie;
	m->level=G.level;
	b->level=G.level;
}
