// Functions for Tron
// Maintainer: Charles Shinaver, Jared Rodgers
//
//

#include "func.h"

void moveBike(LightCycle *cycle, double dt, int board[750][750])
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
            board[(int)cycle->x][(int)(cycle->y + 1)] = 1;
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
            board[(int)cycle->x][(int)(cycle->y - 1)] = 1;
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
            board[(int)(cycle->x + 1)][(int)cycle->y] = 1;
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
            board[(int)(cycle->x - 1)][(int)cycle->y] = 1;
            break;
    }
    

}

void plotBike(LightCycle *cycle, Color bikeColor)
{
    int r = cycle->radius;
    gfx_color(bikeColor.r, bikeColor.g, bikeColor.b);
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

void createBoardBoundaries(int xTopLeft, int yTopLeft, int xBottomRight, int yBottomRight, int board[750][750])
{
    /*
     * Adds ones based on board boundaries for Collision checking
     * and plots lines of board
    */

    int i;

    // Choose whether to plot bike or remove old plot
    
    
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

char checkForKeyboardInput(LightCycle *cycle1, LightCycle *cycle2)
{
    /*
     * Checks for keyboard input and deals with it accordingly
    */

    char c;
    int r1 = cycle1->radius;
    int r2 = cycle2->radius;
    if (gfx_event_waiting())
    {
        c = gfx_wait();
        switch (c)
        {
            case 'j':
                if (cycle1->isAlive)
                {
                    cycle1->orientation = left;
                    cycle1->x -= r1+1;
                }
                break;
            case 'k':
                if (cycle1->isAlive)
                {
                    cycle1->orientation = down;
                    cycle1->y += r1+1;
                }
                break;
            case 'i':
                if (cycle1->isAlive)
                {
                    cycle1->orientation = up;
                    cycle1->y -= r1+1;
                }
                break;
            case 'l':
                if (cycle1->isAlive)
                {
                    cycle1->orientation = right;
                    cycle1->x += r1+1;
                }
                break;
            case 'a':
                if (cycle2->isAlive)
                {
                    cycle2->orientation = left;
                    cycle2->x -= r2;
                }
                break;
            case 's':
                if (cycle2->isAlive)
                {
                    cycle2->orientation = down;
                    cycle2->y += r2;
                }
                break;
            case 'w':
                if (cycle2->isAlive)
                {
                    cycle2->orientation = up;
                    cycle2->y -= r2;
                }
                break;
            case 'd':
                if (cycle2->isAlive)
                {
                    cycle2->orientation = right;
                    cycle2->x += r2;
                }
                break;
            case 'q':
                return 'q';

        } 
    }
}

void createScoreboard (int score[])
{
    char yellow[35] = "Yellow Player's Score:"; 
    char blue[35] = "Blue Player's Score:";
    gfx_text(400, 20, yellow); 
    gfx_text(410, 20, blue);
}
