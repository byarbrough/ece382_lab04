#include "lab04.h"

ball_t createBall(int xPos, int yPos, int xHead, int yHead, unsigned char speed){

	ball_t newBall;
	newBall.position = initVector(xPos, yPos);
	newBall.heading = initVector(xHead, yHead);
	newBall.speed = speed;

	return newBall;
}

//creates a new paddle
paddle_t createPaddle(signed char pos){
	paddle_t newPad;
	newPad.height = pos;
	return newPad;
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
	drawBlock(x, y, 0xFF);
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
					clearDisplay(0xFF);
				}
				else {
					blockColor = BLACK;
					//flip the color of the screen
					clearDisplay(0x00);
				}
				button_press = TRUE;
			}

			//actually draws the block
			if (button_press) {
				button_press = FALSE;
				if (blockColor == BLACK){
					drawBlock(y,x, 0xFF);
				}
				else {
					drawBlock(y,x, 0x00);
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

void pong(ball_t pBall){
	unsigned char playing = TRUE;
	color blockColor = BLACK;
	//create the paddle
	paddle_t paddle = createPaddle(4);

	while(playing){

		//move the ball
		pBall = bounce(pBall);

		//check for movement of the paddle
		if (UP_BUTTON == 0) {
			//while(UP_BUTTON == 0);
			paddle.height--;
		} else if (DOWN_BUTTON == 0) {
			//while(DOWN_BUTTON == 0);
			paddle.height++;
		}

		//check for paddle contact
		if (pBall.position.x == SCREEN_WIDTH){
			if (pBall.position.y != paddle.height){
				//end the game
				playing = FALSE;
			}
		}//end of checking for paddle

		//check for the AUX button
		if (AUX_BUTTON == 0) {
			while (AUX_BUTTON == 0);
			//flip block color
			if (blockColor == BLACK){
				blockColor = WHITE;
			}
			else {
				blockColor = BLACK;
			}

		//update display
			if (blockColor == BLACK){
				clearDisplay(0x00);
				drawBlock(paddle.height, SCREEN_WIDTH, 0xAA);
				drawBlock(pBall.position.y, pBall.position.x, 0xFF);
			}
			else {
				clearDisplay(0x00);
				drawBlock(paddle.height, SCREEN_WIDTH, 0x55);
				drawBlock(pBall.position.y, pBall.position.x, 0x00);
			}

	}//end of playing

	//game over
	while(1);

}//end of pong

