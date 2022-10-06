#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
int place(int *x, int *y)
{
    int ch;
Z:
    while (1)
    {
        if (_kbhit()) //使用于conio.h中的_kbhit()检测击键
        {
            ch = _getch(); //_getch()获取击键
            switch (ch)    //小键盘数字1-9对应棋盘的9个位置
            {
            case 49:
                *x = 1;
                *y = 3;
                break;
            case 50:
                *x = 2;
                *y = 3;
                break;
            case 51:
                *x = 3;
                *y = 3;
                break;
            case 52:
                *x = 1;
                *y = 2;
                break;
            case 53:
                *x = 2;
                *y = 2;
                break;
            case 54:
                *x = 3;
                *y = 2;
                break;
            case 55:
                *x = 1;
                *y = 1;
                break;
            case 56:
                *x = 2;
                *y = 1;
                break;
            case 57:
                *x = 3;
                *y = 1;
                break;
            default:
                goto Z;
            }
            *x = *x - 1;
            *y = *y - 1;
            return 0;
        }
    }
}

void rank() //计分查看函数
{
    FILE *fp = fopen("rank.rk", "r");
    int o;
    if (fp == NULL)
        perror("Error opening file");
    else
    {
        while (o != EOF)
        {
            o = fgetc(fp);
            if (o == 'o')
            {
                o = (fgetc(fp) - 48) * 10;
                o = o + (fgetc(fp) - 48);
                printf("o total win %d times.\n", o);
            }
            if (o == 'x')
            {
                o = (fgetc(fp) - 48) * 10;
                o = o + (fgetc(fp) - 48);
                printf("x total win %d times.\n", o);
            }
        }
    }
}

void wrank(char t) //积分写入函数
{
    int temp;
    int o;
    int x;
    FILE *fp = fopen("rank.rk", "r");
    if (fp == NULL)
        perror("Error opening file");
    else
    {
        while (temp != EOF)
        {
            temp = fgetc(fp);
            if (temp == 'o')
            {
                o = (fgetc(fp) - 48) * 10; // char类型转int类型
                o = o + (fgetc(fp) - 48);
            }
            if (temp == 'x')
            {
                x = (fgetc(fp) - 48) * 10;
                x = x + (fgetc(fp) - 48);
            }
        }
    }
    if (t == 'o')
    {
        o += 1;
    }
    if (t == 'x')
    {
        x += 1;
    }
    fclose(fp);
    FILE *fp1 = fopen("rank.rk", "w"); //因c水平限制，最多统计两位数的获胜次数
    if (o < 10 && x >= 10)
    {
        fprintf(fp1, "o0%dx%d", o, x);
    }
    if (x < 10 && o >= 10)
    {
        fprintf(fp1, "o%dx0%d", o, x);
    }
    if (x < 10 && o < 10)
    {
        fprintf(fp1, "o0%dx0%d", o, x);
    }
    if (o >= 10 && x >= 10)
    {
        fprintf(fp1, "o%dx%d", o, x);
    }
    fclose(fp1);
}