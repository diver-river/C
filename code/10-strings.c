// string.c -- 字符串的格式化
#include <stdio.h>
#define BLURE "Authentic imitation! "

int main(void)
{
  printf("/%2s/\n", BLURE);
  printf("/%24s/\n", BLURE);
  printf("/%24.5s/\n", BLURE);
  printf("/%-23.5s/\n", BLURE);
  return 0;
}
