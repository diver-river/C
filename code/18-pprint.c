// 固定字段宽度为了使输出更加整齐清晰
#include <stdio.h>

int main(void)
{
  int num1, num2, num3;

  printf("Please enter three number: \n");
  scanf("%d %d %d", &num1, &num2, &num3);
  printf("%5d %5d %5d\n", num1, num2, num3);
  return 0;
}
