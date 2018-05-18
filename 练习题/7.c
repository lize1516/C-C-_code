typedef struct Node
{
	int data;
	Node* Rchild;
	Node* Lchild;
	Node* parent;
}Node;
//////////////////////////////////////////////////////
Node* ConstructCore(int* startPre,int* endPre,int* startIn,int* endIn)     //7.重建二叉树
{
	//确定根节点
	int rootValue = startPre[0];
	Node* root = new Node;
	root->data = rootValue;
	root->Lchild = root->Rchild = NULL;
	root->parent = NULL;

	if (startPre == endPre)
	{
		if (startIn == endIn)
			return root;
		else
			throw std::exception("Invalid input.");
	}

	//在中序遍历中找到根节点的值
	int* rootIn = startIn;
	while (rootIn <= endIn&& *rootIn != rootValue)
	{
		rootIn++;
	}

	if (rootIn == endIn&&*rootIn != rootValue)
		throw std::exception("Invalid input.");

	int leftlength = rootIn - startIn;
	int* leftPreEnd = startPre + leftlength;
	if (leftlength>0)
	{
		//构建左子树
		root->Lchild = ConstructCore(startPre+1,leftPreEnd,startIn,rootIn-1);

		if (root->Lchild)
		root->Lchild->parent = root;
	}
	if (leftlength < endPre - startPre)
	{
		//构建右子树
		root->Rchild = ConstructCore(leftPreEnd+1,endPre,rootIn+1,endIn);

		if (root->Rchild)
		root->Rchild->parent = root;
	}
	return root;
}
Node* Construct(int* Pre, int* In, int len)
{
	if (Pre == NULL || In == NULL || len <= 0)
		return NULL;
	return ConstructCore(Pre, Pre + len - 1, In, In + len - 1);
}

void _InOrder(Node* root)
{
	if (root == NULL)
		return;

	cout << root->data << ",";
	_InOrder(root->Lchild);
	_InOrder(root->Rchild);
}
void InOrder(Node* root)
{
	_InOrder(root);
	cout << endl;
}


void test7()
{
	int PreOrdershow[8] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	int InOrdershow[8] = { 4, 7, 2, 1, 5, 3, 8, 6 };
	Node* root=Construct(PreOrdershow, InOrdershow, 8);
	InOrder(root);
	Node* ret=find(root,2);
	Node* temp=GetNext(root,ret);
	cout << temp->data << endl;
}