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
		printf("�ļ���ʧ�ܣ�");
		return 0;
	}
	printf("��Ʒ����\t\t��Ʒ����\t\t��Ʒ����\t\tС��\n");
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