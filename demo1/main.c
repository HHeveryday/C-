#include <stdio.h>
#include <string.h>

int main(void)
{
    int *p; // p�Ǹ��������֣�int* ��ʾ��p����ֻ�ܴ洢int���͵ı�����ַ
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
//         printf("����1\n");
//         break;

//     default:
//         printf("������󣡣���");
//         break;
//     }
//     return 0;
// }

// int main(void)
// {
//     int line = 0;
//     while (line < 20000)
//     {
//         printf_s("���Խ��Ϊ  %d\n", line);
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