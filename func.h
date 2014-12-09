// Header for Tron
// Maintainer: Charles Shinaver, Jared Rodgers
//
//

#include "gfx3.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

enum Orientation{
    up,
    down,
    left,
    right,
};

typedef struct lightCycle {
    int x;
    int y;
    enum Orientation orientation;
    int isAlive;
} lightCycle;

void moveBike(lightCycle *cycle, int board[450][450]);
void plotBike(lightCycle *cycle);
void createBoardBoundaries(int xTopLeft, int yTopLeft, int xBottomRight, int yBottomRight, int board[450][450]);