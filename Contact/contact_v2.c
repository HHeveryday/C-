// 1.ͨѶ¼���ܹ���̬���Ӹ�����Ϣ
// ÿ���˵���Ϣ������+����+�Ա�+�绰+��ַ
// 2.�����˵���Ϣ
// 3.ɾ��ָ���˵���Ϣ
// 4.�޸�ָ���˵���Ϣ
// 5.����ָ���˵���Ϣ
// 6.����ͨѶ¼����Ϣ
// 7.����Ϣ���浽�ļ���

#define MAX_NAME 20
#define MAX_SEX 20
#define MAX_TELE 12
#define MAX_ADDR 30
#define INICAP 3
#define CAPADD 2

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Peoinf
{
    char name[MAX_NAME];
    char sex[MAX_SEX];
    int age;
    char tele[MAX_TELE];
    char addr[MAX_ADDR];
} Peoinf;

// ��̬�汾
// typedef struct Contact
// {
//     Peoinf data[MAX];
//     int sz;
// } Contact;
// ��̬�汾
typedef struct Contact
{
    Peoinf *data;
    int sz;
    int capacity;
} Contact;

void menu()
{
    printf("****************************************\n");
    printf("*****     1. add    2. del         *****\n");
    printf("*****     3. serch  4. modify      *****\n");
    printf("*****     5. sort   6. print       *****\n");
    printf("*****     0. exit                  *****\n");
    printf("****************************************\n");
}

enum Option
{
    EXIT,
    ADD,
    DEL,
    SERCH,
    MODIFY,
    SORT,
    PRIBT
};

// ��̬�汾
// void Init_contact(Contact *p)
// {
//     p->sz = 0;
//     // memset()��������г�ʼ��
//     memset(p->data, 0, sizeof(p->data));
// }

// ��̬�汾
// void Init_contact(Contact *p)
// {
//     p->data = (Peoinf *)malloc(INICAP * sizeof(Peoinf));
//     if (p->data == NULL)
//     {
//         perror("Init_contact");
//         return;
//     }
//     p->capacity = INICAP;
//     p->sz = 0;
// }

// v2��

void Check_capacity(Contact *p)
{
    if (p->sz == p->capacity)
    {
        Peoinf *str = (Peoinf *)realloc(p->data, ((p->capacity) + CAPADD) * sizeof(Peoinf));
        if (str == NULL)
        {
            perror("Add_contact");
            printf("������ϵ��ʧ�ܣ�����\n");
            return;
        }
        p->data = str;
        p->capacity += CAPADD;
        printf("���ݳɹ�\n");
    }
}
void Load_contact(Contact *p)
{
    FILE *pf = fopen("contact.dat", "r");
    if (pf == NULL)
    {
        perror("Load_contact");
        printf("��������ʧ��\n");
    }
    Peoinf temp = {0};
    while (fread(&temp, sizeof(Peoinf), 1, pf))
    {
        Check_capacity(p); //����Ƿ���Ҫ����
        p->data[p->sz] = temp;
        p->sz++;
    }

    fclose(pf);
    pf = NULL;
}

void Init_contact(Contact *p)
{
    p->data = (Peoinf *)malloc(INICAP * sizeof(Peoinf));
    if (p->data == NULL)
    {
        perror("Init_contact");
        return;
    }
    p->capacity = INICAP;
    p->sz = 0;

    // ��������
    Load_contact(p);
}

// ��̬�汾
// void Add_contact(Contact *pc)
// {
//     if (pc->sz == MAX)
//     {
//         printf("ͨѶ¼�������޷�������Ӳ���!!!");
//         return;
//     }
//     printf("������������");
//     scanf("%s", pc->data[pc->sz].name);
//     printf("�������Ա�");
//     scanf("%s", pc->data[pc->sz].sex);
//     printf("���������䣺");
//     scanf("%d", &pc->data[pc->sz].age);
//     printf("������绰���룺");
//     scanf("%d", pc->data[pc->sz].tele);
//     printf("�������ַ��");
//     scanf("%s", pc->data[pc->sz].addr);
//     pc->sz++;
//     printf("���ӳɹ���\n");
// }

// ��̬�汾
// void Add_contact(Contact *pc)
// {
//     if (pc->sz == pc->capacity)
//     {
//         Peoinf *str = (Peoinf *)realloc(pc->data, ((pc->capacity) + CAPADD) * sizeof(Peoinf));
//         if (str == NULL)
//         {
//             perror("Add_contact");
//             return;
//         }
//         pc->data = str;
//         pc->capacity += CAPADD;
//         printf("���ݳɹ�\n");
//     }
//     printf("������������");
//     scanf("%s", pc->data[pc->sz].name);
//     printf("�������Ա�");
//     scanf("%s", pc->data[pc->sz].sex);
//     printf("���������䣺");
//     scanf("%d", &pc->data[pc->sz].age);
//     printf("������绰���룺");
//     scanf("%d", pc->data[pc->sz].tele);
//     printf("�������ַ��");
//     scanf("%s", pc->data[pc->sz].addr);
//     pc->sz++;
//     printf("���ӳɹ���\n");
// }

// v2��

