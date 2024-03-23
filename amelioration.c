#include "amelioration.h"
#include "option.h"

int amelioration(SDL_Surface*screen)
{
	int volume = get_volume();
	int done=1;
	int l=0,n=0;
	
    SDL_Surface *background = NULL, *question=NULL;
    SDL_Surface *load[2];
    SDL_Surface *new[2];
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);

    SDL_Rect background_pos;
    SDL_Rect back_pos;
    SDL_Rect posload;
    SDL_Rect posnew;

    SDL_Event event;

  
    background = IMG_Load("resources/image/menuback.png");
    question = IMG_Load("resources/image/back.png");
    load[0] = IMG_Load("resources/image/resume jaune.png");
    load[1] = IMG_Load("resources/image/resume blue.png");
    new[0] = IMG_Load("resources/image/new jaune.png");
    new[1] = IMG_Load("resources/image/new blue.png");

    
    background_pos.x = 0;
    background_pos.y = 0;
    back_pos.x=336;
    back_pos.y=100;
	posload.x=450;
	posload.y=420;
	posnew.x=700;
	posnew.y=420;

    Mix_Chunk *music1;
    Mix_AllocateChannels(2);
    music1 = Mix_LoadWAV("resources/sound/ClicDeSouris.wav");

	while(done){

	if (SDL_PollEvent(&event)) 
        {
            switch (event.type) 
            {
		case SDL_QUIT: 
                done = 0;
                break;
		case SDL_KEYDOWN:             
                switch (event.key.keysym.sym)
                {
					case SDLK_ESCAPE : 
						done = 0;
					break;
					case SDLK_RIGHT:
					if (n == 0 && l == 0)
                    {
                        n = 1;
                        Mix_PlayChannel(-1, music1, 0);
                    }
                    else if (l == 1 && n == 0)
                    {
                        n = 1;
                        l = 0;
                        Mix_PlayChannel(-1, music1, 0);
                    }
                    else if (n == 1 && l == 0)
                    {
                        l = 1;
                        n = 0;
                        Mix_PlayChannel(-1, music1, 0);
                    }
					break;
					case SDLK_LEFT:
					if (n == 0 && l == 0)
                    {
                        l = 1;
                        Mix_PlayChannel(-1, music1, 0);
                    }
                    else if (l == 1 && n == 0)
                    {
                        n = 1;
                        l = 0;
                        Mix_PlayChannel(-1, music1, 0);
                    }
                    else if (n == 1 && l == 0)
                    {
                        l = 1;
                        n = 0;
                        Mix_PlayChannel(-1, music1, 0);
                    }
					break;
					case SDLK_RETURN:
                    if (n == 1)
                    {

                        Mix_PlayChannel(-1, music1, 0);
                        SDL_Delay(100);
                        return 1;
                    }
                    else if (l == 1)
                    {

                        Mix_PlayChannel(-1, music1, 0);
                        SDL_Delay(100);
                        return 2;
                    }
                    break;
				}
		break;
	    }//fin switchevent
	}//fin ifpoolvent

	SDL_BlitSurface(background, NULL, screen, &background_pos);
	SDL_BlitSurface(question, NULL, screen, &back_pos);
	SDL_BlitSurface(load[l], NULL, screen, &posload);
	SDL_BlitSurface(new[n], NULL, screen, &posnew);
	SDL_Flip(screen);
	}//fin while

    Mix_FreeChunk(music1);
	SDL_FreeSurface(background);
	SDL_FreeSurface(question);
	SDL_FreeSurface(load[0]);
	SDL_FreeSurface(load[1]);
	SDL_FreeSurface(new[0]);
	SDL_FreeSurface(new[1]);
}//fin amelioration

