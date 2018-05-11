#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
void display(p pcon)      //�ļ����뺯��
{
	int i = 0;
	FILE*pfin = fopen(FILENAME, "r");
		if (pfin == NULL)
		{
			perror("fopen");
			exit(EXIT_FAILURE);
		}
		Pof tem = { 0 };
		while (fread(&tem, sizeof(Pof), 1, pfin) != 0)
		{
			Addcapacity(pcon);   //������ϢҪ�ȿ��ٿռ�
			pcon->data[i] = tem;
			i++;
			pcon->sz++;
		}
		printf("����ɹ�");
		fclose(pfin);
}
void Save(p pcon)   //����д���ļ�����
{
	int i = 0;
	FILE*pf = fopen(FILENAME, "w");
	if (pf == NULL)
	{
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < pcon->sz; i++)
	{
		fwrite(pcon->data+i, sizeof(Pof), 1, pf);
	}
	fclose(pf);
}

void Init(p list)  //��ʼ������
{
	list->sz = 0;
	list->data = malloc(CAPACITY*sizeof(Pof));   //��ʼ������memset
	if (list->data == NULL)
	{
		perror("use malloc fail!");
		exit(0);//�����˳�
	}
	memset(list->data, 0, CAPACITY*sizeof(Pof));
	list->capacity = CAPACITY;
}

void Addcapacity(p pcon)     //���ݺ���
{
	if (pcon->sz == pcon->capacity)
	{
		//����
		Pof *ptr = realloc(pcon->data, (pcon->capacity + 2)*sizeof(Pof));
		if (ptr == NULL)
		{
			perror("����ʧ��");
			exit(0);
		}
		else
		{
			pcon->data = ptr;
			pcon->capacity += 2;
		}
	}
}
void Destory(p pcon)  //�ͷ��ڴ�
{
	free(pcon->data);
	pcon->data = NULL;
}


void Add(p pcon)    //¼����Ϣ����
{
	char flat = 'Y';
	while(toupper(flat) == 'Y')
	{
		Addcapacity(pcon);
		int i = 0;
		i = pcon->sz;
		fflush(stdin);
		printf("���������֣�");
		scanf("%s", pcon->data[i].name);
		printf("�������Ա�");
		scanf("%s", pcon->data[i].sex);
		printf("���������䣺");
		scanf("%d", &pcon->data[i].age);
		printf("�������ַ��");
		scanf("%s", pcon->data[i].addr);
		printf("������绰��");
		scanf("%s", pcon->data[i].tele);
		pcon->sz++;
		printf("¼��ɹ���\n");
		printf("�Ƿ�Ҫ����¼����Ϣ����ѡ��(��y���n):");
		fflush(stdin);
		scanf("%c", &flat);
		if (toupper(flat) != 'Y')
		{
			if (toupper(flat) == 'N')
				return;
			else
			{
				printf("����������������룺");
				fflush(stdin);
				scanf("%c", &flat);
			}
		}
	}
}
void Show(const p pcon)  // ��ʾ����
{
	int i = 0;
	printf("%6s%6s%5s%15s%15s\n", "����", "�Ա�", "����", "��ַ", "�绰");
	for (i = 0; i < pcon->sz; i++)
	{
		printf("%6s%6s%5d%15s%15s",
			pcon->data[i].name,
			pcon->data[i].sex,
			pcon->data[i].age,
			pcon->data[i].addr,
			pcon->data[i].tele);
		printf("\n");
	}
}
int find(char name[],p pcon )  //Ѱ�Һ���
{
	int i = 0;
	for (i = 0; i <pcon->sz; i++)
	{
		if (strcmp(name, pcon->data[i].name) == 0)
			return i;
	}
		return -1;
}
void Delete(p pcon)    // ɾ������
{
	char name[NAMEMAX];
	printf("������Ҫɾ���˵�������");
	scanf("%s", &name);
	int ret = find(name,pcon);
	if (ret == -1)
		printf("û�ҵ�Ҫɾ�����ˣ�");
	else
	{
		for (int i = ret; i < pcon->sz; i++)
			pcon->data[i] = pcon->data[i + 1];
		pcon->sz--;
		printf("ɾ���ɹ���");
	}
}
void Search(p pcon)    //���Һ���
{
	char name[NAMEMAX];
	printf("������Ҫ�����˵�������");
	scanf("%s", &name);
	int ret = find(name, pcon);
	if (ret == -1)
		printf("û�ҵ�Ҫ���ҵ��ˣ�");
	else
	{
		printf("%6s%6s%5d%15s%15s",
			pcon->data[ret].name,
			pcon->data[ret].sex,
			pcon->data[ret].age,
			pcon->data[ret].addr,
			pcon->data[ret].tele);
	}
}
void Modify(p pcon)    //�޸ĺ���
{
	char name[NAMEMAX];
	printf("������Ҫ�޸��˵�������");
	scanf("%s", &name);
	int ret = find(name, pcon);
	if (ret == -1)
		printf("û�ҵ�Ҫ�޸ĵ��ˣ�");
	else
	{
		printf("���������֣�");
		scanf("%s", pcon->data[ret].name);
		printf("�������Ա�");
		scanf("%s", pcon->data[ret].sex);
		printf("���������䣺");
		scanf("%d", &pcon->data[ret].age);
		printf("�������ַ��");
		scanf("%s", pcon->data[ret].addr);
		printf("������绰��");
		scanf("%s", pcon->data[ret].tele);
		printf("�޸ĳɹ���");
	}
}
void Sort(p pcon)      //������
{
	int i=0, j = 0;
	for (i = 0; i < pcon->sz - 1;i++)
	for (j = 0; j < pcon->sz - 1 - i;j++)
	{
		if (strcmp(pcon->data[j].name,pcon->data[j+1].name)>0)
		{
			Pof tcmp = pcon->data[j];
			pcon->data[j] = pcon->data[j + 1];
			pcon->data[j + 1] = tcmp;
		}
	}
	printf("�������");
}
void Clear(p pcon)   //��պ���
{
	pcon->sz = 0;
	printf("���������");
}
