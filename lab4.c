#include <msp430g2553.h>

extern void init();
extern void initNokia();
extern void clearDisplay();
extern void drawBlock(unsigned char row, unsigned char col);
extern void eraseBlock(unsigned char row, unsigned char col);

#define		TRUE			1
#define		FALSE			0
#define		UP_BUTTON		(P2IN & BIT5)
#define		DOWN_BUTTON		(P2IN & BIT4)
#define		AUX_BUTTON		(P2IN & BIT3)
#define		LEFT_BUTTON		(P2IN & BIT2)
#define		RIGHT_BUTTON	(P2IN & BIT1)

//define colors for the block
typedef enum	{BLACK, WHITE} color;


void main() {

	unsigned char	x, y, button_press;

	color blockColor = BLACK;

	// === Initialize system ================================================
	IFG1=0; /* clear interrupt flag1 */
	WDTCTL=WDTPW+WDTHOLD; /* stop WD */
	button_press = FALSE;


	init();
	initNokia();
	clearDisplay();
	x=4;		y=4;
	drawBlock(y,x);

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
}//end of main
