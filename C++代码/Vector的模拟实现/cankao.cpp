#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
template <typename T>
struct Node
{
	Node(const T& data = T())
	: _data(data)
	, _next(NULL)
	, _pre(NULL)
	{}
	T _data;
	struct Node* _next;
	struct Node* _pre;
};
template<typename T, typename Ref, typename Ptr>//T,T&,T*
struct ListIterator
{
public:
	typedef Node<T> Node;
	typedef ListIterator<T, Ref, Ptr> Self;
	ListIterator()
		: _pCur(NULL)
	{}
	ListIterator(Node* pCur)
		: _pCur(pCur)
	{}
	ListIterator(const Self& s)
		: _pCur(s._pCur)
	{}
	Self& operator=(const Self& s)
	{
		if (*this != s)
			_pCur = s._pCur;
		return *this;
	}
	Ref operator*()
	{
		return _pCur->_data;
	}
	Ptr operator->()
	{
		return &(_pCur->_data);
	}
	Self& operator++()//前置++
	{
		_pCur = _pCur->_next;
		return *this;
	}
	Self operator++(int)//后置++
	{
		Self tmp(*this);
		_pCur = _pCur->_next;
		return tmp;
	}
	Self& operator--()//前置--
	{
		_pCur = _pCur->_pre;
		return *this;
	}
	Self operator--(int)//后置--
	{
		Self tmp(*this);
		_pCur = _pCur->_pre;
		return tmp;
	}
	bool operator==(const Self& s)
	{
		return _pCur == s._pCur;
	}
	bool operator!=(const Self& s)
	{
		return _pCur != s._pCur;
	}
private:
	Node* _pCur;
};

template <typename T>
class List
{
public:
	typedef Node<T> Node;
	typedef ListIterator<T, T&, T*> Iterator;
	List()
		: _pHead(new Node)
	{
		_pHead->_next = _pHead;
		_pHead->_pre = _pHead;
	}
	List(const T* arr, size_t size)
		: _pHead(new Node)
	{
		_pHead->_next = _pHead;
		_pHead->_pre = _pHead;
		for (size_t i = 0; i < size; i++)
			PushBack(arr[i]);
	}
	List(const List<T>& list)
		: _pHead(new Node(list._pHead->_data))
	{
		_pHead->_next = _pHead;
		_pHead->_pre = _pHead;
		Node* cur = list._pHead->_next;
		while (cur != list._pHead)
		{
			PushBack(cur->_data);
			cur = cur->_next;
		}
	}
	//~List()
	//{
	//	Clear();
	//	delete _pHead;
	//	_pHead = NULL;
	//}
	Iterator Begin()
	{
		return Iterator(_pHead->_next);
	}
	Iterator End()
	{
		return Iterator(_pHead);
	}
	bool operator==(const List<T>& list)
	{
		return _pHead == list._pHead;
	}
	bool operator!=(const List<T>& list)
	{
		return _pHead != list._pHead;
	}
	List<T>& operator=(const List<T>& list)
	{
		if (*this != list)
		{
			_pHead = new Node(list._pHead->_data);
			_pHead->_next = _pHead;
			_pHead->_pre = _pHead;
			Node* cur = list._pHead->_next;
			while (cur != list._pHead)
			{
				PushBack(cur->_data);
				cur = cur->_next;
			}
		}
		return *this;
	}
	//void Clear()
	//{

	//}
	bool Empty()
	{
		return _pHead->_next == _pHead;
	}
	void PushBack(const T& data)
	{
		Node* newNode = new Node(data);
		if (Empty())
		{
			_pHead->_next = newNode;
			newNode->_next = _pHead;
			newNode->_pre = _pHead;
			_pHead->_pre = newNode;
		}
		else
		{
			Node* pTail = _pHead->_pre;
			pTail->_next = newNode;
			newNode->_pre = pTail;
			newNode->_next = _pHead;
			_pHead->_pre = newNode;
		}
	}
	void PopBack()
	{
		if (Empty())
			return;
		Node* pTail = _pHead->_pre;
		pTail->_pre->_next = _pHead;
		_pHead->_pre = pTail->_pre;
		delete pTail;
		pTail = NULL;

		//Node* pTail = _pHead->_pPre->_pPre;
		//delete pTail->_pNext;
		//pTail->_pNext = _pHead;
		//_pHead->_pPre = pTail;
	}
	void PushFront(const T& data)
	{
		Node* newNode = new Node(data);
		if (Empty())
		{
			newNode->_next = _pHead;
			newNode->_pre = _pHead;
			_pHead->_next = newNode;
			_pHead->_pre = newNode;
		}
		else
		{
			newNode->_next = _pHead->_next;
			newNode->_pre = _pHead;
			_pHead->_next->_pre = newNode;
			_pHead->_next = newNode;
		}
	}
	void PopFront()
	{
		if (Empty())
			return;
		Node* pDel = _pHead->_next;
		_pHead->_next = pDel->_next;
		pDel->_next->_pre = _pHead;
		delete pDel;
		pDel = NULL;
	}
	Iterator Insert(Iterator pos, const T& data);
	Iterator Erase(Iterator pos);
	size_t Size()const
	{
		size_t size = 0;
		Node* pcur = _pHead->_next;
		while (pcur != _pHead)
		{
			size++;
			pcur = pcur->_next;
		}
		return size;
	}
	T& Front()
	{
		return _pHead->_next->_data;
	}
	const T& Front()const
	{
		return _pHead->_next->_data;
	}
	T& Back()
	{
		return _pHead->_pre->_data;
	}
	const T& Back()const
	{
		return _pHead->_pre->_data;
	}

private:
	Node* _pHead;
};
