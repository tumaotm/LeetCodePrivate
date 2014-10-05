#include <iostream>
#include <list>

using namespace std;


 struct ListNode {
	     int val;
	     ListNode *next;
	     ListNode(int x) : val(x), next(NULL) {}
	 };

int main()
{	



	return 0;
}

class Solution {
public:
	ListNode *sortList(ListNode *head) {
	if (head == NULL)
		return NULL;
	int k = 0;

	ListNode *p = head;
	while (p)
	{
		k++;
		p=p->next;
	}

	if (k==1)
	{
		return head;
	}

	int l=k/2;
	
	p = head;
	
	ListNode *q = head, *t=NULL;

	for(int i=0;i<l&&q;i++)
	{
		if (i==l-1)
		{
			t = q;
		}
		q = q->next;
	}

	if(t)
		t->next = NULL;

	}
};
