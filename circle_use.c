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
//             printf ("�ҵ��ˣ��±� = %d \n", mid);
//             break;
//         }
//     }
//     if (left > right)
//     {
//         printf ("�Ҳ���\n");
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
//     //int right = sizeof (arr1) / sizeof (arr1[0]) - 2;     //���±꣺�ַ�����'\0'��Ҳ�������У�sizeof��������ֽڣ������0��ʼ�����Ҫ��2
//     int right = strlen(arr1) - 1;                           //���±꣺strlen ��������ַ��������Ҳ�����'\0'����˼�1
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
        printf ("�������ַ���-> \n");
        scanf ("%s", &password);
        if (strcmp(password, "123456") == 0)
        {
            printf ("��¼�ɹ�\n");
            break;
        }
    }
    if (i == 3)
    {
        printf ("������������󣬷��ص�½");
    }
    system ("pause");
    return 0;

}