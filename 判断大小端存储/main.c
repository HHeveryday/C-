#include <stdio.h>

int check_sys(void)
{
    int a = 1;
    // ����1��С��
    // ����2�����
    return *(char *)&a;
}

int main()
{
    // ��дһ�δ��룬�������ǵ�ǰ�������ֽ�����ʲô
    // ����1С��
    // ����0���
    int ret = check_sys();
    if (ret == 1)
    {
        printf("С�˴洢\n");
    }
    else
    {
        printf("��˴洢\n");
    }
    return 0;
}
