#include "stdio.h"
#include "stdlib.h"

//example 1:
/* print two times  */
// for while ѭ���ж�����ʹ��break �� continue ����Ч����һ����
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
// /* because j = 0; �Ǹ�ֵ��䣬�����ж�Ϊ0�����ѭ������Ϊ0 */
// if ��ֵΪ���㣬������ѭ��
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