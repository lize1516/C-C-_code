#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
void display(p pcon)      //文件读入函数
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
			Addcapacity(pcon);   //加载信息要先开辟空间
			pcon->data[i] = tem;
			i++;
			pcon->sz++;
		}
		printf("读入成功");
		fclose(pfin);
}
void Save(p pcon)   //数据写入文件函数
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

void Init(p list)  //初始化函数
{
	list->sz = 0;
	list->data = malloc(CAPACITY*sizeof(Pof));   //初始化函数memset
	if (list->data == NULL)
	{
		perror("use malloc fail!");
		exit(0);//正常退出
	}
	memset(list->data, 0, CAPACITY*sizeof(Pof));
	list->capacity = CAPACITY;
}

void Addcapacity(p pcon)     //增容函数
{
	if (pcon->sz == pcon->capacity)
	{
		//增容
		Pof *ptr = realloc(pcon->data, (pcon->capacity + 2)*sizeof(Pof));
		if (ptr == NULL)
		{
			perror("增容失败");
			exit(0);
		}
		else
		{
			pcon->data = ptr;
			pcon->capacity += 2;
		}
	}
}
void Destory(p pcon)  //释放内存
{
	free(pcon->data);
	pcon->data = NULL;
}


void Add(p pcon)    //录入信息函数
{
	char flat = 'Y';
	while(toupper(flat) == 'Y')
	{
		Addcapacity(pcon);
		int i = 0;
		i = pcon->sz;
		fflush(stdin);
		printf("请输入名字：");
		scanf("%s", pcon->data[i].name);
		printf("请输入性别：");
		scanf("%s", pcon->data[i].sex);
		printf("请输入年龄：");
		scanf("%d", &pcon->data[i].age);
		printf("请输入地址：");
		scanf("%s", pcon->data[i].addr);
		printf("请输入电话：");
		scanf("%s", pcon->data[i].tele);
		pcon->sz++;
		printf("录入成功！\n");
		printf("是否要继续录入信息，请选择(是y或否n):");
		fflush(stdin);
		scanf("%c", &flat);
		if (toupper(flat) != 'Y')
		{
			if (toupper(flat) == 'N')
				return;
			else
			{
				printf("输入错误，请重新输入：");
				fflush(stdin);
				scanf("%c", &flat);
			}
		}
	}
}
void Show(const p pcon)  // 显示函数
{
	int i = 0;
	printf("%6s%6s%5s%15s%15s\n", "姓名", "性别", "年龄", "地址", "电话");
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
int find(char name[],p pcon )  //寻找函数
{
	int i = 0;
	for (i = 0; i <pcon->sz; i++)
	{
		if (strcmp(name, pcon->data[i].name) == 0)
			return i;
	}
		return -1;
}
void Delete(p pcon)    // 删除函数
{
	char name[NAMEMAX];
	printf("请输入要删除人的姓名：");
	scanf("%s", &name);
	int ret = find(name,pcon);
	if (ret == -1)
		printf("没找到要删除的人！");
	else
	{
		for (int i = ret; i < pcon->sz; i++)
			pcon->data[i] = pcon->data[i + 1];
		pcon->sz--;
		printf("删除成功！");
	}
}
void Search(p pcon)    //查找函数
{
	char name[NAMEMAX];
	printf("请输入要查找人的姓名：");
	scanf("%s", &name);
	int ret = find(name, pcon);
	if (ret == -1)
		printf("没找到要查找的人！");
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
void Modify(p pcon)    //修改函数
{
	char name[NAMEMAX];
	printf("请输入要修改人的姓名：");
	scanf("%s", &name);
	int ret = find(name, pcon);
	if (ret == -1)
		printf("没找到要修改的人！");
	else
	{
		printf("请输入名字：");
		scanf("%s", pcon->data[ret].name);
		printf("请输入性别：");
		scanf("%s", pcon->data[ret].sex);
		printf("请输入年龄：");
		scanf("%d", &pcon->data[ret].age);
		printf("请输入地址：");
		scanf("%s", pcon->data[ret].addr);
		printf("请输入电话：");
		scanf("%s", pcon->data[ret].tele);
		printf("修改成功！");
	}
}
void Sort(p pcon)      //排序函数
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
	printf("完成排序！");
}
void Clear(p pcon)   //清空函数
{
	pcon->sz = 0;
	printf("数据已清空");
}
