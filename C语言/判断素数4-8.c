//���ֲ���
#include <stdio.h>
int main()
{
	int arr[]={1,2,3,4,5,6,7,8,9};
    int key = 9;
    int sz = sizeof(arr)/sizeof(arr[0]);
	int ret =  binary_search(arr,sz,key);
     if(ret == -1)
		 printf("û�ҵ�\n");
	 else
		 printf("%d\n",ret);
	 return 0;
}
int binary_search(int arr[],int sz,int key)
{
		int left =0;
		int right = sz-1;
		while(left <=right)
		{
			int mid = left + (right - left)/2;
			if(arr[mid] < key)
				left = mid +1;
			else if(arr[mid] > key)
				right = mid -1;
			else 
				return mid;	

		}
		return -1;
}
�ж�����
#include <stdio.h>
#include <stdlib.h>
int Judge_runnian(int year)
{
	if(((year%4 == 0)&&(year%100 != 0))||(year%400==0))
		return 1;
	else
		return -1;
}
int main()
{
	int year=0;
	printf("���������:");
	scanf("%d",&year);
	int ret = Judge_runnian(year);
		if(ret==-1)
			printf("��������\n");
		else
			printf("������\n");
	system("pause");
	return 0;
	
}
�ж�����
#include <stdio.h>
#include <stdlib.h>
int judge_number(int num)
{
	int i=0;
	if(num ==1)
		return -1;
	else
	{for(i=2;i < num/2;i++)
	{
		if(num%i != 0)
			continue;
		else
			return -1;
	}
        return num;
	}
}
int main()
{
	int num;
  printf("���������֣�");
  scanf("%d",&num);
	int ret = judge_number(num);
	if(ret == -1)
		printf("��������\n");
	else
		printf("%d\n",num);
system("pause");
	return 0;
}
����ÿ����һ�β�����1
#include<stdio.h>
int add(int*p)
{
  *p=*p+1;
}
int main()
{
	int num=0;
	add(&num);
	add(&num);
	printf("�������д�����%d\n",num);
	return 0;
}
