#include <stdio.h>

#define N 101

//十分大きなサイズの配列
int Q[N];

int main(){
  int k, n;

// q(0,0) = 1 なので配列に解を保存しておく
  Q[0] = 1;

// q(0,n) = 0 なので配列に解を保存しておく
  for(n = 1; n < N; n++){
    Q[n] = 0;
  }

  for(k = 1; k < N; k++){
    for(n = k; n < N; n++){
      Q[n] += Q[n - k];
    }
    printf("%d: %d\n", k, Q[k]);
  }

  return 0;
}

