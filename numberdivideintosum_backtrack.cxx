#include <stdio.h>

int a[100]; // Mảng lưu các số hạng của một cách chia
int n;      // Số nguyên dương cần phân chia

// Hàm in ra một cách chia đã tìm thấy
void print_result(int k)
{
    for (int i=1;i<k;i++)
    {
        printf("%d + ",a[i]);
    }
    printf("%d\n",a[k]);
}

// Hàm quay lui để tìm các cách chia
// target: Tổng còn lại cần phải chia
// index: Vị trí của số hạng hiện tại trong mảng a
void backtrack(int target, int index)
{
    // Điều kiện ràng buộc: Số hạng sau không được lớn hơn số hạng trước
    int start = (index==1) ? n-1 : a[index-1];
    for (int i=start;i>=1;i--)
    {
        if (target-i>=0)
        {
            a[index] = i; // Chọn số i làm số hạng thứ index
            if (target-i==0)
            {
                print_result(index); // Nếu tổng đã đủ, in kết quả
                break;
            }
            else backtrack(target-i,index+1); // Đệ quy tìm số tiếp theo
        }
    }
}

int main()
{
    printf("Nhap so nguyen duong n: ");
    scanf("%d",&n);
    printf("Cac cach chia %d thanh tong cac so hang nho hon no la:\n",n);
    backtrack(n,1);
}