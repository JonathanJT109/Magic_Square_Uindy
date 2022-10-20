#include <stdio.h>

#define N 20

int main() {
  int n;
  int square[N][N];
  int sums[2 * N + 2];
  int row;
  int col;
  int isMagic = 1;

  scanf("%d", &n);

  for (row = 0; row < n; row++) {
    for (col = 0; col < n; col++) {
      scanf("%d", &square[row][col]);
    }
  }
}