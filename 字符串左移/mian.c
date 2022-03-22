#include <stdio.h>
#include <string.h>
#include <assert.h>
// 解法1
// void String_left_rotate(char *str, int n)
// {
//     int len = strlen(str);
//     int i = 0;
//     for (i = 0; i < n; i++)
//     {
//         int j = 0;
//         int temp = *str; //把左边第一个元素拿出来，然后将后面的字符依次左移一位
//         for (j = 0; j < len - 1; j++)
//         {
//             *(str + j) = *(str + j + 1);
//         }
//         *(str + len - 1) = temp; //左移完成后将第一个元素放在最后
//     }
// }
// 解法2 --> 三步翻转法

// 假设左移n位，则可以分为三步：
// 1.先逆序前n位
// 2.再逆序后面的元素
// 3.最后整体逆序

void reverse(char *left, char *right)
{
    assert(left && right);
    while (left < right)
    {
        char temp = *right;
        *right = *left;
        *left = temp;
        right--;
        left++;
    }
}

void String_left_rotate(char *str, int n)
{
    assert(str);
    int len = strlen(str);
    reverse(str, str + n - 1);
    reverse(str + n, str + len - 1);
    reverse(str, str + len - 1);
}

int main()
{
    char arr[] = "ABCDEF";
    int n = 3;
    String_left_rotate(arr, n);
    printf("%s ", arr);
    return 0;
}