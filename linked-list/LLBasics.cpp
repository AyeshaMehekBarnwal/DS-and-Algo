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

void InsertAfterNode(Node *prevNode, int newData)
{
	Node *newNode = GetNode(newData);
	newNode->next = prevNode->next;
	prevNode->next = newNode;
}

void InsertAtEnd(Node **head, int newData)
{
	Node *newNode = GetNode(newData);
	Node *last = *head;

	if(*head == NULL)
	{
		*head = newNode;
		return;
	}

	while(last->next != NULL)
		last = last->next;

	last->next = newNode;
	return;
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

void deleteKey(Node **head, int key)
{
	Node *temp = *head, *prev;

	if(temp == NULL)
		return;

	if(temp != NULL && temp->data == key)
	{
		*head = temp->next;
		free(temp);
		return;
	}

	while(temp != NULL && temp->data != key)
	{
		prev = temp;
		temp = temp->next;
	}

	prev->next = temp->next;
	free(temp);
}

void deleteNode(Node **head, int position)
{
	Node *temp = *head, *prev;

	if(*head == NULL)
		return;

	if(position == 0)
	{
		*head = temp->next;
		free(temp);
		return;
	}

	for(int i = 0; i < position - 1 && temp != NULL; i++)
		temp = temp->next;

	if(temp == NULL || temp->next == NULL)
		return;

	prev = temp->next->next;
	free(temp->next);
	temp->next = prev;
	
}

void deleteList(Node **head)
{
	if(*head == NULL)
		return;

	Node *current = *head, *next;
	while(current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

int main()
{
	Node *head = NULL;
	InsertAtEnd (&head, 6);
	InsertAtBeginning (&head, 7);
	InsertAtBeginning (&head, 1);
	InsertAtEnd (&head, 4);
	InsertAfterNode(head->next, 8);

	int noOfNodes = Traverse(head);
	cout << "Total number of nodes : " << noOfNodes << endl;

	deleteKey(&head, 1);
	noOfNodes = Traverse(head);
	cout << "Total number of nodes after deletion : " << noOfNodes << endl;

	deleteNode(&head, 2);
	noOfNodes = Traverse(head);
	cout << "Total number of nodes after deletion : " << noOfNodes << endl;

	return 0;
}
