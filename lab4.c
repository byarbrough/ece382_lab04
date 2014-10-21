#include <msp430g2553.h>
#include "lab04.h"

void main() {



	// === Initialize system ================================================
	IFG1=0; /* clear interrupt flag1 */
	WDTCTL=WDTPW+WDTHOLD; /* stop WD */
	init();
	initNokia();
	clearDisplay();

	paint();
	pong();
	bounce();

}//end of main
