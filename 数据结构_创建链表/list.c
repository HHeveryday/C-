#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;           //������
    struct Node *pNext; //ָ����
} NODE, *PNODE;

PNODE creat_list(void);
void traverse_list(PNODE pHead);
bool is_empty(PNODE pHead);
bool insert_list(PNODE pHead, int pos, int val);
int lenght_list(PNODE pHead);
bool delete_list(PNODE pHead, int pos, int *val);
void sort_list(PNODE pHead);

int main()
{
    int val;
    PNODE pHead = NULL;
    pHead = creat_list(); //����һ����ѭ�������������������ͷ�ڵ�ĵ�ַ����
    traverse_list(pHead); //��������

    // if (is_empty(pHead))
    //     printf("����Ϊ�գ�����\n");
    // else
    //     printf("����Ϊ�գ�����\n");

    // printf("����ĳ���Ϊ��%d", lenght_list(pHead));//������ĳ���

    // sort_list(pHead);     //��������
    // traverse_list(pHead); //��������

    // insert_list(pHead, 3, 52);
    // traverse_list(pHead);

    delete_list(pHead, 4, &val);
    traverse_list(pHead);

    return 0;
}

//��������
PNODE creat_list(void)
{
    int len;   //����ĳ��ȣ��ڵ����Ч������
    int value; //�ڵ�洢������
    int i;
    //����ͷ��㣬û�д��ʵ����Ч������
    PNODE pHead = (PNODE)malloc(sizeof(NODE));
    if (pHead == NULL)
    {
        //����ͷ���ʧ�ܣ���ֹ����
        printf("��������ʧ�ܣ�����\n");
        exit(-1);
    }
    PNODE pTail = pHead;
    pTail->pNext = NULL;
    printf("������Ҫ��������ĳ��ȣ�");
    scanf("%d", &len);
    for (int i = 0; i < len; ++i)
    {
        PNODE pNew = (PNODE)malloc(sizeof(NODE));
        if (pNew == NULL)
        {
            //�������ʧ�ܣ���ֹ����
            printf("��������ʧ�ܣ�����\n");
            exit(-1);
        }
        //�����½ڵ�ɹ����������
        printf("�������%d���ڵ������\n", i + 1);
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

void sort_list(PNODE pHead)
{
    PNODE p, q; //��������PNODE���͵�ָ������������
    int i, j, temp;
    for (i = 0, p = pHead->pNext; i < lenght_list(pHead) - 1; ++i, p = p->pNext)
    {
        for (j = i + 1, q = p->pNext; j < lenght_list(pHead); ++j, q = q->pNext)
        {
            if (p->data > q->data)
            {
                temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
        }
    }
    return;
}

bool insert_list(PNODE pHead, int pos, int val)
{
    PNODE p = pHead;
    int i = 0;
    while (i < pos - 1 && p->pNext != NULL)
    {
        p = p->pNext;
        ++i;
    }
    if (p->pNext == NULL || i > pos - 1)
    {
        return false;
        exit(-1);
    }

    // pָ���Ѿ�ָ����Ҫ����ڵ�ǰһ����λ��
    PNODE pNew = (PNODE)malloc(sizeof(PNODE));
    if (NULL == pNew)
    {
        printf("��̬�����ڴ�ʧ�ܣ�����/n");
        exit(-1);
    }

    //�������Ľڵ����insert����
    pNew->data = val;
    PNODE ptemp = p->pNext; //���ڴ洢��һ���ڵ�
    p->pNext = pNew;
    pNew->pNext = ptemp;
    return true;
}

bool delete_list(PNODE pHead, int pos, int *val)
{
    PNODE p = pHead;
    int i = 0;
    while (i < pos - 1 && p->pNext != NULL)
    {
        p = p->pNext;
        ++i;
    }
    if (p->pNext == NULL || i > pos - 1)
    {
        return false;
        exit(-1);
    }

    // pָ���Ѿ�ָ����Ҫɾ���ڵ��ǰһ����λ��
    PNODE ptemp = p->pNext; //����Ҫɾ���ڵ�
    *val = ptemp->data;     //��ɾ���ڵ��ֵ����
    p->pNext = ptemp->pNext;
    free(ptemp);
    ptemp = NULL;

    return true;
}