void Add_contact(Contact *pc)
{
    Check_capacity(pc);
    printf("������������");
    scanf("%s", pc->data[pc->sz].name);
    printf("�������Ա�");
    scanf("%s", pc->data[pc->sz].sex);
    printf("���������䣺");
    scanf("%d", &pc->data[pc->sz].age);
    printf("������绰���룺");
    scanf("%d", pc->data[pc->sz].tele);
    printf("�������ַ��");
    scanf("%s", pc->data[pc->sz].addr);
    pc->sz++;
    printf("���ӳɹ���\n");
}

void Print_contact(const Contact *pc)
{
    int i = 0;
    // ��ӡ����
    printf("%-10s\t%-5s\t%-5s\t%-15s\t%-15s\n", "����", "�Ա�", "����", "�绰����", "��ַ");
    // ��ӡ����
    for (int i = 0; i < pc->sz; i++)
    {
        printf("%-10s\t%-5s\t%-5d\t%-15s\t%-15s\n",
               pc->data[i].name,
               pc->data[i].sex,
               pc->data[i].age,
               pc->data[i].tele,
               pc->data[i].addr);
    }
}

int Find_byname(const Contact *pc, char name[])
{
    int i = 0;
    for (i = 0; i < pc->sz; i++)
    {
        if (strcmp(pc->data[i].name, name) == 0)
        {
            printf("�ҵ��ˡ�\n");
            return i;
        }
    }
    return 0;
}

void Del_contact(Contact *pc)
{
    char name[MAX_NAME] = {0};
    int i = 0;
    // 1.û��Ԫ��ʱ
    if (pc->sz == 0)
    {
        printf("û����ϵ�ˣ������Խ���ɾ������������");
        return;
    }
    printf("������Ҫ���Ҷ�������֣�");
    scanf("%s", name);
    int ret = Find_byname(pc, name);
    if (ret == 0)
    {
        printf("û���ҵ�����ϵ��\n");
        return;
    }
    // ɾ��
    else
    {
        for (i = ret; i < pc->sz - 1; i++)
        {
            pc->data[i] = pc->data[i + 1];
        }
    }
    pc->sz--;
    printf("ɾ���ɹ���\n");
}

void Search_contact(const Contact *pc)
{
    char name[MAX_NAME] = {0};
    printf("������Ҫ������ϵ�˵�������");
    scanf("%s", name);
    int ret = Find_byname(pc, name);
    if (ret == 0)
    {
        printf("û���ҵ�����ϵ��\n");
        return;
    }
    else
    {
        // ��ӡ����
        printf("%-10s\t%-5s\t%-5s\t%-15s\t%-15s\n", "����", "�Ա�", "����", "�绰����", "��ַ");
        // ��ӡ����

        printf("%-10s\t%-5s\t%-5d\t%-15s\t%-15s\n",
               pc->data[ret].name,
               pc->data[ret].sex,
               pc->data[ret].age,
               pc->data[ret].tele,
               pc->data[ret].addr);
    }
}

void Modify_contact(Contact *pc)
{
    char name[MAX_NAME] = {0};
    printf("������Ҫ�޸���ϵ�˵�������");
    scanf("%s", name);
    int ret = Find_byname(pc, name);
    if (ret == 0)
    {
        printf("û���ҵ�����ϵ��\n");
        return;
    }
    else
    {
        // ��ӡ����
        printf("%-10s\t%-5s\t%-5s\t%-15s\t%-15s\n", "����", "�Ա�", "����", "�绰����", "��ַ");
        // ��ӡ����

        printf("%-10s\t%-5s\t%-5d\t%-15s\t%-15s\n",
               pc->data[ret].name,
               pc->data[ret].sex,
               pc->data[ret].age,
               pc->data[ret].tele,
               pc->data[ret].addr);
        printf("�޸ĳɹ�\n");
    }
}

void Save_caontact(Contact *p)
{
    FILE *pf = fopen("contact.dat", "w");
    if (pf == NULL)
    {
        perror("Save_caontact");
        printf("����ʧ�ܣ�����");
        return;
    }
    int i = 0;
    for (i = 0; i < p->sz; i++)
    {
        fwrite(p->data + i, sizeof(Peoinf), 1, pf);
    }
    fclose(pf);
    pf = NULL;
}

void Destroy_contact(Contact *p)
{
    free(p->data);
    p->data = NULL;
    p->sz = 0;
    p->capacity = 0;
}

int main()
{
    int input = 0;

    Contact contact; //����ͨѶ¼

    Init_contact(&contact); //��ʼ��

    do
    {
        menu();
        printf("��ѡ��");
        scanf("%d", &input);
        switch (input)
        {
        case EXIT:
            Save_caontact(&contact);
            Destroy_contact(&contact); //����ͨѶ¼
            printf("�˳��ɹ�������\n");
            break;
        case ADD:
            Add_contact(&contact);
            break;
        case DEL:
            Del_contact(&contact);
            break;
        case SERCH:
            Search_contact(&contact);
            break;
        case MODIFY:
            Modify_contact(&contact);
        case SORT:
            break;
        case PRIBT:
            Print_contact(&contact);
            break;

        default:
            printf("�����������������");
            break;
        }
    } while (input);

    return 0;
}