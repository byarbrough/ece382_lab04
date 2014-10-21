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
			pong();
		//left for b funct
		} else if (LEFT_BUTTON == 0) {
			while(LEFT_BUTTON == 0);
			bounce();
		}
	}//end while

}//end of main
