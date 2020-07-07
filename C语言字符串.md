# 第三章. 字符串和格式化输入/输出                                     

**在本章中将学习下列内容**

* 函数: strlen()
* 关键字: const
* 字符串
* 如何创建和存储字符串
* 如何使用scanf()和prinf()读取和显示字符串
* 如何使用strlen()函数获取字符串的长度
* 使用C预处理器的#define指令和ANSIC的const修饰符创建符号常量

**示例程序:01-talkback.c**
```c
// talkback.c -- 一个能为你提供信息的对话程序
#include <stdio.h>
#include <string.h>  // 提供strlen()函数的原型
#define DENSITY 62.5 // 人的密度

int main(void)
{
  float weight, volume;
  int size, letters;
  char name[40];     // name是一个有40字符的数组

  printf("Hi! What's your first name?\n");
  scanf("%s", name);
  printf("%s, what's your weight in pounds?\n", name);
  scanf("%f", &weight);
  size = sizeof name;
  letters = strlen(name);  // strlen()来获取字符串的长度
  volume = weight / DENSITY;
  printf("Well, %s, your volume is %2.2f cubic feet.\n", name, volume);
  printf("Also, your first name has %d letters, \n", letters);
  printf("and we have %d bytes to store it in.\n", size);
  return 0;
}
```
> PS: 字符串在数组的最后位置是空字符(\0)

**使用字符串,程序02-praise1.c**
```c
#include <stdio.h>
#define PRAISE "What a super marvelous name!"

int main(void)
{
  char name[40];

  printf("What's your name?\n");
  scanf("%s", name);        --> 在遇到第一个空白字符(blank)、制表符(tab)、换行符(newline)处停止
  printf("Hello, %s. %s\n", name, PRAISE);
  return 0;
}
```

**strlen()查看长度,程序03-praise2.c**
```c
#include <stdio.h>
#include <string.h>
#define PRAISE "What a super marvelous name!"
int main(void)
{
  char name[40];

  printf("What's your name?\n");
  scanf("%s", name);
  printf("Hello, %s. %s\n", name, PRAISE);
  printf("Your name of %d letters occupies %d memory cells.\n", strlen(name), sizeof(name));
  printf("The phrase of praise has %d letters", strlen(PRAISE));
  printf("and occupies %s memory cells.\n", sizeof(PRAISE));
  return 0;
}
```

**常量和C预处理器,程序04-pizza.c**
```c
#include <stdio.h>
#define PI 3.14159

int main(void)
{
  float area, circum, radius;

  printf("What is the radius of your pizza?\n");
  scanf("%f", &radius);
  area = PI * radius * radius;
  circum = 2.0 * PI * radius;
  printf("Your basic pizza parameters are as follows: \n");
  printf("circumference = %1.2f, area = %1.2f\n", circum, area);
  return 0;
}
```

**const修饰符,把变量声明转换常量声明**
`const int MONTHS = 12` **MONTHS代表12的符号常量**

**limits.h中的一些符号常量**
| 符号常量 | 含义 |
| -- | -- |
| CHAR_BIT | 一个char的位数 |
| CHAR_MAX | char类型的最大值 |
| CHAR_MIN | char类型的最小值 |
| SCHAR_MAX | signed char类型的最大值 |
| SCHAR_MIN | signed char类型的 |
| UCHAR_MAX | unsigned char类型的最大值 |
| SHRT_MAX | short类型的最大值 |
| SHRT_MIN | short类型的最小值 |
| USHRT_MAX | unsigned short类型的最大值 |
| INT_MAX | int类型的最大值 |
| INT_MIN | int类型的最小值 |
| UINT_MAX | unsigned int类型的最大值 |
| LONG_MAX | long类型的最大值 |
| LONG_MIN | long类型的最小值 |
| ULONG_MAX | unsigned long类型的最大值 |
| LLONG_MAX | long long类型的最大值 |
| LLONG_MIN | long long类型的最小值 |
| ULLONG_MAX | unsigned long long类型的最大值 |
| FLT_MANT_DIG | float类型的尾数位数 |
| FLT_DIG | float类型的最少有效数字位数(十进制) |
| FLT_MIN_10_EXP | 带有全部有效数字的float类型的负指数的最小值(以10为底) |
| FLT_MAX_10_EXP | float类型的正指数的最大值(以10为底) |
| FLT_MIN | 保留全部精度的float类型整数的最小值 |
| FLT_MAX | float类型正数的最大值 |
|FLT_EPSILON | 1.00 和比 1.00大的最小的float类型值之间的差值 |

