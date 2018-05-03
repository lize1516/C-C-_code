#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqlistD.h"

void test1()
{
	Seq list;
	InitSeqlist(&list);
	PushBack(&list, 1);
	PushBack(&list, 2);
	PushBack(&list, 3);
	PushBack(&list, 4);
	Display(&list);
	PopBack(&list);
	Display(&list);
	PopBack(&list);
	Display(&list);
	PopBack(&list);
	Display(&list);
	PopBack(&list);
	Display(&list);
	PopBack(&list);
	Display(&list);

	ReleaseSpace(&list);
}

void test2()
{
	Seq list;
	InitSeqlist(&list);
	PushFront(&list, 1);
	PushFront(&list, 2);
	PushFront(&list, 3);
	PushFront(&list, 4);
	Display(&list);
	PopFront(&list);
	Display(&list);
	PopFront(&list);
	Display(&list);
	PopFront(&list);
	Display(&list);
	PopFront(&list);
	Display(&list);
	PopFront(&list);
	Display(&list);

	ReleaseSpace(&list);
}

void test3()
{
	Seq list;
	InitSeqlist(&list);
	PushBack(&list, 1);
	PushBack(&list, 2);
	PushBack(&list, 3);
	PushBack(&list, 4);
	PushBack(&list, 5);
	Display(&list);
	Insert(&list, 6, 2);
	Display(&list);

	ReleaseSpace(&list);
}

test4()
{
	Seq list;
	InitSeqlist(&list);
	PushBack(&list, 1);
	PushBack(&list, 2);
	PushBack(&list, 3);
	PushBack(&list, 4);
	PushBack(&list, 5);
	Display(&list);
	Remove(&list, 3);
	Display(&list);
	Remove(&list, 1);
	Display(&list);
	Remove(&list, 5);
	Display(&list);

	ReleaseSpace(&list);
}

test5()
{
	Seq list;
	InitSeqlist(&list);
	PushBack(&list, 1);
	PushBack(&list, 4);
	PushBack(&list, 3);
	PushBack(&list, 4);
	PushBack(&list, 5);
	PushBack(&list, 4);
	PushBack(&list, 5);
	PushBack(&list, 4);
	PushBack(&list, 5);
	Display(&list);
	RemoveAll(&list, 4);
	Display(&list);

	ReleaseSpace(&list);
}

test6()
{
	Seq list;
	InitSeqlist(&list);
	PushBack(&list, 9);
	PushBack(&list, 8);
	PushBack(&list, 6);
	PushBack(&list, 7);
	PushBack(&list, 5);
	PushBack(&list, 3);
	PushBack(&list, 4);
	PushBack(&list, 2);
	PushBack(&list, 1);
	Display(&list);
	Sort(&list);
	Display(&list);
	int tmp = BinarySearch(&list, 6);
	printf("%d\n", tmp);

	ReleaseSpace(&list);
}

void test7()
{
	Seq list;
	InitSeqlist(&list);
	PushBack(&list, 9);
	PushBack(&list, 8);
	PushBack(&list, 6);
	PushBack(&list, 7);
	PushBack(&list, 5);
	PushBack(&list, 3);
	PushBack(&list, 4);
	PushBack(&list, 2);
	PushBack(&list, 1);
	Display(&list);
	Sort(&list);
	Display(&list);
	Reverse(&list);
	Display(&list);

	ReleaseSpace(&list);
}
int main()
{
	//test1();      //尾插，尾删
	//test2();      //头插，头删
	//test3();      //指定位置插入
	//test4();      //删除第一个出现的查找的数
	//test5();      //删除所有指定的数
	//test6();      //排序，二分查找
	test7();      //数组翻转

	system("pause");
	return 0;
}