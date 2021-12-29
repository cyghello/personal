#include "stdio.h"
#include "stdlib.h"
#include "Windows.h"
#include "def_bottom_para.h"

int pretreatment_map_set(p_map_para p_map_para_set)
{
    p_map_para_set->lines = 0;
    p_map_para_set->cols = 0;
    p_map_para_set->border[20][20] = 0;
    system("cls");
    system ("title letgo");
    system ("mode con cols=100 lines=30");
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
                return 1;
            }
            else 
                p_map_para_set->border[p_map_para_set->lines][p_map_para_set->cols] = ' ';
                return 0;
        }

    }    

}
t_map_para tp_map_para;
int main()
{   
    int ret = pretreatment_map_set(&tp_map_para);
    putchar (tp_map_para.border[20][20]);
    system("pause");
    return 0;
}