#include<stdio.h>
#include<string.h>

int main(void)
{
	int i, j, k, l, m, n;
	char fname[100][50], fname0[100][50], fname00[100][50], *np[100], *temp, *ftname[100], *smname[100];
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
		strcpy(fname0[i],fname[i]);
		strcpy(fname00[i],fname[i]);
		np[i] = fname[i];
		ftname[i] = fname0[i];
		smname[i] = fname00[i];
		l = strlen(np[i]);
		for(j=l-1;j>=0;j--) if(*(np[i]+j)==32) break;
		for(k=0;k<l-1-j;k++) *(ftname[i]+k) = *(np[i]+j+1+k);
		*(ftname[i]+k) = '\0';
		*(smname[i]+j) = '\0';
		i++;
	}
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
		{
			if(strcmp(ftname[i],ftname[j])==0)
				if(strcmp(smname[i],smname[j])>0)
				{
					temp = np[i];
					np[i] = np[j];
					np[j] = temp;
					temp = ftname[i];
					ftname[i] = ftname[j];
					ftname[j] = temp;
					temp = smname[i];
					smname[i] = smname[j];
					smname[j] = temp;
				}
			if(strcmp(ftname[i],ftname[j])>0)
			{
				temp = np[i];
				np[i] = np[j];
				np[j] = temp;
				temp = ftname[i];
				ftname[i] = ftname[j];
				ftname[j] = temp;
				temp = smname[i];
				smname[i] = smname[j];
				smname[j] = temp;
			}
		}
	printf("\n----------------------------------------------------------\n");
	for(i=0;i<n;i++) 
	{
		printf("%d. ",i+1);
		puts(np[i]);
	}
	printf("----------------------------------------------------------\n");
}