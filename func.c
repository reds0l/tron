// Functions for Tron
// Maintainer: Charles Shinaver, Jared Rodgers
//
//

#include "func.h"

// Board size
static int xsize = 750;
static int ysize = 750;

void moveBike(LightCycle *cycle, double dt, int board[700][700])
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

void createBoardBoundaries(int xTopLeft, int yTopLeft, int xBottomRight, int yBottomRight, Color boardColor, int board[700][700])
{
    /*
     * Adds ones based on board boundaries for Collision checking
     * and plots lines of board
    */

    int i;

    gfx_color(boardColor.r, boardColor.g, boardColor.b);
    
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
                if (cycle1->isAlive && cycle1->orientation != left)
                {
                    cycle1->orientation = left;
                    cycle1->x -= r1+1;
                }
                break;
            case 'k':
                if (cycle1->isAlive && cycle1->orientation != down)
                {
                    cycle1->orientation = down;
                    cycle1->y += r1+1;
                }
                break;
            case 'i':
                if (cycle1->isAlive && cycle1->orientation != up)
                {
                    cycle1->orientation = up;
                    cycle1->y -= r1+1;
                }
                break;
            case 'l':
                if (cycle1->isAlive && cycle1->orientation != right)
                {
                    cycle1->orientation = right;
                    cycle1->x += r1+1;
                }
                break;
            case 'a':
                if (cycle2->isAlive && cycle2->orientation != left)
                {
                    cycle2->orientation = left;
                    cycle2->x -= r2;
                }
                break;
            case 's':
                if (cycle2->isAlive && cycle2->orientation != down )
                {
                    cycle2->orientation = down;
                    cycle2->y += r2;
                }
                break;
            case 'w':
                if (cycle2->isAlive && cycle2->orientation != up)
                {
                    cycle2->orientation = up;
                    cycle2->y -= r2;
                }
                break;
            case 'd':
                if (cycle2->isAlive && cycle2->orientation != right)
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

void createScoreboard(Scoreboard *score)
{
    char yellow[35] = "Yellow Player's Score: "; 
    char blue[35] = "Blue Player's Score: ";
    sprintf(yellow, "%s%i", yellow, score->player1Score);
    sprintf(blue, "%s%i", blue, score->player2Score);
    gfx_text(550, 20, yellow); 
    gfx_text(550, 40, blue);
}

int isBikeDead(LightCycle *cycle1, LightCycle *cycle2)
{
    /*
     * Returns cycle number if cycle has died, else returns 0
    */

    if (!cycle1->isAlive && !cycle2->isAlive)
    {
        return 3;
    }
    else if (!cycle1->isAlive)
    {
        return 1;
    }
    else if (!cycle2->isAlive)
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

void incrementScoreboard(int deadBikeNumber, Scoreboard *scoreboard)
{
    /*
     * Increments scoreboard based on bike that died
    */
    if (deadBikeNumber == 3)
    {
        return;    
    }
    else if (deadBikeNumber == 1)
    {
        scoreboard->player2Score+= 1;
    }
    else if(deadBikeNumber == 2)
    {
        scoreboard->player1Score += 1;
    }
}

int isDesiringNewGame(LightCycle *cycle1, LightCycle *cycle2, int xInitialCycle1, int yInitialCycle1, int xInitialCycle2, int yInitialCycle2)
{
    /*
     * Asks users if they would like a new game, resets positions if so
    */

    char c;

    if (!cycle2->isAlive && !cycle1->isAlive)
    {
        gfx_color(255, 255, 255);
        gfx_text(250, 20, "It's a tie!");
        gfx_text(250, 40, "Press n for new round. Press q to quit");
    }
    else if (cycle1->isAlive)
    {
        gfx_color(cycle1->color.r, cycle1->color.g, cycle1->color.b);
        gfx_text(250, 20, "Yellow player wins!");
        gfx_text(250, 40, "Press n for new round. Press q to quit");
    }
    else if (cycle2->isAlive)
    {
        gfx_color(cycle2->color.r, cycle2->color.g, cycle2->color.b);
        gfx_text(250, 20, "Blue player wins!");
        gfx_text(250, 40, "Press n for new round. Press q to quit");
    }
    
    while (1)
    {
        c = gfx_wait();
        switch (c)
        {
            case 'n':
                cycle1->x = xInitialCycle1;
                cycle1->y = yInitialCycle1;
                cycle2->x = xInitialCycle2;
                cycle2->y = yInitialCycle2;
                cycle1->isAlive = 1;
                cycle2->isAlive = 1;
                cycle1->orientation = left;
                cycle2->orientation = right;
                return 1;
                break;
            case 'q':
                return 0;
                break;
            default:
                continue;
        }
    }
}

void clearBoard(int board[700][700])
{
    /*
     * fills board with 0's
    */
    int i, j;
    for (i = 0; i < 700; i++)
    {
        for (j = 0; j < 700; j++)
        {
            board[i][j] = 0;
        }
    }
}

void countdown(char *text)
{
}

void changeFontSize(int fontSize)
{
    /*
     * Displays text with given font size
    */
    char fontStr[100];
    sprintf(fontStr, "-*-helvetica-medium-r-normal-*-%i-120-*-*-*-*-iso8859-1", fontSize);
    change_font(fontStr);
}
int randNum (int min, int max)
{
    return rand()%((max-min+1)+min);
}

int createMenu(void)
{
    char c='1';
    gfx_clear();
    while(1)
    {
        changeFontSize(12);
        gfx_color(255,255,255);
        gfx_text(25,25, "Bike one controls:   "
                        "W = up   "
                        "A = left   "
                        "S = down   "
                        "D = right   ");
        gfx_text(25,45, "Bike two controls:   "
                        "I = up   "
                        "J = left   "
                        "K = down   "
                        "L = right   ");
        changeFontSize(20);
        gfx_text(xsize/2, ysize/2+50, "Press n to start a new game");
        changeFontSize(80);
        gfx_color(randNum(0,255),randNum(0,255),randNum(0,255));
        gfx_text(xsize/2, ysize/2, "TRON");
        usleep(700000);
        if (gfx_event_waiting())
        {
            c = gfx_wait();
        }
        if (c=='n')
        {
            changeFontSize(12);
            gfx_clear();
            return 0;
        }
        else if (c=='q')
        {
            return 1;
        }
    }
}
