#include <string.h>
#include <stdlib.h>
#include <stdio.h>

inline int min(int a, int b){
  return (a > b)?a:b;
}

class matrix{
 public:
  int** s;
  int r, c;
  matrix(int r, int c){
    this->r = r;
    this->c = c;
    //ref:http://chiakie.pixnet.net/blog/post/3143518-%5Bc%5D-%E5%A6%82%E4%BD%95%E5%8B%95%E6%85%8B%E9%85%8D%E7%BD%AE%E4%BA%8C%E7%B6%AD%E9%99%A3%E5%88%97
    s = (int**)malloc(sizeof(int*)*r + sizeof(int)*r*c);
    for(int i = 0; i < r; i++){
      s[i] = (int*)s + c*(i+1);
    }
    this->init();
  }
  matrix(int r, int c, int v){//fill with value v
    matrix(r, c);
    this->init(v);
  }
  ~matrix(){//destructor
    if(s != NULL)
      free(s);
  }
  void init(){
    int n = min(r, c);
    for(int i = 0; i < n; i++)
      s[i][i] = 1;
  }
  void init(int v){
    for(int i = 0; i < r; i++){
      for(int j = 0; j < c; j++){
	s[i][j] = v;
      }
    }
  }
  matrix operator+(matrix m){
    if(r != m.r || c != m.c){
      puts("can't add");
      matrix err(r, c);
      return err;
    }
    matrix sum(r, c);
    for(int i = 0; i < r; i++)
      for(int j = 0; j < c; j++)
	sum.s[i][j] = this->s[i][j] + m.s[i][j];
    return sum;
  }
  int operator()(int a, int b){
    return s[a][b];
  }
  matrix operator^(int p){
    if(r != c)
      puts("not square, can't square!");
    matrix ori(*this);
    matrix base(this->r, this->c);
    if (p == 0)
      return base;
    if (p == 1)
      return *this;
    while(p){ 
      if (p & 1)
	base = base * ori;
      p >>= 1;
      ori = ori * ori;
    }
  }
  void add(int r, int c, int v){
    s[r][c] += v;
  }
  matrix operator*(matrix b){
    if(this->c != b.r){//check
      puts("can't multiply");
      return *this;
    }
    matrix m(this->r, b.c, 0);
    for(int r = 0; r < this->r; r++)
      for(int c = 0; c < b.c; c++)
	for(int i = 0; i < this->c; i++)
	  m.add(r, c, ((*this)(r, i)) * b(i, c));
    return m;
  }
  void print(){
    for(int r = 0; r < this->r; r++){
      for(int c = 0; c < this->c; c++){
	printf("%d", s[r][c]);
	if(c != this->c-1)
	  putchar(' ');
      }
      puts("");
    }
  }
  void mod(int m){
    for(int r = 0; r< this->r; r++)
      for(int c = 0; c < this->c; c++)
	s[r][c] %= m;
  }
  
};
