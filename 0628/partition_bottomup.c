#include <stdio.h>

#define N 101

//十分大きなサイズの配列
int Q[N][N];

int min(int a, int b){
  if(a < b) return a;
  else return b;
}

int main(){
  int k, n, i;

// q(0,0) = 1 なので配列に解を保存しておく
  Q[0][0] = 1;

// q(0,n) = 0 なので配列に解を保存しておく
  for(n = 1; n < N; n++){
    Q[0][n] = 0;
  }

  for(k = 1; k < N; k++){
    for(n = k; n < N; n++){
      Q[k][n] = Q[k - 1][n] + Q[min(k, n - k)][n - k];
    }
  }

  for(i = 0; i < N; i++){
    printf("%d: %d\n", i, Q[i][i]);
  }

  return 0;
}

