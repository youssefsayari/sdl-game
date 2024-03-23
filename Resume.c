#include "header.h"

#define  largeur_fenetre 1366
#define  hauteur_fenetre 768
#define largeur_background 8904
#define largeur_map 890

void Resume(SDL_Surface *screengame)
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
	/**************************************************************************************************************/
//declaration des structures du jeu
    background b;
    Personne p;
    ennemi e;
    obstacle ob;
    minimap m;
    temps t;
	enigme En;
	Enigme EN;
	menu Men;
	Game G;
	int level=1;
 	/**************************************************************************************************************/
	int volum = 128;
    int direction = -1;
    int i,j;	
	int collision = 0;
	int redimensionnement = 20*largeur_map/largeur_background;
	Uint32 dt;
	int reponse=-1;
	int deplacement;
	int done=1;
	int test=0,test2=0;
	SDL_Event event;
 	/**************************************************************************************************************/
 	initmusic(&music,&music1);
    SDL_EnableKeyRepeat(10,10);
    Mix_VolumeMusic(volum);
    Mix_PlayMusic(music,-1);
	initEnnemi(&e);
    initPerso(&p);
    initObstacle(&ob);
    init_menu_save(&Men);
    G=chargement_Jeu();
    level=G.level;
    initBack(&b,level);
    initmap(&m,level);
    
    //loadlevel(level,&p,&m,&b,screengame);
    initResume(&p,&e,&m,&b,&t,G);
    initialiser_temps(&t);
 	/**************************************************************************************************************/
    
	    
	do
	{ 
       /**************************************************************************************************************/
		direction = Get_EventDirection(&done);
		deplacement = majminimap(&p,&m,direction,redimensionnement);
		KICCAS_GetKeyState(&p,direction);//pour verifier si une touche de direction est activer
		/**************************************************************************************************************/
		    if(deplacement)    //pour gerer la condition de scrolling.
			    deplacerPerso(&p,dt);
		    if(!deplacement)
			    scrolling(&b,direction);
		/**************************************************************************************************************/
	       	if(e.etat_vie>0)
		        collision = collisionBB(p.pos,e.pos);
		    else
			    collision=0;
	       	if(collision)
			{
				p.collision++;
				e.collision++;
				Mix_PlayChannel(-1, music1, 0);
			}  
			if(direction==-2)
		    {
			      SDL_EnableKeyRepeat(100,100);
			      G=updateGame(p,e,m,b,t);
		          menu_save(&Men,screengame,G);
		          done=0;
		    } 
		    if(m.posdot.x>=890)
    	    {
    		    level++;
    		    e.etat_vie=3;
    		    loadlevel(level,&p,&m,&b,screengame);
    	    }
    	    if(p.etat_vie==0)
    	    {
		        En=generer();
       	        while(p.etat_vie==0 && p.reponse==0)
            	p.reponse=afficherenigme(En,screengame);
    	    }
    	   updatePerso(&p);
		   updateEnnemi(&e,p); 
		   saut(&p);
    	/**************************************************************************************************************/
		deplacerIA(&e);
		//afficher 
    	afficherback(b,screengame);
    	afficherEnnemi(e,screengame);
    	afficher_temps(&t,screengame);
    	afficher_infoPerso(p,screengame);
    	afficherminimap(m, screengame);
    	afficherPerso(p,screengame);
    	animerEnnemi(&e);		//animer l'ennemi
		animerPerso(&p);        //animer le perso
		//rafraichir
	    SDL_Delay(10);
    	SDL_Flip(screengame);

    	/**************************************************************************************************************/
    }while(done!=0 && level!=4);


    free_minimap(m);
    free_temps(t);
	libererennemi(e);
	libererperso(p);
	libererback(b);
	SDL_FreeSurface(screengame);
	SDL_FreeSurface(gameover);
	Mix_FreeChunk(music1);
	Mix_FreeMusic(music);
	SDL_FreeSurface(ob.image);
	TTF_Quit();
}

