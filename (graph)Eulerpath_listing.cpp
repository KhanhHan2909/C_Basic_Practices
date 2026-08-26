#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <dos.h>

#define MAX 50
#define TRUE 1
#define FALSE 0

int m, b[MAX], u, i, OK;

void Init(int A[][MAX], int n){
    int i, j, s, d;
	
    printf("Nhap ma tran ke cua do thi:\n");
    for(i = 1; i <= n; i++)
    	for(j = i + 1; j <= n; j++)
    	{
    		printf("A[%d][%d] = ",i,j);
    		scanf("%d",&A[i][j]);
		}
	for(i = 1; i <= n; i++) A[i][i] = 0;
	for(i = 1; i <= n; i++)
		for(j = 2; j <= i; j++)
			A[i][j] = A[j][i];
    printf("\n Ma tran ke vua nhap:");

    u = 1; d = 0; m = 0;

    for(i = 1; i <= n; i++){
        printf("\n"); s = 0;
        for(j = 1; j <= n; j++){
            printf("%3d", A[i][j]);
            s += A[i][j];
        }
        if (s % 2){ d++; u = i; }
        m = m + s;
    }

    m = m / 2;
    if (d != 2) OK = FALSE;
    else OK = TRUE;
}

void Result(void){
    int i;
    printf("\n Co duong di Euler:");
    for(i = 0; i <= m; i++)
        printf("%3d", b[i]);
}

void DDEULER(int *b, int A[][MAX], int n, int i){
    int j, k;

    for(j = 1; j <= n; j++){
        if (A[b[i-1]][j] == 1){
            A[b[i-1]][j] = 0; 
            A[j][b[i-1]] = 0;
            b[i] = j;
            if (i == m) Result();
            else DDEULER(b, A, n, i+1);
            A[b[i-1]][j] = 1; 
            A[j][b[i-1]] = 1;
        }
    }
}

int main(void){
    int A[MAX][MAX], n;

    printf("\n So dinh do thi: ");
    scanf("%d",&n);
    Init(A, n);
    b[0] = u; 
    i = 1;

    if(OK) DDEULER(b, A, n, i);
    else printf("\n Khong co duong di Euler");

    getch();
}