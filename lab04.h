#include <msp430.h>

#ifndef _LAB04_H
#define _LAB04_H

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

void paint();

#endif
