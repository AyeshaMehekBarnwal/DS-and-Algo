#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

Node * GetNode(int newData)
{
	Node *newNode = new Node();
	newNode->data = newData;
	newNode->next = NULL;
}

void InsertAtBeginning(Node **head, int newData)
{
	Node *newNode = GetNode(newData);
	newNode->next = *head;
	*head = newNode;
}

int findLengthIterative(Node *head)
{
	int count = 0;
	
	while(head != NULL)
	{
		cout << head->data << endl;
		head = head->next;
		count++;
	}

	return count;
}

int countNodes(Node *slowPtr)
{
	Node *temp = slowPtr;
	int count = 1;
	while(temp->next != slowPtr)
	{
		count++;
		temp = temp->next;
	}

	return count;
}

int detectAndCountLoop(Node *head)
{
	if(head == NULL)
		return 0;

	Node *fastPtr = head, *slowPtr = head;
	while(slowPtr && fastPtr && fastPtr->next)
	{
		slowPtr = slowPtr->next;
		fastPtr = fastPtr->next->next;
		if(slowPtr == fastPtr)
			return countNodes(slowPtr);
	}

	return 0;
}

bool detectLoop(Node *head)
{
	if(head == NULL)
		return false;

	Node *fastPtr = head, *slowPtr = head;
	while(slowPtr != NULL && fastPtr != NULL && fastPtr->next !=NULL)
	{
		slowPtr = slowPtr->next;
		fastPtr = fastPtr->next->next;
		if(fastPtr == slowPtr)
			return true;
	}

	return false;
}

bool detectLoopHashing(Node *head)
{
	if(head == NULL)
		return false;

	unordered_set <Node*> s;
	while(head != NULL)
	{
		if(s.find(head) != s.end())
			return true;

		s.insert(head);
		head = head->next;
	}

	return false;
}

int main()
{
	Node *head = NULL;
	InsertAtBeginning (&head, 7);
	InsertAtBeginning (&head, 1);
	InsertAtBeginning (&head, 12);
	InsertAtBeginning (&head, 5);
	InsertAtBeginning (&head, 8);
	InsertAtBeginning (&head, 2);
	InsertAtBeginning (&head, 6);
	InsertAtBeginning (&head, 9);
	InsertAtBeginning (&head, 0); //0 9 6 //2 8 5 12 1 7

	int noOfNodes = findLengthIterative(head);
	cout << "Total number of nodes : " << noOfNodes << endl;

	head->next->next = head;

	detectLoop(head) ? cout << "Loop present!" << endl : cout << "Loop not present!" << endl;
	detectLoopHashing(head) ? cout << "Loop present!" << endl : cout << "Loop not present!" << endl;
	cout << "No. of nodes in loop: " << detectAndCountLoop(head) << endl;

	return 0;
}
