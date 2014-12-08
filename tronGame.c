// Driver for Tron
// Maintainer: Charles Shinaver, Jared Rodgers
//
//

#include "func.h"

int main()
{
    int offset = 50;
    int xsize = 500;
    int ysize = 500;
    int xBoxSize = xsize - offset;
    int yBoxSize = ysize - offset;


    gfx_open(xsize, ysize, "Tron");

    // Plot boundaries
    gfx_line(offset, offset, xBoxSize, offset);
    gfx_line(offset, offset, offset, yBoxSize);
    gfx_line(offset, yBoxSize, xBoxSize, yBoxSize);
    gfx_line(xBoxSize, offset, xBoxSize, yBoxSize);

    // moveBike




    // plotBike
    return 0;
}
