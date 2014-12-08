// Driver for Tron
// Maintainer: Charles Shinaver, Jared Rodgers
//
//

#include "gfx3.h"
#include <stdio.h>

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

int main()
{
    printf("hi");
    return 0;
}
