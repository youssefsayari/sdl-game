prog : main.o fonction.o option.o intro.o quitter.o gfxutils.o integration.o scrolling.o ennemi.o perso.o autre.o Karim_Akkari_1A30.o enigmeSlim.o amelioration.o menu.o enigme.o background.o integrationMulti.o introJeu.o Resume.o IA2.o
	gcc -o prog main.o fonction.o option.o intro.o quitter.o gfxutils.o integration.o scrolling.o ennemi.o perso.o autre.o Karim_Akkari_1A30.o enigmeSlim.o  amelioration.o menu.o enigme.o background.o integrationMulti.o introJeu.o Resume.o IA2.o -lm -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
main.o : main.c
	gcc -o main.o -c main.c -lm -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
fonction.o : fonction.c
	gcc -o fonction.o -c fonction.c -lm -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
option.o : option.c
	gcc -o option.o -c option.c -lm -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
intro.o : intro.c
	gcc -o intro.o -c intro.c -lm -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
quitter.o : quitter.c
	gcc -o quitter.o -c quitter.c -lm -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
gfxutils.o : gfxutils.c
	gcc -o gfxutils.o -c gfxutils.c -lm -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
integration.o : integration.c
	gcc -o integration.o -c integration.c -lm -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
scrolling.o : scrolling.c
	gcc -o scrolling.o -c scrolling.c -lm -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
ennemi.o : ennemi.c
	gcc -o ennemi.o -c ennemi.c -lm -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
perso.o : perso.c
	gcc -o perso.o -c perso.c -lm -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
autre.o : autre.c
	gcc -o autre.o -c autre.c -lm -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
Karim_Akkari_1A30.o : Karim_Akkari_1A30.c
	gcc -o Karim_Akkari_1A30.o -c Karim_Akkari_1A30.c -lm -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
enigmeSlim.o : enigmeSlim.c
	gcc -o enigmeSlim.o -c enigmeSlim.c -lm -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
amelioration.o : amelioration.c
	gcc -o amelioration.o -c amelioration.c -lm -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
menu.o : menu.c
	gcc -o menu.o -c menu.c -lm -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
enigme.o : enigme.c
	gcc -o enigme.o -c enigme.c -lm -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
background.o : background.c
	gcc -o background.o -c background.c -lm -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
integrationMulti.o : integrationMulti.c
	gcc -o integrationMulti.o -c integrationMulti.c -lm -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
introJeu.o : introJeu.c
	gcc -o introJeu.o -c introJeu.c -lm -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
Resume.o : Resume.c
	gcc -o Resume.o -c Resume.c -lm -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
IA2.o : IA2.c
	gcc -o IA2.o -c IA2.c -lm -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g




