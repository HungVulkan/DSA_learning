#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 50000
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selectionSort(int *pa, int n) {
  int min;
  for (int i = 0; i < n - 1; i++) {
    min = i;
    for (int j = i + 1; j < n; j++) {
      if (*(pa + j) < *(pa + min))
        min = j;
    }
    swap((pa + i), (pa + min));
  }
}

void insertionSort(int *pa, int n) {
  int pos, i, x;
  for (i = 1; i < n; ++i) {
    x = pa[i];
    pos = i - 1;
    while (pos >= 0 && pa[pos] > x) {
      pa[pos + 1] = pa[pos];
      pos--;
    }
    pa[pos + 1] = x;
  }
}

void bubbleSort(int *pa, int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = n - 1; j > i; j--) {
      if (*(pa + j) < *(pa + j - 1)) {
        swap((pa + j), (pa + j - 1));
      }
    }
  }
}

void interchangeSort(int *pa, int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (*(pa + j) < *(pa + i)) {
        swap((pa + i), (pa + j));
      }
    }
  }
}

void quickSort(int *pa, int left, int right) {
  if (left >= right)
    return;
  int pivot = pa[(left + right) / 2];
  int i = left, j = right;
  while (i <= j) {
    while (pa[i] < pivot)
      i++;
    while (pa[j] > pivot)
      j--;
    if (i <= j) {
      swap((pa + i), (pa + j));
      i++;
      j--;
    }
  }
  quickSort(pa, left, j);
  quickSort(pa, i, right);
}

void quickSortWrapper(int *pa, int n) { quickSort(pa, 0, n - 1); }

void heapify(int *pa, int n, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && pa[left] > pa[largest])
    largest = left;

  if (right < n && pa[right] > pa[largest])
    largest = right;

  if (largest != i) {
    swap((pa + i), (pa + largest));
    heapify(pa, n, largest);
  }
}

void heapSort(int *pa, int n) {
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(pa, n, i);
  for (int i = n - 1; i > 0; i--) {
    swap((pa + 0), (pa + i));
    heapify(pa, i, 0);
  }
}

void shellSort(int *pa, int n) {
  for (int gap = n / 2; gap > 0; gap /= 2) {
    for (int i = gap; i < n; i += 1) {
      int temp = pa[i];
      int j;
      for (j = i; j >= gap && pa[j - gap] > temp; j -= gap) {
        pa[j] = pa[j - gap];
      }
      pa[j] = temp;
    }
  }
}

void generateRandomArray(int *pa, int n) {
  for (int i = 0; i < n; i++) {
    pa[i] = rand() % 100000;
  }
}

void copyArray(int *src, int *dest, int n) {
  for (int i = 0; i < n; i++) {
    dest[i] = src[i];
  }
}

void measureTime(void (*sortFunc)(int *, int), int *pa, int n,
                 const char *name) {
  clock_t start, end;
  double cpu_time_used;
  start = clock();
  sortFunc(pa, n);
  end = clock();
  cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("%-20s: %f giay\n", name, cpu_time_used);
}

int main() {
  int *originalArray = (int *)malloc(N * sizeof(int));
  int *testArray = (int *)malloc(N * sizeof(int));

  if (originalArray == NULL || testArray == NULL) {
    printf("Khong the cap phat bo nho.\n");
    return 1;
  }

  srand(time(NULL));
  printf("Dang khoi tao mang gom %d phan tu ngau nhien...\n", N);
  generateRandomArray(originalArray, N);
  printf("Khoi tao xong. Bat dau so sanh:\n");
  printf("--------------------------------------\n");

  copyArray(originalArray, testArray, N);
  measureTime(selectionSort, testArray, N, "Selection Sort");

  copyArray(originalArray, testArray, N);
  measureTime(insertionSort, testArray, N, "Insertion Sort");

  copyArray(originalArray, testArray, N);
  measureTime(bubbleSort, testArray, N, "Bubble Sort");

  copyArray(originalArray, testArray, N);
  measureTime(interchangeSort, testArray, N, "Interchange Sort");

  copyArray(originalArray, testArray, N);
  measureTime(quickSortWrapper, testArray, N, "Quick Sort");

  copyArray(originalArray, testArray, N);
  measureTime(heapSort, testArray, N, "Heap Sort");

  copyArray(originalArray, testArray, N);
  measureTime(shellSort, testArray, N, "Shell Sort");
  free(originalArray);
  free(testArray);
  return 0;
}
