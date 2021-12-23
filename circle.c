#include "stdio.h"
#include "stdlib.h"

//example 1:
/* print two times  */
// for while 循环中都可以使用break 和 continue ，其效果是一样的
int main ()
{
    int x, y ;
    for (x= 0, y = 0; x < 2 && y < 5; x++, y++)
    {
        printf ("how many times? \n");
    }
    system ("pause");
    return 0;
}


// example 2:
// /* because j = 0; 是赋值语句，导致判断为0，因此循环次数为0 */
// if 赋值为非零，就是死循环
// int main()
// {
//     int i = 0;
//     int j = 0;
//     for (i = 0, j = 0; j = 0; i++, j++)
//     {
//         printf ("how many times? \n");
//     }

//     system("pause");
//     return 0;
// }