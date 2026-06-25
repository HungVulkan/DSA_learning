#include <stdio.h>
#define N 8
void xuatmang(int *pa, int len)
{
    for (int i = 0; i < len; i++)
        printf("%d ", *(pa + i));
    printf("\n");
}
void nhapmang(int *pa, int len)
{
    for (int i = 0; i < len; i++){
        printf("Nhap a[%d]:", i);
        scanf("%d", (pa + i));
    }
}
void heapify(int *pa, int n, int i)
{
    int largest = i;
    int left  = 2 * i + 1;
    int right = 2 * i + 2;
    int tmp;

    if (left  < n && pa[left]  > pa[largest]) largest = left;
    if (right < n && pa[right] > pa[largest]) largest = right;

    if (largest != i){
        tmp = pa[i]; pa[i] = pa[largest]; pa[largest] = tmp;
        heapify(pa, n, largest);
    }
}
void heapSort(int *pa, int len)
{
    int tmp;
    for (int i = len / 2 - 1; i >= 0; i--)
        heapify(pa, len, i);
    for (int i = len - 1; i > 0; i--){
        tmp = pa[0]; pa[0] = pa[i]; pa[i] = tmp;
        heapify(pa, i, 0);
        printf("Lan lap %d: ", len - i);
        for (int t = 0; t < len; t++)
            printf("%d ", *(pa + t));
        printf("\n");
    }
}

int main()
{
    int a[N];
    nhapmang(a, N);
    printf("Mang truoc khi sap xep:\n");
    xuatmang(a, N);
    heapSort(a, N);
    printf("Mang sau khi sap xep:\n");
    xuatmang(a, N);
    return 0;
}
