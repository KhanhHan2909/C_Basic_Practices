#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	FILE *f1, *f2, *f3;
	int i, j, k, x, dem, n;
	char s1[50][100], s2[50][100], s3[50][100];
	f1 = fopen("Sinhvien.txt","w");
	f2 = fopen("Sinhvien_out.txt","w");
	f3 = fopen("Sinhvien_email.txt","w");
	printf("Co bao nhieu sinh vien? ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		do
		{
			fflush(stdin);
			dem = 0;
			printf("Sinh vien %d: ",i);
			gets(s1[i-1]);
			for(j=0;j<strlen(s1[i-1]);j++)
				if((s1[i-1][j]<65||s1[i-1][j]>90&&s1[i-1][j]<97||s1[i-1][j]>122)&&s1[i-1][j]!=32) dem++;
		} while(dem>0);
		fprintf(f1,"%s\n",s1[i-1]);
		strcpy(s2[i-1],s1[i-1]);
		while(s2[i-1][0]==32)
		{
			for(j=0;j<strlen(s2[i-1]);j++) s2[i-1][j] = s2[i-1][j+1];
		//	s2[i-1][j+1] = '\0';
		}
		while(s2[i-1][strlen(s2[i-1])-1]==32) s2[i-1][strlen(s2[i-1])-1] = '\0';
		for(j=1;j<strlen(s2[i-1])-1;j++)
			if(s2[i-1][j]==32)
				while(s2[i-1][j]==32&&s2[i-1][j+1]==32)
				{
					for(k=j+1;k<strlen(s2[i-1]);k++) s2[i-1][k] = s2[i-1][k+1];
				//	s2[i-1][]
				}
		if(s2[i-1][0]>96&&s2[i-1][0]<123) s2[i-1][0] -= 32;
		for(j=1;j<strlen(s2[i-1]);j++)
		{
			if(s2[i-1][j]==32&&(s2[i-1][j+1]>96&&s2[i-1][j+1]<123)) s2[i-1][j+1] -= 32;
			if(s2[i-1][j-1]!=32&&s2[i-1][j]>64&&s2[i-1][j]<91) s2[i-1][j] += 32;
		}
		fprintf(f2,"%s\n",s2[i-1]);
		for(j=strlen(s2[i-1])-1;j>=0;j--)
			if(s2[i-1][j]==32) break;
			x = strlen(s2[i-1])-1-j;
		for(k=0;k<x;k++) s3[i-1][k] = s2[i-1][j+1+k];
		s3[i-1][x] = s2[i-1][0];
		for(k=1;k<j;k++)
			if(s2[i-1][k]==32)
			{
				s3[i-1][x+1] = s2[i-1][k+1];
				s3[i-1][x+1] += 32;
				x++;
			}
		s3[i-1][0] += 32;
		s3[i-1][x+1] = '\0';
		fprintf(f3,"%s@28tech.com.vn\n",s3[i-1]);
	}
	fclose(f1);
	fclose(f2);
	fclose(f3);
}