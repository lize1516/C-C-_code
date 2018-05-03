#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqlistD.h"

void InitSeqlist(p ps)      //初始化
{
	ps->sz = 0;
	ps->catacity = CATACITY;
	ps->data = (Datatype*)malloc(sizeof(Datatype)* CATACITY);
	if (ps->data == NULL)
	{
		perror("malloc:");
		exit(EXIT_FAILURE);
	}
	memset(ps->data, 0, sizeof(Datatype)*CATACITY);
}

void Extend(p ret)         //增容
{
	Datatype*tmp = realloc(ret->data, sizeof(Datatype)*(ret->catacity + 2));
	if (tmp == NULL)
	{
		perror("realloc:");
		exit(EXIT_FAILURE);
	}
	else
	{
		ret->data = tmp;
		ret->catacity += 2;
	}
}
void PushBack(p ps, Datatype d)     //尾插
{
	assert(ps);
	if (ps->sz == ps->catacity)
		Extend(ps);

	if (ps->sz == MAX)
		return;
	ps->data[ps->sz] = d;
	ps->sz++;
}

void PopBack(p ps)       //尾删
{
	assert(ps);
	if (ps->sz != 0)
	{
		ps->sz--;
	}
	else
		return;
}

void PushFront(p ps, Datatype d)      //头插
{
	int i = 0;
	assert(ps);

	if (ps->sz == ps->catacity)
		Extend(ps);

	if (ps->sz == MAX)
	{
		return;
	}
	for (i = ps->sz; i>0; i--)
	{
		ps->data[i] = ps->data[i - 1];
	}
	ps->data[0] = d;
	ps->sz++;
}
void PopFront(p ps)       //头删
{
	assert(ps);
	int i = 0;
	for (i = 0; i < ps->sz - 1; i++)
	{
		ps->data[i] = ps->data[i + 1];
	}
	ps->sz--;
}

int  Find(p ps, Datatype d)     //查找
{
	int i = 0;
	assert(ps);
	if (ps->sz == 0)
		return -1;
	while (i<ps->sz)
	{
		if (ps->data[i] == d)
			return i;
		i++;
	}
	return -1;
}

void Insert(p ps, Datatype d, int pos)          //在选定位置处插入一个数
{
	assert(ps);
	if (ps->sz == MAX)
		return;
	int i = 0;
	for (i = ps->sz; i >= pos; i--)
	{
		ps->data[i] = ps->data[i - 1];
	}
	ps->data[pos - 1] = d;
	ps->sz++;
}

void Remove(p ps, Datatype d)      //删除一个数
{
	assert(ps);
	if (ps->sz == 0)
		return;
	int ret = Find(ps, d);
	if (ret == -1)
	{
		return;
	}
	else
	{
		int i = 0;
		for (i = ret; i < ps->sz - 1; i++)
			ps->data[i] = ps->data[i + 1];
		ps->sz--;
	}
}

void RemoveAll(p ps, Datatype d)      //删除对应的所有数
{
	int i = 0;
	assert(ps);
	if (ps->sz == 0)
		return;
	while (1)
	{
		int ret = Find(ps, d);
		if (ret == -1)
		{
			return;
		}
		else
		{
			Remove(ps, d);
		}
	}
}

void Reverse(p ps)        //翻转
{
	assert(ps);
	int left = 0;
	int right = ps->sz - 1;
	while (left < right)
	{
		Datatype ret = ps->data[left];
		ps->data[left] = ps->data[right];
		ps->data[right] = ret;
		left++;
		right--;
	}
}

void Sort(p ps)          //排序
{
	int i = 0, j = 0;
	assert(ps);
	for (i = 0; i < (ps->sz - 1); i++)
	for (j = 0; j < (ps->sz - 1 - i); j++)
	{
		if (ps->data[j]>ps->data[j + 1])
		{
			int tmp = ps->data[j];
			ps->data[j] = ps->data[j + 1];
			ps->data[j + 1] = tmp;
		}
	}
}

int BinarySearch(p ps, Datatype d)        //二分查找
{
	int left = 0;
	int right = ps->sz - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (ps->data[mid] > d)
			right = mid - 1;
		else if (ps->data[mid] < d)
			left = mid + 1;
		else
			return mid;
	}
	return -1;
}

void Display(const p ps)         //显示函数
{
	int i = 0;
	for (i = 0; i < ps->sz; i++)
		printf("%d ", ps->data[i]);
	printf("\n");
}

void ReleaseSpace(p ps)         //释放空间
{
	free(ps->data);
	ps->data = NULL;
}