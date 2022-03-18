#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu()
{
    printf("*************************************\n");
    printf("*****     1.play 2.exit   ***********\n");
    printf("*************************************\n");
}

void game()
{
    int num = 0;
    int guess = 0;

    num = rand() % 100 + 1;
    // printf("%d\n", num);
    while (1)
    {
        printf("请猜数字：");
        scanf("%d", &guess);
        if (guess > num)
        {
            printf("猜大了\n");
        }
        else if (guess < num)
        {
            printf("猜小了\n");
        }
        else
        {
            printf("猜对了\n");
            break;
        }
    }
}

int main()
{
    int input = 0;
    srand((unsigned int)time(NULL));
    do
    {
        menu();

        printf("请选择：");

        scanf("%d", &input);

        switch (input)
        {
        case 1:
            game();
            break;
        case 2:
            break;

        default:
            printf("输入错误，请重新输入！！！");
            break;
        }
    } while (input == 1);

    return 0;
}