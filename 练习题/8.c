/////////////////////////////////////////////////////
//8.二叉树的下一个节点
Node* GetNext(Node* root, Node* key)
{
	if (root == NULL)
		return NULL;
	Node* Next = NULL;
	if (key->Rchild != NULL)
	{
		Node* ret = key->Rchild;
		while (ret->Lchild != NULL)
		{
			ret = ret->Lchild;
		}
		Next = ret;
	}
	else if (key->parent != NULL)
	{
		Node* ret = key;
		Node* Parent = key->parent;
		while (Parent != NULL&&Parent->Rchild == ret)
		{
			ret = Parent;
			Parent = Parent->parent;
		}
		Next = Parent;
	}
	return Next;

}
Node* find(Node* root,int d)
{
	if (root == NULL)
		return NULL;
	if (root->data == d)
		return root;
	
	if (find(root->Lchild, d) != NULL)
		return find(root->Lchild, d);
	if (find(root->Rchild, d) != NULL)
		return find(root->Rchild, d);
	return NULL;
}

//////////////////////////////////////////////