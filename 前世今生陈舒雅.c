#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void goodman() 
{
    char name[][10] = { "�����", "��˽�", "ɳ����", "�����", "̫�׽���", "����Ů" };
    printf("���ǰ���ǣ�");
    srand((unsigned)time(NULL));
    int i = rand() % 6; 
    printf("%s\n", name[i]);
}

void badman() 
{
    char name[][10] = { "�׹Ǿ�", "��߸ħͯ", "֩�뾫", "֩��Ů", "֩����", "��Һ" };
    printf("���ǰ���ǣ�");
    srand((unsigned)time(NULL));
    int i = rand() % 6; 
    printf("%s\n", name[i]);
}

int main1() {
    int a, b, c;
    char kong;
    printf("ǰ��������");
    scanf("%c", &kong);
    if (kong == ' ') 
    {
        while (1) 
        {
            goodman();
            printf("�������������1������������2��");
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
            printf("�������������1������������2��");
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
