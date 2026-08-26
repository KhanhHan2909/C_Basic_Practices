#include<stdio.h>
#include<conio.h>

void main(void)
{
	int n, a, b, c, d, e, f;
	do
	{
		printf("Nhap so tien: ");
		scanf("%d",&n);
	} while(n<=0);
	if(n>=50)
	{
		a = n/50; 
		printf("So tien loai 50 dong la %d\n",a);
		b = n%50;
		if(b>=25)
		{
			printf("So tien loai 25 dong la 1\n");
			c = b - 25;
			if(c>=10)
			{
				d = c/10; e = c%10;
				printf("So tien loai 10 dong la %d\n",d);			
				if(e>=5)
				{
					printf("So tien loai 5 dong la 1\n");
					f = e - 5;
					if(f>0) printf("So tien loai 1 dong la %d\n",f);
				}
				else if(e>0&&e<5) printf("So tien loai 1 dong la %d\n",e);
			}
			else if(c<10&&c>=5)
			{
				printf("So tien loai 5 dong la 1\n");
				d = c - 5;
				if(d>0) printf("So tien loai 1 dong la %d\n",d);
			}
			else if(c>0&&c<5) printf("So tien loai 1 dong la %d\n",c);
		}
		else if(b<25&&b>=10)
		{
			c = b/10;
			printf("So tien loai 10 dong la %d\n",c);
			d = b%10;
			if(d>=5)
			{
				printf("So tien loai 5 dong la 1\n");
				e = d - 5;
				if(e>0) printf("So tien loai 1 dong la %d",e);
			}
			else if(d>0&&d<5) printf("So tien loai 1 dong la %d\n",d);
		}
		else if(b>=5&&b<10)
		{
			printf("So tien loai 5 dong la 1\n");
			c = b - 5;
			if(c>0) printf("So tien loai 1 dong la %d\n",c);
		}
		else if(b>0&&b<5) printf("So tien loai 1 dong la %d\n",b);
	}
	else if(n>=25&&n<50)
	{
		printf("So tien loai 25 dong la 1\n");
		a = n - 25;
		if(a>=10)
		{
			b = a/10;
			printf("So tien loai 10 dong la %d\n",b);
			c = a%10;
			if(c>=5)
			{
				printf("So tien loai 5 dong la 1\n");
				d = c - 5;
				if(d>0) printf("So tien loai 1 dong la %d\n",d);
			}
			else if(c>0&&c<5) printf("So tien loai 1 dong la %d\n",c);
		}
		else if(a>=5&&a<10)
		{
			printf("So tien loai 5 dong la 1\n");
			b = a - 5;
			if(b>0) printf("So tien loai 1 dong la %d\n",b);
		}
		else if(a>0&&a<5) printf("So tien loai 1 dong la %d\n",a);
	}
	else if(n>=10&&n<25)
	{
		a = n/10;
		printf("So tien loai 10 dong la %d\n",a);
		b = n%10;
		if(b>=5)
		{
			printf("So tien loai 5 dong la 1\n");
			c = b - 5;
			if(c>0) printf("So tien loai 1 dong la%d\n",c);
		}
		else if(b>0&&b<5) printf("So tien loai 1 dong la %d\n",b);
	}
	else if(n>=5&&n<10)
	{
		printf("So tien loai 5 dong la 1\n");
		a = n - 5;
		if(a>0) printf("So tien loai 1 dong la %d\n",a);
	}
	else printf("So tien loai 1 dong la %d\n",n);
	getch();
}