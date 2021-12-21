#include "stdio.h"
#include "stdlib.h"



void menu ()
{
    printf ("*********************\n");
    printf ("*********111     2222\n");
    printf ("*********333     4444\n");
    printf ("*********    000     \n");
    printf ("*********************\n");
}
int Add (int x, int y)
{
    return x + y;

}
int Sub (int x, int y)
{
    return x - y;

}
int Mul (int x, int y)
{
    return x * y;

}
int Div (int x, int y)
{
    return x / y;

}

int main ()
{
    int input = 0;
    int x = 0;
    int y = 0;
    int (*pfArr[5])(int, int) = {0, Add, Sub, Mul, Div};

    do 
    {
        menu ();
        printf ("请选择: ->");
        scanf ("%d", &input);
        if (input >= 1 && input <=4)
        {
            printf ("请输入两个操作数");
            scanf ("%d%d",&x, &y);
            int ret = pfArr[input](x, y);
            printf ("%d\n", ret);

        }
        else if (input == 0)
        {
            printf ("退出\n");
        }
        else 
        {
            printf ("选择错误\n");
        }
    }while (input);



    system ("pause");
    return 0;
}