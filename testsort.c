#include <stdio.h>

// void bubble_sort(int arr[], int sz)
// {
//     // 确定冒泡排序的趟数
//     int i = 0;
//     for (i = 0; i < sz - 1; i++)
//     {
//         int flag = 1; //假设这一次要排序的数据以及有序
//         // 每一趟冒泡排序的内容
//         int j = 0;
//         for (j = 0; j < sz - 1 - i; j++)
//         {
//             if (arr[j] > arr[j + 1])
//             {
//                 int temp = 0;
//                 temp = arr[j + 1];
//                 arr[j + 1] = arr[j];
//                 arr[j] = temp;
//                 flag = 0; //本次排序的数据不完全有序
//             }
//         }
//         if (flag == 1)
//         {
//             break;
//         }
//     }
// }

// int main()
// {
//     int i = 0;
//     int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
//     int sz = sizeof(arr) / sizeof(arr[0]);
//     bubble_sort(arr, sz);
//     for (i = 0; i < sz; i++)
//     {
//         printf("%d ", arr[i]);
//     }

//     return 0;
// }

// 求数二进制中的1个数的高效算法

int main()
{
    int count = 0;
    int a = 0;
    scanf("%d", &a);
    while (a)
    {
        a = a & (a - 1);
        count++;
    }
    printf("%d", count);
}