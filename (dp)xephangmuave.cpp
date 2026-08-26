#include<stdio.h>

int main() {
	int i, j, n, t[101], r[100], dp[101][101];
	do {
		printf("Nhap so nguoi mua ve (> 1 nguoi): ");
		scanf("%d",&n);
	} while(n<2);
	printf("Nhap thoi gian mua ve rieng cua moi nguoi:\n");
	for(i=1;i<=n;i++) {
		printf("t[%d] = ",i);
		scanf("%d",&t[i]);
		dp[i][1] = 1;
	}
	printf("Nhap thoi gian mua ve chung (+ ve nguoi dung sau) cua moi nguoi (> t tuong ung):\n");
	for(i=1;i<n;i++) {
		do {
			printf("r[%d] = ",i);
			scanf("%d",&r[i]);
		} while(r[i]<=t[i]);
	}
	printf("\nNhung nguoi can roi khoi hang de tong thoi gian mua ve nho nhat la:\n");
	if(n==2) {
		if(r[1]<t[1]+t[2]) printf("2");
		else printf("Khong co ai!");
		return 0;
	}
	for(i=2;i<=n;i++) {
		for(j=2;j<=i-1;j++) {
			if(!dp[i-1][j]) dp[i][j] = 0;
			else dp[i][j] = 1;
		}
		if(!dp[i][i-1]) {
			if(r[i-2]+t[i]<=t[i-2]+r[i-1]) dp[i][i] = 1;
			else {
				dp[i][i-1] = 1;
				dp[i][i] = 0;
			}
		}
		else {
			if(r[i-1]<t[i-1]+t[i]) dp[i][i] = 0;
			else dp[i][i] = 1;
		}
	}
	bool notpendingall = false;
	for(i=2;i<=n;i++) if(!dp[n][i]) {
		notpendingall = true;
		break;
	}
	if(!notpendingall) printf("Khong co ai!");
	else for(i=2;i<=n;i++) if(!dp[n][i]) printf("%d ",i);
}