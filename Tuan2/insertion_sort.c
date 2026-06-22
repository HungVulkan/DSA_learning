#include <stdio.h>
#define N 8
void xuatmang(int *pa, int len)
{
    for (int i = 0; i < len; i++){
        printf("%d ", *(pa + i));
    }
    printf("\n");
}
void nhapmang(int *pa, int len)
{
    for (int i = 0; i < len; i++){
        printf("Nhap a[%d]:", i);
        scanf("%d", (pa + i));
    }
}
void insertionSort(int *pa, int len)
{
    int pos,i;
    int x;
    for (i = 1; i < len; ++i) {
        x = pa[i];
        pos = i-1;
        while (pos >= 0 && pa[pos] > x) {
            pa[pos + 1] = pa[pos];
            pos--;
        }
        pa[pos + 1] = x;
        printf("Lan lap %d: ",i);
        for (int t = 0; t< len; t++)
        printf("%d ",*(pa+t));
        printf ("\n");
    }
}
int main()
{
    int a[N];
    nhapmang(a, N);
    printf("Mang truoc khi sap xep:\n");
    xuatmang(a, N);
    insertionSort(a, N);
    printf("Mang sau khi sap xep:\n");
    xuatmang(a, N);
    //printf("%d", linearsearch(a, N, 4));
    //printf("a[%d]", binarysearch(a,N, 4));	
    return 0;
}
