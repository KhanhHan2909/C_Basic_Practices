#include<stdio.h>
#include<conio.h>

void main(void)
{
	int gio, phut, giay, giayc, a, b, c, d, e, f, g, h;
	printf("Nhap hh:mm:ss: ");
	scanf("%2d %2d %2d", &gio, &phut, &giay);
	if (giay>59||phut>59||gio>99) printf("Nhap khong hop le.\n");
	else
	{
		printf("Nhap so giay cong them:");
		scanf("%d", &giayc);
		a = giay + giayc;
		b = a/60;
		if (a<60) printf("Ket qua: %d:%d:%d", gio, phut, a);
    	else
    	{
    		c = phut + b;
    		if (c<60)
    		{
    			d = a%60;
    			printf("Ket qua: %d:%d:%d", gio, c, d);
    		}
    		else
    		{
    			e = c/60;
    			h = gio + e;
    			f = c%60;
    			g = a%60;
    			printf("Ket qua: %d:%d:%d", h, f, g);
    		}
    	}
    }	
	getch();
}