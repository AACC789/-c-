#include<stdio.h>
#include<time.h>
int main12()
{
	FILE *fp;
	char name[20];
	int num;
	float price, sum=0 ,total= 0;
	fp=fopen("shopping.txt","w+");
	if(fp==NULL)
	{
		printf("文件打开失败！");
		return 0;
	}
	printf("商品名称\t\t商品数量\t\t商品单价\t\t小计\n");
	while(fscanf(fp,"%s%d%d",&name,&num,&price)!=EOF)
	{
		sum=num*price;
		total += sum;
		printf("%-15s%-15d%-15.2f%-15.2f\n",name,num,price,sum);
	}
	printf("%.2f\n", total);


	fclose(fp);
	return 0;
}