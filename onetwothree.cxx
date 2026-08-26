#include<stdio.h>
#include<conio.h>

#define K 'keo'
#define B 'bua'
#define G 'giay'

void main(void)
{
	char c1, c2;
	printf("Turn 1: ");
	scanf("%s",&c1);
	printf("Turn 2: ");
	scanf("%s",&c2);
	switch(c1)
	{
		case K:
		{
			switch(c2)
			{
				case G: printf("1win"); break;
				case B: printf("2win"); break;
			}
		}; break;
		case B:
		{
			switch(c2)
			{
				case K: printf("1win"); break;
				case G: printf("2win"); break;
			}
		}; break;
		case G:
		{
			switch(c2)
			{
				case B: printf("1win"); break;
				case K: printf("2win"); break;
			}
		}; break;
	}
	getch();
}