#include <stdio.h>
#include <stdbool.h>
#include <stdbool.h>
#include <stdlib.h>

//定义了一�?数据类型，�?�数�?类型的名字叫做struct Arr，�?�数�?类型�?有三�?成员
struct Arr
{
    int *pBase; //首元素地址
    int len;    //数组能�?�纳的最大元素个�?
    int cnt;    //当前数组的有效元素个�?
};

void init_arr(struct Arr *pArr, int lenth);
bool append_arr(struct Arr *pArr, int val);            //追加
bool insert_arr(struct Arr *pArr, int index, int val); //插入
bool delete_arr(struct Arr *pArr, int index, int *pval);
int get();
bool is_empty(struct Arr *pArr);
bool is_full(struct Arr *pArr);
void sort_arr(struct Arr *pArr);
void show_arr(struct Arr *pArr);
void inversion_arr(struct Arr *pArr); //逆序

int main()
{
    int val = 0;
    struct Arr arr;
    init_arr(&arr, 6);
    append_arr(&arr, 20);
    append_arr(&arr, 63);
    append_arr(&arr, 12);
    append_arr(&arr, 15);
    insert_arr(&arr, 5, 16);
    show_arr(&arr);
    delete_arr(&arr, 4, &val);
    show_arr(&arr);
    printf("%d\n", val);
    inversion_arr(&arr);
    show_arr(&arr);
    printf("=====================\n");
    sort_arr(&arr);
    show_arr(&arr);

    return 0;
}

void init_arr(struct Arr *pArr, int lenth)
{
    pArr->pBase = (int *)malloc(sizeof(int) * 6);
    if (NULL == pArr->pBase)
    {
        printf("动态内存分配失败！\n");
        exit(-1); //终止整个程序
    }
    else
    {
        pArr->len = lenth;
        pArr->cnt = 0;
    }
    return;
}

void show_arr(struct Arr *pArr)
{
    if (is_empty(pArr))
    {
        printf("数组为空！！！");
    }
    else
    {
        for (int i = 0; i < pArr->cnt; i++)
        {
            printf("%d", pArr->pBase[i]);
            printf("\n");
        }
    }
}

bool is_empty(struct Arr *pArr)
{
    if (0 == pArr->cnt)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool is_full(struct Arr *pArr)
{
    if (pArr->len == pArr->cnt)
    {
        return true;
    }
    return false;
}

bool append_arr(struct Arr *pArr, int val)
{
    if (is_full(pArr))
    {
        return false;
    }
    //不满时可以追加
    else
    {
        pArr->pBase[pArr->cnt] = val;
        (pArr->cnt)++;
        return true;
    }
}

bool insert_arr(struct Arr *pArr, int index, int val)
{
    // 1、判�?�?否能够添加元�?
    if (index < 1 || index > pArr->cnt + 1 || is_full(pArr))
    {
        return false;
    }
    else
    {
        // 2、将要插入位�?以及之后的元素往后移一�?位置，从后往�?
        int i = 0;
        for (int i = pArr->cnt - 1; i >= index - 1; i--)
        {
            pArr->pBase[i + 1] = pArr->pBase[i];
        }
        // 3、将要插入的元素放入数组，数组元素个数加一
        pArr->pBase[index - 1] = val;
        pArr->cnt++;
        return true;
    }
}

bool delete_arr(struct Arr *pArr, int index, int *pval)
{
    int i = 0;
    // 1、判断是否可以进行删除操作
    if (is_empty(pArr) || index < 1 || index > pArr->cnt)
    {
        return false;
    }
    // 1 2 3 4 5  [3]
    // 2、将元素从前往后移，便可以实现删除的效果，并将删除的元素保存
    *pval = pArr->pBase[index - 1];
    for (int i = index - 1; i < pArr->cnt - 1; i++)
    {
        pArr->pBase[i] = pArr->pBase[i + 1];
    }
    // 3、元素个数减一
    pArr->cnt--;
    return true;
}

void inversion_arr(struct Arr *pArr)
{
    int left = 0;
    int right = pArr->cnt - 1;
    while (left < right)
    {
        int temp = pArr->pBase[right];
        pArr->pBase[right] = pArr->pBase[left];
        pArr->pBase[left] = temp;
        left++;
        right--;
    }
}

void sort_arr(struct Arr *pArr)
{
    //冒泡排序->升序
    int i, j, temp;
    //趟数
    for (int i = 0; i < pArr->cnt - 1; i++)
    {
        //每一趟
        int flag = 1; //假设此次排序的数据以及完全有序
        for (int j = 0; j < pArr->cnt - i - 1; j++)
        {
            if (pArr->pBase[j] > pArr->pBase[j + 1])
            {
                temp = pArr->pBase[j + 1];
                pArr->pBase[j + 1] = pArr->pBase[j];
                pArr->pBase[j] = temp;
                flag = 0; //说明这一趟排序的数据不完全有序
            }
        }
        if (flag == 1)
        {
            return;
        }
    }
}