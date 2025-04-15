#include <stdio.h>
#include <math.h>

int newline() {
    putchar('\n');
}

int putdec(int d);

int put_test_line(int n)
{
    putchar('t');
    putchar('e');
    putchar('s');
    putchar('t');
    putchar(' ');
    putchar('#');
    putdec(n);
    putchar(':');

    return 0;
}

int putdigit(int d){
  if (d>=0 && d<=9){
    putchar( '0' + d);
    return 0;
  }else{
    return -1;
  }
}

int puthdigit(int h){
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

int main()
{
  /*putdigit(5);
  putchar('\n');
  puthdigit(12);
  putchar('\n');
  putdec(345.00);
  putchar('\n');
  putbin(10);
  putchar('\n');
  puthex(12);
  putchar('\n');*/
  
  
  /*printf("Bonjour\n");*/
  int i =-2147483648;
  put_test_line(1); putdec(214); newline();
  put_test_line(2); putdec(-74); newline();
  put_test_line(3); putdec(1); newline();
  put_test_line(4); putdec(-1); newline();
  put_test_line(5); putdec(0); newline();
  put_test_line(6); putdec(2147483647); newline();
  put_test_line(7); putdec(-2147483648); newline();
  put_test_line(8); putdec(-(-2147483648)); newline();
  put_test_line(9); puthex(0); newline();
  put_test_line(10); puthex(10); newline();
  put_test_line(11); puthex(16); newline();
  put_test_line(12); puthex(2147483647); newline();
  put_test_line(13); puthex(-2147483648); newline();
  put_test_line(14); puthex(0xCAFEBABE); newline();
  put_test_line(15); puthex(-1); newline();
  put_test_line(16); putbin(0); newline();
  put_test_line(17); putbin(1); newline();
  put_test_line(18); putbin(-1); newline();
  put_test_line(19); putbin(2147483647); newline();
  put_test_line(20); putbin(-2147483648); newline();
  return 0;
}
