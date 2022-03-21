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
    // �Ƚ���������ֵ�Ĵ�С
    return *(int *)e1 - *(int *)e2; //����
    // return -(*(int *)e1 - *(int *)e2);//����
}
int cmp_float(const void *e1, const void *e2)
{
    // �Ƚ���������ֵ�Ĵ�С
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
    // �Ƚ��ַ���������ֱ���ô���С�ڣ�Ӧ����strcmp
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
    struct Stu s[3] = {{"����", 20}, {"����", 30}, {"����", 10}};
    int sz = sizeof(s) / sizeof(s[0]);
    qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);
    // ��һ���������������������Ԫ�صĵ�ַ
    // �ڶ��������������������Ԫ�ظ���
    // �������������������ÿ��Ԫ�صĴ�С����λ���ֽ�
    // ���ĸ��������Ǻ���ָ�룬�Ƚ�����Ԫ�����ú����ĵ�ַ-���������Ҫʹ�����ֽ�ʵ�֣�
    // ����ָ������������ǣ����Ƚϵ�����Ԫ�صĵ�ַ
}

// -------------------------------------------��ʹ�ÿ⺯����������--------------------------------------

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
    // ÿһ�˱ȽϵĶ���
    for (i = 0; i < sz - 1; i++)
    {
        int j = 0;
        for (j = 0; j < sz - 1 - i; j++)
        {
            //����Ԫ�صıȽ�
            if (cmp((char *)base + j * width, (char *)base + (j + 1) * width) > 0)
            {
                // ����
                Swap((char *)base + j * width, (char *)base + (j + 1) * width, width);
            }
        }
    }
}

void test4()
{
    int arr[] = {1, 5, 6, 8, 7, 4, 3, 2, 9};
    int sz = sizeof(arr) / sizeof(arr[0]);
    // ʹ��bubble_sort�ĳ���Աһ��֪���Լ��������ʲô���ݣ�
    // ��Ӧ��֪����αȽϴ����������е�Ԫ��
    bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
}

void test5()
{
    struct Stu s[3] = {{"����", 20}, {"����", 30}, {"����", 10}};
    int sz = sizeof(s) / sizeof(s[0]);
    // ʹ��bubble_sort�ĳ���Աһ��֪���Լ��������ʲô���ݣ�
    // ��Ӧ��֪����αȽϴ����������е�Ԫ��
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