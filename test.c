#include <stdio.h>
#include <string.h>

// int my_strlen(char *str)
// {
//     int count = 0;
//     while (*str != '\0')
//     {
//         count++;
//         str++;
//     }
//     return count;
// }

// 递归方式
// int my_strlen(char *str)
// {
//     if (*str != '\0')
//     {
//         return 1 + my_strlen(str + 1);
//     }
//     else
//         return 0;
// }

// 指针方式
int my_strlen(char *str)
{
    char *start = str;
    char *end = str;
    while (*end != '\0')
    {
        end++;
    }
    return end - start;
}

int main()
{

    char arr[] = "abcdsdsde";

    printf("%d", my_strlen(arr));

    return 0;
}

// int main()
// {
//     char arr[] = "hello world";
//     memset(arr, '*', 5);
//     printf("%s\n", arr);
// }

// void print(int n)
// {
//     if (n > 9)
//     {
//         print(n / 10);
//     }
//     printf("%d\n", n % 10);
// }

// int main()
// {
//     int num = 0;
//     scanf("%d", &num);
//     print(num);
//     return 0;
// }