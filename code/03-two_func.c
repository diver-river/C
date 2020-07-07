#include <stdio.h>
void Say(void);    /* 声明函数 */

int main(void)
{
  printf("I will summon the butler function.\n");
  Say();          /* 调用函数 */
  printf("Yes, Bring me some tea and writeable CO-ROMS\n");
  return 0;
}

void Say(void)    /* 函数的作用,打印一段文字 */
{
  printf("You rang, Sir?\n");
}
