#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
//=======================================================================================
#define LENTH 20
char path[20] = "d:\\ͨѶ¼.txt";

//-------------------------------------------------------------------------------
typedef struct person //�ṹ������
{
    char count[10];       //���
    char name[LENTH];     //����
    char number[LENTH];   //�绰����
    struct person *prior; //ǰ��ָ��
    struct person *next;  //���ָ��

} node;

void control(int x, int p);
void list();
void faceopration(char a[][60], int w);
void opration(int x);
void controlmain(int x);
//----------------------------------------------------------------------------------
node *head = NULL; //ȫ�ֱ���-ͷ�ڵ�
//===================================================================================
void check() //�Լ캯��   ��ǩ����
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
        p = head->next;         //��ַ
        p->count[1] = 16;
        p->count[2] = 16;
        // p->number[LENTH-2]=17;
        // p->number[LENTH-3]=17;
    }
}
//-----------------------------------------------------------------------------------------------
void filesite() //�ļ���д
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
                fprintf(fp, "%-4s    %-12s     %-12s\n", "���", "����", "�绰����");
            fprintf(fp, "%-8s      %-12s     %-12s \n", p->count, p->name, p->number);
            i++;
        }
    }
    else
        printf("file  memory error! please check\n");
}
//===============================�����������������============================
void face(char a[][80])
{
    int j = 0;
    char x;
    int i = 8, BC = 8; // BCΪcontrolʵ��
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
                      "           ^^^^^^^^^^^^^^^^^^^^^  ��ӭʹ��    ^^^^^^^^^^^^^^^^^^^^^^", // 4
                      "\0",                                                                   // 5
                      "               ��ѡ��Ҫ���еĲ�����        ",                          // 6
                      "\0",                                                                   // 7
                      "                 ���ȫ��     <---------->      1           ",         // 8
                      "\0",                                                                   // 9
                      "                 �½��û�     <---------->      2           ",         // 10
                      "\0",                                                                   // 11
                      "                 �����û�     <---------->      3           ",         // 12
                      "\0",                                                                   // 13
                      "                 �˳�����     <---------->      4           "};        // 14

    a[8][5] = 16;
    a[8][6] = 16;
    a[8][59] = 17;
    a[8][58] = 17;
    while (i < 20)
        printf("%s\n", a + i++);

    face(a);
}

//=====================================================================
void facenode() //�ڵ������
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
            } //�������˵�
            else
                opration(AC); // ACΪҪ�޸Ļ�ɾ���Ľڵ���� int��
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
node *newone() //����ͷ�ڵ�
{
    node *p;
    p = (node *)malloc(sizeof(node));
    memset(p->count, ' ', LENTH);
    p->next = NULL;
    p->prior = NULL;
    return p;
} // newone

//--------------------------------------------------------------------------
void start() //�����ʼ��
{

    head = newone();
    strcpy(head->name, "�������˵�");

    memset(head->count, ' ', 5);
    memset(&head->count[5], '\0', 5);
    memset(head->number, '\0', LENTH);
    head->prior = head;
}
//----------------------------------------------------------------------
void creat() //������û�
{
    int i = 0, j = 0;
    char x, c;

    char arry[10][40] = {"\0",                               // 0
                         "      Ҫ�����½���ϵ��?         ", // 1
                         "\0",                               // 2
                         "         ȷ��     Y           ",   // 3
                         "\0",                               // 4
                         "         ȡ��     N           ",   // 5
                         "\0"};                              // 6

    node *p;
    node *q, *temp;
    FILE *fp = fopen(path, "at");
    temp = newone();
    p = head->prior;              // Pָ�����һ���ڵ�
    i = atoi(head->prior->count); //������һ���ڵ����ţ�������

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
                    printf("\n\n  �����������͵绰:\n");
                    scanf("%s%s", &temp->name, &temp->number);
                    printf("\n\n_________________ȷ����%s����Ϣ����ͨѶ¼��Y/N________________\n", temp->name);
                    c = getch();
                    if (c == 'y' || c == 'Y')
                    {
                        fp = fopen(path, "at");
                        q = newone();

                        //��Ŵ���
                        i++;
                        sprintf(&q->count[5], "%d", i);
                        //   sprintf(&head->count[5],"%d",i);
                        //����������绰
                        strcpy(q->name, temp->name);
                        strcpy(q->number, temp->number);
                        //��������
                        p->next = q;
                        q->prior = p;

                        q->next = head;
                        head->prior = q;

                        p = p->next;

                        if (fp)
                        {
                            if (1 == i)
                                fprintf(fp, "%-4s    %-12s     %-12s\n", "���", "����", "�绰����");

                            fprintf(fp, "%-8s      %-12s     %-12s \n", q->count, q->name, q->number);
                            printf("\n\n\n___________________________          �ѳɹ�����%s\n", path);
                            fclose(fp);
                            Sleep(1000);
                        }

                        else
                            printf("ͨѶ¼�ļ���������PATH\n");

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
void del(int n) //ɾ���û�,nΪҪɾ���Ľڵ����int
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
            //��ɾ����Ϊ���һ���ڵ�ʱyy

            if (p->next == head)
            {
                system("title 111");
                q->next = head;
                head->prior = q;
                free(p);
                printf("ɾ�����!");
                filesite(); //�ļ���д
                Sleep(500);
                system("cls");
                break;
            }

            //����ɾ��
            q->next = p->next;
            p->next->prior = p->prior;
            //��Ž�һ

            do
            {

                q = q->next;
                j = atoi(q->count);
                j--;

                sprintf(&q->count[5], "%d", j);

            } while (q->next != head);
            filesite(); //�ļ���д
            printf("ɾ����ɣ�\n");
            Sleep(400);
            system("cls");
            break;

        } // if

    } // while

} //  del
//-----------------------------------------------------------------------------
void search() //��̬����
{

    char test[LENTH] = {"\0"}; //������Թؼ��뼰����
    int i = 0;
    char temp; //
    char arr[LENTH] = {"\0"};
    char arrname[LENTH] = {"\0"};
    char num[10] = {"���"}, name[10] = {"����"}, tel[10] = {"�绰"};
    node *p = head;
    system("cls");
    printf("\n\n==================================����===============================\n\n");

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

        printf("\n\n=========================����=============================\n\n");
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

    } // while����
    printf("���ҽ���\n");
    Sleep(500);
    system("cls");

} // search
//------------------------------------------------------------------------------
void list() //��ʾȫ���б�
{

    char num[10] = {"���"}, name[10] = {"����"}, tel[10] = {"�绰"};
    node *p;
    char x;
    putchar(10);
    putchar(10);
    p = head;

    if (!p->next)
    {
        printf("\n\n\n_______________ ͨѶ¼ĿǰΪ�գ�   �Ƿ�ʼ�½�? Y/N _________________\n\n");
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
        printf("\n     ����%s   ������Ϣ��\n\n", &head->prior->count[3]);
    }

} // list
//-------------------------------�ܿ���̨------------------------------------------

