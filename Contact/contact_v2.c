// 1.通讯录中能够动态增加个人信息
// 每个人的信息：名字+年龄+性别+电话+地址
// 2.增加人的信息
// 3.删除指定人的信息
// 4.修改指定人的信息
// 5.查找指定人的信息
// 6.排序通讯录的信息
// 7.将信息保存到文件中

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

// 静态版本
// typedef struct Contact
// {
//     Peoinf data[MAX];
//     int sz;
// } Contact;
// 动态版本
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

// 静态版本
// void Init_contact(Contact *p)
// {
//     p->sz = 0;
//     // memset()对数组进行初始化
//     memset(p->data, 0, sizeof(p->data));
// }

// 动态版本
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

// v2版

void Check_capacity(Contact *p)
{
    if (p->sz == p->capacity)
    {
        Peoinf *str = (Peoinf *)realloc(p->data, ((p->capacity) + CAPADD) * sizeof(Peoinf));
        if (str == NULL)
        {
            perror("Add_contact");
            printf("增加联系人失败！！！\n");
            return;
        }
        p->data = str;
        p->capacity += CAPADD;
        printf("增容成功\n");
    }
}
void Load_contact(Contact *p)
{
    FILE *pf = fopen("contact.dat", "r");
    if (pf == NULL)
    {
        perror("Load_contact");
        printf("加载数据失败\n");
    }
    Peoinf temp = {0};
    while (fread(&temp, sizeof(Peoinf), 1, pf))
    {
        Check_capacity(p); //检测是否需要增容
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

    // 加载数据
    Load_contact(p);
}

// 静态版本
// void Add_contact(Contact *pc)
// {
//     if (pc->sz == MAX)
//     {
//         printf("通讯录已满，无法进行添加操作!!!");
//         return;
//     }
//     printf("请输入姓名：");
//     scanf("%s", pc->data[pc->sz].name);
//     printf("请输入性别：");
//     scanf("%s", pc->data[pc->sz].sex);
//     printf("请输入年龄：");
//     scanf("%d", &pc->data[pc->sz].age);
//     printf("请输入电话号码：");
//     scanf("%d", pc->data[pc->sz].tele);
//     printf("请输入地址：");
//     scanf("%s", pc->data[pc->sz].addr);
//     pc->sz++;
//     printf("增加成功。\n");
// }

// 动态版本
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
//         printf("增容成功\n");
//     }
//     printf("请输入姓名：");
//     scanf("%s", pc->data[pc->sz].name);
//     printf("请输入性别：");
//     scanf("%s", pc->data[pc->sz].sex);
//     printf("请输入年龄：");
//     scanf("%d", &pc->data[pc->sz].age);
//     printf("请输入电话号码：");
//     scanf("%d", pc->data[pc->sz].tele);
//     printf("请输入地址：");
//     scanf("%s", pc->data[pc->sz].addr);
//     pc->sz++;
//     printf("增加成功。\n");
// }

// v2版

void Add_contact(Contact *pc)
{
    Check_capacity(pc);
    printf("请输入姓名：");
    scanf("%s", pc->data[pc->sz].name);
    printf("请输入性别：");
    scanf("%s", pc->data[pc->sz].sex);
    printf("请输入年龄：");
    scanf("%d", &pc->data[pc->sz].age);
    printf("请输入电话号码：");
    scanf("%d", pc->data[pc->sz].tele);
    printf("请输入地址：");
    scanf("%s", pc->data[pc->sz].addr);
    pc->sz++;
    printf("增加成功。\n");
}

void Print_contact(const Contact *pc)
{
    int i = 0;
    // 打印标题
    printf("%-10s\t%-5s\t%-5s\t%-15s\t%-15s\n", "姓名", "性别", "年龄", "电话号码", "地址");
    // 打印内容
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
            printf("找到了。\n");
            return i;
        }
    }
    return 0;
}

void Del_contact(Contact *pc)
{
    char name[MAX_NAME] = {0};
    int i = 0;
    // 1.没有元素时
    if (pc->sz == 0)
    {
        printf("没有联系人，不可以进行删除操作！！！");
        return;
    }
    printf("请输入要查找对象的名字：");
    scanf("%s", name);
    int ret = Find_byname(pc, name);
    if (ret == 0)
    {
        printf("没有找到该联系人\n");
        return;
    }
    // 删除
    else
    {
        for (i = ret; i < pc->sz - 1; i++)
        {
            pc->data[i] = pc->data[i + 1];
        }
    }
    pc->sz--;
    printf("删除成功。\n");
}

void Search_contact(const Contact *pc)
{
    char name[MAX_NAME] = {0};
    printf("请输入要查找联系人的姓名：");
    scanf("%s", name);
    int ret = Find_byname(pc, name);
    if (ret == 0)
    {
        printf("没有找到该联系人\n");
        return;
    }
    else
    {
        // 打印标题
        printf("%-10s\t%-5s\t%-5s\t%-15s\t%-15s\n", "姓名", "性别", "年龄", "电话号码", "地址");
        // 打印内容

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
    printf("请输入要修改联系人的姓名：");
    scanf("%s", name);
    int ret = Find_byname(pc, name);
    if (ret == 0)
    {
        printf("没有找到该联系人\n");
        return;
    }
    else
    {
        // 打印标题
        printf("%-10s\t%-5s\t%-5s\t%-15s\t%-15s\n", "姓名", "性别", "年龄", "电话号码", "地址");
        // 打印内容

        printf("%-10s\t%-5s\t%-5d\t%-15s\t%-15s\n",
               pc->data[ret].name,
               pc->data[ret].sex,
               pc->data[ret].age,
               pc->data[ret].tele,
               pc->data[ret].addr);
        printf("修改成功\n");
    }
}

void Save_caontact(Contact *p)
{
    FILE *pf = fopen("contact.dat", "w");
    if (pf == NULL)
    {
        perror("Save_caontact");
        printf("保存失败！！！");
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

    Contact contact; //创建通讯录

    Init_contact(&contact); //初始化

    do
    {
        menu();
        printf("请选择：");
        scanf("%d", &input);
        switch (input)
        {
        case EXIT:
            Save_caontact(&contact);
            Destroy_contact(&contact); //销毁通讯录
            printf("退出成功！！！\n");
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
            printf("输入错误，请重新输入");
            break;
        }
    } while (input);

    return 0;
}