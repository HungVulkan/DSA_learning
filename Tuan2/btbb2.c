#include <stdio.h>
#include <stdlib.h>
#define N 100
void nhapmang(int *pa, int *n) {
  printf("nhap so phan tu cua mang: ");
  scanf("%d", n);
  for (int i = 0; i < *n; i++) {
    printf("nhap a[%d]:", i);
    scanf("%d", (pa + i));
  }
}
void xuatmang(int *pa, int len) {
  for (int i = 0; i < len; i++) {
    printf("%d ", *(pa + i));
  }
}
void timdaycon(int *pa, int n) {
  if (n == 0) {
    printf("mang rong.\n");
    return;
  }
  int max_len = 1;
  int start_idx = 0;
  int cur_len = 1;
  int cur_start = 0;
  for (int i = 1; i < n; i++) {
    if (pa[i] > pa[i - 1]) {
      cur_len++;
    } else {
      if (cur_len > max_len) {
        max_len = cur_len;
        start_idx = cur_start;
      }
      cur_len = 1;
      cur_start = i;
    }
  }
  if (cur_len > max_len) {
    max_len = cur_len;
    start_idx = cur_start;
  }
  printf("day con tang dai nhat %d: ", max_len);
  for (int i = start_idx; i < start_idx + max_len; i++) {
    printf("%d ", pa[i]);
  }
  printf("\n");
}
int main() {
  int a[N];
  int n = 0;
  nhapmang(a, &n);
  printf("mang vua nhap gom:");
  xuatmang(a, n);
  printf("\n");
  timdaycon(a, n);
  return 0;
}
