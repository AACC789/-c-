#include <stdio.h>

// ��ӡһ���Ǻŵĺ���
void star() {
    printf("\t\t\t\t");
    for (int i = 0; i < 21; i++) {
        printf("* ");
    }
    printf("\n");
}

void small() {
    printf("\t\t\t\t");
    printf("*\t\t\t\t\t*\n");// ��ӡ�������ǺŵĿ��к���
}

int main2() {
    star(); // ��ʾһ���Ǻ�
    small(); // ��ʾ�������ǺŵĿ���
    printf("\t\t\t\t");
    printf("*\t     ������������\t\t*\n");
    small();
    printf("\t\t\t\t");
    printf("*\t     qq��3087609055\t\t*\n");
    small();
    printf("\t\t\t\t");
    printf("*\t     �绰:13349700621    \t*\n");
    small();
    printf("\t\t\t\t");
    printf("*   ��������:������������������������\t*\n");
    small();
    printf("\t\t\t\t");
    printf("*\t\t\"\\(^_^)/\"\t\t*\n");//��б�� \��˫���� "�����������ת��� \\, \��
    small(); // ��ʾ�������ǺŵĿ��У���������
    small();
    star();
    return 0;
}