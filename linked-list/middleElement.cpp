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

int middleElement(Node *head)
{
	if(head == NULL)
		return 0;

	Node *fastPtr = head, *slowPtr = head;
	while(fastPtr != NULL && fastPtr->next != NULL)
	{
		slowPtr = slowPtr->next;
		fastPtr = fastPtr->next->next;
	}
	return slowPtr->data;
}

int main()
{
	Node *head = NULL;
	int key = 67;
	InsertAtBeginning (&head, 7);
	InsertAtBeginning (&head, 1);
	InsertAtBeginning (&head, 12);
	InsertAtBeginning (&head, 5);
	InsertAtBeginning (&head, 8);
	InsertAtBeginning (&head, 2);
	InsertAtBeginning (&head, 6);
	InsertAtBeginning (&head, 9);
	InsertAtBeginning (&head, 0);

	int noOfNodes = findLengthIterative(head);
	cout << "Total number of nodes : " << noOfNodes << endl;

	cout << "The middle element is: " << middleElement(head) << endl;

	return 0;
}
