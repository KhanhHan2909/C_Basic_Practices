#include<stdio.h>
#include<string.h>

int main(void)
{
	int n, m, e, f;
	char dg[13][10] = {"\0","mot","hai","ba","bon","nam","sau","bay","tam","chin","muoi","tram","le"};
	do
	{
		printf("Nhap so co toi da 3 chu so: ");
		scanf("%d",&n);
	} while(n>999);
	if(n<=10) printf("%s",dg[n]);
	else if(n>10&&n<20)
	{
		m = n%10;
		printf("%s ",dg[10]); printf("%s",dg[m]);
	}
	else if(n>=20&&n<100)
	{
		e = n/10; m = n%10;
		printf("%s %s %s",dg[e],dg[10],dg[m]);
	}
	else if(n==100||n==200||n==300||n==400||n==500||n==600||n==700||n==800||n==900)
	{
		m = n/100;
		 printf("%s %s",dg[m],dg[11]);
	}
	else if((n<110&&n>100)||(n<210&&n>200)||(n<310&&n>300)||(n<410&&n>400)||(n<510&&n>500)||(n<610&&n>600)||(n<710&&n>700)||(n<810&&n>800)||(n<910&&n>900))
	{
		e = n/100; m = n%100;
		printf("%s %s %s %s",dg[e],dg[11],dg[12],dg[m]);
	}
	else if((n<120&&n>109)||(n<220&&n>209)||(n<320&&n>309)||(n<420&&n>409)||(n<520&&n>509)||(n<620&&n>609)||(n<720&&n>709)||(n<820&&n>809)||(n<920&&n>909))
	{
		e = n/100; m = (n%100)%10;
		printf("%s %s %s %s",dg[e],dg[11],dg[10],dg[m]);
	}
	else
	{
		e = n/100; f = (n/10)%10; m = (n%100)%10;		printf("%s %s %s %s %s",dg[e],dg[11],dg[f],dg[10],dg[m]);
	}
}