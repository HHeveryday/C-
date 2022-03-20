#include <stdio.h>

void print1(int arr[3][4], int x, int y)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void print2(int (*p)[4], int x, int y)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            // printf("%d ", p[i][j]);
            printf("%d ", *(p[i] + j));
            // printf("%d ", (*(p + i))[j]);
            // printf("%d ", *(*(p + i) + j));
        }
        printf("\n");
    }
}

int main()
{
    int arr[3][4] = {{1, 2, 3, 4}, {2, 3, 4, 5}, {3, 4, 5, 6}};
    print1(arr, 3, 4); //以正常形式打印二维数组中的元素
    print2(arr, 3, 4); //使用数组指针的方式
    return 0;
}
