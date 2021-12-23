#include "stdio.h"
#include "stdlib.h"
#include "windows.h"
#include "string.h"

// /* ues_1 */
// int main()
// {
//     int arr[10] = {0, 1, 2, 3, 5, 6, 7, 8, 10, 12};
//     int k = 17;
//     int sz = sizeof (arr) / sizeof (arr[0]);
//     int left = 0;
//     int right = sz - 1;

//     while (left <= right)
//     {
//         int mid = (left + right) / 2;
//         if (arr[mid] < k)
//         {
//             left = mid +1;
//         }
//         else if (arr[mid] > k)
//         {
//             right = mid -1;
//         }
//         else
//         {
//             printf ("找到了，下标 = %d \n", mid);
//             break;
//         }
//     }
//     if (left > right)
//     {
//         printf ("找不到\n");
//     }
//     system("pause");
//     return 0;
// }

// /* use-2 */
// int main()
// {
//     char arr1[] = {"hello world!!!!!!!!!"};
//     char arr2[] = {"********************"};
//     int left = 0;
//     //int right = sizeof (arr1) / sizeof (arr1[0]) - 2;     //求下标：字符串有'\0'，也在数组中，sizeof计算的是字节，又因从0开始，因此要减2
//     int right = strlen(arr1) - 1;                           //求下标：strlen 计算的是字符串长度且不包括'\0'，因此减1
//     while (left <= right)
//     {
//         arr2[left] = arr1[left];
//         arr2[right] = arr1[right];

//         printf ("%s\n", arr2);
//         Sleep (500);
//         system ("cls");

//         left++;
//         right--;
//     }
//     printf ("%s\n", arr2);
//     system ("pause");
//     return 0;
// }

int main ()
{
    int i = 0;
    char password[20] = { 0 }; 
    for (i = 0; i < 3; i++)
    {
        printf ("请输入字符串-> \n");
        scanf ("%s", &password);
        if (strcmp(password, "123456") == 0)
        {
            printf ("登录成功\n");
            break;
        }
    }
    if (i == 3)
    {
        printf ("三次输入均错误，返回登陆");
    }
    system ("pause");
    return 0;

}