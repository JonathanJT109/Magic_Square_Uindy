/*
If you saw the comment in the last submit. Please ignore. I accidentaly made a directory named main (because I used clang to run my program) and the program could not execute the file. But now it should work fine. I also fixed the sum of rows and columns.
*/
#include <stdio.h>
#define N 20

void print(int list[N][N], int sums[], int n){
  int i, j;
  for(i = 0; i < n; i++) printf("%3d ", sums[i]);
  printf("|%3d\n", sums[n]);
  for(int i = 0; i < n * 4 + 4; i++) printf("-");
  printf("\n");
  for(i = 0; i < n; i++){
    for(j = 0; j < n + 1; j++){
      if(j == n){
        printf("|%3d", sums[n + i + 1]);
        continue;
      } 
      printf("%3d ", list[i][j]);
    }
    printf("\n");
  }
  for(int i = 0; i < n * 4 + 4; i++) printf("-");   
  printf("\n");
  for(int i = 0; i < n * 5 - n; i++) printf(" ");
  printf("|%3d ", sums[n * 2 + 1]);
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
       sums[a] += square[col][row]; 
    }
    a++;
  }
  sums[a] = 0;
  for(row = n - 1; row >= 0; row--){
    for(col = 0; col < n; col++){
      if(row == (n - col - 1)){
        sums[a] += square[row][col];
      } 
    }
  }
  a++;
  for (col = 0; col < n; col++) {
    sums[a] = 0;
    for (row = 0; row < n; row++) {
       sums[a] += square[col][row]; 
    }
    a++;
  }
  sums[a] = 0;
  for(row = 0; row < n; row++){
    for(col = 0; col < n; col++){
      if(row == col){
        sums[a] += square[row][col];
      } 
    }
  }
  
  print(square, sums, n);
  
  
  for(row = 0; row < a - 1; row++) if(sums[row] != sums[row + 1]) isMagic = 0;

  printf((isMagic == 1) ? "MAGIC!" : "Not Magic");
  printf("\n");
}

// 28  32  36  40 | 34
//--------------------
//  1   2   3   4 | 10
//  5   6   7   8 | 26
//  9  10  11  12 | 42
// 13  14  15  16 | 58
//--------------------
//                | 34
// 15  15  15 | 15
//----------------
//  8   1   6 | 15
//  3   5   7 | 15
//  4   9   2 | 15
//----------------
//            | 15
