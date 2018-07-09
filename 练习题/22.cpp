ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead==NULL)
            return NULL;
    ListNode* first = pListHead;
	ListNode* slow = pListHead;
	while (--k)
	{
		if (first == NULL)
			return NULL;
		first = first->next;
	}
	if (first == NULL)
		return NULL;
	while (first->next)
	{
        first=first->next;
		slow = slow->next;
	}
	return slow;    //
    }
