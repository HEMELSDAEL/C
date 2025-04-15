#include<stdio.h>

int putdigit(int d){
  if (d>=0 && d<=9){
    putchar( '0' + d);
    return 0;
  }else{
    return -1;
  }
}


int putdec(int d){
  int i=1000000000, res=0;
  if(d==0){
    putdigit(0);
    return 0;
  }
  if(d<0){
    putchar('-');
    d = -d;
  }
  while ((d/i)==0){
    i/=10;
  }
  while (i!=0){
    int n = (d/i)%10;
    if(n<0){
      n = -n;
    }
    res = putdigit(n);
    i/=10;
  }
  return res;
}

int ln = __LINE__;
int main(){
  putdec(ln);
  return 0;
}
