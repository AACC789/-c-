#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int cai()
{
	
	printf("������һ��1~100֮���������\n");
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
			printf("�´��ˣ����������룺\n");
			scanf("%d", &num);
			shu++;
		}
		else if(guess > num)
		{
			printf("��С�ˣ����������룺\n");
			scanf("%d", &num);
			shu++;
		}
		else if (guess == num)
		{
			printf("��ϲ�㣬��¶��ˣ�\n");
			break;
		}
	}
	if (shu > 7)
	{
		printf("�ߴζ��²�����Ҳ̫���˰ɣ�\n");
	}
	return 0;
}
int main9()
{
	printf("��ӭ���������Ҳµ���Ϸ��\n");
	while (1)
	{
		cai();
		printf("�Ƿ�����棿y/n");
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