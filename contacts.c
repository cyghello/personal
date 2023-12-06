#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
//=======================================================================================
#define LENTH 20
char path[20] = "d:\\通讯录.txt";

//-------------------------------------------------------------------------------
typedef struct person //结构体属性
{
    char count[10];       //序号
    char name[LENTH];     //姓名
    char number[LENTH];   //电话号码
    struct person *prior; //前驱指针
    struct person *next;  //后继指针

} node;

void control(int x, int p);
void list();
void faceopration(char a[][60], int w);
void opration(int x);
void controlmain(int x);
//----------------------------------------------------------------------------------
node *head = NULL; //全局变量-头节点
//===================================================================================
void check() //自检函数   标签至首
{
    node *p = head;
    do
    {

        p->count[1] = ' ';
        p->count[2] = ' ';
        // p->number[LENTH-2]=' ';
        // p->number[LENTH-3]=' ';
        if (p->next)
            p = p->next;

    } while (p->next && p->next != head->next);
    if (head->next)
    {
        p = head->next;         //地址
        p->count[1] = 16;
        p->count[2] = 16;
        // p->number[LENTH-2]=17;
        // p->number[LENTH-3]=17;
    }
}
//-----------------------------------------------------------------------------------------------
void filesite() //文件重写
{
    int i = 0;
    node *p = head;

    FILE *fp = fopen(path, "at");
    if (fp)
    {
        while (p->next && p->next != head)
        {
            p = p->next;
            if (0 == i)
                fprintf(fp, "%-4s    %-12s     %-12s\n", "序号", "姓名", "电话号码");
            fprintf(fp, "%-8s      %-12s     %-12s \n", p->count, p->name, p->number);
            i++;
        }
    }
    else
        printf("file  memory error! please check\n");
}
//===============================导航界面的两个函数============================
void face(char a[][80])
{
    int j = 0;
    char x;
    int i = 8, BC = 8; // BC为control实参
    while (x = getch())
    {
        BC = 8;
        if (x == '\r')
        {
            while (a[BC][5] != 16)
                BC = BC + 2;
            controlmain(BC);
        }
        if (x == 'w' || x == 'a')
        {

            if (a[8][5] == 16)
                continue;
            a[i][5] = ' ';
            a[i][6] = ' ';
            a[i][59] = ' ';
            a[i][58] = ' ';
            i = i - 2;
            a[i][5] = 16;
            a[i][6] = 16;
            a[i][59] = 17;
            a[i][58] = 17;
            j = 0;
            system("cls");
            while (j < 20)
                printf("%s\n", a + j++);
        }
        else if (x == 's' || x == 'd')
        {

            if (a[14][5] == 16)
                continue;

            a[i][5] = ' ';
            a[i][6] = ' ';
            a[i][59] = ' ';
            a[i][58] = ' ';
            i = i + 2;
            a[i][5] = 16;
            a[i][6] = 16;
            a[i][59] = 17;
            a[i][58] = 17;
            j = 0;
            system("cls");

            while (j < 20)
                printf("%s\n", a + j++);
        }
        else
            continue;
    }
}
//---------------------------------------------------------------------------
void picture()
{

    int i = 0;

    char a[20][80] = {"\0",                                                                   // 0
                      "\0",                                                                   // 1
                      "\0",                                                                   // 2
                      "\0",                                                                   // 3
                      "           ^^^^^^^^^^^^^^^^^^^^^  欢迎使用    ^^^^^^^^^^^^^^^^^^^^^^", // 4
                      "\0",                                                                   // 5
                      "               请选择要进行的操作：        ",                          // 6
                      "\0",                                                                   // 7
                      "                 浏览全部     <---------->      1           ",         // 8
                      "\0",                                                                   // 9
                      "                 新建用户     <---------->      2           ",         // 10
                      "\0",                                                                   // 11
                      "                 查找用户     <---------->      3           ",         // 12
                      "\0",                                                                   // 13
                      "                 退出程序     <---------->      4           "};        // 14

    a[8][5] = 16;
    a[8][6] = 16;
    a[8][59] = 17;
    a[8][58] = 17;
    while (i < 20)
        printf("%s\n", a + i++);

    face(a);
}

