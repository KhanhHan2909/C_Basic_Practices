#include <graphics.h>
#include <conio.h>   // For getch()

int main(){
   	int gd = DETECT, gm;
   	initgraph(&gd, &gm, "C:\\TC\\BGI");
   	line(100,100,300,300);
   	line(300,300,150,450);
   	line(150,450,100,100);
	getch();
   	closegraph();
   	return 0;
}