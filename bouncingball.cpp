#include <graphics.h>
#include <conio.h>
#include <dos.h>

int main() {
    int gd = DETECT, gm;
    int x = 50, y = 50, dx = 5, dy = 5, r = 20;

    initgraph(&gd, &gm, "");

    while (!kbhit()) { // Loop until key pressed
        cleardevice(); //Erase old frame before new frame created
        circle(x, y, r);
        x += dx;
        y += dy;

        if (x + r > getmaxx() || x - r < 0) dx = -dx;
        if (y + r > getmaxy() || y - r < 0) dy = -dy;

        delay(50); // Control speed
    }
	getch();
    closegraph();
    return 0;
}