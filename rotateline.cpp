#include<stdio.h>
#include<winbgim.h>

int main() {
	int d, x1, x2, y1, y2, x01, x02, y01, y02, angle = 90;
	struct arccoordstype a;
	printf("Nhap vao do dai duong thang (pixels): ");
	scanf("%d",&d);
	initwindow(800,600);
	while(true) {
		setcolor(0);
		arc(getmaxx()/2,getmaxy()/2,0,angle,d);
		getarccoords(&a);
		x1 = a.xend; y1 = a.yend;
		arc(getmaxx()/2,getmaxy()/2,0,angle+180,d);
		getarccoords(&a);
		x2 = a.xend; y2 = a.yend;
		setcolor(15);
		line(x1,y1,x2,y2);
		angle = (angle - 1)%360;
		delay(50);
		setcolor(0);
		x01 = x1; y01 = y1; x02 = x2; y02 = y2;
		line(x01,y01,x02,y02);
	}
}