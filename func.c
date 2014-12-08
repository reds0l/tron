// Functions for Tron
// Maintainer: Charles Shinaver, Jared Rodgers
//
//

#include "func.h"

void moveBike(lightCycle *cycle, int board[][450])
{
    /*
     * Checks for collision, moves bike, and adds trail behind
    */

    switch (cycle->orientation)
    {
        case up:
            // Movement
            if (!cycle->isAlive)
            {
                return;
            }
            cycle->y -= 1;

            // Collision Checking
            //TODO Possibly check line in front of cycle
            if (board[cycle->x][cycle->y])
            {
                cycle->isAlive = 0;
            }

            // Add trail
            //TODO write add trail part

    }
    

}