//=====================================================================
void facenode() //节点操作表
{
    node *p = head;
    char x = 'z';
    int AC = 8;

    while (x = getch())
    {

        if (x == '\r')
        {
            p = head->next;
            AC = 1;
            while (p->count[1] != 16)
            {
                AC = AC + 1;
                p = p->next;
            }
            if (p == head)
            {
                controlmain(99);
            } //返回主菜单
            else
                opration(AC); // AC为要修改或删除的节点序号 int型
        }
        if (x == 'w' || x == 'a')
        {

            if (head->next->count[1] == 16)
                continue;
            p->count[1] = ' ';
            p->count[2] = ' ';
            // p->number[LENTH-2]=' ';
            // p->number[LENTH-3]=' ';
            p = p->prior;
            p->count[1] = 16;
            p->count[2] = 16;
            // p->number[LENTH-2]=17;
            // p->number[LENTH-3]=17;

            system("cls");

            list();
        }
        else if (x == 's' || x == 'd')
        {

            if (head->count[1] == 16)
                continue;

            p->count[1] = ' ';
            p->count[2] = ' ';
            // p->number[LENTH-2]=' ';
            // p->number[LENTH-3]=' ';
            p = p->next;

            p->count[1] = 16;
            p->count[2] = 16;
            // p->number[LENTH-2]=17;
            // p->number[LENTH-3]=17;

            system("cls");

            list();
        }
        else
            continue;
    }
}

//-------------------------------------------------------------------------
node *newone() //创建头节点
{
    node *p;
    p = (node *)malloc(sizeof(node));
    memset(p->count, ' ', LENTH);
    p->next = NULL;
    p->prior = NULL;
    return p;
} // newone

