#include "header.h"

#define  largeur_fenetre 1366
#define  hauteur_fenetre 768
#define largeur_background 8904
#define largeur_map 890

void ecran_Jeu_Multi(SDL_Surface *screengame)
{
	/************************************************************************************************************/
//initialiser 
	SDL_Surface *gameover=NULL;
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
	TTF_Init();
	/**************************************************************************************************************/
//declaration de la music
	Mix_Chunk  *music1;
    Mix_Music *music;
    initmusic(&music,&music1);
	/**************************************************************************************************************/
//declaration des structures du jeu
    backgroundm b;
    Personne p1,p2;
    ennemi e;
    obstacle ob;
    minimap m1,m2;
    temps t;
	enigme En;
	SDL_Event event;
	Enigme EN;
 	/**************************************************************************************************************/
	int volum = 128;
    int direction = -1;
    int direction2=-1;
    int i,j;	
	int collision = 0;
	int redimensionnement = 10*largeur_map/largeur_background;
	Uint32 dt;
	int reponse=-1;
	int deplacement,deplacement2;
	int done=1;
	int test=0;
 	/**************************************************************************************************************/
    SDL_EnableKeyRepeat(30,30);
    Mix_VolumeMusic(volum);
    Mix_PlayMusic(music,-1);
	initEnnemi(&e);
    initBack_Multi(&b);
    initPerso1(&p1);
    initPerso2(&p2);
    initObstacle(&ob);
    initmap1(&m1);
    initmap2(&m2);
    test=jouer_enigme(&EN,screengame);
    initialiser_tempsm(&t);
 	/**************************************************************************************************************/
    
	while(done)
	{ 
		direction = Get_EventDirection2(&done,&direction2);
		KICCAS_GetKeyStateMulti(&p1,&p2,direction,direction2);
		//collision = collisionBB(p1.pos,e1.pos);
		deplacement = majminimap(&p1,&m1,p1.dir,redimensionnement);
	    deplacement2 = majminimap2(&p2,&m2,p2.dir,redimensionnement);
		/**************************************************************************************************************/
		/**************************************************************************************************************/
			scrolling_Multi(&b,direction);
			scrolling2_Multi(&b,direction2);
        /**************************************************************************************************************/
		/*if(p.reponse==0)
    	{
		    En=generer();
       	    while(p.etat_vie==0 && p.reponse==0)
            	p.reponse=afficherenigme(En,screengame);
    	}*/
    	   //updatePerso(&p);
		   //updateEnnemi(&e,p); 
       /**************************************************************************************************************/
		//deplacerEnnemi(&e); //deplacer l'ennemi
		//deplacerIA(&e);
		//animerEnnemi(&e);		//animer l'ennemi
		animerPersoMulti(&p1);//animer le perso
		animerPersoMulti(&p2);
		/**************************************************************************************************************/
	       	/*if(collision)
			{
				p.collision++;
				Mix_PlayChannel(-1, music1, 0);
			} */  
 		/**************************************************************************************************************/
        //afficher 
        afficherPerso(p1,screengame);
		afficherPerso(p2,screengame);
        aficherBack_Multi(b,screengame);
    	//afficherEnnemi(e,screengame);
    	afficher_temps(&t, screengame);
    	afficherminimap(m1,screengame);
    	afficherminimap(m2,screengame);

    	/**************************************************************************************************************/
		//rafraichir
	    SDL_Delay(10);
    	SDL_Flip(screengame);
    	/**************************************************************************************************************/
    }


    free_minimap(m1);
    free_minimap(m2);
    free_temps(t);
	libererennemi(e);
	libererpersoMulti(p1);
	libererpersoMulti(p2);
	SDL_FreeSurface(b.image);
	SDL_FreeSurface(screengame);
	SDL_FreeSurface(gameover);
	Mix_FreeChunk(music1);
	Mix_FreeMusic(music);
	SDL_FreeSurface(ob.image);
	TTF_Quit();
}
