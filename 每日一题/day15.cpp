//右旋链表

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void Init(ListNode** head)
{
	*head = NULL;
}
void Push_back(ListNode** list, int d)
{
	ListNode* head = *list;
	ListNode* newNode = new ListNode(d);

	if (head == NULL)
	{
		*list = newNode;
	}
	else
	{
		ListNode* tail = head;
		while (tail->next)
		{
			tail = tail->next;
		}
		tail->next = newNode;
	}
}
int Count(ListNode* head)
{
	int count = 0;
	while (head)
	{
		head = head->next;
		count++;
	}
	return count;
}
ListNode *rotateRight(ListNode *head, int k) {
	if (head == NULL)
		return NULL;
	int num = k%Count(head);

	if (num== 0)
		return head;
	ListNode* first = head;
	ListNode* slow = head;
	ListNode* newhead = NULL;
	while (num--)
	{
		if (first == NULL)
			return NULL;
		first = first->next;
	}
	if (first==NULL)
		return head;

	while (first->next)
	{
		first = first->next;
		slow = slow->next;
	}
	ListNode* tail = first;
	newhead = slow->next;
	slow->next = NULL;
	first->next = head;
	
	return newhead;
}
int main()
{
	ListNode* list;
	Init(&list);
	Push_back(&list, 1);
	Push_back(&list, 2);
	Push_back(&list, 3);
	Push_back(&list, 4);
	Push_back(&list, 5);

	ListNode* ret = rotateRight(list, 6);
	system("pause");
	return 0;
}

//2.将有序链表转换成一棵高度平衡的搜索二叉树
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
void Init(ListNode** head)
{
	*head = NULL;
}
void Push_back(ListNode** list, int d)
{
	ListNode* head = *list;
	ListNode* newNode = new ListNode(d);

	if (head == NULL)
	{
		*list = newNode;
	}
	else
	{
		ListNode* tail = head;
		while (tail->next)
		{
			tail = tail->next;
		}
		tail->next = newNode;
	}
}
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};
TreeNode* CreateBST(vector<int>& arr,int start,int end)
{
	if (start > end)
		return NULL;

	int mid = (start + end) / 2;
	TreeNode* root = new TreeNode(arr[mid]);
	root->left = CreateBST(arr, start, mid - 1);
	root->right = CreateBST(arr, mid + 1, end);
	return root;
}

TreeNode *sortedListToBST(ListNode *head) {
	if (head == NULL)
		return NULL;
	vector<int> arr;
	ListNode* temp = head;
	while (temp)
	{
		arr.push_back(temp->val);
		temp = temp->next;
	}
	return CreateBST(arr,0,arr.size()-1);

}

TreeNode *sortedListToBST2(ListNode *head) {
	if (head == NULL)
		return NULL;
	if (head->next == NULL)
		return new TreeNode(head->val);

	ListNode* first = head->next->next;
	ListNode* slow = head;
	while (first&&first->next)
	{
		first = first->next->next;
		slow = slow->next;
	}
	ListNode* left = head;
	ListNode* mid = slow->next;
	ListNode* right=mid->next ;
	slow->next = NULL;

	TreeNode* root = new TreeNode(mid->val);
	root->left = sortedListToBST2(left);
	root->right = sortedListToBST2(right);

	return root;
}
int main()
{
	ListNode* list;
	Init(&list);
	Push_back(&list, 1);
	Push_back(&list, 2);
	/*Push_back(&list, 3);
	Push_back(&list, 4);
	Push_back(&list, 5);
	Push_back(&list, 6);
	Push_back(&list, 7);
	Push_back(&list, 8);
	Push_back(&list, 9);
	Push_back(&list, 10);
*/



	TreeNode* root = sortedListToBST(list);

	return 0;
}
