#include <stdio.h>
#include <assert.h>

int My_strlen(const char *p)
{
    assert(p != NULL); //保证指针的有效性
    int count = 0;
    while (*p != '\0')
    {
        p++;
        count++;
    }

    return count;
}

int main()
{
    char arr[] = "1a661516husgudhidsef";
    printf("%d", My_strlen(arr));
    return 0;
}