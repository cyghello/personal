#include "stdio.h"
#include "stdlib.h"

/*注意#define的使用 其中#define f(x, y) x*y 与#define f(x, y) (x)*(y)完全不同*/
/*上述两种形式带来的差异是由于 宏定义 f(x,y)时形参是否带有括号引起的*/
/*其中没有括号的 表示的参数的顺序运算，其中包括乘法，形如:x = (a = 1) + 1 * y = (b = 2) + 1 ,这个结果就是4  */
/*而有括号的就表示为 (x = (a = 1) + 1) * (y = (b = 2) + 1),其结果为6，这个表示的就是两个参数的相乘*/

#define f(x, y) (x) *(y)
int main()
{
    int x = 3;
    int y = 4;
    int ret = f(x, y);
    int a = 1;
    int b = 2;
    int rse = 10*f(a + 1, b + 1);


    system("pause"); //ÔÝÍ£ÖÕ¶Ë
    // getchar();
    return 0;
}
