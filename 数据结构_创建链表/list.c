#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;           //数据域
    struct Node *pNext; //指针域
} NODE, *PNODE;

PNODE creat_list(void);
void traverse_list(PNODE pHead);
bool is_empty(PNODE pHead);
int insert_list(PNODE);
int lenght_list(PNODE pHead);
bool delete_list(PNODE);
void sort_list(PNODE);

int main()
{
    PNODE pHead = NULL;
    pHead = creat_list(); //创建一个非循环单链表，并将该链表的头节点的地址返回
    traverse_list(pHead); //遍历链表

    // if (is_empty(pHead))
    //     printf("链表为空！！！\n");
    // else
    //     printf("链表不为空！！！\n");

    // printf("链表的长度为：%d", lenght_list(pHead));//求链表的长度
    return 0;
}

//创建链表
PNODE creat_list(void)
{
    int len;   //链表的长度（节点的有效个数）
    int value; //节点存储的数据
    int i;
    //创建头结点，没有存放实际有效的数据
    PNODE pHead = (PNODE)malloc(sizeof(NODE));
    if (pHead == NULL)
    {
        //创建头结点失败，终止程序
        printf("创建链表失败！！！\n");
        exit(-1);
    }
    PNODE pTail = pHead;
    pTail->pNext = NULL;
    printf("请输入要创建链表的长度：");
    scanf("%d", &len);
    for (int i = 0; i < len; ++i)
    {
        PNODE pNew = (PNODE)malloc(sizeof(NODE));
        if (pNew == NULL)
        {
            //创建结点失败，终止程序
            printf("创建链表失败！！！\n");
            exit(-1);
        }
        //创建新节点成功，存放数据
        printf("请输入第%d个节点的数据\n", i + 1);
        scanf("%d", &value);
        pNew->data = value;

        pTail->pNext = pNew;
        pNew->pNext = NULL;
        pTail = pNew;
    }
    return pHead;
}

void traverse_list(PNODE pHead)
{
    PNODE p = pHead->pNext;
    while (NULL != p)
    {
        printf("%d ", p->data);
        p = p->pNext;
    }
    printf("\n");
}

bool is_empty(PNODE pHead)
{
    if (NULL == pHead->pNext)
        return true;
    else
        return false;
}

int lenght_list(PNODE pHead)
{
    int cnt = 0;
    PNODE p = pHead;
    while (p->pNext)
    {
        cnt++;
        p = p->pNext;
    }
    return cnt;
}