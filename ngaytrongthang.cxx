#include<stdio.h>
#include<conio.h>

void main(void)
{
	int a, b, c, d, i;
	printf("Nhap nam: ");
	scanf("%d",&a);
	b = a%100;
	c = a%400;
	d = a%4;
		printf("Nhap thang: ");
		scanf("%d",&i);
		switch(i)
		{
			case 1: printf(""); 
			case 3: printf("");
			case 5: printf("");
			case 7: printf("");
			case 8: printf("");
			case 10: printf("");
			case 12: printf("31"); break;
			case 2: 
			{
				if(b==0) 
				{
					if(c==0) printf("29");
					else printf("28");
				}
				else if(d==0) printf("29");
				else printf("28");
			    break;
			}
			case 4: printf("");
			case 6: printf("");
			case 9: printf("");
			case 11: printf("30"); break;
		}
}
