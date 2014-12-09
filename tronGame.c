// Driver for Tron
// Maintainer: Charles Shinaver, Jared Rodgers
//
//
#include "func.h"

int main()
{
    int i;
    int offset = 50;
    int xsize = 500;
    int ysize = 500;
    int xBoxSize = xsize - offset;
    int yBoxSize = ysize - offset;
    lightCycle *cycle1 = malloc(sizeof(lightCycle));
    cycle1->x = 425;
    cycle1->y = 70;
    cycle1->orientation = left;
    cycle1->isAlive = 1;
    int board[450][450] = {0};

    gfx_open(xsize, ysize, "Tron");

    // Plot boundaries and add to board
    createBoardBoundaries(offset, offset, xBoxSize, yBoxSize, board);


    while(1)
    {
        // moveBike
        moveBike(cycle1, board);
        plotBike(cycle1);
        
        usleep(2000);
    }


    //    plotBike(cycle2);
    return 0;
}

