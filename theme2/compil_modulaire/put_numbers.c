#include <stdio.h>
#include <math.h>

static int putdigit(int d){
  if (d>=0 && d<=9){
     putchar( '0' + d);
    return 0;
  }else{
    return -1;
  }
}

int putdec(int d){
  int i = 1000000000, res=0;
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
  while(i!=0){
    int n = (d/i)%10;
    if(n<0){
      n = -n;
    }
    res = putdigit(n);
    i/=10;
  }
  return res;
}
static int puthdigit(int h){
  if(0<=h && h<=9){
    putchar(48+h);
    return 0;
  }
  else if (10<=h && h<=15){
    putchar(55+h);
    return 0;
  }
  else{
    return -1;
  }
}

int puthex(int h){
  int found = 1;
  int cpt = 31;
  if (h==0){
    return putdigit(0);
  }
  while (((h & (15 << cpt)) == 0) && found){
    for (int i = 0; i<4; i++){
      if((h & (1 << (cpt-i))) != 0){
	found = 0;
      }
    }
    if (found == 1){
      cpt = cpt - 4;
    }
  }
  while(cpt>=0){
    int res = 0;
    for(int j = 3; j>=0; j--){
      if(h & (1 << cpt)){
	res +=  pow(2,j);
      }
      cpt--;
    }
    puthdigit(res);
  }
}

int putbin(int b){
  if (b==0){
    putdigit(0);
    return 0;
  }
  int i = 31, res = 0;
  while ((b>>i)==0){
    i--;
  }
  while (i!=-1){
    res = putdigit((b & (1<<i))!=0);
    i--;
  }
  return res;
}