**程序05-defines.c,示例如下:**
```c
// 使用limit.h和float.h定义常量
#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
  printf("Some number limits for this system: \n");
  printf("Biggest int: %d\n", INT_MAX);
  printf("Smallest unsigned long: %11d\n", LLONG_MIN);
  printf("One byte = %d bits on this system.\n", CHAR_BIT);
  printf("Largest double: %e\n", DBL_MAX);
  printf("Smallest normal float: %e\n", FLT_MIN);
  printf("float precision = %d digits\n", FLT_DIG);
  printf("float epsilon = %e\n", FLT_EPSILON);
  return 0;
}
```

**printf()函数,转换说明符及作为结果打印输出**
| 转换说明 | 输出 |
| -- | -- |
| %a | 浮点数、十六进制数字和p-计数法(C99) |
| %A | 浮点数、十六进制数字和p-计数法(C99) |
| %c | 一个字符 |
| %d | 有符号十进制整数 |
| %e | 浮点数、e-计数法 |
| %E | 浮点数、E-计数法 |
| %f | 浮点数、十进制计数法 |
| %g | 根据数值不同自动选择%f或%e. %e格式在指数小于-4或大于等于精度时使用 |
| %G | 根据数值不同自动选择%f或%E. %E格式在指数小于-4或者大于等于精度时使用 |
| %i | 有符号十进制整数(%d相同) |
| %o | 无符号八进制整数 |
| %p | 指针 |
| %s | 字符串 |
| %u | 无符号十进制整数 |
| %x | 使用十六进制数字0f的无符号十六进制整数 |
| %X | 使用十六进制数字0F的无符号十六进制整数 |
| %% | 打印一个百分号 |

**使用scanf()函数,程序input.c**
```c
#include <stdio.h>

int main(void)
{
  int age;   // 变量
  float assets; // 变量
  char pet[30]; // 字符串
  
  printf("Enter your age, assets, and favorite pet.\n");
  scanf("%d %f", &age, &assets);  // 此处需要使用&
  scanf("%s", pet);   // 对char数组不需使用&
  printf("%d $%.2f %s\n", age, assets, pet);
  return 0;
}
```

**字符串格式化输入/输出**
| 转换说明符 | 意义 |
| ---------  | ---- |
| %c | 把输入解释成一个字符 |
| %d | 把输入解释成一个有符号十进制整数 |
| %e, %f, %g, %a | 把输入解释成一个浮点数 |
| %E, %F, %G, %A | 把输入解释成一个浮点数 |
| %i | 把输入解释成一个有符号十进制整数 |
| %o | 把输入解释成一个有符号八进制整数 |
| %p | 把输入解释成一个指针(一个地址) | 
| %s | 把输入解释成一个字符串: 输入的内容以第一个非空白字符作为开始, 并且包含直到下一个空白字符的全部字符 |
| %u | 把输入解释成一个无符号的十进制整数 |
| %x, %X | 把输入解释成有符号十六进制整数 |

**printf()和scanf()的*修饰符**
```c
#include <stdio.h>

int main(void)
{
  unsigned with, precision;
  int nuber = 256;
  double weight = 242.5;

  printf("What field width?\n");
  scanf("%d", &weight);
  printf("The number is: %*d: \n", width, number);
  printf("Now enter a width and a precision: \n");
  scanf("%d %d", &width, &precision);
  printf("Weight = %*.*f\n", width, precision, weight);
  return 0;
}
```

## 复习题
**找出下面程序错误**
```c
define B booboo
define X 10
main(int)
{
  int age;
  char name;
  rintf("Please enter your first name.");
  scanf("%s", name);
  printf("All right, %c, what's your age?\n", name);
  scanf("%f", age):
  xp = age + X;
  printf("That's a %s! You must be at least %d.\n", B , xp);
  return 0;
}
```

# 第四章. 运算符、表达式和语句

**在本章中您将学习下列内容**
* 关键字: while, typedef
* 运算符: =-*/%++--(type)
* C的各种运算符,其中包括用于普通数学运算
* 运算符的优先级及术语“语句”和“表达式”
* 简单的while循环
* 符合语句、自动类型转换和类型指派
* 如何编写带有参数的函数

**循环示例如下**
```c
// 计算多个鞋尺码对应的长度
#include <stdio.h>
#define ADJUST 7.64
#define ACALE 0.325

int main(void)
{
  double shoe, foot;

  printf("Shoe size(men's)   foot length\n");
  shoe = 3.0;
  while(shoe < 18.5)
  {
    foot = SCALE * shoe + ADJUST;
    printf("%10.lf %15.2f inches\n", shoe, foot);
    shoe = shoe + 1.0;
  }
  printf("If the shoe fits, wear it.\n");
  return 0;
}
```

**各种运算符**
> "="为赋值运算符<br>
> "+"为加法运算符<br>
> "-"为减法运算符<br>
> "*"为乘法运算符<br>
> "/"为减法运算符<br>

**指数增长,看程序21-wheat.c**
