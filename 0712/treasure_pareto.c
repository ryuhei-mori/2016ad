#include <stdio.h>

#define N 20000
#define WMAX 100000
#define MAXSTATES WMAX

unsigned int C[N];
unsigned int V[N];

/*
状態の構造体
*/
struct state_t {
  int c;
  int v;
};

/*
  states は状態の整列した集合を表す配列
  states_tmp0 と states_tmp1 は状態の集合の更新のために使う配列
  ns は状態の個数とする
*/
struct state_t states[MAXSTATES];
struct state_t states_tmp0[MAXSTATES];
struct state_t states_tmp1[MAXSTATES];
unsigned int ns;

/*
states_tmp0 と states_tmp1 を「マージ」して states に保存する関数
c が W を超える状態は保存する必要がない
*/
void merge(int W){
}

int main(){
  int i, j;
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

/*
  重さ0，価値0 の状態がひとつある
*/
  states[0].c = 0;
  states[0].v = 0;
  ns = 1;

/*
  ここにプログラムを書く
*/

/*
  最適値と最終的な状態の数の出力（下2行は消さないこと）
*/
  printf("%d\n", states[ns-1].v);
  printf("%d\n", ns);

  return 0;
}
