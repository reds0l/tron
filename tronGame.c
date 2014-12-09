// Driver for Tron
// Maintainer: Charles Shinaver, Jared Rodgers
//
//
#include "func.h"

int main()
{
    int i;
    char c;
    double dt = .1;
    Color black = {0, 0, 0};
    Color white = {255, 255, 255};
    Color bike1Color = {125, 125, 125};
    // Box Dimensions
    int offset = 50;
    int xsize = 500;
    int ysize = 500;
    int xBoxSize = xsize - offset;
    int yBoxSize = ysize - offset;
    int board[450][450] = {0};

    // Create cycle1
    LightCycle *cycle1 = malloc(sizeof(LightCycle));
    cycle1->x = 425;
    cycle1->y = 70;
    cycle1->orientation = left;
    cycle1->isAlive = 1;
    cycle1->radius = 2;
    cycle1->color = bike1Color;


    gfx_open(xsize, ysize, "Tron");

    // Plot boundaries and add to board
    createBoardBoundaries(offset, offset, xBoxSize, yBoxSize, board);


    while(1)
    {
        if (checkForKeyboardInput(cycle1, cycle1) == 'q')
        {
            return 0;
        }

        // moveBike
        moveBike(cycle1, dt, board);
        plotBike(cycle1, cycle1->color);

        usleep(500);
        
    }


    //    plotBike(cycle2);
    return 0;
}