void control(int x, int p) // XΪ��������,PΪ�����루int��
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

    while (atoi(&q->count[5]) != p) //Ŀ��ڵ㶨λ
    {
        q = q->next;
    }
    switch (x)
    {

    case 21: //�޸��û�����
    {
        printf("�������µ��û�����\n");
        scanf("%s", temp);

        printf("\nȷ���޸���Ϊ%s���û���Ϣ? Y/N\n", q->name);
        c = getch();
        if (c == 'Y' || c == 'y')
        {

            memset(q->name, '\0', LENTH);
            strcpy(q->name, temp);
            filesite(); //�ļ���д
            printf("�޸ĳɹ���\n");
            Sleep(500);
            check();
            system("cls");

            list();
            facenode();
        }
        else
        {
            printf("�������룡\n");
            Sleep(500);
            check();
            system("cls");
            check();
            list();
            facenode();
        }

        break;
    }
    case 23: //�޸��û��绰����
    {
        printf("�������µĵ绰���룺\n");
        scanf("%s", temp);
        printf("\nȷ���޸���Ϊ%s���û���Ϣ? Y/N\n", q->name);
        c = getch();
        if (c == 'Y' || c == 'y')
        {

            memset(q->number, '\0', LENTH);
            strcpy(q->number, temp);
            filesite(); //�ļ���д
            printf("�޸ĳɹ���\n");
            Sleep(500);
            check();
            system("cls");

            list();
            facenode();
        }
        else
        {
            printf("�������룡\n");
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
    //----------------------------����Ϊ�����û����޸�ɾ��----------------------------------------------
    //���ص�ǰ�б�
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
void controlmain(int x) //���˵���Ӧ�Ĺ���
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

    } //-------------------------����Ϊ������������Ҫ--20����-------------------------------------
}
//-----------------------------------------------------------------------
void opration(int p) //�����û���Ӧ�Ĳ���         ��facenode()����
{
    int i = 0;
    char arr[8][60] = {
        "\0",                     // 0
        "    �޸ĸ��û�����    ", // 1
        "\0",                     // 2
        "    �޸ĸ��û��绰    ", // 3
        "\0",                     // 4
        "    ɾ�����û�����    ", // 5
        "\0",                     // 6
        "         ����         ", // 7
    };
    printf("\n\n______________________________________________________\n");
    arr[1][1] = 16;
    arr[1][2] = 16;
    arr[1][19] = 17;
    arr[1][20] = 17;
    system("cls");
    printf("\n\n\n\n\n\n\n\n                    ������ʲô?\n\n");
    while (i < 8)
        printf("                    %s\n", arr[i++]);
    faceopration(arr, p); // pΪҪ�޸Ļ�ɾ���ڵ����,int���ͣ���facenode()�е���opration()��������
}
void faceopration(char a[][60], int p) //�ڵ������
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
            control(CC + 20, p); // CCΪ�����룬PΪҪ�޸�ɾ���Ľڵ����int����AC��������
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

            printf("\n\n\n\n\n\n\n\n                    ������ʲô?\n\n");
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

            printf("\n\n\n\n\n\n\n\n                    ������ʲô?\n\n");
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
    system("title ͨѶ¼       --by Giant");
    start();
    picture();
    return 0;
}