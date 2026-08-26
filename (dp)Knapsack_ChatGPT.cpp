#include<stdio.h>

#include <stdio.h>

int max(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}

int main()
{
    int n, W;
    
    printf("Nhap so do vat: ");
    scanf("%d", &n);

    printf("Nhap trong luong toi da cua tui: ");
    scanf("%d", &W);

    int w[n+1], v[n+1];

    printf("Nhap trong luong cac do vat:\n");
    for(int i = 1; i <= n; i++)
        scanf("%d", &w[i]);

    printf("Nhap gia tri cac do vat:\n");
    for(int i = 1; i <= n; i++)
        scanf("%d", &v[i]);

    int dp[n+1][W+1];

    // Khởi tạo
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= W; j++)
            dp[i][j] = 0;

    // Quy hoạch động
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= W; j++)
        {
            if(w[i] <= j)
                dp[i][j] = max(dp[i-1][j], v[i] + dp[i-1][j - w[i]]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    printf("Gia tri lon nhat co the dat duoc: %d\n\n", dp[n][W]);
    
    /*for(int i=0;i<=n;i++)
    {
    	for(int j=0;j<W;j++) printf("%4d ",dp[i][j]);
    	printf("\n");
	}*/
    
    // Truy vết tìm đồ vật được chọn
    int j = W;

    printf("\nCac do vat duoc chon: ");

    for(int i = n; i > 0; i--)
    {
        if(dp[i][j] != dp[i-1][j])
        {
            printf("%d ", i);
            j = j - w[i];
        }
    }

    return 0;
}