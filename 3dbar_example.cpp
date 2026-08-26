#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int height[] = {100, 150, 80, 200}; // Heights of bars
    int x = 50;

    for (int i = 0; i < 4; i++) {
        setfillstyle(LINE_FILL, i+1); // Line color fill
        bar3d(x, 300-height[i], x+50, 300, 20, 1); // Draw 3D bar
        x += 70;
    }

    getch();
    closegraph();
    return 0;
}