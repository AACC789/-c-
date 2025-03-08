#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int cai()
{
	
	printf("请输入一个1~100之间的整数：\n");
	int num;
	scanf("%d", &num);
	srand(time(NULL));
	int guess = rand() % 100 + 1;
	//printf("%d\n", guess);
	int shu=0;
	while (shu<=7)
	{
		if (guess < num)
		{
			printf("猜大了，请重新输入：\n");
			scanf("%d", &num);
			shu++;
		}
		else if(guess > num)
		{
			printf("猜小了，请重新输入：\n");
			scanf("%d", &num);
			shu++;
		}
		else if (guess == num)
		{
			printf("恭喜你，你猜对了！\n");
			break;
		}
	}
	if (shu > 7)
	{
		printf("七次都猜不到，也太菜了吧！\n");
	}
	return 0;
}
int main9()
{
	printf("欢迎来到你想我猜的游戏！\n");
	while (1)
	{
		cai();
		printf("是否继续玩？y/n");
		char c;
		while ((getchar()) != '\n');   
		scanf("%c", &c);
		if (c == 'n')
		{
			break;
		}
		else if (c == 'y')
		{
			continue;
		}

	}
	return 0;
}