//--------------------------------------------------------------------------
void start() //链表初始化
{

    head = newone();
    strcpy(head->name, "返回主菜单");

    memset(head->count, ' ', 5);
    memset(&head->count[5], '\0', 5);
    memset(head->number, '\0', LENTH);
    head->prior = head;
}
//----------------------------------------------------------------------
void creat() //添加新用户
{
    int i = 0, j = 0;
    char x, c;

    char arry[10][40] = {"\0",                               // 0
                         "      要继续新建联系人?         ", // 1
                         "\0",                               // 2
                         "         确认     Y           ",   // 3
                         "\0",                               // 4
                         "         取消     N           ",   // 5
                         "\0"};                              // 6

    node *p;
    node *q, *temp;
    FILE *fp = fopen(path, "at");
    temp = newone();
    p = head->prior;              // P指向最后一个节点
    i = atoi(head->prior->count); //求出最后一个节点的序号，即总数

    arry[3][3] = 16;
    arry[3][4] = 16;
    arry[3][22] = 17;
    arry[3][23] = 17;

    for (;;)
    {
        system("cls");
        printf("\n\n\n\n\n\n\n\n");
        j = 0;
        while (j < 10)
            printf("                      %s\n", arry + j++);

        while (x = getch())
        {
            system("cls");
            printf("\n\n\n\n\n\n\n\n");
            j = 0;
            while (j < 10)
                printf("                      %s\n", arry + j++);

            if (x == '\r')
            {
                if (arry[3][3] == 16)
                {
                    system("cls");
                    memset(temp->name, '\0', LENTH);
                    memset(temp->number, '\0', LENTH);
                    printf("\n\n  请输入姓名和电话:\n");
                    scanf("%s%s", &temp->name, &temp->number);
                    printf("\n\n_________________确定将%s的信息存入通讯录？Y/N________________\n", temp->name);
                    c = getch();
                    if (c == 'y' || c == 'Y')
                    {
                        fp = fopen(path, "at");
                        q = newone();

                        //序号寸入
                        i++;
                        sprintf(&q->count[5], "%d", i);
                        //   sprintf(&head->count[5],"%d",i);
                        //导入姓名与电话
                        strcpy(q->name, temp->name);
                        strcpy(q->number, temp->number);
                        //接入链表
                        p->next = q;
                        q->prior = p;

                        q->next = head;
                        head->prior = q;

                        p = p->next;

                        if (fp)
                        {
                            if (1 == i)
                                fprintf(fp, "%-4s    %-12s     %-12s\n", "序号", "姓名", "电话号码");

                            fprintf(fp, "%-8s      %-12s     %-12s \n", q->count, q->name, q->number);
                            printf("\n\n\n___________________________          已成功导入%s\n", path);
                            fclose(fp);
                            Sleep(1000);
                        }

                        else
                            printf("通讯录文件出错！请检查PATH\n");

                        if (1 == i)
                        {
                            p->count[1] = 16;
                            p->count[2] = 16;
                            p->number[LENTH - 2] = 17;
                            p->number[LENTH - 3] = 17;
                        }
                    }
                }
                if (arry[5][3] == 16)
                {
                    system("cls");
                    picture();
                    break;
                }

            } //    =='\r'

            if (x == 'w' || x == 'a')
            {
                if (arry[3][3] == 16)
                    continue;
                arry[3][3] = 16;
                arry[3][4] = 16;
                arry[3][22] = 17;
                arry[3][23] = 17;

                arry[5][3] = ' ';
                arry[5][4] = ' ';
                arry[5][22] = ' ';
                arry[5][23] = ' ';
                system("cls");

                printf("\n\n\n\n\n\n\n\n");
                j = 0;
                while (j < 10)
                    printf("                      %s\n", arry + j++);
            }
            else if (x == 's' || x == 'd')
            {
                if (arry[5][3] == 16)
                    continue;
                arry[3][3] = ' ';
                arry[3][4] = ' ';
                arry[3][22] = ' ';
                arry[3][23] = ' ';

                arry[5][3] = 16;
                arry[5][4] = 16;
                arry[5][22] = 17;
                arry[5][23] = 17;
                system("cls");
                printf("\n\n\n\n\n\n\n\n");
                j = 0;
                while (j < 10)
                    printf("                      %s\n", arry + j++);
            }
            else
                continue;

        } // while

    } // for

} // creat
//---------------------------------------------------------------------------
void del(int n) //删除用户,n为要删除的节点序号int
{
    node *q = head, *p = head;
    int j = 0;

    while (p != head->prior)
    {

        q = p;
        p = p->next;

        if (atoi(&p->count[5]) == n)
        {

            // sprintf(head->count+5,"%d",i);
            //当删除的为最后一个节点时yy

            if (p->next == head)
            {
                system("title 111");
                q->next = head;
                head->prior = q;
                free(p);
                printf("删除完成!");
                filesite(); //文件重写
                Sleep(500);
                system("cls");
                break;
            }

            //常规删除
            q->next = p->next;
            p->next->prior = p->prior;
            //序号进一

            do
            {

                q = q->next;
                j = atoi(q->count);
                j--;

                sprintf(&q->count[5], "%d", j);

            } while (q->next != head);
            filesite(); //文件重写
            printf("删除完成！\n");
            Sleep(400);
            system("cls");
            break;

        } // if

    } // while

} //  del
//-----------------------------------------------------------------------------
void search() //动态搜索
{

    char test[LENTH] = {"\0"}; //定义测试关键码及长度
    int i = 0;
    char temp; //
    char arr[LENTH] = {"\0"};
    char arrname[LENTH] = {"\0"};
    char num[10] = {"序号"}, name[10] = {"姓名"}, tel[10] = {"电话"};
    node *p = head;
    system("cls");
    printf("\n\n==================================查找===============================\n\n");

    while (i < LENTH)
    {

        p = head;
        system("cls");
        printf("\n\n\n           %s           %-12s               %-12s\n", num, name, tel);
        while (p->next && p->next != head)
        {
            p = p->next;
            memset(arr, '\0', LENTH);
            memset(arrname, '\0', LENTH);
            strncpy(arr, p->number, i);
            strncpy(arrname, p->name, i);
            if (0 == strcmp(arr, test) || 0 == strcmp(arrname, test))
            {
                printf("_______________________________________________________________\n");
                printf("        %s         %12s\n", &p->count[3], p->name);
                printf("                                                 %12s  \n", p->number);
            }
        }

        printf("\n\n=========================查找=============================\n\n");
        puts(test);
        putchar(10);

        temp = getch();
        if (!i && temp == '\b')
            break;
        if (i && temp == '\b')
        {

            test[i - 1] = '\0';
            i = i - 2;
        }
        else if (!i && temp == '\b')
            continue;

        else
        {
            test[i] = temp;
        }

        i++;

    } // while输入
    printf("查找结束\n");
    Sleep(500);
    system("cls");

} // search
//------------------------------------------------------------------------------
void list() //显示全部列表
{

    char num[10] = {"序号"}, name[10] = {"姓名"}, tel[10] = {"电话"};
    node *p;
    char x;
    putchar(10);
    putchar(10);
    p = head;

    if (!p->next)
    {
        printf("\n\n\n_______________ 通讯录目前为空！   是否开始新建? Y/N _________________\n\n");
        x = getch();
        if (x == 'Y' || x == 'y')
        {
            system("cls");
            creat();
        }
        else
        {
            system("cls");
            picture();
        }
    }
    else
    {
        printf("          %s              %-12s                %-12s\n\n", num, name, tel);
        do
        {
            p = p->next;
            printf("_______________________________________________________________\n");
            printf("        %s         %12s\n", p->count, p->name);
            printf("                                                 %12s  \n", p->number);

        } while (p->next && p->next != head->next);
        printf("_______________________________________________________________\n");
        printf("\n     共计%s   个人信息！\n\n", &head->prior->count[3]);
    }

} // list
//-------------------------------总控制台------------------------------------------

