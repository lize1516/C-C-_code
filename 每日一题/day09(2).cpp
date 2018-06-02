//复杂链表的拷贝
struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) 
		:label(x), next(NULL), random(NULL)
	{	}
};
typedef struct RandomListNode Node;
void Init(Node** head)
{
	*head = NULL;
}
void PushBack(Node** head, int d)
{
	Node* newNode = new Node(d);
	Node* list = *head;
	if (list == NULL)
	{
		*head = newNode;
	}
	else
	{
		Node* tail = NULL;
		while (list)
		{
			tail = list;
			list = list->next;
		}
		tail->next = newNode;
	}
}
Node* Find(Node* head,int d)
{
	Node* list = head;
	while (list)
	{
		if (list->label == d)
			return list;
		list = list->next;
	}
	return NULL;
}
RandomListNode* Clone(RandomListNode* pHead)
{
	if (pHead == NULL)
		return NULL;
	RandomListNode* list = pHead;
	RandomListNode* newhead=NULL;
	RandomListNode* p = NULL;
	//将新节点连接到链表上
	while (list)
	{
		RandomListNode* newNode = new RandomListNode(list->label);
		newNode->next = list->next;
		list->next = newNode;
		list = newNode->next;
	}
	list = pHead;
	while (list)
	{
		p = list->next;
		if (list->random)
		p->random = list->random->next;
		list =p->next;
	}
	//将新节点与原来的链表断开
	list = pHead;
	newhead =pHead->next;
	while (list)
	{
		p = list->next;
		list->next = p->next;
		list = list->next;

		if (list)
		p->next = list->next;
	}

	return newhead;
}
int main()
{
	Node* mylist;
	Init(&mylist);
	PushBack(&mylist, 1);
	PushBack(&mylist, 2);
	PushBack(&mylist, 3);
	PushBack(&mylist, 4);
	Find(mylist, 1)->random = Find(mylist, 3);
	Find(mylist, 2)->random = Find(mylist, 1);
	Find(mylist, 3)->random = Find(mylist, 4);
	Find(mylist, 4)->random = Find(mylist, 2);
	Node* newlist = Clone(mylist);

	system("pause");
	return 0;
}
