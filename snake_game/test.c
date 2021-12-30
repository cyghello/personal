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



