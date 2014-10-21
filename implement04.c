#include "lab04.h"

void paint(){
	unsigned char	x, y, button_press;
	x=4;		y=4;
	drawBlock(x, y);
	button_press = FALSE;

	color blockColor = BLACK;

	while(1) {

			if (UP_BUTTON == 0) {
				while(UP_BUTTON == 0);
				if (y>=1) y=y-1;
				button_press = TRUE;
			} else if (DOWN_BUTTON == 0) {
				while(DOWN_BUTTON == 0);
				if (y<=6) y=y+1;
				button_press = TRUE;
			} else if (LEFT_BUTTON == 0) {
				while(LEFT_BUTTON == 0);
				if (x>=1) x=x-1;
				button_press = TRUE;
			} else if (RIGHT_BUTTON == 0) {
				while(RIGHT_BUTTON == 0);
				if (x<=10) x=x+1;
				button_press = TRUE;
			}
			//check for aux button push
			else if (AUX_BUTTON == 0) {
				while (AUX_BUTTON == 0);
				if (blockColor == BLACK){
					blockColor = WHITE;
				}
				else {
					blockColor = BLACK;
				}
				button_press = TRUE;
			}

			//actually draws the block
			if (button_press) {
				button_press = FALSE;
				if (blockColor == BLACK){
				drawBlock(y,x);
				}
				else {
					eraseBlock(y,x);
				}
		}
	}
}

void bounce(){
}

void pong(){
}

