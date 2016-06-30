#include <stdio.h>

#define N 1000
#define WMAX 100000

unsigned int C[N+1];
unsigned int V[N+1];


int main(){
  int i;
  unsigned int n, W;

  if(scanf("%u", &n) != 1) return 1;
  if(scanf("%u", &W) != 1) return 1;
  if(n > N){
    puts("Too many items");
    return 1;
  }
  if(W > WMAX){
    puts("Too large bag");
    return 1;
  }
  for(i = 0; i < n; i++){
    if(scanf("%u", C+i) != 1) {
      puts("Error");
      return 1;
    }
  }
  for(i = 0; i < n; i++){
    if(scanf("%u", V+i) != 1) {
      puts("Error");
      return 1;
    }
  }
/*
  この時点で宝の数は n に，袋の限界容量は W に，
  宝の重さは配列 C に，宝の価値は配列 V に
  代入されているとしてよい
*/

/* 宝の重さと価値を出力 (最終的には次の3行は消すこと) */
  for(i = 0; i < n; i++){
    printf("%d, %d\n", C[i], V[i]);
  }

  return 0;
}
