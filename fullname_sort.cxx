#include<stdio.h>
#include<conio.h>
#include<string.h>

int main(void)
{
	int i, j, k, l, m, n;
	char fname[100][50], name[50], fname0[100][50], ftname0[100][50], ftname[100][50], smname[100][50];
	do
	{
		printf("Co bao nhieu nguoi? ");
		scanf("%d",&n);
	} while(n<1);
	i = 0;
	while(i<n)
	{
		fflush(stdin);
		printf("Ho ten thu %d: ",i+1);
		gets(fname[i]);
		l = strlen(fname[i]);
		for(k=0;k<l;k++) fname0[i][l-k-1] = fname[i][k];
		fname0[i][l] = '\0';
		for(k=0;k<l;k++)
		{
			if(fname0[i][k]==32) break;
			else ftname0[i][k] = fname0[i][k];
		}
		ftname0[i][k] = '\0';
		m = strlen(ftname0[i]);
		for(k=0;k<m;k++) ftname[i][m-k-1] = ftname0[i][k];
		ftname[i][m] = '\0';
		for(k=0;k<l-m;k++) smname[i][k] = fname[i][k];
		smname[i][l-m] = '\0';
		i++;
	}
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
		{
			if(strcmp(ftname[i],ftname[j])==0)
				if(strcmp(smname[i],smname[j])>0)
				{
					strcpy(name,fname[i]);
					strcpy(fname[i],fname[j]);
					strcpy(fname[j],name);
					strcpy(name,fname0[i]);
					strcpy(fname0[i],fname0[j]);
					strcpy(fname0[j],name);
					strcpy(name,ftname0[i]);
					strcpy(ftname0[i],ftname0[j]);
					strcpy(ftname0[j],name);
					strcpy(name,ftname[i]);
					strcpy(ftname[i],ftname[j]);
					strcpy(ftname[j],name);
					strcpy(name,smname[i]);
					strcpy(smname[i],smname[j]);
					strcpy(smname[j],name);
				}
			if(strcmp(ftname[i],ftname[j])>0)
			{
				strcpy(name,fname[i]);
				strcpy(fname[i],fname[j]);
				strcpy(fname[j],name);
				strcpy(name,fname0[i]);
				strcpy(fname0[i],fname0[j]);
				strcpy(fname0[j],name);
				strcpy(name,ftname0[i]);
				strcpy(ftname0[i],ftname0[j]);
				strcpy(ftname0[j],name);
				strcpy(name,ftname[i]);
				strcpy(ftname[i],ftname[j]);
				strcpy(ftname[j],name);
				strcpy(name,smname[i]);
				strcpy(smname[i],smname[j]);
				strcpy(smname[j],name);
			}
		}
	printf("\n----------------------------------------------------------\n");
	for(i=0;i<n;i++) 
		printf("%d. %s\n",i+1,fname[i]);
	printf("----------------------------------------------------------\n");
}