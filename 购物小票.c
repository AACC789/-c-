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
	printf("收银员：%s", name);
	stars();

	{ time_t a = time(0);struct tm b = *localtime(&a);printf("%04d-%02d-%02d %02d:%02d:%02d\n", b.tm_year + 1900, b.tm_mon + 1, b.tm_mday, b.tm_hour, b.tm_min, b.tm_sec); }
	stars();
	printf("\t\t欢迎来到最好吃的水果店\n");
	stars();
	printf("品名\t\t\t数量\t单价\t小计\n");
	int num,num2;
	printf("请输入两个商品分别的数量：");
	scanf_s("%d %d", &num, &num2);
	
	printf("苹果\t\t\t%d\t5.00\t%.2f\n",num,5.00*num );
	float all = 5.00 * num;
	printf("香蕉\t\t\t%d\t8.00\t%.2f\n", num2,8.00*num2);
	float all1 = 8.00 * num2;
	printf("合计%.2f\n", all + all1);
	float total;
	scanf_s("%f", &total);
	printf("收银：%.2f\t找零：%.2f\n", total, total - all - all1);
	stars();
	{ time_t a = time(0);struct tm b = *localtime(&a);printf("%04d-%02d-%02d %02d:%02d:%02d\n", b.tm_year + 1900, b.tm_mon + 1, b.tm_mday, b.tm_hour, b.tm_min, b.tm_sec); }
	printf("谢谢会顾，欢迎下次光临！\n");
	stars();
	
	return 0;


}