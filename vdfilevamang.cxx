#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main()
{
	FILE *f;
	int i, a[5], b[5];
	for(i=0;i<5;i++)
	{
		printf("Nhap vao 1 so: ");
		scanf("%d",&a[i]);
	}
	if((f=fopen("array.dat","wb"))==NULL)
	{
		printf("Khong the mo file!");
		exit(0);
	}
	fwrite(a,sizeof(a),1,f);
	fclose(f);
	f = fopen("array.dat","rb");
	fread(b,sizeof(b),1,f);
	for(i=0;i<5;i++)
		printf("%d ",b[i]);
	fclose(f);
}