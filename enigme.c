#include "enigme.h"



void generer_enigme(Enigme *e){
	e->pos_selected=0;
	e->background= IMG_Load("resources/image/background.png");
	e->back= IMG_Load("resources/image/menuback.png");
	e->button[0]= IMG_Load("resources/image/button.png");
	e->button[1]= IMG_Load("resources/image/button_s.png");

	TTF_Init();
	TTF_Font *police = NULL,*police1=NULL;

	SDL_Color couleur = {0,0,0};

	police = TTF_OpenFont("resources/arial.ttf", 30);
	police1 = TTF_OpenFont("resources/arial.ttf", 20);
	SDL_Surface *texte;

	char questionn[50];

	srand(time(NULL));
	e->num_question=rand()%4;

	while(e->num_question==0){
		srand(time(NULL));
		e->num_question=rand()%4;
	}

	FILE *fquestion=NULL;
	fquestion=fopen("resources/file/questions.txt","r+");
	if(fquestion!=NULL){
		int test=1;
		while (fgets(questionn, 50, fquestion) &&(test!=e->num_question)){
			test++;
		}
		
		fclose(fquestion);
	}

	char reponse[20],reponse1[20],reponse2[20],reponse3[20];

	int min,max;
    switch(e->num_question)
    {
    	case 1:
    	{
    		min=0;
    		max=2;
    		break;
    	}
    	case 2:
    	{
    		min=3;
    		max=5;
    		break;
    	}
    	case 3:
    	{
    		min=6;
    		max=8;
    		break;
    	}
    }

	FILE *freponse=NULL;
	freponse=fopen("resources/file/reponses.txt","r+");
	if(freponse!=NULL){
		int test=0;
		while (fgets((reponse), 15, freponse) &&(test<max)){	
			
			if(test>=min){
				e->reponses[test-min]=TTF_RenderText_Blended(police1, reponse, couleur);
			}
			test++;
		}	
		fclose(freponse);
	}


	FILE *fvraireponse=NULL;
	fvraireponse=fopen("resources/file/vraireponses.txt","r+");
	if(fvraireponse!=NULL){
		int test=1;
		while (fgets((reponse), 15, fvraireponse)){
			
			if(test==e->num_question){
				printf("%s\n",reponse);
				e->reponses[2]=TTF_RenderText_Blended(police1, reponse, couleur);

				srand(time(NULL));
				e->positionVraiReponse=rand()%4;

				while(e->positionVraiReponse==0){
					srand(time(NULL));
					e->positionVraiReponse=rand()%4;
				}
				printf("%d\n",e->positionVraiReponse);
			}
			test++;
		}
		fclose(freponse);
	}


	e->question = TTF_RenderText_Blended(police, questionn, couleur);

	e->pos_question.x=413;
	e->pos_question.y=210;

	e->pos_reponse1.x=563;
	e->pos_reponse1.y=416;

	e->pos_reponse2.x=365;
	e->pos_reponse2.y=542;//648;

	e->pos_reponse3.x=754;
	e->pos_reponse3.y=542;//651;

	e->pos_reponse1txt.x=e->pos_reponse1.x+50;
	e->pos_reponse1txt.y=e->pos_reponse1.y+30;

	e->pos_reponse2txt.x=e->pos_reponse2.x+50;
	e->pos_reponse2txt.y=e->pos_reponse2.y+30;

	e->pos_reponse3txt.x=e->pos_reponse3.x+50;
	e->pos_reponse3txt.y=e->pos_reponse3.y+30;
	e->pos_back.x=179;
	e->pos_back.y=20;


	Mix_AllocateChannels(20);
	SDL_WM_SetCaption("SDL_MIXER",NULL);
	if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1){

	}
	e->sound=Mix_LoadWAV("resources/sound/clic.wav");
	Mix_VolumeMusic(MIX_MAX_VOLUME);

}

