#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LEN 256

void bubblesort(char **arr, int n) {
  char *temp;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      // so sánh 2 chuỗi, nếu chuỗi trước lớn hơn chuỗi sau thì hoán đổi con trỏ
      if (strcmp(arr[i], arr[j]) > 0) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

int main() {
  FILE *inFile, *outFile;
  char buffer[MAX_LEN];
  char *strings[MAX_LINES]; // mảng con trỏ để lưu các chuỗi
  int count = 0;

  // a. đọc file văn bản
  inFile = fopen("input.txt", "r");
  if (inFile == NULL) {
    printf("khong the mo file input\n");
    return 1;
  }

  // b. lưu các chuỗi vào mảng sử dụng con trỏ
  while (fgets(buffer, MAX_LEN, inFile) != NULL && count < MAX_LINES) {
    // xóa ký tự xuống dòng '\n' ở cuối chuỗi nếu có
    buffer[strcspn(buffer, "\n")] = 0;

    // cấp phát bộ nhớ vừa đủ cho chuỗi hiện tại và copy vào
    strings[count] = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
    strcpy(strings[count], buffer);
    count++;
  }
  fclose(inFile);

  // c. sắp xếp các chuỗi theo thứ tự từ điển
  bubblesort(strings, count);

  // d. ghi các chuỗi đã sắp xếp vào file khác
  outFile = fopen("output.txt", "w");
  if (outFile == NULL) {
    printf("khong the tao file output\n");
    return 1;
  }

  // e. in ra màn hình đồng thời ghi vào file
  printf("cac chuoi sau khi sap xep:\n");
  for (int i = 0; i < count; i++) {
    fprintf(outFile, "%s\n", strings[i]);
    printf("%s\n", strings[i]); // in ra màn hình

    // giải phóng bộ nhớ đã cấp phát
    free(strings[i]);
  }
  fclose(outFile);

  printf("\nda ghi ket qua vao file output thanh cong!\n");
  return 0;
}