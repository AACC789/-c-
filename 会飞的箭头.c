#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
void jian()
{
	printf("\t\t*");
	printf("\t\t  *");
	printf("***********");
	printf("\t\t   *");
	printf("\t\t*");
}
int main()
{
	printf("\t\t");
	jian();
	Sleep(200);
	system("cls");
	Sleep(200);

	while (1)
	{
		printf("\t\t");
		/*
		for (int i = 0;i < 5;i++)
		{
			printf(" ");
		}
		*/
		jian();
		Sleep(200);
		system("cls");
		Sleep(200);
	}
	return 0;
}