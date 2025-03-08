#include<stdio.h>
int year()
{
	int sum = 0;
	for (int i = 2023;i <= 2223;i++)
	{
		if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
		{
			printf("%d ", i);
			sum++;
		}
	}
	printf("个数为：%d\n", sum);
	return 0;
}
int math()
{
	printf("%d %d ", 2, 3);
	int sum = 2;
	for (int i = 0;i <= 100;i++)
	{
		for (int j = 2;j <=i/2;j++)
		{
			if (i % j == 0)
			{
				break;
			}
			else if(j == i/2)
			{
				printf("%d ", i);
				sum++;
			}
		}
	}
	
	printf("个数为：%d", sum);
	return 0;
}
int main6()
{
	year();
	math();
	return 0;
}
