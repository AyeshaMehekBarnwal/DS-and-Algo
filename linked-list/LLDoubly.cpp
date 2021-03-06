#include<bits/stdc++.h>
using namespace std;

class Node
{
	public:
		int data;
		Node *prev;
		Node *next;
};

void insertAtBeginning(Node **head, int data)
{
	Node *newNode = new Node;
	newNode->data = data;
	newNode->prev = NULL;
	newNode->next = *head;
	if(*head != NULL)
		(*head)->prev = newNode;
	*head = newNode;
}

void insertAtEnd(Node *head, int data)
{
	Node *newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;
	
	while(head->next != NULL)
		head = head->next;

	head->next = newNode;
	newNode->prev = head;
}

void insertAfterNode(Node *ptr, int data)
{
	if(ptr == NULL)
	{
		cout << "Given node is NULL" << endl;
		return;
	}

	Node *newNode = new Node;
	newNode->data = data;
	newNode->prev = ptr;
	newNode->next = ptr->next;
	ptr->next = newNode;
	if(newNode->next != NULL)
		newNode->next->prev = newNode;
	
}

void insertBeforeNode(Node **head, Node *ptr, int data)
{
	if(ptr == NULL)
	{
		cout << "Given node is NULL" << endl;
		return;
	}

	Node *newNode = new Node;
	newNode->data = data;
	newNode->prev = ptr->prev;
	ptr->prev = newNode;
	newNode->next = ptr;

	if(newNode->prev != NULL)
		newNode->prev->next = newNode;

	else
		*head = newNode;
}

void deleteNode(Node **head, Node *ptr)
{
	if(*head == NULL || ptr == NULL)
	{
		cout << "Linked list is empty" << endl;
		return;
	}

	if(*head == ptr)
		*head = ptr->next;

	if(ptr->next != NULL)
		ptr->next->prev = ptr->prev;
	
	if(ptr->prev != NULL)
		ptr->prev->next = ptr->next;

	free(ptr);
	return;
}

void traverse(Node *head)
{
	Node *last;
	while(head != NULL)
	{
		cout << head->data << " ";
		last = head;
		head = head->next;
	}

	cout << endl;

	while(last != NULL)
	{
		cout << last->data << " ";
		last = last->prev;
	}

	cout << endl;
}

int main()
{
	Node *head = NULL;
	insertAtBeginning(&head, 1);
	insertAtBeginning(&head, 2);
	insertAtBeginning(&head, 3);
	insertAtBeginning(&head, 4);
	insertAtBeginning(&head, 5);
	insertAtBeginning(&head, 6);
	traverse(head);

	insertAtEnd(head, 100);
	insertAtEnd(head, 200);
	insertAtEnd(head, 300);
	traverse(head);

	insertAfterNode(head->next->next, -55);
	traverse(head);

	insertBeforeNode(&head, head->next, -89);
	traverse(head);

	deleteNode(&head, head->next->next);
	deleteNode(&head, head);
	traverse(head);

	return 0;
}
