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

int Traverse(Node *head)
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

int getNthNodeBeginning(Node *head, int n)
{
	if(head == NULL)
		return 0;

	while(--n)
		head = head->next;

	return head->data;
}

int getNthNodeEnd(Node *head, int n)
{
	Node *temp = head, *current = head;
	int count = n;

	while(count--)
		temp = temp->next;

	while(temp != NULL)
	{
		current = current->next;
		temp = temp->next;
	}
	
	return current->data;
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
	InsertAtBeginning (&head, 0);

	int noOfNodes = Traverse(head);
	cout << "Total number of nodes : " << noOfNodes << endl;

	int nthNode = getNthNodeBeginning(head, 4);
	cout << nthNode << endl;

	nthNode = getNthNodeEnd(head, 2);
	cout << nthNode << endl;

	return 0;
}
