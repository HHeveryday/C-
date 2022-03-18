#include <stdio.h>
#include <string.h>

int main(void)
{
    int *p; // p是个变量名字，int* 表示该p变量只能存储int类型的变量地址
    int i = 10;
    int j;

    p = &i;

    return 0;
}

// int main(void)
// {
//     int day;
//     scanf("%d", &day);
//     switch (day)
//     {
//     case 1:
//         printf("测试1\n");
//         break;

//     default:
//         printf("输入错误！！！");
//         break;
//     }
//     return 0;
// }

// int main(void)
// {
//     int line = 0;
//     while (line < 20000)
//     {
//         printf_s("测试结果为  %d\n", line);
//         line++;
//     }

//     return 0;
// }
// int main()
// {
//     printf("Hello world!!!");
//     return 0;
// }

// int main()
// {
//     int sum = 0, num1 = 0, num2 = 0;
//     scanf("%d%d", &num1, &num2);
//     sum = num1 + num2;
//     printf("sum=%d\n", sum);

//     return 0;
// }