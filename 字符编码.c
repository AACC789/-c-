#include<stdio.h>
int main6()
{
	int b[10];
	char t;
	int m;
	scanf_s("%c", &t);
	for (int i = 0;i < 8;i++)
	{
		m = (t >> i)&0x01;
		if (m == 0)
		{
			b[i] = 0;
		}
		else
		{
			b[i] = 1;
		}
	}
	for (int j = 7;j >= 0;j--)
	{
		printf("%d", b[j]);
	}

}