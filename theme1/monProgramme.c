extern int putchar(int);
int foo(int x){
  int a = putchar(x);
  return 42;
}

int main(){
  int b = foo(65); /*65 est le code ASCII de A*/
}
