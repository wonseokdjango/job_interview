#include <cstdio>

int N;
int ARR[1000000 + 1];

void sort(int arr[], int s, int e) {

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
