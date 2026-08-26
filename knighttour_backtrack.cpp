#include <stdio.h>

#define N 8   // kích thước bàn cờ

int board[N][N];

// 8 hướng đi của quân mã
int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

// kiểm tra nước đi hợp lệ
int isSafe(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1);
}

// hàm đệ quy tìm lời giải
int solveKnight(int x, int y, int step) {
    if (step == N * N + 1)
        return 1;  // đã đi đủ

    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (isSafe(nx, ny)) {
            board[nx][ny] = step;
            if (solveKnight(nx, ny, step + 1))
                return 1;
            board[nx][ny] = -1; // quay lui
        }
    }
    return 0;
}

// in bàn cờ
void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%2d ", board[i][j]);
        printf("\n");
    }
}

int main() {
    // khởi tạo
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = -1;

    // bắt đầu từ ô (0,0)
    board[0][0] = 1;

    if (solveKnight(0, 0, 2))
        printBoard();
    else
        printf("Khong tim duoc loi giai!\n");

    return 0;
}