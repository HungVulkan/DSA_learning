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
void shellSort(int *pa, int len)
{
    int lap = 0;
    for (int gap = len / 2; gap > 0; gap /= 2){
        for (int i = gap; i < len; i++){
            int x = pa[i];
            int pos = i - gap;
            while (pos >= 0 && pa[pos] > x){
                pa[pos + gap] = pa[pos];
                pos -= gap;
            }
            pa[pos + gap] = x;
        }
        lap++;
        printf("Lan lap %d (gap=%d): ", lap, gap);
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
    shellSort(a, N);
    printf("Mang sau khi sap xep:\n");
    xuatmang(a, N);
    return 0;
}
