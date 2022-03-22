#include <stdio.h>
#include <string.h>
#include <assert.h>
int Is_string_rotate(char *str1, char *str2)
{
    assert(str1 && str2);
    if (strlen(str1) != strlen(str2))
    {
        return 0;
    }
    // 1.将字符串1复制一次:ABCDEFABCDEF,要是arr2可以移动得到aar1,则arr2必定为arr1的子字符串
    int len = strlen(str1);
    strncat(str1, str1, len);
    // 2.调用库函数比较str2是否为改变后str1的子串
    char *ret = strstr(str1, str2);
    return ret != NULL;
}

int main()
{
    char arr1[20] = "ABCDEF";
    char arr2[] = "DEFABC";
    int flag = Is_string_rotate(arr1, arr2);
    if (flag == 1)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}