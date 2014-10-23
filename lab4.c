#include <msp430g2553.h>
#include "lab04.h"

void main() {



	// === Initialize system ================================================
	IFG1=0; /* clear interrupt flag1 */
	WDTCTL=WDTPW+WDTHOLD; /* stop WD */
	init();
	initNokia();
	clearDisplay();

	while(1) {
		//up for required funct
		if (UP_BUTTON == 0) {
			while(UP_BUTTON == 0);
			paint();

		//down for a funct
		} else if (DOWN_BUTTON == 0) {
			while(DOWN_BUTTON == 0);
			ball_t theBall = createBall(4, 4, 1, -1, 5); //create a new ball
			pong(theBall);

		//left for b funct
		} else if (LEFT_BUTTON == 0) {
			ball_t theBall = createBall(4, 4, 1, -1, 3); //create a pong ball
			while(LEFT_BUTTON == 0);
			//bounce the ball forever
			while(1){
				drawBlock(theBall.position.y, theBall.position.x);
				theBall = bounce(theBall);
				clearDisplay();
				if (UP_BUTTON == 0){
					theBall.speed++;
				}
				if (DOWN_BUTTON == 0){
					theBall.speed--;
				}

			}
		}
	}//end while

}//end of main
