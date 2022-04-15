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
int insert_list(PNODE);
int lenght_list(PNODE pHead);
bool delete_list(PNODE);
void sort_list(PNODE);

int main()
{
    PNODE pHead = NULL;
    pHead = creat_list(); //����һ����ѭ�������������������ͷ�ڵ�ĵ�ַ����
    traverse_list(pHead); //��������

    // if (is_empty(pHead))
    //     printf("����Ϊ�գ�����\n");
    // else
    //     printf("����Ϊ�գ�����\n");

    // printf("����ĳ���Ϊ��%d", lenght_list(pHead));//������ĳ���
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