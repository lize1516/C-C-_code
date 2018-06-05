//链表逆序
#if 0
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
ListNode* ReverseList(ListNode* pHead) {
	ListNode* newhead = NULL;
	ListNode* p = NULL;
	while (pHead)
	{
		p = pHead->next;
		pHead->next = newhead;
		newhead = pHead;
		pHead = p;
	}
	return newhead;

}

