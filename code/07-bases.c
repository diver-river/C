#include <stdio.h>

int main(void)
{
  int x = 100;
  printf("dec = %d; octal = %o; hex = %x\n", x, x, x);
  printf("dec = %d; octal = %#o; hex = %#x\n", x, x, x);  /* 要显示0和0x前缀,必须要加入#符号 */
  return 0;
}

