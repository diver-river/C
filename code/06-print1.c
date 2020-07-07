#include <stdio.h>

int main(void)
{
  int ten = 10;
  int two = 2;
  printf("Doing it right: ");
  printf("%d minus %d is %d\n", ten, two, ten - two);
  printf("Doing it wrong: ");
  printf("%d minus %d is %d\n", ten);  /* 当遗漏了数,会发生内存随机分配,导致意外错误 */
  return 0;
}
