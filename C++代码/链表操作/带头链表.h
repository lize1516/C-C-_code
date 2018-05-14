#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

typedef struct Node
{
	Node(int _data=int())
	:data(_data)
	, Next(NULL)
	{}

	int data;
	Node* Next;
}Node,*pNode;

class List
{
public:
	List()
		:size(0)
	{
		head = new Node;
	}

	int Size()
	{
		return size;
	}
	void Pushback(int d)   //Î²²å
	{
		assert(head);
		pNode ret = head->Next;
		pNode newNode = new Node(d);
		if (ret == NULL)
		{
			head->Next = newNode;
		}
		else
		{
			pNode tail = NULL;
			while (ret)
			{
				tail = ret;
				ret = ret->Next;
			}
			tail->Next = newNode;
		}
		size++;
	}
	void Popback()     //Î²É¾
	{
		pNode ret = head->Next;
		if (ret == NULL)
			return;
		pNode tail =NULL;
		while (ret->Next)
		{
			tail = ret;
			ret = ret->Next;
		}
		if (ret == head->Next)
		{
			head->Next = NULL;
			delete ret;
		}
		else
		{
			tail->Next = NULL;
			delete ret;
		}
		size--;
	}
	/////////////////////////////////////////////
	void Pushfront(int d)
	{
		assert(head);
		pNode ret = head->Next;
		pNode newNode = new Node(d);
		
		newNode->Next = head->Next;
		head->Next = newNode;
		size++;
	}
	void Popfront()
	{
		pNode del = head->Next;
		if (del == NULL)
		{
			return;
		}
		head->Next =del->Next;
		delete del;
		size--;
	}


	void Display()
	{
		pNode ret = head->Next;
		while (ret)
		{
			cout << ret->data << "->";
			ret = ret->Next;
		}
		cout << "NULL" << endl;
	}



private:
	pNode head;
	int size;
};

void test()
{
	List mylist;
	mylist.Pushback(4);
	mylist.Pushback(3);
	mylist.Pushback(2);
	mylist.Pushback(1);
	mylist.Display();

	mylist.Popback();
	mylist.Display();
	mylist.Popback();
	mylist.Display();
	mylist.Popback();
	mylist.Display();
	mylist.Popback();
	mylist.Display();
	mylist.Popback();
	mylist.Display();
}
void test2()
{
	List list;
	list.Pushfront(1);
	list.Pushfront(2);
	list.Pushfront(3);
	list.Pushfront(4);
	list.Display();
	cout << list.Size() << endl;

	list.Popfront();
	list.Display();
	list.Popfront();
	list.Display();
	cout << list.Size() << endl;
	list.Popfront();
	list.Display();
	list.Popfront();
	list.Display();
	list.Popfront();
	list.Display();


	
}