#include <stdio.h>
#include <assert.h>

int My_strcmp(const char *str1, const char *str2)
{
    assert(str1 && str2);
    while (*str1 == *str2)
    {
        if (*str1 == '\0')
        {
            return 0;
        }
        str1++;
        str2++;
    }
    // if (*str1 > *str2)
    // {
    //     return 1;
    // }
    // else
    // {
    //     return -1;
    // }
    return *str1 - *str2;
}

int main()
{

    char *p = "abcg";
    char *q = "abcf";
    int ret = My_strcmp(p, q);
    if (ret > 0)
    {
        printf("p > q");
    }
    else if (ret < 0)
    {
        printf("p < q");
    }
    else
    {
        printf("p == q");
    }
    return 0;
}