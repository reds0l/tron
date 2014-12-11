// Header for Tron
// Maintainer: Charles Shinaver, Jared Rodgers
//
//

#include "gfx3.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

enum Orientation{
    left,
    right,
    up,
    down,
};

typedef struct Color {
    int r;
    int g;
    int b;
} Color;

typedef struct LightCycle {
    double x;
    double y;
    enum Orientation orientation;
    int isAlive;
    int radius;
    Color color;
} LightCycle;

typedef struct Scoreboard {
    int player1Score;
    int player2Score;
} Scoreboard;


void moveBike(LightCycle *cycle, double dt, int board[750][750]);
void plotBike(LightCycle *cycle, Color bikeColor);
void removeOldBike(LightCycle *cycle, double dt, Color colorForReplacing);
void createBoardBoundaries(int xTopLeft, int yTopLeft, int xBottomRight, int yBottomRight, Color boardColor, int board[750][750]);
char checkForKeyboardInput(LightCycle *cycle1, LightCycle *cycle2);
int isBikeDead(LightCycle *cycle1, LightCycle *cycle2);
void incrementScoreboard(int deadBikeNumber, Scoreboard *scoreboard);
int isDesiringNewGame(LightCycle *cycle1, LightCycle *cycle2, int xInitialCycle1, int yInitialCycle1, int xInitialCycle2, int yInitialCycle2);
void clearBoard(int board[750][750]);
void createScoreboard(Scoreboard *score);
