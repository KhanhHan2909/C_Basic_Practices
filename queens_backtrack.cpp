#include<stdio.h>
#include<stdlib.h>

bool checkvalidpos(int x,int i,int y,int j)
{
	if(x==y) return false;
	if(x==y+i-j) return false;
	if(x==y-i+j) return false;
	return true;
}

void nextqueen(int *a,int n,int i)
{
	int pos, j, count;
	bool approved;
	for(pos=1;pos<=n;pos++)
	{
		count = 0;
		approved = false;
		for(j=0;j<i;j++) if(checkvalidpos(pos,i,a[j],j)) count++;
		if(count==i)
		{
			a[i] = pos;
			approved = true;
		}
		if(approved)
		{
			if(i==n-1)
			{
				for(j=0;j<n;j++) printf("(%d;%d) ",j+1,a[j]);
				printf("\n");
				break;
			}
			else nextqueen(a,n,i+1); 
		}
	}
}

int main()
{
	int i, j, n, *a;
	printf("Nhap kich thuoc ban co (nxn ; n>3): ");
	scanf("%d",&n);
	a = (int*)malloc(n*sizeof(int));
	printf("Cac cach xep %d quan hau vao ban co de chung khong an duoc nhau la:\n",n);
	nextqueen(a,n,0);
	free(a);
}