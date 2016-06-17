#include <stdio.h>


//B[start], B[start+1], ..., B[end-1]の中で k+1 番目に大きい値を返す関数
int quickselect(int B[], int start, int end, int k){
  int m, i, tmp;
  int pivot;

//サイズが1の場合はその唯一の要素を返す
  if(end == start+1) return B[start];

/*
B[start]をピボットとし，Bの前半にピボット以下の要素，
Bの後半にピボットより大きい要素を配置する
*/
  pivot = B[start]; 
  m = start+1;
  for(i = start+1; i < end; i++){
    if(B[i] <= pivot){
      tmp = B[m];
      B[m] = B[i];
      B[i] = tmp;
      m++;
    }
  }

//ピボットより大きい要素が k 個あった場合
  if(end == m + k) return pivot;
//ピボットより大きい要素が k 個より少ない場合
  else if(end < m + k) return quickselect(B, start+1, m, k - (end - m) - 1);
//ピボットより大きい要素が k 個より多い場合
  else return quickselect(B, m, end, k);
}

int main(){
  int i;
  int A[] = { 6, 1, 20 , 3, 8, 9, 2, 7, 10, 6 };

  for(i = 0; i < 10; i++){
    printf("%d th: %d\n", i, quickselect(A, 0, 10, i));
  }

  return 0;
}
