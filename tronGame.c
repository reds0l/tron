// Driver for Tron
// Maintainer: Charles Shinaver, Jared Rodgers
//
//
#include "gfx3.h"
#include <stdio.h>
#define WIDTH 500
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

void moveBike(lightCycle *cycle);
void plotBike(lightCycle *cycle);

int main()
{
    // moveBike

    //    plotBike(cycle1);
    //    plotBike(cycle2);
    return 0;
}

void plotBike(struct lightCycle *cycle)
{
    int r=2;
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
