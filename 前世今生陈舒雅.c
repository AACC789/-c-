#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void goodman() 
{
    char name[][10] = { "孙悟空", "猪八戒", "沙和尚", "贝多芬", "太白金星", "七仙女" };
    printf("你的前世是：");
    srand((unsigned)time(NULL));
    int i = rand() % 6; 
    printf("%s\n", name[i]);
}

void badman() 
{
    char name[][10] = { "白骨精", "哪吒魔童", "蜘蛛精", "蜘蛛女", "蜘蛛王", "毒液" };
    printf("你的前世是：");
    srand((unsigned)time(NULL));
    int i = rand() % 6; 
    printf("%s\n", name[i]);
}

int main1() {
    int a, b, c;
    char kong;
    printf("前世今生：");
    scanf("%c", &kong);
    if (kong == ' ') 
    {
        while (1) 
        {
            goodman();
            printf("如果继续请输入1，结束请输入2：");
            scanf("%d", &a);
            if (a == 1) 
            {
                continue;
            }
            else if (a == 2) 
            {
                break;
            }
        }
    }
    else {
        while (1) 
        {
            badman();
            printf("如果继续请输入1，结束请输入2：");
            scanf("%d", &b);
            if (b == 1) 
            {
                continue;
            }
            else if (b == 2) 
            {
                break;
            }
        }
    }

    return 0;
}
