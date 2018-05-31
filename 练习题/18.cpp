#include<assert.h>
typedef struct Node
{
	int data;
	Node* Next;
}Node;

void Init(Node** head)
{
	*head = NULL;
}
void Push_back(Node** list, int d)
{
	Node* head = *list;
	Node* newNode = new Node;
	newNode->data = d;
	newNode->Next = NULL;

	if (head == NULL)
	{
		*list = newNode;
	}
	else
	{
		Node* tail = head;
		while (tail->Next)
		{
			tail = tail->Next;
		}
		tail->Next = newNode;
	}
}
Node* Find(Node* list,int d)
{
	assert(list);
	Node* head = list;
	while (head)
	{
		if (head->data == d)
			return head;
		else
			head = head->Next;
	}
	return NULL;
}
void DeleteNode(Node** list, Node* del)
{
	assert(*list);
	Node* head = *list;
	Node* tail = head;
	Node* temp = NULL;
	if (head == del)
	{
		delete head;
		*list = NULL;
	}
	else
	{
		while (tail->Next)
		{
			temp = tail;
			tail = tail->Next;
		}
		if (del == tail)
		{
			temp->Next = NULL;
			delete tail;
		}
		else
		{
			Node* ret = NULL;
			del->data = del->Next->data;
			ret = del->Next;
			del->Next = ret->Next;
			delete ret;
		}
	}
}

void test18()
{
	Node* list;
	Init(&list);
	Push_back(&list, 1);
	Push_back(&list, 2);
	Push_back(&list, 3);
	Push_back(&list, 4);

	Node* del = Find(list, 4);
	DeleteNode(&list, del);
}
