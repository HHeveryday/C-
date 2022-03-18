#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 9
#define COL 9
#define ROWS ROW + 2
#define COLS COL + 2
#define EASY_COUNT 80

void Init_Board(char board[ROWS][COLS], int rows, int cols, char set)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            board[i][j] = set;
        }
    }
}

void Display_Board(char board[ROWS][COLS], int row, int col)
{
    int i = 0;
    int j = 0;
    // 打印列号
    for (i = 0; i <= col; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
    for (i = 1; i <= row; i++)
    {
        printf("%d ", i); //打印行号
        for (j = 1; j <= col; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void Set_Mine(char board[ROWS][COLS], int row, int col)
{
    int count = EASY_COUNT;
    while (count)
    {
        int x = rand() % row + 1; // 1 - 9
        int y = rand() % col + 1;
        if (board[x][y] == '0')
        {
            board[x][y] = '1';
            count--;
        }
    }
}

int Get_Mine_Count(char mine[ROWS][COLS], int x, int y)
{
    return mine[x - 1][y] +
           mine[x - 1][y - 1] +
           mine[x][y - 1] +
           mine[x + 1][y - 1] +
           mine[x + 1][y] +
           mine[x + 1][y + 1] +
           mine[x][y + 1] +
           mine[x - 1][y + 1] - 8 * '0';
}

void Find_Mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
    int x = 0;
    int y = 0;
    int flag = 0;
    while (flag < row * col - EASY_COUNT)
    {
        printf("请输入排查雷的坐标：\n");
        scanf("%d%d", &x, &y);
        if (x >= 1 && x <= row && y >= 1 && y <= col)
        {
            // 坐标合法
            // 1.踩雷
            if (mine[x][y] == '1')
            {
                printf("很遗憾，踩雷了！！！");
                Display_Board(show, row, col);
                break;
            }
            else //没有踩雷
            {
                // 计算x，y坐标周围有几个雷
                int counts = Get_Mine_Count(mine, x, y);
                show[x][y] = counts + '0';
                Display_Board(show, row, col);
                flag++;
            }
        }
        else
        {
            printf("输入坐标非法，请重新输入！！！\n");
        }
    }
    if (flag == row * col - EASY_COUNT)
    {
        printf("恭喜你，排查成功！！！\n");
        Display_Board(mine, row, col);
    }
}

void game()
{
    // 雷的信息存储
    // 1.布置好雷的信息
    char mine[ROWS][COLS] = {0};
    // 2.排查出雷的信息
    char show[ROWS][COLS] = {0};
    // 初始化
    Init_Board(mine, ROWS, COLS, '0');
    Init_Board(show, ROWS, COLS, '*');
    // 打印棋盘
    // Display_Board(mine, ROW, COL);
    Display_Board(show, ROW, COL);

    // 布置雷
    Set_Mine(mine, ROW, COL);
    Display_Board(mine, ROW, COL);

    // 扫雷
    Find_Mine(mine, show, ROW, COL);
}

void menu()
{
    printf("*****************************************\n");
    printf("**********      1. play    **************\n");
    printf("**********      0. exit    **************\n");
    printf("*****************************************\n");
}

void test()
{
    srand((unsigned int)time(NULL));

    int input = 0;
    do
    {
        menu();
        printf("请选择：");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            game();
            break;
        case 0:
            printf("退出游戏\n");
            break;

        default:
            printf("输入错误，请重新输入！！！\n");
            break;
        }
    } while (input);
}

int main()
{
    test();
    return 0;
}