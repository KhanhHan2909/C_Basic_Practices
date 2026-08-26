#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *f;
	int n, i;
	printf("Nhap mot so: "); scanf("%d",&n);
	if((f = fopen("int_data.dat","wb"))==NULL)
	{
		printf("Khong the mo file!");
		exit(0);
	}
	else
		for(i=0;i<n;i++)
			fwrite(&i,sizeof(int),1,f);
			fclose(f);
	f = fopen("int_data.dat","rb");
	while(fread(&i,sizeof(int),1,f)==1)
		printf("%d ",i);
	fclose(f);
}