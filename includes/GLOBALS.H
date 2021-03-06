#ifndef GLOBALS_H
#define GLOBALS_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <dos.h>
#include <bios.h>
#include <string.h>
#include <dirent.h>
#include <time.h>

#define bool int
#define true 1
#define false 0
#define MaxX 90
#define MaxY 30
#define MaxSpeed 20
#define oTICKSPEED 150
#define oTIMELIMIT 100
#define totModes 4

int torchRange = 7;
int totLevels;
int levelCnt;
int wished = false;
bool startAnimation = true, returnTitle = false, wait = false, soundOn = true, animationOn = true;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
int nx[] = { -1, 1, 0, 0 };
int ny[] = { 0, 0, -1, 1 };
char border[] = { 196, 179, 218, 191, 192, 217 };
unsigned int TICKSPEED = oTICKSPEED;
unsigned int TIMELIMIT = oTIMELIMIT;

char currentMode[10];
char Modes[totModes][10] = { "Normal", "Normal+", "Hard", "Hard+" };

// Custom Delay function for animation
void halt(int x) {   
    if(!animationOn)	return;
	delay(x);
	while(1)
	{	if(kbhit())	getch();
		else	break;
	}
}

// Distance between difference of points
int distance(int xdiff, int ydiff) {
	int val = abs(xdiff * xdiff) + abs(ydiff * ydiff);
	return (val <= 0) ? 0 : val;
}

// Generate sound
void noise(int f, int d) {
	if(!soundOn)	return;
	sound(f);	halt(d);	nosound();
}

// Draw border around whole screen
void drawBorder() {
	int i;
	textcolor(GREEN);
	for(i=1; i<=24; i++) {	// Vertical
		gotoxy(1, i);	cprintf("%c", border[1]);	gotoxy(80, i);	cprintf("%c", border[1]);
	}
	gotoxy(1, 24);	cprintf("%c", border[4]);	gotoxy(80, 24);	cprintf("%c", border[5]);
	gotoxy(80, 1);	insline();
	gotoxy(1, 1);	cprintf("%c", border[2]);	gotoxy(80, 1);	cprintf("%c", border[3]);
	for(i=2; i<80; i++) {	// Horizontal
		gotoxy(i, 1);	cprintf("%c", border[0]);	gotoxy(i, 25);	cprintf("%c", border[0]);
	}
	textcolor(YELLOW);
}

#include "MZRUN/INCLUDES/TILE.H"
#include "MZRUN/INCLUDES/COORD.H"
//#include "MZRUN/INCLUDES/PATHFIND.H"
#include "MZRUN/INCLUDES/STATE.H"
#include "MZRUN/INCLUDES/OBJECT.H"
#include "MZRUN/INCLUDES/HELP.H"
#include "MZRUN/INCLUDES/LEVEL.H"
#include "MZRUN/INCLUDES/ENGINE.H"
#include "MZRUN/INCLUDES/SCRIPT.H"
#include "MZRUN/INCLUDES/GAME.H"

#endif