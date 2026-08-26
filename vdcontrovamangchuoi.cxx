#include<stdio.h>
#include<string.h>

int main(void)
{
	char name[3][30], *cptr[3], *ctemp;
	int i, j, c = 0;
	while(c<3)
	{
		printf("Nhap ten thu %d: ",c+1);
		gets(name[c]);
		cptr[c++] = name[c];
	}
	for(i=0;i<2;i++)
		for(j=i+1;j<3;j++)
		{
			if(strcmp(cptr[i],cptr[j])>0)
			{
				ctemp = cptr[i];
				cptr[i] = cptr[j];
				cptr[j] = ctemp;
			}
		}
	for(i=0;i<3;i++)
	{
		puts(cptr[i]);
	}
}