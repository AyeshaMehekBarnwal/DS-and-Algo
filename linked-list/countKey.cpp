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

int countKey(Node *head, int key)
{
	if(head == NULL)
		return 0;
	
	int count = 0;

	while(head != NULL)
	{
		if(head->data == key)
			count++;
		head = head->next;
	}

	return count;
}

int countKeyRcr(Node *head, int key)
{
	if(head == NULL)
		return 0;
	if(head->data == key)
		return 1 + countKey(head->next, key);
	return countKey(head->next, key);
}

int main()
{
	Node *head = NULL;
	int key = 1;
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

	cout << "The number of occurences of given number is: " << countKey(head, key) << endl;
	cout << "The number of occurences of given number is: " << countKeyRcr(head, key) << endl;

	return 0;
}