int nouv(SDL_Surface*screen)
{
	int done=1;
	int s=0,t=0;
	SDL_Event event;

	//creation background
    SDL_Surface *background = NULL,*question= NULL;
    SDL_Surface *single[2];
    SDL_Surface *two[2];
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);

    background = IMG_Load("resources/image/menuback.png");
    question = IMG_Load("resources/image/background1.png");
    single[0] = IMG_Load("resources/image/single.png");
    single[1] = IMG_Load("resources/image/single1.png");
    two[0] = IMG_Load("resources/image/two.png");
    two[1] = IMG_Load("resources/image/two1.png");

    // determiner pos de back
    SDL_Rect background_pos;
    SDL_Rect back_pos;
    SDL_Rect possingle;
    SDL_Rect postwo;

    background_pos.x = 0;
    background_pos.y = 0;
    back_pos.x=336;
    back_pos.y=100;
	possingle.x=450;
	possingle.y=420;
	postwo.x=700;
	postwo.y=420;

    Mix_Chunk *music1;
    Mix_AllocateChannels(2);
    music1 = Mix_LoadWAV("resources/sound/ClicDeSouris.wav");
	
	while(done){
	if (SDL_PollEvent(&event)) 
        {
            switch (event.type) 
            {
		case SDL_QUIT: 
                done = 0;
                break;
		case SDL_KEYDOWN:             
                switch (event.key.keysym.sym) 
                {
					case SDLK_ESCAPE : 
						done = 0;
					break;
					case SDLK_RIGHT:
					if (t == 0 && s == 0)
                    {
                        t = 1;
                        Mix_PlayChannel(-1, music1, 0);
                    }
                    else if (s == 1 && t == 0)
                    {
                        t = 1;
                        s = 0;
                        Mix_PlayChannel(-1, music1, 0);
                    }
                    else if (t == 1 && s == 0)
                    {
                        s = 1;
                        t = 0;
                        Mix_PlayChannel(-1, music1, 0);
                    }
					break;
					case SDLK_LEFT:
					if (t == 0 && s == 0)
                    {
                        s = 1;
                        Mix_PlayChannel(-1, music1, 0);
                    }
                    else if (s == 1 && t == 0)
                    {
                        t = 1;
                        s = 0;
                        Mix_PlayChannel(-1, music1, 0);
                    }
                    else if (t == 1 && s == 0)
                    {
                        s = 1;
                        t = 0;
                        Mix_PlayChannel(-1, music1, 0);
                    }
					break;
					case SDLK_RETURN:
                    if (s == 1)
                    {

                        Mix_PlayChannel(-1, music1, 0);
                        SDL_Delay(100);
                        return 1;
                    }
                    else if (t == 1)
                    {

                        Mix_PlayChannel(-1, music1, 0);
                        SDL_Delay(100);
                        return 2;
                    }
				}
		break;
	    }
	}

	SDL_BlitSurface(background, NULL, screen, &background_pos);
	SDL_BlitSurface(question, NULL, screen, &back_pos);
	SDL_BlitSurface(single[s], NULL, screen, &possingle);
	SDL_BlitSurface(two[t], NULL, screen, &postwo);
	SDL_Flip(screen);


	}
    Mix_FreeChunk(music1);
	SDL_FreeSurface(background);
	SDL_FreeSurface(single[0]);
	SDL_FreeSurface(single[1]);
	SDL_FreeSurface(two[0]);
	SDL_FreeSurface(two[1]);

}

int nouv2(SDL_Surface*screen)
{
    int done=1;
    int c=0,s=0;
    SDL_Event event;

    //creation background
    SDL_Surface *background = NULL;
    SDL_Surface *clavier[2];
    SDL_Surface *souris[2];
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);

    background = IMG_Load("resources/image/background1.png");
    clavier[0] = IMG_Load("resources/image/keyboard.png");
    clavier[1] = IMG_Load("resources/image/keyboard1.png");
    souris[0] = IMG_Load("resources/image/mouse.png");
    souris[1] = IMG_Load("resources/image/mouse1.png");

    // determiner pos de back
    SDL_Rect background_pos; 
    SDL_Rect posclavier;
    SDL_Rect possouris;

    background_pos.x = 336;
    background_pos.y = 100;
    posclavier.x=500;
    posclavier.y=380;
    possouris.x=695;
    possouris.y=380;

    Mix_Chunk *music1;
    Mix_AllocateChannels(2);
    music1 = Mix_LoadWAV("resources/sound/ClicDeSouris.wav");
    
    while(done)
    {
       if (SDL_PollEvent(&event)) // lors de l'execution de n'importe quel evenement
        {
            switch (event.type) //determiner le tyype de l'evenement
            {
              case SDL_QUIT: //croix rouge
                done = 0;
                break;
              case SDL_KEYDOWN:             // lors de l"appuie d'un boutton du clavier
                switch (event.key.keysym.sym) // determine le boutton du clavier appuyer
                {
                    case SDLK_ESCAPE : 
                        done = 0;
                    break;
                    case SDLK_RIGHT:
                    if ( c == 0 && s == 0)
                    {
                        s = 1;
                        Mix_PlayChannel(-1, music1, 0);
                    }
                    else if (c == 0 && s == 1)
                    {
                        s = 0;
                        c = 1;
                        
                        Mix_PlayChannel(-1, music1, 0);
                    }
                    else if (c == 1 && s == 0)
                    {
                        c = 0;
                        s = 1;
                        Mix_PlayChannel(-1, music1, 0);
                    }
                    break;
                    case SDLK_LEFT:
                    if (c == 0 && s == 0)
                    {
                        c = 1;
                        Mix_PlayChannel(-1, music1, 0);
                    }
                    else if (c == 0 && s == 1)
                    {
                        s = 0;
                        c = 1;
                        
                        Mix_PlayChannel(-1, music1, 0);
                    }
                    else if (c == 1 && s == 0)
                    {
                        c = 0;
                        s = 1;
                        Mix_PlayChannel(-1, music1, 0);
                    }
                    break;
                    case SDLK_RETURN: //enter
                    if (s == 1)
                    {
                        //possouris.x+=90;
                        Mix_PlayChannel(-1, music1, 0);
                        SDL_Delay(400);
                        //return 1;
                    }
                    else if (c == 1)
                    {
                        //posclavier.x-=90;
                        Mix_PlayChannel(-1, music1, 0);
                        SDL_Delay(400);
                        return 2;
                    }
                }
              break;
            }
        }
            SDL_BlitSurface(background, NULL, screen, &background_pos);
            SDL_BlitSurface(clavier[c], NULL, screen, &posclavier);
            SDL_BlitSurface(souris[s], NULL, screen, &possouris);
            SDL_Flip(screen);
    }

    
    Mix_FreeChunk(music1);
    SDL_FreeSurface(background);
    SDL_FreeSurface(clavier[0]);
    SDL_FreeSurface(clavier[1]);
    SDL_FreeSurface(souris[0]);
    SDL_FreeSurface(souris[1]);

}
