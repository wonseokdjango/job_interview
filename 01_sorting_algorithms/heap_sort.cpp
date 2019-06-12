#include <cstdio>

int N;
int ARR[1000000 + 1];

void heap_sort(int arr[], int size);
void heapify(int arr[], int size, int cur);
void swap(int& a, int& b);
int get_left(int cur);
int get_right(int cur);
int get_parent(int cur);


void sort(int arr[], int s, int e) {
  heap_sort(arr, e - s + 1);
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

/**************
        0
    1       2
  3   4   5   6   
***************/
void heap_sort(int arr[], int size) {

  for (int cur = size - 1; cur >= 0; --cur) {
    if (get_left(cur) < size)
      heapify(arr, size, cur);
  }

  for (int cur = size - 1; cur > 0; --cur) {
    swap(arr[cur], arr[0]);
    heapify(arr, cur, 0);
  }
}

void heapify(int arr[], int size, int cur) {

  while (1) {
    int l = get_left(cur);
    int r = get_right(cur);

    int l_val = (l < size) ? arr[l] : 1000000 + 1;
    int r_val = (r < size) ? arr[r] : 1000000 + 1;

    if (arr[cur] <= l_val && arr[cur] <= r_val)
      break;
    else if (l_val < r_val) {
      swap(arr[cur], arr[l]);
      cur = l;
    }
    else {
      swap(arr[cur], arr[r]);
      cur = r;
    }
  }
}

void swap(int& a, int& b) {
  int tmp = a;
  a = b;
  b = tmp;
}

int get_left(int cur) {
  
  return 2 * cur + 1;
}

int get_right(int cur) {
  
  return 2 * cur + 2;
}

int get_parent(int cur) {

  return (cur - 1) / 2; 
}
