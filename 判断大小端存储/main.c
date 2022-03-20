#include <stdio.h>

int check_sys(void)
{
    int a = 1;
    // 返回1，小端
    // 返回2，大端
    return *(char *)&a;
}

int main()
{
    // 编写一段代码，告诉我们当前机器的字节序是什么
    // 返回1小端
    // 返回0大端
    int ret = check_sys();
    if (ret == 1)
    {
        printf("小端存储\n");
    }
    else
    {
        printf("大端存储\n");
    }
    return 0;
}
