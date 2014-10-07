#include <iostream>
#include <list>
#include <stdlib.h>

using namespace std;


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
	 ListNode* p1, * p2;
	 p1 = head;
	 while (p1->next!=NULL)
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
	 while (-1 != value)
	 {
		 p1 = head->next;
		 p2 = (ListNode*)malloc(sizeof(ListNode));
		 p2->val = value;
		 p2->next = p1;
		 head -> next = p2;
		 cin >> value;
	 }
	 return head;
 }

 ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
 {
	 if (l1 == NULL)
	 {
		 return l2;
	 }
	 if (l2 == NULL)
	 {
		 return l1;
	 }

	 ListNode *node = NULL;

	 if (l1->val < l2->val) //value
	 {
		 node = l1;
		 l1 = l1->next;
	 }
	 else
	 {
		 node = l2;
		 l2 = l2->next;
	 }

	 ListNode *head = node;

	 while (l1 != NULL&l2 != NULL)
	 {
		 if (l1->val < l2->val)
		 {
			 node->next = l1;
			 node = node->next;
			 l1 = l1->next;
		 }
		 else
		 {
			 node->next = l2;
			 node = node->next;
			 l2 = l2->next;
		 }

	 }
	 if (l1 != NULL)
	 {
		 node->next = l1;
	 }
	 else if (l2 != NULL)
	 {
		 node->next = l2;
	 }

	 return head;

 }

 ListNode *SortList(ListNode *head) {
	 if (head == NULL || head->next == NULL)
	 {
		 return head;
	 }

	 ListNode *fast = head;
	 ListNode *slow = head;

	 while (fast->next != NULL)
	 {
		 fast = fast->next->next;
		 if (fast == NULL)
		 {
			 break;
		 }

		 slow = slow->next;
	 }

	 ListNode *right = slow->next;
	 slow->next = NULL;

	 ListNode *left = SortList(head);
	 right = SortList(right);

	 return mergeTwoLists(left, right);
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
	
	

	Print(SortList(List));

	return 0;
}

/*class Solution {
public:
	ListNode *SortList(ListNode *head) {
		if (head == NULL || head->next == NULL)
		{
			return head;
		}

		ListNode *fast = head;
		ListNode *slow = head;

		while (fast->next != NULL)
		{
			fast = fast->next->next;
			if (fast == NULL)
			{
				break;
			}

			slow = slow->next;
		}

		ListNode *right = slow->next;
		slow->next = Null;

		ListNode *left = sortList(head);
		right = sortList(right);
		
		return mergeTwoLists(left, right);
	}

	ListNode mergeTwoLists(ListNode *l1, ListNode *l2)
	{
		if (l1 == NULL)
		{
			return l2;
		}
		if (l2 == NULL)
		{
			return l1;
		}

		ListNode *node = NULL;

		if (l1->val < l2->val) //value
		{
			node = l1;
			l1 = l1->next;
		}
		else
		{
			node = l2;
			l2 = l2->next;
		}

		ListNode *head = node;

		while (l1 != NULL&l2 != NULL)
		{
			if (l1->val < l2->val)
			{
				node->next = l1;
				node = node->next;
				l1 = l1->next;
			}
			else
			{
				node->next = l2;
				node = node->next;
				l2 = l2->next;
			}

		}
			if (l1!=NULL)
			{
				node->next = l1;
			}
			else if (l2 != NULL)
			{
				node->next = l2;
			}

			return head;
		
	}*/