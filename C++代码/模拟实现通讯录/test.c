#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
enum Choose
{
	EXIT,     //�˳�
	ADD,      //¼����Ϣ
	SHOW,     //��ʾ��Ϣ
	DELETE,	  //ɾ����Ϣ
	SEARCH,   //������Ϣ
	MODIFY,   //�޸ĺ���
	SORT,     //����
	CLEAR,    //���
	DISPLAY   //�����ļ�
};
void my_enum()
{
	printf("\n\n\t\t\t��ͨѶ¼��\n");
	printf("\n\t\t1.¼����Ϣ    2.��ʾ��Ϣ\n");
	printf("\t\t3.ɾ����Ϣ    4.������Ϣ\n");
	printf("\t\t5.�޸���Ϣ    6.��Ϣ����\n");
	printf("\t\t7.�����Ϣ    8.�����ļ�\n");

	printf("\t���������֣�1--7������0�˳�����:");
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
			printf("�˳�ϵͳ");
			break;
		case DISPLAY:
			display(&list);  //�ļ�����
			break;
		default:
			printf("���������д����������룡");
			break;
		}
	} while (i);
	return 0;
}