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
int linearSearch(int *pa, int len, int key)
{
    for (int i = 0; i < len; i++){
        printf("Buoc %d: so sanh a[%d]=%d voi key=%d",
               i+1, i, pa[i], key);
        if (pa[i] == key){
            printf(" → Tim thay!\n");
            return i;
        }
        printf("\n");
    }
    return -1;
}
int main()
{
    int a[N];
    int key, result;
    nhapmang(a, N);
    printf("Mang vua nhap:\n");
    xuatmang(a, N);
    printf("Nhap gia tri can tim: ");
    scanf("%d", &key);
    result = linearSearch(a, N, key);
    if (result != -1)
        printf("Tim thay %d tai chi so a[%d]\n", key, result);
    else
        printf("Khong tim thay %d trong mang\n", key);
    return 0;
}
