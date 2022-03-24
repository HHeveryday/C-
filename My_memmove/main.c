#include <stdio.h>
#include <assert.h>
// 可以处理内存重复的问题
void *My_memmove(void *dest, const void *src, size_t num)
{
    assert(dest && src);
    void *ret = dest;
    if (dest < src) //从前往后拷贝
    {
        while (num--)
        {
            *(char *)dest = *(char *)src;
            dest = (char *)dest + 1;
            src = (char *)src + 1;
        }
    }
    else //从后往前拷贝
    {
        while (num--)
        {
            *((char *)dest + num) = *((char *)src + num);
        }
    }
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    My_memmove(arr + 2, arr, 20);
    return 0;
}