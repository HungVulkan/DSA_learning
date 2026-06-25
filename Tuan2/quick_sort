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
static int lap = 0;
int partition(int *pa, int len, int low, int high)
{
    int pivot = pa[high];
    int i = low - 1;
    int tmp;
    for (int j = low; j < high; j++){
        if (pa[j] <= pivot){
            i++;
            tmp = pa[i]; pa[i] = pa[j]; pa[j] = tmp;
        }
    }
    tmp = pa[i+1]; pa[i+1] = pa[high]; pa[high] = tmp;
    return i + 1;
}
void quickSort(int *pa, int len, int low, int high)
{
    if (low < high){
        int pi = partition(pa, len, low, high);
        lap++;
        printf("Lan lap %d (pivot=pa[%d]=%d): ", lap, pi, pa[pi]);
        for (int t = 0; t < len; t++)
            printf("%d ", *(pa + t));
        printf("\n");

        quickSort(pa, len, low,  pi - 1);
        quickSort(pa, len, pi + 1, high);
    }
}
int main()
{
    int a[N];
    nhapmang(a, N);
    printf("Mang truoc khi sap xep:\n");
    xuatmang(a, N);
    lap = 0;
    quickSort(a, N, 0, N - 1);
    printf("Mang sau khi sap xep:\n");
    xuatmang(a, N);
    return 0;
}
