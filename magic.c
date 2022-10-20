#include <stdio.h>

#define N 20

void print(int list[N][N], int sums[], int n, int a){
   int i, j;
  for(i = 0; i < n; i++) printf(" %d ", sums[i]);
  printf("| %d\n", sums[n]);
  printf(" ----------------\n");
  //for(i = )
  printf("\n");
}

int main() {
  int square[N][N];
  int sums[2 * N + 2];
  int row, col, n, isMagic = 1, a = 0;
  scanf("%d", &n);
  
  for (row = 0; row < n; row++) {
    for (col = 0; col < n; col++) {
      scanf("%d", &square[row][col]);
    }
  }
  
  for (row = 0; row < n; row++) {
    sums[a] = 0;
    for (col = 0; col < n; col++) {
       sums[a] += square[row][col]; 
    }
    a++;
  }
  sums[n] = square[0][n-1] + square[(int)(n / 2.0 - .5)][(int)(n / 2.0 - .5)] + square[n-1][0]; 
  
  print(square, sums, n, a);
  
  for(row = 0; row < a - 1; row++) if(sums[row] != sums[row + 1]) isMagic = 0;
  
  printf((isMagic == 1) ? "MAGIC!" : "Not Magic");
  printf("\n");
}