#include<stdio.h>
int main()
{
	int a = 7;
	printf("����a���ܵ�ַ��%p\n", &a);
	char* p = (char*)&a;
	for (int i = 0;i < 4;i++)
	{
		printf("�ֽڵ�ַ%d��%p\n", i + 1, p + i);//p+i��ʾ���Ǵ�p��ָ��ĵ�ַ��ʼ�����ƫ��i���ֽڵĵ�ַp[i]=*(p+i)
		//���ÿ���ֽڵĶ�����
		for (int j = 7;j >= 0;j--)
		{
			printf("%d", (*(p + i) >> j) & 1);
			
		}
		printf("\n");
	}
	return 0;
}