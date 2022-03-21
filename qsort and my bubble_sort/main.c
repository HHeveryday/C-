#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Stu
{
    char name[20];
    int age;
};

int cmp_int(const void *e1, const void *e2)
{
    // 比较两个整形值的大小
    return *(int *)e1 - *(int *)e2; //升序
    // return -(*(int *)e1 - *(int *)e2);//降序
}
int cmp_float(const void *e1, const void *e2)
{
    // 比较两个浮点值的大小
    if (*(float *)e1 == *(float *)e2)
    {
        return 0;
    }
    else if (*(float *)e1 > *(float *)e2)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

int cmp_stu_by_age(const void *e1, const void *e2)
{
    return ((struct Stu *)e1)->age - ((struct Stu *)e2)->age;
}

int cmp_stu_by_name(const void *e1, const void *e2)
{
    // 比较字符串，不能直接用大于小于，应该用strcmp
    return strcmp(((struct Stu *)e1)->name, ((struct Stu *)e2)->name);
}

void test1()
{
    int i = 0;
    int arr[] = {1, 5, 6, 8, 7, 4, 3, 2, 9};
    int sz = sizeof(arr) / sizeof(arr[0]);
    qsort(arr, sz, sizeof(arr[0]), cmp_int);
    for (i = 0; i < sz; i++)
    {
        printf("%d ", arr[i]);
    }
}

void test2()
{
    int i = 0;
    float f[] = {9.0, 8.0, 7.0, 6.0, 3.0};
    int sz = sizeof(f) / sizeof(f[0]);
    qsort(f, sz, sizeof(f[0]), cmp_float);
    for (i = 0; i < sz; i++)
    {
        printf("%f ", f[i]);
    }
}

void test3()
{
    struct Stu s[3] = {{"张三", 20}, {"李四", 30}, {"王五", 10}};
    int sz = sizeof(s) / sizeof(s[0]);
    qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);
    // 第一个参数：待排序数组的首元素的地址
    // 第二个参数：待排序数组的元素个数
    // 第三个参数：待排序的每个元素的大小，单位是字节
    // 第四个参数：是函数指针，比较两个元素所用函数的地址-这个函数需要使用者字节实现，
    // 函数指针的两个参数是：待比较的两个元素的地址
}

// -------------------------------------------不使用库函数进行排序--------------------------------------

void Swap(char *buf1, char *buf2, int width)
{
    int i = 0;
    for (i = 0; i < width; i++)
    {
        char temp = *buf1;
        *buf1 = *buf2;
        *buf2 = temp;
        buf1++;
        buf2++;
    }
}

void bubble_sort(void *base, int sz, int width, int (*cmp)(const void *e1, const void *e2))
{
    int i = 0;
    // 每一趟比较的对数
    for (i = 0; i < sz - 1; i++)
    {
        int j = 0;
        for (j = 0; j < sz - 1 - i; j++)
        {
            //两个元素的比较
            if (cmp((char *)base + j * width, (char *)base + (j + 1) * width) > 0)
            {
                // 交换
                Swap((char *)base + j * width, (char *)base + (j + 1) * width, width);
            }
        }
    }
}

void test4()
{
    int arr[] = {1, 5, 6, 8, 7, 4, 3, 2, 9};
    int sz = sizeof(arr) / sizeof(arr[0]);
    // 使用bubble_sort的程序员一定知道自己排序的是什么数据，
    // 就应该知道如何比较待排序数组中的元素
    bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
}

void test5()
{
    struct Stu s[3] = {{"张三", 20}, {"李四", 30}, {"王五", 10}};
    int sz = sizeof(s) / sizeof(s[0]);
    // 使用bubble_sort的程序员一定知道自己排序的是什么数据，
    // 就应该知道如何比较待排序数组中的元素
    bubble_sort(s, sz, sizeof(s[0]), cmp_stu_by_age);
}

int main()
{
    // test1();
    // test2();
    // test3();
    // test4();
    test5();

    return 0;
}