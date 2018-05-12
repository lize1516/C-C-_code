//二分法
#include<stdio.h>
int main()
{
	int arr[]={1,2,3,4,5,6,7,8,9,10};
	int key = -4;
	int left = 0;
	int right = sizeof(arr)/sizeof(arr[0])-1;
	if((key > arr[right])||key < arr[left])
		printf("找不到\n");
	else
	{
	   while(left <= right)
	  {
		int mid;
		mid = left + (right-left)/2;
		if(arr[mid]>key)
			right = mid - 1;
		else if(arr[mid]<key)
			left = mid + 1;
		else
		{
			printf("%d \n",mid);
			break;
		}
	  }
	}

return 0;
}
//乘法口诀表
//#include<stdio.h>
//void main()
//{
// int x,y,z;
// for(x=1;x<=9;x++)
//   {
//	 for(y=1;y<=x;y++) 
//	   {
//				z=x*y;
//			printf("%d*%d=%2d  ",y,x,z);
//		}
//  printf("\n");
//    }
//}
//找素数
//#include <stdio.h>
//int main()
//{
//	int i,a,c;
//	for(i=100;i <= 200;i++)
//	{
//		for(a = 2;a <= i/2;a++)
//		{
//			c = i%a;
//		   if(c!=0)
//			continue;
//		   else
//			   break;
//		}
//		if(a > i/2)
//		printf("%d\n",i);
//	}
//return 0;
//}