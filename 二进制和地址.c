#include<stdio.h>
int main()
{
	int a = 7;
	printf("变量a的总地址：%p\n", &a);
	char* p = (char*)&a;
	for (int i = 0;i < 4;i++)
	{
		printf("字节地址%d：%p\n", i + 1, p + i);//p+i表示的是从p所指向的地址开始，向后偏移i个字节的地址p[i]=*(p+i)
		//输出每个字节的二进制
		for (int j = 7;j >= 0;j--)
		{
			printf("%d", (*(p + i) >> j) & 1);
			
		}
		printf("\n");
	}
	return 0;
}