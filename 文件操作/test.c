#include <stdio.h>

// int main()
// {
//     // FILE *p = fopen("a.txt", "w");
//     FILE *p = fopen("a.txt", "r");
//     if (p == NULL)
//     {
//         perror("file");
//         return 1;
//     }

//     // 写文件
//     // fputc('h', p);
//     // fputc('e', p);
//     // fputc('l', p);
//     // fputc('l', p);
//     // fputc('o', p);

//     //读文件
// // 使用fgetc从文件流读取信息
//     int ret = fgetc(p);
//     printf("%c\n", ret);
//     ret = fgetc(p);
//     printf("%c\n", ret);
//     ret = fgetc(p);
//     printf("%c\n", ret);

//     fclose(p);
//     p = NULL;

//     return 0;
// }

// 使用fgetc从标准输入流读取
// int main()
// {
//     int ret = fgetc(stdin);
//     printf("%c\n", ret);
//     ret = fgetc(stdin);
//     printf("%c\n", ret);
//     ret = fgetc(stdin);
//     printf("%c\n", ret);
//     return 0;
// }

// int main()
// {
//     // FILE *p = fopen("a.txt", "w");
//     FILE *p = fopen("a.txt", "r");

//     if (p == NULL)
//     {
//         perror("file");
//         return 1;
//     }

//     // 写文件-按照行来写
//     // fputs("abcdef\n", p);
//     // fputs("123456", p);

//     // 读一行
//     char arr[10] = {0};
//     fgets(arr, 5, p);
//     printf("%s\n", arr);
//     fgets(arr, 5, p);
//     printf("%s\n", arr);

//     fclose(p);
//     p = NULL;

//     return 0;
// }

typedef struct S
{
    char name[10];
    int age;
    float f;
} s;

int main()
{
    s s1 = {"abcde", 20, 5.5f};
    FILE *p = fopen("a.txt", "w");
    if (p == NULL)
    {
        perror("FILE");
        return 1;
    }
    // 写文件
    fprintf(p, "%s %d %f", s1.name, s1.age, s1.f);
    // 读文件
    // fscanf(p, "%s %d %f", s1.name, &(s1.age), (s1.f));

    fclose(p);
    p = NULL;

    return 0;
}
