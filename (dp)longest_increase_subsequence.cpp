#include<stdio.h>
#include<stdlib.h>

void subsequenceslisting(int A[],int n,int dp[],int *printedsubsequence,int size,int max,int tempmax,int i) {
	int j, k, nexttempmax, temp, tempindex;
	for(j=i-1;j>-1;j--) {
		if(dp[j]==tempmax) {
			printedsubsequence[size++] = A[j];
			if(tempmax>1) {
				nexttempmax = dp[j-1];
				k = j - 1;
				while(nexttempmax==tempmax&&k>0) {
					k--;
					nexttempmax = dp[k];
				}
				tempindex = k;
				for(k=tempindex;k>-1;k--) if(dp[k]>nexttempmax&&dp[k]<tempmax) nexttempmax = dp[k];
			}
			if(size==max) {
				int copy[100];
				for(k=0;k<size;k++) copy[k] = printedsubsequence[k];
				for(k=0;k<size/2;k++) {
					temp = copy[k];
					copy[k] = copy[size-1-k];
					copy[size-1-k] = temp;
				}
				for(k=0;k<size;k++) printf("%d ",copy[k]);
				printf("\n");
			}
			else subsequenceslisting(A,n,dp,printedsubsequence,size,max,nexttempmax,j);
			size--;
		}
	}
}

int main() {
	int i, j, n, max, A[100], dp[100], count, greatervalue, *printedsubsequence, temp, size = 0;
	bool greaterchanged;
	printf("Nhap vao so phan tu day: ");
	scanf("%d",&n);
	if(n==1) {
		printf("Day con don dieu tang dai nhat co 1 phan tu.");
		return 0;
	}
	printedsubsequence = (int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++) {
		printf("A[%d] = ",i);
		scanf("%d",&A[i]);
		dp[i] = 1;
	}
	for(i=0;i<n;i++) for(j=0;j<i;j++) if(A[j]<A[i]) if(dp[j]+1>dp[i]) dp[i] = dp[j] + 1;
	max = dp[0];
	for(i=0;i<n;i++) if(dp[i]>max) max = dp[i];
	printf("Day con don dieu tang dai nhat co %d phan tu.\n\nLiet ke cac day con tang dai nhat:\n",max);
	subsequenceslisting(A,n,dp,printedsubsequence,0,max,max,n);
	free(printedsubsequence);
}