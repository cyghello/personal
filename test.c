#include "stdio.h"
#include "stdlib.h"

#define f(x, y) (x) *(y)
int main()
{
    int x = 3;
    int y = 4;
    int ret = f(x, y);
    int a = 1;
    int b = 2;
    int rse = 10*f(a + 1, b + 1);


    system("pause"); //ÔİÍ£ÖÕ¶Ë
    // getchar();
    return 0;
}