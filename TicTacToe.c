#pragma execution_character_set("gbk")
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <io.h>
#include <stdlib.h>
#include "TicTacToe.h"

int judge(char i[3][3]) // 8个月前写的判断函数，我自己看不懂了，反正能用就行（
{
	for (int x = 0; x <= 2; x++)
	{
		if (i[x][0] == i[x][1] && i[x][1] == i[x][2] && i[x][2] != '-')
		{
			printf("%cwin\n", i[x][1]);
			system("pause");
			wrank(i[x][1]);
			return 1;
		}
	}
	for (int x = 0; x <= 2; x++)
	{
		if (i[0][x] == i[1][x] && i[1][x] == i[2][x] && i[2][x] != '-')
		{
			printf("%cwin\n", i[1][x]);
			system("pause");
			wrank(i[1][x]);
			return 1;
		}
	}
	if (i[0][0] == i[1][1] && i[1][1] == i[2][2] && i[2][2] != '-')
	{
		printf("%cwin\n", i[1][1]);
		return 3;
		system("pause");
		wrank(i[1][1]);
		return 1;
	}
	if (i[0][2] == i[1][1] && i[1][1] == i[2][0] && i[2][0] != '-')
	{
		printf("%cwin\n", i[1][1]);
		system("pause");
		wrank(i[1][1]);
		return 1;
	}
}
int view(char jg[3][3])
{
	for (int i = 0; i <= 2; i++) //使用三个for循环打印
	{
		printf("%c", jg[i][0]);
	}
	printf("\n");
	for (int i = 0; i <= 2; i++)
	{
		printf("%c", jg[i][1]);
	}
	printf("\n");
	for (int i = 0; i <= 2; i++)
	{
		printf("%c", jg[i][2]);
	}
	printf("\n");
}
int create()
{
	char q[3][3] = {{'-', '-', '-'}, {'-', '-', '-'}, {'-', '-', '-'}}; //二维数组作为棋盘
	view(q);															//打印棋盘的函数
	int x = 0;															//声明坐标变量
	int y = 0;
	int jg;
	for (int i = 0; i <= 3; i++) //少写判断多偷懒
	{
		if (jg != 1)
		{
		A:
			printf("'o'turn\n");
			place(&x, &y);
			if (q[x][y] == '-')
			{
				q[x][y] = 'o';
			}
			else
			{
				printf("Here is a %c.\n", q[x][y]);
				goto A;
			}
			view(q);
			jg = judge(q);
		}
		if (jg != 1)
		{
		B:
			printf("'x'turn\n");
			place(&x, &y);
			if (q[x][y] == '-')
			{
				q[x][y] = 'x';
			}
			else
			{
				printf("Here is a %c.\n", q[x][y]);
				goto B;
			}
			view(q);
			jg = judge(q);
		}
	}
	if (jg != 1)
	{
		printf("'o'turn\n");
		place(&x, &y);
		if (q[x][y] == '-')
		{
			q[x][y] = 'o';
		}
		else
		{
			printf("Here is a %c.\n", q[x][y]);
			goto A;
		}
		view(q);
		jg = judge(q);
	}
	return (jg);
}
int game()
{
	char a;
A:
	scanf("%c", &a); //使用scanf获取输入，类型为字符，为了防止类型为整型时，用户输入字符会无限循环报错
	switch (a)
	{
	case '1':
		if (create() != 1)
			printf("game over\n");
		break;
	case '2':
		printf("aclgh\'s shit\n");
		break;
	case '3':
		rank();
		break;
	case '4':
		return (2);
	default:
		goto A;
	}
}

int main()
{
	printf("Generating integral file......\n");
	if (access("rank.rk", 0)) // access()于io.h中检测rank.rk是否存在，不存在返回1
	{
		FILE *flp = fopen("rank.rk", "w");
		fprintf(flp, "o00x00"); //不存在则创建
		printf("Done!\n");
		fclose(flp);
	}
	else
	{
		printf("Enjoy it!\n"); //存在继续运行
	}
O:
	printf("  _______ _   _______      _______         \n |__   __(_) |__   __|    |__   __|        \n    | |   _  ___| | __ _  ___| | ___   ___ \n    | |  | |/ __| |/ _` |/ __| |/ _ \\ / _ \\\n    | |  | | (__| | (_| | (__| | (_) |  __/\n    |_|  |_|\\___|_|\\__,_|\\___|_|\\___/ \\___|\n");
	printf("***********************************\n***********************************\n");
	printf("**1.start**2.auth**3.rank**4.quit**\n");
	printf("***********************************\n***********************************\n"); // GUI以及游戏图标
	if (game() != 2)
		goto O;
	//调用游戏主函数
	system("pause");
}
