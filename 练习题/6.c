//6.链表..........从尾到头打印单链表
template<class T>
struct Node
{
	T data;
	struct Node<T>* Next;
};

template<class T>
class List
{
	typedef struct Node<T> Node;
	typedef Node* pNode;
public:
	List()
		:size(0)
	{
		head = NULL;
	}
	void Push_front(T d)
	{
		pNode newNode = new Node;
		newNode->data = d;
		newNode->Next = NULL;
		if (head == NULL)
		{
			head = newNode;
		}
		else
		{
			newNode->Next = head;
			head = newNode;
		}
		size++;
	}
	void Pop_front()
	{
		if (head == NULL)
			return;
		pNode del = head;
		if (head->Next == NULL)
		{
			delete head;
			head = NULL;
		}
		else
		{
			head = head->Next;
			delete del;
		}
		size--;
	}
	////////////////////////////
	void reverseShow()       //从尾到头打印单链表
	{
		_reverseShow(head);
		cout << "NULL" << endl;
	}


	///////////////////////
	int Size()
	{
		return size;
	}
	void Display()
	{
		pNode ret = head;
		while (ret)
		{
			cout << ret->data << "->";
			ret = ret->Next;
		}
		cout << "NULL" << endl;
	}
private:
	void _reverseShow(pNode root)
	{
		if (root == NULL)
			return;
		if (root->Next!=NULL)
		_reverseShow(root->Next);

		cout << root->data << "->";
	}

private:
	pNode head;
	int size;
};
void test6()
{
	List<int> list;
	list.Push_front(4);
	list.Push_front(3);
	list.Push_front(2);
	list.Push_front(1);
	list.Display();

	/*list.Pop_front();
	list.Pop_front();
	list.Display();
	list.Pop_front();
	list.Pop_front();
	list.Pop_front();
	list.Display();*/
	list.reverseShow();

}
