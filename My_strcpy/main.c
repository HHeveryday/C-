#include <stdio.h>
#include <assert.h>
/*
// 初始：
void My_strcpy(char *dest, char *src)
{
    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = *src;
}
// 优化1
void My_strcpy(char *dest, char *src)
{
    while (*src != '\0')
    {
        *dest++ = *src++;
    }
    *dest = *src;
}

// 优化2
void My_strcpy(char *dest, char *src)
{
    while (*dest++ = *src++)
    {
        ;
    }
}
// 优化3
void My_strcpy(char *dest, char *src)
{
    if (dest != NULL && src != NULL) //防止了因为传入空指针导致程序崩溃，但是不利于发现传参数时出现的问题
    {
        while (*dest++ = *src++)
        {
            ;
        }
    }
}

// 优化4
void My_strcpy(char *dest, char *src)
{
    assert(dest != NULL && src != NULL); //断言

    while (*dest++ = *src++)
    {
        ;
    }
}
*/
// 优化5
// const放在指针变量*的左边时，修饰的是*p,也就是说不能通过p来改变*p（num）的值
// const放在指针变量*的右边边时，修饰的是指针变量本身p,p不能被改变
// 增加返回值实现了链式访问
char *My_strcpy(char *dest, const char *src) //表示src指向的对象不能被改变，保证了进行复制时源不能被改变，增加的代码的健壮性
{
    char *ret = dest;
    assert(dest != NULL && src != NULL); //断言
                                         // 把src指向的字符串拷贝到dest指向的空间，包含'\0'字符
    while (*dest++ = *src++)
    {
        ;
    }
    return ret;
}

int main()
{
    char arr1[] = "#######################";
    char arr2[] = "hello";
    //实现库函数中的字符串拷贝程序，并具有较好的编程风格
    printf("%s\n", My_strcpy(arr1, arr2));
    return 0;
}
