#include<stdio.h>
#define XMAX 21
#define YMAX 21
int main() {
  long long int matrix[XMAX][YMAX];
  int i,j;
  for(i=0;i<=XMAX-1;i++) {
    matrix[XMAX-1][i]=1;
    matrix[i][YMAX-1]=1;
  }
  for(i=XMAX-2;i>=0;i--)
    for(j=YMAX-2;j>=0;j--)
      matrix[i][j]=matrix[i+1][j]+matrix[i][j+1];
  printf("%lld",matrix[0][0]);
}
