#include "stdio.h"
#include "stdlib.h"
#include "Windows.h"
#include "def_bottom_var.h"
//#include "pre_para_set.h"


/*****************map-test1
void pre_map_para_set (p_map_para p_map_para_set)
{
    p_map_para_set->lines = 100;
    p_map_para_set->cols = 30;
    p_map_para_set->border[p_map_para_set->lines][p_map_para_set->cols] = 0;

}

void pretreatment_map_set(p_map_para p_map_para_set)
{
    for (p_map_para_set->lines = 0; 
         p_map_para_set->lines < 20; p_map_para_set->lines++)
    {
        for (p_map_para_set->cols = 0;
             p_map_para_set->cols < 20; p_map_para_set->cols++)
        {
            p_map_para_set->border[p_map_para_set->lines][p_map_para_set->cols] = ' ';
        }
    }
    for (p_map_para_set->lines = 0;
         p_map_para_set->lines < 20; p_map_para_set->lines++)
    {
        for (p_map_para_set->cols = 0;
             p_map_para_set->cols < 20; p_map_para_set->cols++)
        {
            if (p_map_para_set->lines == 0 || p_map_para_set->lines == 19 
                || p_map_para_set->cols == 0 || p_map_para_set->cols == 19)
            {
                p_map_para_set->border[p_map_para_set->lines][p_map_para_set->cols] = '#';
            }
            else 
                p_map_para_set->border[p_map_para_set->lines][p_map_para_set->cols] = ' ';
        }

    }    

}
t_map_para tp_map_para;
int main()
{   
    system("cls");
    system ("title letgo");
    system ("mode con cols=100 lines=30");
    pre_map_para_set (&tp_map_para);
    pretreatment_map_set (&tp_map_para);
    for (tp_map_para.lines = 0;
         tp_map_para.lines < 20; tp_map_para.lines++)
    {
        for (tp_map_para.cols = 0;
             tp_map_para.cols < 20; tp_map_para.cols++)
        {

            putchar (tp_map_para.border[tp_map_para.lines][tp_map_para.cols]);

        }
        putchar (10);

    }    
    system("pause");
    return 0;
}
****************************************************/


/***********************
/* void gotoxy(int x, int y)
{

    COORD coord;

    coord.X = x;

    coord.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);       
    //SetConsolecursorposition设置指定控制台屏幕缓冲区中的光标位置 
    //GetStdHandle 检索指定标准设备的句柄
    //((DWORD)-10) 实际上是无符号数 4294967286。

}
void GotoXY(int x, int y)
{
    HANDLE a;
    COORD b;
    fflush(stdout);
    b.X = x;
    b.Y = y;
    a = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(a,b);
} */

************************/

struct coordinate
{
    int x;
    int y;
    time_t* p;
    char food_direction[20][20];
};
typedef struct coordinate t_coordinate, *p_coordinate;

struct snake_state
{
    int x;
    int y;
    int direction;
    int length;
};

typedef struct snake_state t_snake_state, *p_snake_state;


void generate_food (p_coordinate pt_food_coordinate, p_snake_state pt_snake_snake)
{
    if (pt_food_coordinate->x == pt_snake_snake->x 
        && pt_food_coordinate->y == pt_snake_snake->y)
    {
        pt_snake_snake->length++;
        time_t random_value;
        random_value = time(pt_food_coordinate->p);
        srand(random_value);
        pt_food_coordinate->x = rand() % 19;
        pt_food_coordinate->y = rand() % 19;
        pt_food_coordinate->food_direction[pt_food_coordinate->x][pt_food_coordinate->y] = 'M';

    }
    //缺少初始位置的食物


}

void pre_generate_food (p_coordinate pt_food_coordinate)
{
    pt_food_coordinate->x = 0;
    pt_food_coordinate->y = 0;
    pt_food_coordinate->food_direction[20][20] = 0;    //初始化二维数组应该做循环，考虑下是否该初始化
}

void pre_snake_state (p_snake_state pt_snake_snake)
{
    pt_snake_snake->x = 0;
    pt_snake_snake->y = 0;
    pt_snake_snake->length = 0;
    pt_snake_snake->direction = 0;
}


t_coordinate food;
t_snake_state snake_head;

int main ()
{
    pre_generate_food (&food);
    pre_snake_state (&snake_head);
    generate_food (&food, &snake_head);
    putchar (food.food_direction[food.x][food.y]);
    // int i;
    // srand((int)time(0));
    // for( i = 0; i < 10; i++ )
    //     printf( "Random number #%d: %d\n", i, rand() ); 
    system ("pause");
    return 0;
}
