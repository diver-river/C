#include <stdio.h>

int main(void)
{
  float weight, value;
  printf("Are you worth your weight in rhodium?\n");
  printf("Let's check it out.\n");
  printf("Please enter your weight in pounds: ");
  /* 接受用户输入 */
  scanf("%f", &weight);
  value = 770 * 15.5833 * weight;
  printf("Your weight in rhodium is worth $%.2f.\n", value);  /* %.2f保留浮点数后两位 */
  printf("You are easily worth that! If rhodium prices drop, \n");
  printf("eat more to maintain your value.\n");
  return 0;
}
