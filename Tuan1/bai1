#include <stdio.h>
#include <stdlib.h>
#define N 100
void xuatmang(int *pa, int len) {
  for (int i = 0; i < len; i++)
    printf("%d ", *(pa + i));
  printf("\n");
}
void bubblesort(int *pa, int n) {
  int temp;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (*(pa + i) > *(pa + j)) {
        temp = *(pa + i);
        *(pa + i) = *(pa + j);
        *(pa + j) = temp;
      }
      xuatmang(pa, n);
    }
  }
}
int docfile(char *tenFile, int *pa) {
  FILE *fi = fopen(tenFile, "rt");
  int count = 0, temp;
  while (!feof(fi) && count < N) {
    if (fscanf(fi, "%d", &temp) == 1) {
      *(pa + count) = temp;
      count++;
    }
  }
  fclose(fi);
  return count;
}
void ghifile(char *tenFile, int *pa, int n) {
  FILE *fo = fopen(tenFile, "wt");
  for (int i = 0; i < n; i++)
    fprintf(fo, "%d ", *(pa + i));
  fclose(fo);
}
int main() {
  int a[N];
  int n = docfile("input.txt", a);
  printf("mang truoc khi sap xep:");
  xuatmang(a, n);
  bubblesort(a, n);
  printf("mang sau khi sap xep:");
  xuatmang(a, n);
  ghifile("output.txt", a, n);
  return 0;
}
