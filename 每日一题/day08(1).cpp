//删除倒数第k个节点
typedef struct ListNode
{
	int data;
	ListNode* next;
}ListNode;

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
	if (pListHead == NULL)
		return NULL;
	ListNode* first = pListHead;
	ListNode* slow = pListHead;
	while (--k)
	{
		first = first->next;
		if (first == NULL)
			break;
	}
	if (k != 0)
		return NULL;
	if (first != NULL)
	{
		while (first->next)
		{
			first = first->next;
			slow = slow->next;
		}
	}
	return slow;
}
