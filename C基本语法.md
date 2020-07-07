# 标准的C程序使用格式如下

**函数头**
```c
#include <stdio.h>  -->预处理指令
int main(void)      -->带有参数的函数名
```
**函数体**
```c
{
  int q;                        -->声明语句
  q = 1;                        -->赋值语句
  printf("%d is neat. \n", q);  -->函数语句
  return 0;                     -->结束语句
}
```

**通俗来说,标准的C程序如下格式:**
```c
#include <stdio.h>
int main(void)
{
  statements;  -->声明
  return 0;
}
```

# 增强程序的可读性

**以下是一个示例**
```c
#include <stdio.h>
int main(void)  /* converts 2 fathoms to feet */ -->使用注释
{
  int feet, fathoms;  -->选用有意义的名字
                      -->使用空行 /(反斜杠)增强可读性
  fathoms = 2;        -->每行仅用一个语句
  feet = 6 * fathoms; -->执行语句
  printf("There are %d feet in %d fathoms!\n", feet, fathoms);
  return 0;
}
```

# 定义自己的函数

**以下仅是一个模板,具体查看程序03-two_func.c**
```
#include <stdio.h>      -->头文件
void functionName(type);-->声明函数

int main(void)          -->主函数也是程序开始的入口
{
  statements;
  return 0;
}

void functionName(type) -->函数定义
{
  statements;           -->执行程序
  return something;     -->根据情况选择是否返回元素
}
```

# 调试程序

**详情看程序04-nogood.c,以下为错误示范**
```c
#include <stdio.h>
int main(void)
{
  int n, int n2;
  printf("n = %d, n2 = %d", n, n2);
  return 0;
}
```

## 复习题

**1.改下面程序,详细看程序01-test.c**
```c
include studio.h
int main{void}  /* 该程序可显示一年中有多少周 */
(
  int s
  s: = 56;
  print(There are s weeks in a year.);
  return 0;
)
```

**2.下面的每一个例子都是某个程序的一部分,写出输出的结果**
```
> a. prinft("Baa Basa Black Sheep.");
>    prinft("Have you any wool?\n");
> b. prinft("Begone!\nO creature of lard!");
> c. prinft("What?\nNo\nBonzo?\n");
> d. int num;
>    num = 2;
>    printf("%d + %d = %d\n", num, num, num + num);  -->4
```

**考虑下面程序,详细看程序02-test.c**
```c
#include <stdio.h>
int main(void)
{
  int a, b;
  a = 5;
  b = 2; /* b = 2 */
  b = a; /* b = 5 */
  a = b; /* a = 5 */
  printf("%d %d\n", b, a);
  return 0;
}
```

# 第二章. 数据和C

**在本章中将学习以下内容**

* 关键字:`int, short, long unsigned, char, float, double, _Bool, _Complex, _Imaginary`
* 运算符:`sizeof`
* 函数:`scanf()`
* C使用的基本数据类型
* 整数类型和浮点数类型的区别
* 对上述类型,如何书写常量和声明变量
* 使用printf()和scanf()函数读写各种类型数据的值

**简单的示例程序**

```c
/* rhodium.c -- 用金属衡量体重 */
#include <stdio.h>
int main(void)
{
  float weight;
  float value;    /* 声明体重和金属变量 */
  printf("Are you worth your weight in rhodium?\n");
  printf("Let's check it out.\n");
  printf("Please enter your weight in pounds: ");
  /* 接受用户输入数据 */
  scanf("%f", &weight);
  value = 770 * weight * 14.5833;
  printf("Your weight in rhodium is worth $%.2f.\n", value);
  printf("You are easily worth that! If rhodium prices drop, \n");
  printf("eat more to maintain your value.\n");
  return 0;
}
```

##变量与常量数据

**整型变量的一个例子,查看程序06-print1.c**
```c
#include <stdio.h>

int main(void)
{
  int ten = 10;
  int two = 2;
  printf("Doing it right: ");
  printf("%d minus %d is %d\n", ten, two, ten - two);
  printf("Doing it wrong: ");
  printf("%d minus %d is %d\n", ten);  /* 故意漏掉两个参数 */
  return 0;
}
```

**八进制和十六进制**

```
> 八进制以前缀0开头
> 十六进制以前缀0x或0X开头
```

**查看程序07-bases.c了解**
```c
#include <stdio.h>

int main(void)
{
  int x = 100;
  printf("dec = %d; octal = %o; hex = %x\n", x, x, x);
  /* %#o、%#x、和%#X 分别生成0、0x和0X前缀 */
  printf("dec = %d; octal = $#o; hex = %#X\n", x, x, x);
  return 0;
}
```

**声明其他整数类型**
```c
long int estline;     --> %ld
long johns;           --> %l
short int ear;        
short ear;
unsigned int set;     --> %u
unsigned player;
unsigned long headcount;
unsigned short yellow;
long long age;
```
> 声明不同类型是为了适应不同的机器

**一种特殊的情况,整数溢出程序08-toobig.c**
```c
/* 超出系统最大int值 */
#include <stdio.h>

int main(void)
{
  int i = 324985429542;
  unsigned int j = 4294967296;

  printf("%d %d %d\n", i, i+1, i+2);
  printf("%d %u %u\n", j, j+1, j+2);
  return 0;
}
```
> 当出现溢出时会重置到起始点

**打印长类型和短类型,程序09-print2.c**

**使用char类型**
> char grade = 'A'
> <br>使用转义序列作为字符变量时,必须用单引号括起来
> <br>C把char当作有符号类型，意味这char类型值的典型范围为-128到127
> <br>C把char当作无符号类型，意味这其取值范围为0-255

**转义序列及意义**
---
| 序列 | 意义 |
| ---- | ---- |
| \a | 警报 |
| \b | 退格 |
| \f | 走纸 |
| \n | 换行 |
| \r | 回车 |
| \t | 水平制表符 |
| \v | 垂直制表符 |
| \\ | 反斜杠(\) | 
| \' | 单引号(') |
| \" | 双引号(") |
| \? | 问好(?) |
| \0oo | 八进制值(o表示一个八进制数字) |
| xhh | 十六进制值(h表示一个十六进制数字) |

**打印一个字符及编码值,程序10-charcode.c**
```c
#include <stdio.h>

int main(void)
{
  char ch;
  printf("Please enter a character.\n");
  scanf("%c", &ch);
  printf("The code for %c is %d.\n", ch, ch);
  return 0;
}
```

**可移植类型: inttypes.h, 看程序11-altnames.c**

**这个程序要注意**
```c
/* showf_pt.c -- 以两种方式显示浮点值 */
#include <stdio.h>

int main(void)
{
  float aboat = 32000.0;
  double abet = 2.14e9;
  long double dip = 5.32e-5;
  printf("%f can be written %e\n", aboat, aboat);
  printf("%f can be written %e\n", abet, abet);
  printf("%f can be written %e\n", dip, dip);
  return 0;
}
```

**浮点数舍入误差, 程序13-floaterr.c**
```c
// floaterr.c -- 说明舍入误差
#include <stdio.h>

int main(void)
{
  float a, b;

  b = 2.0e20 + 1.0;
  a = b - 2.0e20;
  printf("%f \n", a);
  return 0;
}
```

**`sizeof输出类型大小，详细看程序14-typesize.c`**

**参数和易犯的错误**

## 复习题

**1.找出下面程序的错误**
```c
include <stdio.h>
main
(
  float g; h;
  float tax, rate;

  g = e21;
  tax = rate * g;
)
```
