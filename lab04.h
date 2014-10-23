#include <msp430.h>

#ifndef _LAB04_H
#define _LAB04_H

extern void init();
extern void initNokia();
extern void clearDisplay(unsigned );
extern void drawBlock(unsigned char row, unsigned char col, unsigned char color);
extern void eraseBlock(unsigned char row, unsigned char col);

#define		TRUE			1
#define		FALSE			0
#define		UP_BUTTON		(P2IN & BIT5)
#define		DOWN_BUTTON		(P2IN & BIT4)
#define		AUX_BUTTON		(P2IN & BIT3)
#define		LEFT_BUTTON		(P2IN & BIT2)
#define		RIGHT_BUTTON	(P2IN & BIT1)

#define SCREEN_WIDTH 11
#define SCREEN_HEIGHT 7

//define colors for the block
typedef enum {BLACK, WHITE} color;

typedef struct {
    int x;
    int y;
} vector2d_t;

typedef struct {
	unsigned char speed;
    vector2d_t position;
    vector2d_t heading;
} ball_t;

typedef struct {
	signed char height;
}paddle_t;

ball_t createBall(int xPos, int yPos, int xHead, int yHead, unsigned char speed);

ball_t moveBall(ball_t ballToMove);

vector2d_t initVector(int x, int y);

paddle_t createPaddle(signed char pos);

void paint();
ball_t bounce(ball_t moveB);
void pong();

#endif
