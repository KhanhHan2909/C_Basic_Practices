#include <graphics.h>
#include <conio.h>
#include <math.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int midy = 200;

    for (int x = 0; x < 640; x++) {
        int y = midy + 100 * sin(x * 3.14 / 180); // Convert degrees to radians
        putpixel(x, y, WHITE); // Draw pixel
    }

    getch();
    closegraph();
    return 0;
}