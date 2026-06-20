#include <stdio.h>
#include <stdlib.h>
#define N 8
void xuatmang(int *pa, int len) {
  for (int i = 0; i < len; i++)
    printf("%d ", *(pa + i));
  printf("\n");
}

void nhapmang(int *pa, int len) {
  for (int i = 0; i < len; i++) {
    printf("nhap a[%d]: ", i);
    scanf("%d", (pa + i));
  }
}

int tongmang(int *pa, int n) {
  if (n == 0)
    return 0;
  return *(pa + n - 1) + tongmang(pa, n - 1);
  
}

int phanhoach(int *pa, int trai, int phai) {
  int pivot = *(pa + phai);
  int i = trai - 1, temp;

  for (int j = trai; j < phai; j++) {
    if (*(pa + j) <= pivot) {
      i++;
      temp = *(pa + i);
      *(pa + i) = *(pa + j);
      *(pa + j) = temp;
    }
  }

  temp = *(pa + i + 1);
  *(pa + i + 1) = *(pa + phai);
  *(pa + phai) = temp;

  return i + 1;
}

void quicksort(int *pa, int trai, int phai) {
  if (trai >= phai)
    return;
  printf("\ndang xu ly khoang tu index %d den %d \n", trai, phai);
  int vitripivot = phanhoach(pa, trai, phai);
  printf("pivot duoc chon la %d dat tai index %d\n", *(pa + vitripivot),
         vitripivot);
  xuatmang(pa, N);
  quicksort(pa, trai, vitripivot - 1);
  quicksort(pa, vitripivot + 1, phai);
}

int main() {
  int a[N];
  nhapmang(a, N);
  printf("mang truoc khi sap xep: ");
  xuatmang(a, N);
  printf("tong cac phan tu: %d\n", tongmang(a, N));
  quicksort(a, 0, N - 1);
  printf("mang sau khi sap xep: ");
  xuatmang(a, N);

  return 0;
}
