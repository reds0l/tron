// Functions for Tron
// Maintainer: Charles Shinaver, Jared Rodgers
//
//

#include "func.h"

void moveBike(lightCycle *cycle, double dt, int board[450][450])
{
    /*
     * Checks for collision, moves bike, and adds trail behind
    */
    int i, iMax;
    int x = cycle->x;
    int y = cycle->y;
    int r = cycle->radius;

    switch (cycle->orientation)
    {
        case up:
            // Movement
            if (!cycle->isAlive)
            {
                return;
            }
            cycle->y -= 1*dt;

            // Collision Checking
            i = x - r;
            iMax = x + r;
            for (; i < iMax; i++)
            {
                if (board[i][y] != 0)
                {
                    cycle->isAlive = 0;
                    return;
                }
            }

            // Add trail
            //TODO write add trail part
            break;
        case down:
            // Movement
            if (!cycle->isAlive)
            {
                return;
            }
            cycle->y += 1*dt;

            // Collision Checking
            i = x - r;
            iMax = x + r;
            for (; i < iMax; i++)
            {
                if (board[i][y] != 0)
                {
                    cycle->isAlive = 0;
                    return;
                }
            }

            // Add trail
            //TODO write add trail part
            break;
        case left:
            // Movement
            if (!cycle->isAlive)
            {
                return;
            }
            cycle->x -= 1*dt;

            // Collision Checking
            i = y - r;
            iMax = y + r;
            for (; i < iMax; i++)
            {
                if (board[x][i] != 0)
                {
                    cycle->isAlive = 0;
                    return;
                }
            }

            // Add trail
            //TODO write add trail part
            break;
        case right:
            // Movement
            if (!cycle->isAlive)
            {
                return;
            }
            cycle->x += 1*dt;

            // Collision Checking
            i = y - r;
            iMax = y + r;
            for (; i < iMax; i++)
            {
                if (board[x][i] != 0)
                {
                    cycle->isAlive = 0;
                    return;
                }
            }

            // Add trail
            //TODO write add trail part
            break;
    }
    

}

void plotBike(lightCycle *cycle)
{
    int r = cycle->radius;
    gfx_circle(cycle->x, cycle->y, r);
    switch (cycle->orientation){
        case up:
            gfx_triangle(cycle->x-r, cycle->y+r, cycle->x+r, cycle->y+r, cycle->x, cycle->y+2*r);
            break;
        case down:
            gfx_triangle(cycle->x-r, cycle->y-r, cycle->x+r, cycle->y-r, cycle->x, cycle->y-2*r);
            break;
        case left:
            gfx_triangle(cycle->x+r, cycle->y-r, cycle->x+r, cycle->y+r, cycle->x+2*r, cycle->y);
            break;
        case right:
            gfx_triangle(cycle->x-r, cycle->y+r, cycle->x-r, cycle->y+r, cycle->x-2*r, cycle->y);
            break;
    }
}

void createBoardBoundaries(int xTopLeft, int yTopLeft, int xBottomRight, int yBottomRight, int board[450][450])
{
    /*
     * Adds ones based on board boundaries for Collision checking
     * and plots lines of board
    */

    int i;
    
    gfx_line(xTopLeft, yTopLeft, xBottomRight, xTopLeft);
    for (i = xTopLeft; i < xBottomRight; i++)
    {
        board[i][yTopLeft] = 1;
    }

    gfx_line(xTopLeft, yTopLeft, xTopLeft, yBottomRight);
    for (i = yTopLeft; i < yBottomRight; i++)
    {
        board[xTopLeft][i] = 1;
    }


    gfx_line(xTopLeft, yBottomRight, xBottomRight, yBottomRight);
    for (i = xTopLeft; i < xBottomRight; i++)
    {
        board[i][yBottomRight] = 1;
    }


    gfx_line(xBottomRight, yTopLeft, xBottomRight, yBottomRight);
    for (i = yTopLeft; i < yBottomRight; i++)
    {
        board[xBottomRight][i] = 1;
    }
}
