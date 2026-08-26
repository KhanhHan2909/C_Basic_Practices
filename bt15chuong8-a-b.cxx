#include<stdio.h>
#include<string.h>

#define NUM_ROOM 10


int main(void)
{
	int r;
	char s[NUM_ROOM][10] = {"Empty","Empty","Occupied","Occupied","Occupied","Empty","Occupied","Empty","Empty","Empty"};
	printf("Nhap so phong: ");
	scanf("%d",&r);
	printf("Phong ban tim dang trong trang thai: %s",s[r+1]);
}