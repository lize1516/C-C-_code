#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
enum Choose
{
	EXIT,     //退出
	ADD,      //录入信息
	SHOW,     //显示信息
	DELETE,	  //删除信息
	SEARCH,   //查找信息
	MODIFY,   //修改函数
	SORT,     //排序
	CLEAR,    //清空
	DISPLAY   //读入文件
};
void my_enum()
{
	printf("\n\n\t\t\t【通讯录】\n");
	printf("\n\t\t1.录入信息    2.显示信息\n");
	printf("\t\t3.删除信息    4.查找信息\n");
	printf("\t\t5.修改信息    6.信息排序\n");
	printf("\t\t7.清空信息    8.读入文件\n");

	printf("\t请输入数字（1--7），【0退出程序】:");
}

int main()
{
	Contact list;
	Init(&list);
	int i = 0;
	do
	{
		my_enum();
		scanf("%d", &i);
		switch (i)
		{
		case ADD:
			Add(&list);
			break;
		case SHOW:
			Show(&list);
			break;
		case DELETE:
			Delete(&list);
			break;
		case SEARCH:
			Search(&list);
			break;
		case MODIFY:
			Modify(&list);
			break;
		case SORT:
			Sort(&list);
			break;
		case CLEAR:
			Clear(&list);
			break;
		case EXIT:
			Save(&list);
			Destory(&list);
			printf("退出系统");
			break;
		case DISPLAY:
			display(&list);  //文件读入
			break;
		default:
			printf("输入数字有错，请重新输入！");
			break;
		}
	} while (i);
	return 0;
}