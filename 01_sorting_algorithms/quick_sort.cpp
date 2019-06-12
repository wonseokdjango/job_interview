#include <cstdio>

int N;
int ARR[1000000 + 1];

void quick_sort(int arr[], int s, int e);
int partition(int arr[], int s, int e);
void swap(int& a, int& b);

void sort(int arr[], int s, int e) {
  quick_sort(arr, s, e);
}

int main(void) {

  scanf(" %d", &N);
  for (int it = 0; it < N; ++it)
    scanf(" %d", &ARR[it]);

  sort(ARR, 0, N - 1);

  for (int it = 0; it < N; ++it)
    printf("%d\n", ARR[it]);

  return 0;
}

void quick_sort(int arr[], int s, int e) {

  if (s < e) {
    int pivot_pos = partition(arr, s, e);
    quick_sort(arr, s, pivot_pos - 1);
    quick_sort(arr, pivot_pos + 1, e);
  }
}

int partition(int arr[], int s, int e) {

  // for preventing worst case
  swap(arr[(s + e) / 2], arr[e]);

  int pre = s - 1;
  int pivot = arr[e];

  for (int cur = s; cur < e; ++cur) {
    if (arr[cur] >= pivot)
      swap(arr[cur], arr[++pre]);
  }

  swap(arr[++pre], arr[e]);

  return pre;
}

void swap(int& a, int& b) {
  int tmp = a;
  a = b;
  b = tmp;
}
