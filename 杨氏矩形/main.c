#include <stdio.h>

// int Find_num(int arr[3][3], int r, int c, int num)
// {
//     int x = 0;
//     int y = c - 1;
//     while (x < r && y >= 0)
//     {
//         if (arr[x][y] < num)
//         {
//             x++;
//         }
//         else if (arr[x][y] > num)
//         {
//             y--;
//         }
//         else
//         {
//             printf("x= %d y= %d", x, y);
//             return 1;
//         }
//     }
// }

int Find_num(int arr[3][3], int *px, int *py, int num)
{
    int x = 0;
    int y = *py - 1;
    while (x < *px && y >= 0)
    {
        if (arr[x][y] < num)
        {
            x++;
        }
        else if (arr[x][y] > num)
        {
            y--;
        }
        else
        {
            *px = x;
            *py = y;
            return 1;
        }
    }
    return 0;
}

int main()
{
    int arr[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int num = 9;
    int x = 3; //��
    int y = 3; //��
    // &x,&y
    // 1.�������
    // 2.����ֵ
    int ret = Find_num(arr, &x, &y, num);
    if (ret == 1)
    {
        printf("�ҵ���\n");
        printf("�±�Ϊ: %d, %d", x, y);
    }
    else
    {
        printf("û���ҵ�\n");
    }
}