#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "windows.h"
//#include "pro_control_fly.h"
//#include "do_updown.h"


void updown_para_set(char width[14][31], int* fposition, int* ddong, int move)  //鸟向上移动 1，向下移动 0
{
    if  (move)
    {
        //开始，鸟先动
        *fposition -= 1;                   
        if (width[*fposition][7] == '*')               //7是设置的初始坐标   //*是设置的边界样式
        {
            //撞墙记做0
            *ddong = 0;                           
        }
        width[*fposition][7] = 'm';
        width[*fposition + 1][7] = ' ';
    }
    else 
        //开始，鸟先动
        *fposition += 1;                   
        if (width[*fposition][7] == '*')               //7是设置的初始坐标   //*是设置的边界样式
        {
            //撞墙记做0
            *ddong = 0;                           
        }
        width[*fposition][7] = 'm';
        width[*fposition - 1][7] = ' ';

}
int main ()
{
    system ("mode con cols=100 lines=32");
    system("title fly_ggg");
    int wcolumn;
    int wline;
    int ddong;          
    int ddong_value;       
    int fly_value = 0;
    char fly_single;
    char replace = ' ';
    int go_step;
    int gen_wall;
    //int empty_wall = 6;
    int fposition = 7;
    char width[14][31];
    int point = 0;
    int max_point = 0;
   

    //width[fposition][7] = 'm';


    while (replace == ' ')
    {
        for (int wline = 0;wline < 14;wline++)
        {
            for (int wcolumn = 0; wcolumn < 31;wcolumn++)
            {
                width[wline][wcolumn] = ' ';
            }
        }
        //地图布置
        
        //地图边界设计
        for (int wcolumn = 0;wcolumn <= 30;wcolumn++)
        {
            width [0][wcolumn] = '*';
            width [13][wcolumn] = '*';

        }
        int fposition = 7;
        width[fposition][7] = 'm';


        int ddong = 1;
        int ddong_value = 1; 
        int point = 0;
        int empty_wall = 6;


        while (ddong_value == 1)
        {
            system("cls");                  // 每次打印要清屏
            for (int wline = 0;wline < 14;wline++)
            {
                for (int wcolumn = 0; wcolumn < 31;wcolumn++)
                {
                    putchar(width [wline][wcolumn]);
                
                }
                putchar (10);       //打印换行
            }
            printf("\t你的分数：%d\t最高分：%d  ", point, max_point);
            if (ddong == 1)
            {
                printf("按空格键飞");
            }
            else 
            {
                printf("芜湖~~");
            }
            if (fly_value)
            {
                updown_para_set(width, &fposition, &ddong_value, 1);
                fly_value -=1;
            }
            if(kbhit())
            {
                fly_single = getch();
                if (fly_single == ' ')
                {
                    fly_value = 2;
                    ddong = 0;
                }
            }
            else if (go_step % 2 == 0 && fly_value == 0)
            {
                updown_para_set(width, &fposition, &ddong_value, 0);
            }
            if (go_step % 20 == 0)
            {
                gen_wall = rand() % (12 - empty_wall) + 2;
                for (wline = 1;wline < 13; wline++)
                {
                    if (wline < gen_wall || wline >= gen_wall + empty_wall)
                    {
                        width[wline][31] = '*';
                    }
                    else 
                    {
                        width[wline][31] = ' ';
                    }
                }

            }
            for (wcolumn = 0;wcolumn < 31;wcolumn++)                /// 这个for循环 问题很大（缺乏知识点）
            {
                if (width[1][wcolumn] == '*')
                {
                    if (wcolumn == 0)
                    
                        for (wline = 1;wline < 13;wline++)
                        {
                            width[wline][wcolumn] = ' ';
                        }
                    
                    else 
                    {
                        for (wline = 1;wline < 13;wline++)
                        
                            if (width[wline][wcolumn] == '*')               //
                            {
                                width[wline][wcolumn - 1] = '*';
                                width[wline][wcolumn] = ' ';            
                            }
                        
                        if (wcolumn == 7)
                        {
                            point += 1;
                        }
                    }
                }
            }
            max_point = (point > max_point) ? point : max_point;
            if (go_step % 90 == 0)
            {
                empty_wall -= 1;
            }
            go_step += 1;
            Sleep (200);
            // system ("cls");
            // printf ("\n\n\t你鸟没了！\n\n\t你的分数：%d\t最高分：%d\n\n", point, max_point);
            // printf ("\t\t按空格键重新开始");
            // //system ("pause");
            // replace = getch();

        }
        system ("cls");
        printf ("\n\n\t你鸟没了！\n\n\t你的分数：%d\t最高分：%d\n\n", point, max_point);
        printf ("\t\t按空格键重新开始");
        //system ("pause");
        replace = getch();
    }
    return 0;
    // }
    
    // if (ddong)
    // {
    //     ddong_value = 0;
    //     return ddong_value;
    // }
    // else
    // {
    //     ddong_value = 1;
    //     return ddong_value;
    // }
    // if (fly_value)
    // {
    //     updown_para_set(width[14][31], &fposition, &ddong, 1);
    //     fly_value -=1;
    // }
    // if(kbhit())
    // {
    //     fly_single = getch();
    //     if (fly_single == ' ')
    //     {
    //         fly_value = 2;
    //         ddong = 0;
    //     }
    // }
    // else if (go_step % 2 == 0 && fly_value == 0)
    // {
    //     updown_para_set(width[14][31], &fposition, &ddong, 0);
    // }
    // if (go_step % 20 ==0)
    // {
    //     gen_wall = rand() % (12 - empty_wall) + 2;
    //     for (wline = 1;wline < 13; wline++)
    //     {
    //         if (wline < gen_wall || wline > gen_wall + empty_wall)
    //         {
    //             width[wline][31] = '*';
    //         }
    //         else 
    //         {
    //             width[wline][31] = ' ';
    //         }
    //     }

    // }
    // for (wcolumn = 0;wcolumn < 31;wcolumn++)
    // {
    //     if (width[1][wcolumn] == '*')
    //     {
    //         if (wcolumn == 0)
    //         {
    //             for (wline = 0;wline < 13;wline++)
    //             {
    //                 width[wline][wcolumn] = ' ';
    //             }
    //         }
    //         else 
    //         {
    //             for (wline = 0;wline < 13;wline++)
    //             {
    //                 if (width[wline][wcolumn] = '*')
    //                 {
    //                     width[wline][wcolumn - 1] = '*';
    //                     width[wline][wcolumn] = '*';
    //                 }
    //             }
    //             if (wcolumn == 7)
    //             {
    //                 point += 1;
    //             }
    //         }
    //     }
    // }
    // max_point = (point > max_point) ? point : max_point;
    // if (go_step % 90 == 0)
    // {
    //     empty_wall -= 1;
    // }
    // go_step += 1;
    // sleep (200);
    // system ("cls");
	// printf ("\n\n\t你鸟没了！\n\n\t你的分数：%d\t最高分：%d\n\n", point, max_point);
	// printf ("\t\t按空格键重新开始");
    // system ("pause");
    // replace = getch();
    
}