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


/*关于自增的讨论
在Windows环境下，假设x = 10, 
1）x++ + x++ = 21
2）x++ + ++x = 22
3) ++x + x++ = 23
4) ++x + ++x = 24
上述4种情况无论是先考虑所有的前置++ ，运算完所有的相加，还是考虑顺序运算都感觉没有一个完全的定论
虽然实际应用中，这个是尽量避免的问题，但是很多学识上的问题，都会考虑这个，但是这个也涉及编译器环境问题，
产生的矛盾也无法解决.我所思考的是：对于含有两个自增的运算，都会将所有的前置++先计算，然后将两个式子相加，
如果第二个是后置++，那么会将其视为前置++进行运算
*/
/*Linux环境下，计算自增的式子有一定的顺序，比如说三个式子，前两个式子会先相加，在判断第三个式子*/


//对文件操作无法写入的问题，一定要记得关闭文件,文件指针置空
//关于读文件并在标准输出流打印，需要用到一个rewind()的函数 ，将文件指针移到由流指定的开始处
//
void test()
{
    char name[20], tele[20];
    char number[20] = {0};
    char line_food = '\r';
    int num;
    int i = 0;
    FILE *content = fopen("contacts.txt", "a+"); //附加文本 ：
    if (content == NULL)
    {
        cout << "fail to open file";
    }
    else
    {
        system("cls");
        cout << "please enter order number :" << endl; //底层函数？？？？.
        while (cin >> num)                             //输入文件结束符CTRL + Z // >> 与 << 这两个操作符传参是地址(这只是其一，这两个操作符有很多重载)
        {
            if (i == 0)
            {
                system("cls");
                cout << "please enter order number :" << endl;
                // rewind (content);      //只能指向一次！！？？ //还不懂
                fprintf(content, "number : %d \n", num); //文件流输出没有int类型的？？
                // cout << "hello";
                // cout << &num << endl;
                i++;
                cout << i << endl;
                // system ("cls");
                cout << "please enter name :" << endl;
                while (cin >> num)
                {
                    if (i == 1)
                    {
                        // rewind (content);
                        fprintf(content, "name : %d \n", num);
                        i++;
                        cout << i << endl;
                        // system ("cls");
                        cout << "please enter telephone number :" << endl;
                        while (cin >> num)
                        {
                            if (i == 2)
                            {
                                // rewind (content);
                                fprintf(content, "telephone number : %d \n", num);
                                i = 0;
                                cout << i << endl;
                                fclose(content);
                            }
                            // break; //返回上一级输入
                        }
                    }
                }
            }
            // if (i == 0)
            // {

            //     rewind(content);
            //     fputs(&number[0], content); //文件流输出没有int类型的？？
            //     // cout << "hello";
            //     cout << number[0];
            //     i++;
            //     cout << i;
            //     break; //一次打印
            //     system ("cls");
            //     cout << "please enter name :" << endl;
            // }
        }
    }
}
