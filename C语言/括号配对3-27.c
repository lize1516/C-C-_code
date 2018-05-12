//#include <stdio.h>
//int main()
//{
//	int i,n,m,k;
//	for(i = 100;i <=999;i++)
//	{
//		n = i%10;
//		m = i/100;
//		k = i/10 - (i/100)*10;
//		if((n*n*n+m*m*m+k*k*k) == i)
//			printf("%d\n",i);
//
//	}
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int i,a,Sn = 0,b = 0;
//	printf("请输入一个整数\n");
//	scanf("%d",&a);
//	
//		for(i=1;i <= 5;i++)
//	{
//		b = b*10 + a;
//		Sn = Sn + b;
//	
//	}
//    printf("Sn=%d",Sn);
//	
//return 0;
//}
//菱形
//#include <stdio.h>
//int main()
//{
//	int i,m,a;
//	for(i = 1;i <= 13;i+= 2)
//	{
//			for(a = (13-i)/2;a >= 1;a--)
//				printf(" ");
//				for(m = 1;m <= i;m++)
//				printf("*");
//		       printf("\n");
//	}
//	for(i = 11;i >= 1;i-=2)
//	{
//		for(a = (13-i)/2;a >= 1;a--)
//				printf(" ");
//		for(m = 1;m <= i;m++)
//		printf("*");
//		printf("\n");
//	}
//
//	return 0;
//}
//花括号配对
#include <stdio.h>
int main()
{
	char ch;
	int a=0;
	while((ch=getchar())!= EOF)
	{
		if(ch =='{')
			a ++;
		else if(ch =='}'&& a==0)
		{
			printf("不匹配\n");
			return 0;
		}
		else if(ch =='}'&& a!=0)
			a--;
	}
	if(a == 0)
		printf("匹配\n");
	else
		printf("不匹配\n");
	return 0;
}