void control(int x, int p) // X为操作类型,P为操作码（int）
{
    char temp[LENTH] = {'\0'};
    char c;
    // char pchar[LENTH]={'\0'};

    node *q = head;
    // sprintf(pchar,"%s",p);
    /*
    if(p!=atoi(pchar))
    {
        printf("need debug!!!  please check!\n ");
        Sleep(100000);
    }
    */
    q = head;

    while (atoi(&q->count[5]) != p) //目标节点定位
    {
        q = q->next;
    }
    switch (x)
    {

    case 21: //修改用户姓名
    {
        printf("请输入新的用户名：\n");
        scanf("%s", temp);

        printf("\n确定修改名为%s的用户信息? Y/N\n", q->name);
        c = getch();
        if (c == 'Y' || c == 'y')
        {

            memset(q->name, '\0', LENTH);
            strcpy(q->name, temp);
            filesite(); //文件重写
            printf("修改成功！\n");
            Sleep(500);
            check();
            system("cls");

            list();
            facenode();
        }
        else
        {
            printf("放弃存入！\n");
            Sleep(500);
            check();
            system("cls");
            check();
            list();
            facenode();
        }

        break;
    }
    case 23: //修改用户电话号码
    {
        printf("请输入新的电话号码：\n");
        scanf("%s", temp);
        printf("\n确定修改名为%s的用户信息? Y/N\n", q->name);
        c = getch();
        if (c == 'Y' || c == 'y')
        {

            memset(q->number, '\0', LENTH);
            strcpy(q->number, temp);
            filesite(); //文件重写
            printf("修改成功！\n");
            Sleep(500);
            check();
            system("cls");

            list();
            facenode();
        }
        else
        {
            printf("放弃存入！\n");
            Sleep(500);
            check();
            system("cls");

            list();
            facenode();
        }
        break;
    }
    case 25:
        del(p);
        check();
        list();
        facenode();
        break;
    //----------------------------以上为单个用户的修改删除----------------------------------------------
    //返回当前列表
    case 27:
    {
        check();
        system("cls");
        list();
        facenode();
        break;
    }
    default:
        printf("error!\n");
        break;
    }
}
//-----------------------------------------------------------------------
void controlmain(int x) //主菜单对应的功能
{
    switch (x)
    {
    case 8:
        check();
        list();
        system("cls");
        check();
        list();
        facenode();
        break;
    case 10:
        creat();
        system("cls");
        picture();
        break;
    case 12:
        search();
        picture();
        break;
    case 14:
        exit(0);
        break;
    case 99:
        system("cls");
        picture();
        break;
    default:
        printf("\n12345678\n");
        break;

    } //-------------------------以上为主导航界面需要--20以内-------------------------------------
}
//-----------------------------------------------------------------------
void opration(int p) //单个用户对应的操作         由facenode()调用
{
    int i = 0;
    char arr[8][60] = {
        "\0",                     // 0
        "    修改该用户姓名    ", // 1
        "\0",                     // 2
        "    修改该用户电话    ", // 3
        "\0",                     // 4
        "    删除该用户资料    ", // 5
        "\0",                     // 6
        "         返回         ", // 7
    };
    printf("\n\n______________________________________________________\n");
    arr[1][1] = 16;
    arr[1][2] = 16;
    arr[1][19] = 17;
    arr[1][20] = 17;
    system("cls");
    printf("\n\n\n\n\n\n\n\n                    您想做什么?\n\n");
    while (i < 8)
        printf("                    %s\n", arr[i++]);
    faceopration(arr, p); // p为要修改或删除节点序号,int类型，由facenode()中调用opration()函数传入
}
void faceopration(char a[][60], int p) //节点操作表
{
    int j = 0;
    char x = 'z';
    int i = 1, CC = 1;

    while (x = getch())
    {

        if (x == '\r')
        {
            CC = 1;
            while (a[CC][1] != 16)
            {

                CC = CC + 2;
            }
            control(CC + 20, p); // CC为操作码，P为要修改删除的节点序号int型由AC计数传入
        }
        if (x == 'w' || x == 'a')
        {

            if (a[1][1] == 16)
                continue;
            a[i][1] = ' ';
            a[i][2] = ' ';
            a[i][19] = ' ';
            a[i][20] = ' ';
            i = i - 2;
            a[i][1] = 16;
            a[i][2] = 16;
            a[i][19] = 17;
            a[i][20] = 17;
            j = 0;
            system("cls");

            printf("\n\n\n\n\n\n\n\n                    您想做什么?\n\n");
            while (j < 8)
            {

                printf("                    %s\n", a + j++);
            }
        }
        else if (x == 's' || x == 'd')
        {

            if (a[7][1] == 16)
                continue;
            a[i][1] = ' ';
            a[i][2] = ' ';
            a[i][19] = ' ';
            a[i][20] = ' ';
            i = i + 2;
            a[i][1] = 16;
            a[i][2] = 16;
            a[i][19] = 17;
            a[i][20] = 17;

            j = 0;
            system("cls");

            printf("\n\n\n\n\n\n\n\n                    您想做什么?\n\n");
            while (j < 8)
            {

                printf("                    %s\n", a + j++);
            }
        }
        else
            continue;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    system("title 通讯录       --by Giant");
    start();
    picture();
    return 0;
}