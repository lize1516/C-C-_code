//用两个栈实现队列

template<class T>
class CQueue
{
public:
	CQueue()
	{}

	CQueue<T>& operator=(CQueue<T>& q)
	{
		if (this != &q)
		{
			CQueue<T> ret1;
			CQueue<T> ret2;
			int _size = q.Size();
			int i = 0;
			for (i = 0; i < _size; i++)
			{
				ret1.Push(q.Front());
				ret2.Push(q.Front());
				q.Pop();
			}

			int _size2 = (*this).Size();
			for (i = 0; i < _size2; i++)
			{
				(*this).Pop();
			}
			for (i = 0; i < _size; i++)
			{
				(*this).Push(ret1.Front());
				ret1.Pop();
			}
			for (i = 0; i < _size; i++)
			{
				q.Push(ret2.Front());
				ret2.Pop();
			}
		}

		return *this;
	}

	CQueue<T>& Swap(CQueue<T>& q)
	{
		CQueue<T> ret;
		int _size = q.Size();
		int i = 0;
		for (i = 0; i < _size; i++)
		{
			ret.Push(q.Front());
			q.Pop();
		}
		int _size2 = (*this).Size();
		for (i = 0; i < _size2; i++)
		{
			q.Push((*this).Front());
			(*this).Pop();
		}

		for (i = 0; i < _size; i++)
		{
			(*this).Push(ret.Front());
			ret.Pop();
		}

		return *this;
	}
	void Push(const T& node)
	{
		s1.push(node);
	}
	void Pop()
	{
		if (s1.empty() && s2.empty())
			return;
		else if (s2.empty())
		{
			int _size = s1.size();
			for (int i = 0; i < _size; i++)
			{
				s2.push(s1.top());
				s1.pop();
			}
		}

		s2.pop();
	}
	T Front()
	{
		if (s1.empty() && s2.empty())
			return NULL;
		else if (s2.empty())
		{
			int _size = s1.size();
			for (int i = 0; i < _size; i++)
			{
				s2.push(s1.top());
				s1.pop();
			}
		}
		
		return s2.top();
	}
	T Back()
	{
		if (s1.empty() && s2.empty())
			return NULL;
		else if (s1.empty())
		{
			int _size = s2.size();
			for (int i = 0; i < _size; i++)
			{
				s1.push(s2.top());
				s2.pop();
			}
		}

		return s1.top();
	}


	int Size()
	{
		return  (s1.size() + s2.size());
	}
	bool Empty()
	{
		if (s1.empty() == true && s2.empty() == true)
			return true;
		else
			return false;
	}


private:
	stack<T> s1;
	stack<T> s2;
};
void test9()
{
	CQueue<int> q1;
	q1.Push(1);
	q1.Push(2);
	q1.Push(3);
	q1.Push(4);
	q1.Push(5);
	cout << "size: "<<q1.Size() << endl;
	cout << "front : "<<q1.Front() << endl;
	cout <<"back: " <<q1.Back() << endl;

	q1.Pop();
	cout << "size: " << q1.Size() << endl;
	cout << "front : " << q1.Front() << endl;
	cout << "back: " << q1.Back() << endl;

	q1.Pop();
	cout << "size: " << q1.Size() << endl;
	cout << "front : " << q1.Front() << endl;
	cout << "back: " << q1.Back() << endl;

	if (q1.Empty())
	{
		cout << "true" << endl;
	}
	else
		cout << "false" << endl;
	q1.Pop();
	q1.Pop();
	q1.Pop();
	q1.Pop();
	if (q1.Empty())
	{
		cout << "true" << endl;
	}
	else
		cout << "false" << endl;
}
void test92()
{
	CQueue<int> q1;
	CQueue<int> q2;
	q1.Push(1);
	q1.Push(2);
	q1.Push(3);
	q1.Push(4);
	q1.Push(5);
	//q2 = q1;
	q1.Swap(q2);

}
