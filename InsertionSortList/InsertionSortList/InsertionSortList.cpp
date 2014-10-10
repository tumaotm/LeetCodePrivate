#include <iostream>
#include <list>

using namespace std;

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

 ListNode* InitList() //Initial a List
 {
	 ListNode *head;
	 head = (ListNode*)malloc(sizeof(ListNode));
	 if (head == NULL)
	 {
		 cout << "Yamede" << endl;
		 return NULL;
	 }
	 head->next = NULL;
	 return head;
 }

 void InsertListToTail(ListNode* head, int value)
 {
	 ListNode* p1, *p2;
	 p1 = head;
	 while (p1->next != NULL)
	 {
		 p1 = p1->next;
	 }
	 p2 = (ListNode*)malloc(sizeof(ListNode));
	 p2->val = value;
	 p2->next = NULL;
	 p1->next = p2;
 }



 ListNode* CreateList(ListNode *head)
 {
	 ListNode *p1, *p2;
	 head = (ListNode*)malloc(sizeof(ListNode));
	 head->next = NULL;

	 int value;
	 cout << "input a row of number, end with -1" << endl;
	 cin >> value;
	 //head->val = value;

	 while (-1 != value)
	 {
		 p1 = head->next;
		 p2 = (ListNode*)malloc(sizeof(ListNode));
		 p2->val = value;
		 p2->next = p1;
		 head->next = p2;
		 cin >> value;
	 }
	 return head;
 }




 ListNode *insertionSortList(ListNode *head) {
	 if (NULL == head || head->next == NULL)
	 {
		 return head;
	 }

	 ListNode *node = head;
	 ListNode *p = NULL;

	 while (node->next != NULL)
	 {
		 p = node->next;

		 if (p->val >= node->val)
		 {
			 node = node->next;
			 continue;
		 }

		 node->next = p->next;

		 if (p->val <= head->val)
		 {
			 p->next = head;
			 head = p;
			 continue;
		 }

		 ListNode *findInsertionPos(ListNode *a, ListNode*b);

		 ListNode *pos = findInsertionPos(head, p);

		 p->next = pos->next;
		 pos->next = p;

		
	 }
	 return head;
 }
	ListNode *findInsertionPos(ListNode*head, ListNode*p)
		{
			ListNode *pos = head;
			while (head != NULL && head->val< p->val)
			{
				pos = head;
				head = head->next;
			}
			return pos;
		}

	


void Print(ListNode* node)
{
	ListNode *p;
	p = node->next;
	while (p != NULL)
	{
		cout << p->val << endl;
		p = p->next;
	}
}

int main()
{
	ListNode *head = InitList();
	ListNode *List = CreateList(head);

	Print(insertionSortList(List));

	return 0;
}