#include <allegro.h>
#include <iostream>
#include <stdlib.h>
using namespace std;


const int bScreen = 500;
const int hScreen = 500;

const int NROWS = bScreen;
const int NCOLS = hScreen;

#define v(r,c) ((r)*NCOLS+(c))

BITMAP *buffer;

int white; // = makecol(255,255,255);
int green; // = makecol(0, 128, 50);
int black; // = makecol( 0, 255, 128);
int step = 0;   // step

int *readMatrix;
int *writeMatrix;

void swap() {
	int* tmp = readMatrix;
	readMatrix = writeMatrix;
	writeMatrix = tmp;
}

void transitionFunction(int y, int x) {

}

void allegroInit(){
	allegro_init();
	install_keyboard();
	install_mouse();
	set_gfx_mode( GFX_AUTODETECT_WINDOWED, bScreen, hScreen, 0, 0);
	show_mouse(screen);
	buffer = create_bitmap(bScreen, hScreen);
	black = makecol(0, 0, 0);
	white = makecol(255, 255, 255);
	green = makecol(0, 128, 50);
	black = makecol(0, 0, 0);
}

void initGameOfLife(){
	readMatrix  = new int[NROWS*NCOLS];
	writeMatrix = new int[NROWS*NCOLS];

	for (int y = 0; y < NROWS; y++)
		for (int x = 0; x < NCOLS; x++) {
			readMatrix[v(y,x)] = 0;
			writeMatrix[v(y,x)] = 0;
		}

	for (int y = 0; y < NROWS; y++)
		for (int x = 0; x < NCOLS; x++) {
			int tmp = rand()%100;
			if(tmp < 70){
				readMatrix[v(y,x)] = 1;
				writeMatrix[v(y,x)] = 1;
			}
		}

}

void drawwithAllegro() {
	//draw every pixel with a color depending on the state
	for (int y = 0; y < NROWS; y++)
		for (int x = 0; x < NCOLS; x++)
			switch (readMatrix[v(y,x)]) {
			case 0:
				putpixel(buffer, y, x, green);
				break;
			case 1:
				putpixel(buffer, y, x, white);
				break;
			}
	textprintf_ex(buffer, font, 0, 0, white, black, "steps : %i", step);
	//Move the modified buffer to the screen
	blit(buffer, screen, 0, 0, 0, 0, bScreen, hScreen);
}



int main(int, char**) {
	srand(time(NULL));
	allegroInit();
	initGameOfLife();

	while (!key[KEY_ESC])
	{
		for (int y = 0; y < NROWS; y++)
			for (int x = 0; x < NCOLS; x++)
				transitionFunction(y,x);
		swap();
		step++;
		drawwithAllegro();
	}
	return 0;
}
END_OF_MAIN()
