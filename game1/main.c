#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define ROW 3
#define COL 3

void Init_Board(char board[ROW][COL], int row, int col)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void Display_Board(char board[ROW][COL], int row, int col)
{
    int i = 0;
    for (i = 0; i < row; i++)
    {
        int j = 0;
        for (j = 0; j < col; j++)
        {
            printf(" %c ", board[i][j]);
            if (j < col - 1)
            {
                printf("|");
            }
        }
        printf("\n");
        if (i < row - 1)
        {
            for (j = 0; j < col; j++)
            {
                printf("---");
                if (j < col - 1)
                {
                    printf("|");
                }
            }
        }
        printf("\n");
    }
}

void menu()
{
    printf("**********************************\n");
    printf("********1.play  0.exit************\n");
    printf("**********************************\n");
}

void Player_Move(char board[ROW][COL], int row, int col)
{
    int x = 0;
    int y = 0;
    printf("����ߣ�\n");
    // �ж���������Ϸ���
    while (1)
    {
        printf("������Ҫ�µ����꣺\n");
        scanf("%d%d", &x, &y);
        if (x >= 1 && x <= row && y >= 1 && y <= col)
        {
            if (board[x - 1][y - 1] == ' ')
            {
                board[x - 1][y - 1] = '*';
                break;
            }
            else
            {
                printf("�����걻ռ��\n");
            }
        }
        else
        {
            printf("����������������룡����\n");
        }
    }
}

void Computer_Move(char board[ROW][COL], int row, int col)
{
    int x = 0;
    int y = 0;
    printf("�����ߣ�\n");

    while (1)
    {
        x = rand() % row;
        y = rand() % col;
        if (board[x][y] == ' ')
        {
            board[x][y] = '#';
            break;
        }
    }
}

int Is_Full(char board[ROW][COL], int row, int col)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (board[i][j] == ' ')
                return 0;
        }
    }
    return 1;
}

char Is_Win(char board[ROW][COL], int row, int col)
{
    int i = 0;
    for (i = 0; i < row; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
        {
            return board[i][1];
        }
    }
    for (i = 0; i < col; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
        {
            return board[1][i];
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
    {
        return board[1][1];
    }
    if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0] != ' ')
    {
        return board[1][1];
    }
    if (1 == Is_Full(board, ROW, COL))
    {
        return 'Q';
    }
    else
    {
        return 'C';
    }
}

void game()
{
    char ret = 0;
    char board[ROW][COL] = {0};
    Init_Board(board, ROW, COL);
    Display_Board(board, ROW, COL);
    while (1)
    {
        Player_Move(board, ROW, COL);
        Display_Board(board, ROW, COL);
        // �ж�����Ƿ�Ӯ
        ret = Is_Win(board, ROW, COL);
        if (ret != 'C')
        {
            break;
        }
        Computer_Move(board, ROW, COL);
        Display_Board(board, ROW, COL);
        ret = Is_Win(board, ROW, COL);
        if (ret != 'C')
        {
            break;
        }
    }
    if (ret == '*')
    {
        printf("���Ӯ������\n");
    }
    else if (ret == '#')
    {
        printf("����Ӯ������\n");
    }
    else
    {
        printf("ƽ�֣�����\n");
    }
}

void test()
{
    int input = 0;
    srand((unsigned int)time(NULL));
    do
    {
        menu();
        printf("��ѡ��->:\n");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            game();
            break;
        case 0:
            printf("�˳���Ϸ\n");
            break;

        default:
            printf("����������������룡����\n");
            break;
        }
    } while (input);
}

int main()
{
    test();
    return 0;
}