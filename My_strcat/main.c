#include <stdio.h>
#include <assert.h>

char *My_strcat(char *dest, const char *src)
{
    assert(dest && src);
    // 1. 将目标数组的指针移到\0处
    char *ret = dest;
    while (*dest)
    {
        dest++;
    }
    // 2. 将源的元素复制到目标中
    while (*dest++ = *src++)
    {
        ;
    }
    return ret;
}

int main()
{
    char arr1[] = "hello ";
    char arr2[] = "world";
    // My_strcat(arr1, arr2);
    printf("%s\n", My_strcat(arr1, arr2));
    return 0;
}