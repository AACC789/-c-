#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void stars()
{
	for (int i = 0;i < 25;i++)
	{
		printf("- ");
	}
	printf("\n");
}

int main7()
{
	char name[10];
	fgets(name, 10, stdin);
	printf("����Ա��%s", name);
	stars();

	{ time_t a = time(0);struct tm b = *localtime(&a);printf("%04d-%02d-%02d %02d:%02d:%02d\n", b.tm_year + 1900, b.tm_mon + 1, b.tm_mday, b.tm_hour, b.tm_min, b.tm_sec); }
	stars();
	printf("\t\t��ӭ������óԵ�ˮ����\n");
	stars();
	printf("Ʒ��\t\t\t����\t����\tС��\n");
	int num,num2;
	printf("������������Ʒ�ֱ��������");
	scanf_s("%d %d", &num, &num2);
	
	printf("ƻ��\t\t\t%d\t5.00\t%.2f\n",num,5.00*num );
	float all = 5.00 * num;
	printf("�㽶\t\t\t%d\t8.00\t%.2f\n", num2,8.00*num2);
	float all1 = 8.00 * num2;
	printf("�ϼ�%.2f\n", all + all1);
	float total;
	scanf_s("%f", &total);
	printf("������%.2f\t���㣺%.2f\n", total, total - all - all1);
	stars();
	{ time_t a = time(0);struct tm b = *localtime(&a);printf("%04d-%02d-%02d %02d:%02d:%02d\n", b.tm_year + 1900, b.tm_mon + 1, b.tm_mday, b.tm_hour, b.tm_min, b.tm_sec); }
	printf("лл��ˣ���ӭ�´ι��٣�\n");
	stars();
	
	return 0;


}