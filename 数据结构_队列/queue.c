#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <stdlib.h>

#define QUEUE_LENTH 6 //����ѭ�����еĴ�С

/**
 * @brief ��ѭ������ʵ�ֶ����ݽṹ
 *
 */

typedef struct queue
{
    int *pBase; //�����׵�ַ
    int front;  //����
    int rear;   //��β
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
        printf("���ӳɹ������ӵ�Ԫ��Ϊ��%d \n", val);
    }
    else
    {
        printf("����ʧ�ܣ�����\n");
    }
    traverse_queue(&Q);
    return 0;
}

void init(QUEUE *pQ)
{
    //����ѭ������
    pQ->pBase = (int *)malloc(sizeof(int) * QUEUE_LENTH);
    if (NULL == pQ->pBase)
    {
        printf("������̬�ڴ�ʧ�ܣ�����\n");
        exit(-1);
    }
    pQ->front = 0;
    pQ->rear = 0;
}

/**
 * @brief �ж�ѭ�������Ƿ�����
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
 * @brief ��Ӻ���
 *
 * @param pQ Ҫ�����Ķ�
 * @param val Ҫ��ӵ�ֵ
 * @return true ��ӳɹ�
 * @return false ���ʧ��
 */
bool en_queue(QUEUE *pQ, int val)
{
    if (full_queue(pQ))
    {
        printf("�����������޷�������Ӳ���������\n");
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