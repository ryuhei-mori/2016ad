#include <stdio.h>
#include <stdlib.h>


struct tree {
  struct tree *l;
  int v;
  struct tree *r;
  int h;
};

typedef struct tree tree_t;

int count;

int tree_height(tree_t *t){
}

/*
  2分探索木 l の要素は必ず v より小さい
  2分探索木 r の要素は必ず v より大きい
*/
tree_t *tree_create(tree_t *l, int v, tree_t *r){
}

void tree_free(tree_t *r){
  free(r);
  count--;
}

void tree_print_elements(tree_t *t){
}

/*
  tree_height(l) <= tree_height(r) + 2 &&
  tree_height(r) <= tree_height(l) + 2
  が true であると仮定してよい
*/
/*
発展的課題
tree_t *tree_bal(tree_t *l, int v, tree_t *r) {
}
*/

int tree_mem(int x, tree_t *t){
}

tree_t *tree_add(int x, tree_t *t) {
}

int tree_min(tree_t *t){
}

int tree_max(tree_t *t){
}

tree_t *tree_remove_min(tree_t *t){
}

/*
  2分探索木 t1 の要素は必ず2分探索木 t2 の要素より小さい
*/
tree_t *tree_merge(tree_t *t1, tree_t *t2){
}

tree_t *tree_remove(int x, tree_t *t){
}

int tree_size(tree_t *t){
  if(t == NULL) return 0;
  return 1 + tree_size(t->l) + tree_size(t->r);
}


/*
平衡性のチェック(発展的課題)
int tree_check(tree_t *t){
  if(t == NULL) return 1;
  return tree_height(t->l) <= tree_height(t->r)+1 &&
  tree_height(t->r) <= tree_height(t->l)+1 && tree_check(t->l) && tree_check(t->r);
}
*/

int main(){
  int i;
  tree_t *t = NULL;

  for(i = 0; i < 7919; i++){
    t = tree_add(i*4000 % 7919, t);
  }

  tree_print_elements(t);

// サイズが7919かチェック
  printf("size = %d\n", tree_size(t));

  for(i = 0; i < 7919; i++){
    t = tree_remove(i*5000 % 7919, t);
  }

  tree_print_elements(t);
// サイズが0かチェック
  printf("size = %d\n", tree_size(t));

/*
//  平衡性のチェック
  for(i = 0; i < 100000; i++) {
    int rnd = rand()%1000;
    if(rand() % 2)
      t = tree_remove(rnd, t);
    else
      t = tree_add(rnd, t);
    if(!tree_check(t)) puts("ERROR");
  }

//  確保しているノードの領域の数と木のサイズが一致するかチェック
  printf("count = %d\n", count);
  printf("size = %d\n", tree_size(t));
*/
 

  return 0;
}
