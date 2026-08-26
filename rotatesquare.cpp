#include<stdio.h>
#include<winbgim.h>

int main() {
	int d, x1, x2, y1, y2, x3, y3, x4, y4, x01, y01, x02, y02, x03, y03, x04, y04, angle = 45;
	struct arccoordstype a;
	printf("Nhap vao ban kinh quay cua hinh vuong (pixels): ");
	scanf("%d",&d);
	initwindow(800,600);
	while(true) {
		setcolor(0);
		arc(getmaxx()/2,getmaxy()/2,0,angle,d);
		getarccoords(&a);
		x1 = a.xend; y1 = a.yend;
		arc(getmaxx()/2,getmaxy()/2,0,angle+90,d);
		getarccoords(&a);
		x2 = a.xend; y2 = a.yend;
		arc(getmaxx()/2,getmaxy()/2,0,angle+180,d);
		getarccoords(&a);
		x3 = a.xend; y3 = a.yend;
		arc(getmaxx()/2,getmaxy()/2,0,angle+270,d);
		getarccoords(&a);
		x4 = a.xend; y4 = a.yend;
		setcolor(15);
		line(x1,y1,x2,y2); line(x2,y2,x3,y3); line(x3,y3,x4,y4); line(x4,y4,x1,y1);
		angle = (angle-1)%360;
		delay(50);
		x01 = x1; y01 = y1; x02 = x2; y02 = y2; x03 = x3; y03 = y3; x04 = x4; y04 = y4;
		setcolor(0);
		line(x01,y01,x02,y02); line(x02,y02,x03,y03); line(x03,y03,x04,y04); line(x04,y04,x01,y01);
	}
}