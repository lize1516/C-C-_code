#include <stdio.h>
#include <math.h>
int main()
{
	int i,k;
	for(i = 101;i < 200;i = i++)
	{
		for(k = 2;k <= i/2;k++)
		{
			if(i % k == 0)
			break;
		}
			if(k > i/2)
			{
				printf("%d ",i);
			}
	}
	return 0;
}

乘法口诀表

#include <stdio.h>
void main()
{
	int a,b;
	for(a=1;a<=9;a++)
	{
	for(b=1;b<=a;b++)
	
	{	
		
		printf("%d * %d = %d ",a,b,a*b);
	}
	
	printf("\n");

	}


return 0;
}
判断1000-2000年之间的闰年
#include <stdio.h>
void main()
{
	int i = 0,year = 0;
	for(i = 1000;i<= 2000; i++)
	{
	if(i%4 == 0&&i%100 != 0)
	{year =i;
	printf("%d\t",year);
	}
	if(i%400 == 0)
	{year =i;
	printf("%d\t",year);
	}
	}
return 0;
}