#include <stdio.h>
#include <stdlib.h>
 
int main(){
  int *p = 0;
  char *q = 0;
  char *s = 0;
  void *t = 0;
  int number = 5;
  p = (int *)malloc(number * sizeof(int));
  q = (char *)malloc(sizeof(char));
  s = (char *)malloc(sizeof(char));
  t = malloc(0);
  /*
    说明：内存单元的编号是以十六进制表示的，而一个内存单元是8bit，
          即一个字节；两个十六进制想减对应的十进制数即为包含的内存单位个数。
          亦即对应有多少个byte。
          如0xf--0x0，一共相隔15个字节
 
   */
  printf("sizeof(int)占用%lu个字节\n", sizeof(int));
  printf("sizeof(char)占用%lu个字节\n", sizeof(char));
  //  printf("sizeof(double)占用%lu个字节\n", sizeof(double));
 
  /* printf("sizeof(float)占用%lu个字节\n", sizeof(float)); */
 
  printf("已申请int类型内存块首地址：%p\n", p);
  printf("已申请char类型内存块首地址：%p\n", q);
  printf("已申请char类型内存块首地址：%p\n", s);
  printf("malloc(0)对应的内存块首地址：%p\n", t);
 
  free(p);
  free(q);
  free(s);
  free(t);
  return 0;
}