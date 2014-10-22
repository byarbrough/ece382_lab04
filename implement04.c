#include "lab04.h"

ball_t createBall(int xPos, int yPos, int xHead, int yHead, unsigned char speed, unsigned char radius){

	ball_t newBall;
	newBall.position = initVector(xPos, yPos);
	newBall.heading = initVector(xHead, yHead);
	newBall.radius = radius;
	newBall.speed = speed;

	return newBall;
}

vector2d_t initVector(int x, int y)
{
    vector2d_t newVector;
    newVector.x = x;
    newVector.y = y;

    return newVector;
}

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

/**
 * This method is resposible for moving and bouncing the ball
 */
ball_t bounce(ball_t moveB){

	//check for bouncing
	if (moveB.position.x <= 0 || moveB.position.x >= SCREEN_WIDTH){
		moveB.heading.x *= -1;
	}
	if (moveB.position.y <= 0 || moveB.position.y >= SCREEN_HEIGHT){
			moveB.heading.y *= -1;
	}

	//move the ball
	moveB.position.x += moveB.heading.x;
	moveB.position.y += moveB.heading.y;

	//delay
	unsigned long x = 0;
	while (x < (82016/moveB.speed)){
		x++;
	}

	return moveB;
}

/*
void bounce(){
	unsigned char speed = 1;
	signed char	x, y;
	signed char xHead, yHead;
	x=4;		y=4;
	xHead = 1;	yHead= 1;
	drawBlock(x, y);

	while(1){
		//horizontal bounce
		if(x >= 11 || x <= 0){
			xHead *= -1;
		}
		//vertical bounce
		if ( y >= 7 || y <= 0 ){
			yHead *= -1;
		}

		//update position
		x += xHead;
		y += yHead;

		//draw
		clearDisplay();
		drawBlock(y, x);

		//delay
		unsigned long x = 0;
		while (x < (802016/speed)){
			x++;
		}
	}

}
*/

void pong(){
}

