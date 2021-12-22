#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main ()
{
    //数组名是首元素地址
    //1. sizeof(数组名) - 数组名表示整个数组
    //2. &数组名 - 数组名表示整个数组
    //
    //一维数组
    int a[] = {1, 2, 3, 4};                 //16 4*4
    printf ("%d\n", sizeof(a));             //16 //sizeof (数组名) - 计算的是数组总大小 - 单位是字节 - 16
    printf ("%d\n", sizeof(a + 0));         //8或者4 - 数组名这里表示首元素地址，a+0 还是首元素地址，地址大小是4或者8
    printf ("%d\n", sizeof(*a));            //4  - 数组名表示元素地址。*a就是首元素，sizeof(*a) 就是4

    printf ("%d\n", sizeof(a + 1));         //8或者4 - 数组名这里表示首元素地址，a+1 第二个元素的地址，地址的大小就是4/8个字节
    printf ("%d\n", sizeof(a[1]));          //4 - 第二个元素的大小

    printf ("%d\n", sizeof(&a));            //8或者4 - &a取出的是数组的大小，但是数组的地址也是地址，地址的大小就是4/8个字节
    printf ("%d\n", sizeof(*&a));           //16 - &a数组的地址，数组的地址解引用访问的数组，sizeof计算的就是数组的大小单位是字节

    printf ("%d\n", sizeof(&a + 1));        //8或者4 - &a是数组的地址，&a+1虽然跳过整个数组，但还是地址，所以是4/8个字节
    printf ("%d\n", sizeof(&a[0]));         //8或者4 - 第一个元素的地址
    printf ("%d\n", sizeof(&a[0] + 1));     //8或者4 - &a[0]+1是第二个元素的地址



    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    printf ("%d\n", sizeof(arr));               //6 //sizeof (数组名) - 计算的是数组总大小
    printf ("%d\n", sizeof(arr + 0));           //8 //数组名这里表示首元素地址，a+0 还是首元素地址，地址大小是4或者8

    printf ("%d\n", sizeof(*arr));              //1 //数组名表示元素地址。*arr就是首元素，sizeof(*arr) 就是1

    printf ("%d\n", sizeof(arr[1]));            //1 //数组名表示元素地址。arr[1]就是第二个元素，sizeof(arr[1]) 就是1
    printf ("%d\n", sizeof(&arr));              //8 //&a取出的是数组的大小，但是数组的地址也是地址，地址的大小就是4/8个字节

    printf ("%d\n", sizeof(*&arr));             //6 //&arr数组的地址，数组的地址解引用访问的数组，sizeof计算的就是数组的大小单位是字节
    printf ("%d\n", sizeof(&arr + 1));          //8 //&a是数组的地址，&a+1虽然跳过整个数组，但还是地址，所以是4/8个字节

    printf ("%d\n", sizeof(&arr[0]));           //8 //8或者4 - 第一个元素的地址
    printf ("%d\n", sizeof(&arr[0] + 1));       //8 //8或者4 - &a[0]+1是第二个元素的地址

    
    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    
    printf ("%d\n", strlen(arr));           //随机值    //该数组没有'\0' , 所以是随机值
    printf ("%d\n", strlen(arr + 0));       //随机值

    // printf ("%d\n", strlen(*arr));          //error      //非法访问地址
    // printf ("%d\n", strlen(arr[1]));        //error

    printf ("%d\n", strlen(&arr));          //随机值 a

    printf ("%d\n", strlen(&arr + 1));      //随机值 b = a - 6

    printf ("%d\n", strlen(&arr[0] + 1));   //随机值 c = a - 1

    
    
    
    system ("pause");
    return 0;
}