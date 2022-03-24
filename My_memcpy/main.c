#include <stdio.h>
#include <assert.h>

// 可以拷贝内存不重叠的情况
void *My_memcpy(void *dest, const void *src, size_t num)
{
    assert(dest && src);
    void *ret = dest;
    while (num--)
    {
        *(char *)dest = *(char *)src;
        dest = (char *)dest + 1;
        src = (char *)src + 1;
    }
    return ret;
}

int main()
{
    int i = 0;
    int arr1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arr2[10] = {0};
    My_memcpy(arr2, arr1, 20);
    return 0;
}