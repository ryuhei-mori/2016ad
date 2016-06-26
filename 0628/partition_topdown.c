#include <stdio.h>

#define N 101

//十分大きなサイズの配列
int Q[N][N];

int min(int a, int b){
  if(a < b) return a;
  else return b;
}

int q(int k, int n){
//計算済みの場合は配列の値を返す
  if(Q[k][n] != -1) return Q[k][n];
//そうでない場合は計算結果を配列に保存しておく
  Q[k][n] = q(k - 1, n) + q(min(k, n - k), n - k);
  return Q[k][n];
}

int p(int n){
  return q(n, n);
}

int main(){
  int k, n, i;

// q(0,0) = 1 なので配列に解を保存しておく
  Q[0][0] = 1;

// q(0,n) = 0 なので配列に解を保存しておく
  for(n = 1; n < N; n++){
    Q[0][n] = 0;
  }

/*
  それ以外の場合は未計算なので，
  その「しるし」として -1 を代入しておく
*/
  for(k = 1; k < N; k++){
    for(n = 0; n < N; n++){
      Q[k][n] = -1;
    }
  }

  for(i = 0; i < N; i++){
    printf("%d: %d\n", i, p(i));
  }

  return 0;
}

