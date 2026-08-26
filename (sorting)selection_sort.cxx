#include <stdio.h>

void selectionSort(int a[100],int n)
{
    int i, j, minIndex, temp;
    for(i=0;i<n-1;i++)
    {
        minIndex = i;
        // Tìm phần tử nhỏ nhất trong đoạn chưa sắp xếp
        for(j=i+1;j<n;j++) if(a[j]<a[minIndex]) minIndex = j;
        // Đổi chỗ nếu tìm được phần tử nhỏ hơn
        if(minIndex!=i)
        {
            temp = a[i];
            a[i] = a[minIndex];
            a[minIndex] = temp;
        }
    }
}

int main()
{
    int i, a[100], n;
    printf("Nhap so phan tu: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("a[%d] = ",i);
		scanf("%d",&a[i]);
	}
    selectionSort(a,n);
    printf("Mang sau khi sap xep tang dan: ");
    for(i=0;i<n;i++) printf("%d ",a[i]);
}