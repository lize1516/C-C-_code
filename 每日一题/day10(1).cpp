//合并两条单调递增的链表
#if 0
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{

	if (pHead1 == NULL)
		return pHead2;
	else if (pHead2 == NULL)
		return pHead1;

	ListNode* ret = NULL;
	ListNode*tail = NULL;
	
	while (pHead1&&pHead2)
	{
		if (((pHead1->val) > (pHead2->val))&&ret==NULL)
		{
			ret = pHead2;
			pHead2 = pHead2->next;
			tail = ret;
		}
		else if (ret == NULL)
		{
			ret = pHead1;
			pHead1 = pHead1->next;
			tail =ret;
		}
		else if ((pHead1->val) > (pHead2->val))
		{
			tail->next = pHead2;
			pHead2 = pHead2->next;
			tail = tail->next;
		}
		else
		{
			tail->next =pHead1;
			pHead1 = pHead1->next;
			tail = tail->next;
		}
	}
	if (pHead1 == NULL&&pHead2 != NULL)
		tail->next = pHead2;
	else if (pHead1 != NULL&&pHead2 == NULL)
		tail->next = pHead1;

	return ret;
}
