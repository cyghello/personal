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
    int x; 
    int y;
    do 
    {
        menu();
        printf ("��ѡ��: >");
        scanf ("%d", &input);

        switch (input)
        {
        case 1:
            printf ("����������������");
            scanf ("%d%d", &x, &y);
            printf ("%d\n", Add(x, y));
            break;
        case 2:
            printf ("����������������");
            scanf ("%d%d", &x, &y);
            printf ("%d\n", Sub(x, y));
            break;
        case 3:
            printf ("����������������");
            scanf ("%d%d", &x, &y);
            printf ("%d\n", Mul(x, y));
            break;
        case 4:
            printf ("����������������");
            scanf ("%d%d", &x, &y);
            printf ("%d\n", Div(x, y));
            break;
        case 0:
            printf ("�˳�\n");
            break;
        default:
            printf ("ѡ�����\n");
            break;
         
        }
    
    }while (input);

    system ("pause");
    return 0;
}