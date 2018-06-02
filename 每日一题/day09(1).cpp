//从尾到头打印链表
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x)
		:val(x), next(NULL)
	{	}
};
void BackPrint(ListNode*head,vector<int>& ret)
{
	if (head == NULL)
		return;
	BackPrint(head->next, ret);
	ret.push_back(head->val);
}
vector<int> printListFromTailToHead(ListNode* head) {
	vector<int> ret;
	BackPrint(head,ret);

	return ret;
}
