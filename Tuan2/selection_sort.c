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
void selectionsort(int *pa, int n)
{
    int min;
    for ( int i = 0; i < n - 1; i++)
    {
        min = i;
        for ( int j = i+1; j < n ; j++)
        {
            if (*(pa+j) < *(pa+min))
            min = j;
        }
        int temp = *(pa+i);
        *(pa+i) = *(pa+min);
        *(pa+min) = temp;
        printf("Lan lap %d: ",i+1);
        for (int t = 0; t< n; t++)
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
    selectionsort(a, N);
    printf("Mang sau khi sap xep:\n");
    xuatmang(a, N);
    //printf("%d", linearsearch(a, N, 4));
    //printf("a[%d]", binarysearch(a,N, 4));	
    return 0;
}
