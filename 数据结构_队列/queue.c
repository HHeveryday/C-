#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <stdlib.h>

#define QUEUE_LENTH 6 //开辟循环队列的大小

/**
 * @brief 用循环队列实现队数据结构
 *
 */

typedef struct queue
{
    int *pBase; //数组首地址
    int front;  //队首
    int rear;   //队尾
} QUEUE;

void init(QUEUE *pQ);
bool en_queue(QUEUE *pQ, int val);
void traverse_queue(QUEUE *pQ);
bool out_queue(QUEUE *pQ, int *val);
bool empty_queue(QUEUE *pQ);

int main(void)
{
    int val;
    QUEUE Q;
    init(&Q);
    en_queue(&Q, 1);
    en_queue(&Q, 2);
    en_queue(&Q, 3);
    en_queue(&Q, 4);
    en_queue(&Q, 5);
    traverse_queue(&Q);
    if (out_queue(&Q, &val))
    {
        printf("出队成功，出队的元素为：%d \n", val);
    }
    else
    {
        printf("出队失败！！！\n");
    }
    traverse_queue(&Q);
    return 0;
}

void init(QUEUE *pQ)
{
    //创建循环数组
    pQ->pBase = (int *)malloc(sizeof(int) * QUEUE_LENTH);
    if (NULL == pQ->pBase)
    {
        printf("创建动态内存失败！！！\n");
        exit(-1);
    }
    pQ->front = 0;
    pQ->rear = 0;
}

/**
 * @brief 判断循环队列是否已满
 *
 * @param pQ
 * @return true
 * @return false
 */
bool full_queue(QUEUE *pQ)
{
    if (pQ->front == (pQ->rear + 1) % QUEUE_LENTH)
        return true;
    else
        return false;
}

/**
 * @brief 入队函数
 *
 * @param pQ 要操作的队
 * @param val 要入队的值
 * @return true 入队成功
 * @return false 入队失败
 */
bool en_queue(QUEUE *pQ, int val)
{
    if (full_queue(pQ))
    {
        printf("队列已满，无法进行入队操作！！！\n");
        return false;
    }
    else
    {
        pQ->pBase[pQ->rear] = val;
        pQ->rear = (pQ->rear + 1) % QUEUE_LENTH;
        return true;
    }
}

void traverse_queue(QUEUE *pQ)
{
    int p = pQ->front;
    while (p != pQ->rear)
    {
        printf("%d ", pQ->pBase[p]);
        p = (p + 1) % QUEUE_LENTH;
    }
    printf("\n");
}

bool empty_queue(QUEUE *pQ)
{
    if (pQ->front == pQ->rear)
        return true;
    else
        return false;
}

bool out_queue(QUEUE *pQ, int *val)
{
    if (empty_queue(pQ))
    {
        return false;
    }
    else
    {
        *val = pQ->pBase[pQ->front];
        pQ->front = (pQ->front + 1) % QUEUE_LENTH;
        return true;
    }
}