#include <stdio.h>
#include <limits.h>

#define MAX 100

int n; // số đỉnh
int a[MAX][MAX];

// Hàm tìm đỉnh chưa xét có dist nhỏ nhất
int minDistance(int dist[], int visited[]) {
    int min = INT_MAX, min_index = -1;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

// Dijkstra
void dijkstra(int start, int end) {
    int dist[MAX];
    int visited[MAX];

    // Khởi tạo
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;  // ∞
        visited[i] = 0;
    }

    dist[start] = 0;

    // Lặp n-1 lần
    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = 1;

        // Cập nhật các đỉnh kề
        for (int v = 0; v < n; v++) {
            if (!visited[v] &&
                a[u][v] != 0 &&              // có cạnh
                dist[u] != INT_MAX &&
                dist[v] > dist[u] + a[u][v]) {

                dist[v] = dist[u] + a[u][v];
            }
        }
    }

    // In kết quả
    printf("Khoang cach tu %d den %d la: %d", start, end, dist[end]);
}

int main() {
	int i, j, start, end;
	
	do
	{
		printf("Nhap so dinh do thi: ");
		scanf("%d", &n);
	} while(n<1);
	
	printf("Nhap ma tran ke cua do thi:\n");
	for(i=0; i < n; i++)
		for(j = i; j < n; j++)
		{
			do
			{
				printf("a[%d][%d] = ", i, j);
				scanf("%d", &a[i][j]);
			} while(a[i][j] < 0);
		}
	for(i = 0; i < n; i++)
		for(j = 0; j < i; j++)
			a[i][j] = a[j][i];
			
	printf("\nMa tran ke vua nhap:\n");
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
			printf("%3d ", a[i][j]);
		printf("\n");
	}
	
	do {
		printf("Nhap dinh di va dinh den: ");
		scanf("%d %d", &start, &end);
	} while(start<0 || start>=n || end<0 || end>=n);
	
	dijkstra(start,end);
}