void afficher_enigme(Enigme *e,SDL_Surface *ecran)
{
	int x,y,z;
	int a=0;
	int b=0;
	int c=0;


	switch(e->positionVraiReponse)
	{
		case 1:
			x=2;
			y=0;
			z=1;

			switch(e->pos_selected)
			{
			case 1:
				a=1;
				b=0;
				c=0;
			break;
			case 2:
				a=0;
				b=1;
				c=0;
			break;
			case 3:
				a=0;
				b=0;
				c=1;
			break;
		    }
		break;
		case 2:
			x=0;
			y=2;
			z=1;
			switch(e->pos_selected)
			{
	        case 1:
				a=1;
				b=0;
				c=0;
			break;
			case 2:
				a=0;
				b=1;
				c=0;
			break;
			case 3:
				a=0;
				b=0;
				c=1;
			break;
		    }
		break;
		case 3:
			x=0;
			y=1;
			z=2;
			switch(e->pos_selected)
			{
			case 1:
				a=1;
				b=0;
				c=0;
			break;
			case 2:
				a=0;
				b=1;
				c=0;
			break;
			case 3:
				a=0;
				b=0;
				c=1;
			break;
		    }
        break;
	}
			    SDL_BlitSurface(e->back, NULL, ecran, NULL);
			    SDL_BlitSurface(e->background, NULL, ecran,&e->pos_back);
			    SDL_BlitSurface(e->question, NULL, ecran, &e->pos_question);
			    SDL_BlitSurface(e->button[a], NULL, ecran, &e->pos_reponse1);
				SDL_BlitSurface(e->button[b], NULL, ecran, &e->pos_reponse2);
				SDL_BlitSurface(e->button[c], NULL, ecran, &e->pos_reponse3);
				SDL_BlitSurface(e->reponses[x], NULL, ecran, &e->pos_reponse1txt);
				SDL_BlitSurface(e->reponses[y], NULL, ecran, &e->pos_reponse2txt);
				SDL_BlitSurface(e->reponses[z], NULL, ecran, &e->pos_reponse3txt);
				SDL_Flip(ecran);
	            //SDL_Delay(10);
}


int jouer_enigme(Enigme *e,SDL_Surface*ecran)
{
	generer_enigme(e);
	int continuer=1;
	SDL_Event event;
	int test=0;

	while(continuer)
      {	
		afficher_enigme(e,ecran);

		if(SDL_PollEvent(&event))
		{
			switch (event.type)
			{
				case SDL_KEYDOWN:
					switch(event.key.keysym.sym)
					{
						case SDLK_a:
						    e->pos_selected=1;
							Mix_PlayChannel(2,e->sound,0);
							test=verify_enigme(e,ecran);
						break;
						case SDLK_b:
						    e->pos_selected=2;
							Mix_PlayChannel(2,e->sound,0);	
							test=verify_enigme(e,ecran);
						break;
						case SDLK_c:
						    e->pos_selected=3;
							Mix_PlayChannel(2,e->sound,0);
							test=verify_enigme(e,ecran);
						break;
					}
					continuer=0;
				break;
				case SDL_QUIT:
	                continuer=0;
				break;
			}
		}
	}
	free_enigme(e);
	return test;
}

void free_enigme(Enigme *e){
	SDL_FreeSurface(e->background);
	SDL_FreeSurface(e->back);
	SDL_FreeSurface(e->question);
	SDL_FreeSurface(e->reponses[0]);
	SDL_FreeSurface(e->reponses[1]);
	SDL_FreeSurface(e->reponses[2]);
	SDL_FreeSurface(e->button[0]);
	SDL_FreeSurface(e->button[1]);
}

int verify_enigme(Enigme *e,SDL_Surface *ecran)
{
	SDL_Rect pos={330,330};
	if(e->positionVraiReponse==e->pos_selected)
	{
		printf("You win\n");
		SDL_Surface *win;
		win=IMG_Load("resources/image/youwin.png");
		SDL_BlitSurface(win, NULL, ecran,&pos);
		SDL_Flip(ecran);
		SDL_Delay(2000);
		return 1;

	}
	else
	{
		SDL_Surface *lost;
		lost=IMG_Load("resources/image/youlost.png");
		SDL_BlitSurface(lost, NULL, ecran, &pos);
		SDL_Flip(ecran);
		printf("You lost\n");
		SDL_Delay(2000);
		return 0;
	}
	
}
