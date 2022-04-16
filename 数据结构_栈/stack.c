#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

//栈的程序实现

//节点
typedef struct Node
{
    int data;
    struct Node *pNext;
} NODE, *PNODE;

//栈
typedef struct Stack
{
    PNODE pTop;    //栈顶指针
    PNODE pBottom; //栈底指针
} STACK, *PSTACK;

void init(PSTACK pS);
void push(PSTACK pS, int val);
void traverse(PSTACK pS);
bool pop(PSTACK pS, int *val);
bool empty(PSTACK pS);

void clear(PSTACK pS);

int main()
{
    int val;
    STACK S;
    init(&S);
    push(&S, 1);
    push(&S, 2);
    push(&S, 3);
    push(&S, 4);
    push(&S, 5);
    push(&S, 6);
    traverse(&S);
    pop(&S, &val);
    traverse(&S);
    printf("%d\n", val);
    clear(&S);
    if (empty(&S))
    {
        printf("success\n");
    }
    traverse(&S);
    return 0;
}

void init(PSTACK pS)
{
    PNODE pNew = (PNODE)malloc(sizeof(PNODE));
    if (NULL == pNew)
    {
        printf("动态分配内存失败！！！\n");
        exit(-1);
    }
    pS->pBottom = pNew;
    pS->pTop = pS->pBottom;
    pS->pBottom->pNext = NULL; //将栈底的指针域置为空
}

//压栈操作
void push(PSTACK pS, int val)
{
    PNODE pNew = (PNODE)malloc(sizeof(PNODE));
    if (NULL == pNew)
    {
        printf("动态分配内存失败！！！\n");
        exit(-1);
    }
    pNew->data = val;
    pNew->pNext = pS->pTop;
    pS->pTop = pNew;
}

void traverse(PSTACK pS)
{
    PNODE p = pS->pTop;
    while (p != pS->pBottom)
    {
        printf("%d ", p->data);
        p = p->pNext;
    }
    printf("\n");
}

//出栈操作
bool pop(PSTACK pS, int *val)
{
    if (empty(pS))
    {
        return false;
    }
    else
    {
        PNODE p = pS->pTop;
        *val = p->data;
        pS->pTop = p->pNext;
        free(p);
        p = NULL;
        return true;
    }
}

bool empty(PSTACK pS)
{
    if (pS->pBottom == pS->pTop)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//清空栈
void clear(PSTACK pS)
{

    if (empty(pS))
    {
        return;
    }
    else
    {
        PNODE p = pS->pTop;
        PNODE q = NULL;
        while (p != pS->pBottom)
        {
            q = p->pNext;
            free(p);
            p = q;
        }
        pS->pTop = pS->pBottom;
    }
}
