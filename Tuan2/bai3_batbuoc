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
  printf("\n");
}
void demsoduongchay(int *pa, int n) {
  if (n < 2) {
    printf("so duong chay: 0\n");
    return;
  }
  int runs = 0;
  int current_length = 1;
  for (int i = 1; i < n; i++) {
    if (*(pa + i) > *(pa + i - 1)) {
      current_length++;
    } else {
      if (current_length >= 2) {
        runs++;
      }
      current_length = 1;
    }
  }
  if (current_length >= 2) {
    runs++;
  }
  printf("so duong chay: %d\n", runs);
}
int main() {
  int a[N];
  int n = 0;
  nhapmang(a, &n);
  printf("mang vua nhap: ");
  xuatmang(a, n);
  demsoduongchay(a, n);
  return 0;
}
