// Driver for Tron
// Maintainer: Charles Shinaver, Jared Rodgers
//
//
#include "func.h"

int main()
{
    int i;
    int deadBikeNumber;
    char c;
    double dt = .1;
    Color black = {0, 0, 0};
    Color white = {255, 255, 255};
    Color bike1Color = {255, 255, 0};
    Color bike2Color = {0, 102, 204};
    Scoreboard *scoreboard = malloc(sizeof(Scoreboard));
    scoreboard->player1Score = 0;
    scoreboard->player2Score = 0;
    // Box Dimensions
    int offset = 50;
    int xsize = 750;
    int ysize = 750;
    int xBoxSize = xsize - offset;
    int yBoxSize = ysize - offset;
    int board[700][700] = {0};

    int xInitialCycle1 = xsize-offset-10;
    int yInitialCycle1 = ysize-offset-25;
    // Create cycle1
    LightCycle *cycle1 = malloc(sizeof(LightCycle));
    cycle1->x = xInitialCycle1;
    cycle1->y = yInitialCycle1;
    cycle1->orientation = left;
    cycle1->isAlive = 1;
    cycle1->radius = 2;
    cycle1->color = bike1Color;

    int xInitialCycle2 = offset+10;
    int yInitialCycle2 = offset+25;
    // Create cycle2
    LightCycle *cycle2 = malloc(sizeof(LightCycle));
    cycle2->x = xInitialCycle2;
    cycle2->y = yInitialCycle2;
    cycle2->orientation = right;
    cycle2->isAlive = 1;
    cycle2->radius = 2;
    cycle2->color = bike2Color;


    gfx_open(xsize, ysize, "Tron");

    // Plot boundaries and add to board
    createBoardBoundaries(offset, offset, xBoxSize, yBoxSize, white, board);
    createScoreboard(scoreboard);

    while(1)
    {
        // Check if game has ended
        deadBikeNumber = isBikeDead(cycle1, cycle2);
        if (deadBikeNumber)
        {
            incrementScoreboard(deadBikeNumber, scoreboard);
            if (!isDesiringNewGame(cycle1, cycle2, xInitialCycle1, yInitialCycle1, xInitialCycle2, yInitialCycle2))
            {
                return 0;
            }
            else
            {
                gfx_clear();
                clearBoard(board);
                createBoardBoundaries(offset, offset, xBoxSize, yBoxSize, white, board);
                createScoreboard(scoreboard);
                deadBikeNumber = 0;
            }
        }

        else if (checkForKeyboardInput(cycle1, cycle2) == 'q')
        {
            return 0;
        }

        // moveBike
        moveBike(cycle1, dt, board);
        plotBike(cycle1, cycle1->color);
        moveBike(cycle2, dt, board);
        plotBike(cycle2, cycle2->color);

        usleep(500);
        
    }


    //    plotBike(cycle2);
    return 0;
}

