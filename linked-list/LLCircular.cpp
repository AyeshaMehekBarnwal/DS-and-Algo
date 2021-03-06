#include<bits/stdc++.h>
using namespace std;

class Node
{
	public:
		int data;
		Node *next;
};

void insertToEmpty(Node **last, int data)
{
	if(*last != NULL)
	{
		cout << "Linked list is not empty" << endl;
		return;
	}
	Node *newNode = new Node;
	newNode->data = data;
	*last = newNode;
	(*last)->next = *last;
}

void insertAtBeginning(Node **last, int data)
{
	if(last == NULL)
	{
		cout << "Linked list is empty" << endl;
		return;
	}

	Node *newNode = new Node;
	newNode->data = data;
	newNode->next = (*last)->next;
	(*last)->next = newNode;
}

void insertAtEnd(Node **last, int data)
{
	if(last == NULL)
	{
		cout << "Linked list is empty" << endl;
		return;
	}

	Node *newNode = new Node;
	newNode->data = data;
	newNode->next = (*last)->next;
	(*last)->next = newNode;
	*last = newNode;
}

void traverse(Node *last)
{
	if(last == NULL)
	{
		cout << "Linked list is empty" << endl;
		return;
	}

	Node *temp = last->next;
	do
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	while(temp != last->next);
	cout << endl;
}

void deleteNode(Node **last, int key)
{
	if(*last == NULL)
	{
		cout << "Linked list is empty" << endl;
		return;
	}

	

}

int main()
{
	Node *last = NULL;
	insertToEmpty(&last, 1);
	traverse(last);

	insertAtBeginning(&last, 2);
	insertAtBeginning(&last, 3);
	insertAtBeginning(&last, 4);
	insertAtBeginning(&last, 5);
	insertAtBeginning(&last, 6);
	traverse(last);

	insertAtEnd(&last, 100);
	insertAtEnd(&last, 200);
	insertAtEnd(&last, 300);
	insertAtEnd(&last, 400);
	insertAtEnd(&last, 500);
	traverse(last);
	
	return 0;
}
