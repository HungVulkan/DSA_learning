#include <stdio.h>
#include <stdlib.h>
#define N 100

typedef struct {
  char ngay[3];
  char thang[3];
  char nam[5];
} NgaySinh;
typedef struct {
  NgaySinh ngaysinh;
  char mssv[11];
  char hoten[21];
  float dtb;
} SinhVien;
int docfile(char *tenFile, SinhVien *ds_sv) {
  FILE *fi = fopen(tenFile, "rt");
  if (fi == NULL) {
    printf("khong the mo file %s\n", tenFile);
    return 0;
  }
  int count = 0;
  while (count < N) {
    if (fscanf(fi, " %10[^\n] %20[^\n] %2[0-9]/%2[0-9]/%4[0-9] %f",
               ds_sv[count].mssv, ds_sv[count].hoten,
               ds_sv[count].ngaysinh.ngay, ds_sv[count].ngaysinh.thang,
               ds_sv[count].ngaysinh.nam, &ds_sv[count].dtb) != 6)
      break;
    count++;
  }
  fclose(fi);
  return count;
}
void xuatsv(SinhVien sv) {
  printf("MSSV: %-10s - Ho ten: %-20s - Ngay sinh: %s/%s/%s - DTB: %.2f\n",
         sv.mssv, sv.hoten, sv.ngaysinh.ngay, sv.ngaysinh.thang,
         sv.ngaysinh.nam, sv.dtb);
}
void xuatfile(SinhVien *ds_sv, int n) {
  for (int i = 0; i < n; i++)
    xuatsv(ds_sv[i]);
}
int sosanhngaysinh(NgaySinh ns1, NgaySinh ns2) {
  int n1 = atoi(ns1.nam), n2 = atoi(ns2.nam);
  int t1 = atoi(ns1.thang), t2 = atoi(ns2.thang);
  int d1 = atoi(ns1.ngay), d2 = atoi(ns2.ngay);
  if (n1 != n2)
    return (n1 < n2) ? -1 : 1;
  if (t1 != t2)
    return (t1 < t2) ? -1 : 1;
  if (d1 != d2)
    return (d1 < d2) ? -1 : 1;
  return 0;
}
void timsvngaysinhnhohat(SinhVien *ds_sv, int n) {
  if (n == 0)
    return;
  int idx_min = 0;
  for (int i = 1; i < n; i++) {
    if (sosanhngaysinh(ds_sv[i].ngaysinh, ds_sv[idx_min].ngaysinh) < 0)
      idx_min = i;
  }
  printf("sinh vien co ngay sinh nho nhat la:\n");
  xuatsv(ds_sv[idx_min]);
}
void timsvdtb(SinhVien *ds_sv, int n) {
  float diem_yc;
  printf("nhap diem trung binh can tim: ");
  scanf("%f", &diem_yc);
  int found = 0;
  for (int i = 0; i < n; i++) {
    if (ds_sv[i].dtb == diem_yc) {
      xuatsv(ds_sv[i]);
      found++;
    }
  }
  if (found == 0)
    printf("khong tim thay sinh vien nao co DTB = %.2f\n", diem_yc);
}
void sapxeptheomssv(SinhVien *ds_sv, int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      int k = 0;
      while (ds_sv[i].mssv[k] != '\0' && ds_sv[j].mssv[k] != '\0') {
        if (ds_sv[i].mssv[k] != ds_sv[j].mssv[k])
          break;
        k++;
      }
      if (ds_sv[i].mssv[k] > ds_sv[j].mssv[k]) {
        SinhVien temp = ds_sv[i];
        ds_sv[i] = ds_sv[j];
        ds_sv[j] = temp;
      }
    }
  }
}
void timsvmss(SinhVien *ds_sv, int n) {
  char mssv_yc[11];
  printf("nhap MSSV can tim: ");
  scanf("%10s", mssv_yc);
  sapxeptheomssv(ds_sv, n);
  int left = 0, right = n - 1, found_idx = -1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    int k = 0, cmp = 0;
    while (ds_sv[mid].mssv[k] != '\0' && mssv_yc[k] != '\0') {
      if (ds_sv[mid].mssv[k] != mssv_yc[k]) {
        cmp = (ds_sv[mid].mssv[k] > mssv_yc[k]) ? 1 : -1;
        break;
      }
      k++;
    }
    if (cmp == 0) {
      if (ds_sv[mid].mssv[k] == '\0' && mssv_yc[k] == '\0') {
        found_idx = mid;
        break;
      } else {
        cmp = (ds_sv[mid].mssv[k] == '\0') ? -1 : 1;
      }
    }
    if (cmp < 0)
      left = mid + 1;
    else
      right = mid - 1;
  }
  if (found_idx != -1) {
    xuatsv(ds_sv[found_idx]);
  } else {
    printf("khong tim thay sinh vien co MSSV %s\n", mssv_yc);
  }
}
int main() {
  SinhVien ds_sv[N];
  int n = docfile("input.txt", ds_sv);
  if (n == 0) {
    printf("khong co du lieu hoac file bi loi\n");
    return 1;
  }
  xuatfile(ds_sv, n);
  timsvngaysinhnhohat(ds_sv, n);
  timsvdtb(ds_sv, n);
  timsvmss(ds_sv, n);
  return 0;
}
