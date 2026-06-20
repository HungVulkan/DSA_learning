#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define N 100
void nhapmang(int *pa, int *n) {
  printf("nhap so phan tu cua mang: ");
  scanf("%d", n);
  for (int i = 0; i < *n; i++) {
    printf("nhap a[%d]: ", i);
    scanf("%d", (pa + i));
  }
}
void xuatmang(int *pa, int len) {
  for (int i = 0; i < len; i++)
    printf("%d ", *(pa + i));
}
int lasnt(int n) {
  if (n < 2)
    return 0;
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0)
      return 0;
  }
  return 1;
}
void timsnt(int *pa, int n) {
  printf("cac so nguyen to trong mang: ");
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (lasnt(*(pa + i))) {
      printf("%d ", *(pa + i));
      count++;
    }
  }
  if (count == 0)
    printf(" khong co so nguyen to nao\n");
  else
    printf("\n");
}
int main() {
  int a[N];
  int n = 0;
  nhapmang(a, &n);
  printf("mang vua nhap gom: ");
  xuatmang(a, n);
  printf("\n");
  timsnt(a, n);
  return 0;
}
