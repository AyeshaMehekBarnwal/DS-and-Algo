#include<bits/stdc++.h>
using namespace std;

class Node
{
	public:
		int data;
		Node* next;
};

void insertAtBeginning(Node **head, int data)
{
	Node *newNode = new Node();
	newNode->data = data;
	newNode->next = *head;
	*head = newNode;
}

void insertAfterNode(Node *prev, int data)
{
	if(prev == NULL)
	{
		cout << "The given node is NULL" << endl;
		return;
	}

	Node *newNode = new Node();
	newNode->data = data;
	newNode->next = prev->next;
	prev->next = newNode;
}

void insertAtEnd(Node **head, int data)
{
	Node *newNode = new Node();
	newNode->data = data;
	newNode->next = NULL;

	if(head == NULL)
	{
		*head = newNode;
		return;
	}

	Node *temp = *head;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}

	temp->next = newNode;
}

void traverseList(Node *head)
{
	while(head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}

	cout << endl;
}

void deleteKey(Node **head, int key)
{
	Node *temp = *head, *prev;

	if(temp == NULL)
	{
		cout << "The linked list is empty" << endl;
		return;
	}
	
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

	if(temp == NULL)
	{
		cout << "Given key is not present" << endl;
		return;
	}

	prev->next = temp->next;
	free(temp);
}

void deleteNode(Node **head, int position)
{
	if(*head == NULL)
	{
		cout << "The linked list is empty" << endl;
		return;
	}

	Node *temp = *head, *next;
	if(position == 0)
	{
		*head = temp->next;
		free(temp);
		return;
	}

	for(int i = 0; temp != NULL && i < position - 1; i++)
	{
		temp = temp->next;
	}

	if(temp == NULL || temp->next == NULL)
		return;

	next = temp->next->next;
	free(temp->next);
	temp->next = next;
}

void deleteNodePtr(Node *ptr)
{
	Node *temp = ptr->next;
	ptr->data = temp->data;
	ptr->next = temp->next;
	free(temp);
}

void deleteList(Node **head)
{
	if(*head == NULL)
		return;
	
	Node *current = *head, *next = NULL;
	while(current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}

	*head = NULL;
}

int main()
{
	Node *head = NULL;
	insertAtBeginning(&head, 1);
	insertAtBeginning(&head, 2);
	insertAtBeginning(&head, 3);
	insertAtBeginning(&head, 4);
	insertAtBeginning(&head, 5);

	traverseList(head);

	insertAfterNode(head->next, 100);
	insertAfterNode(head->next->next, 500);
	insertAfterNode(NULL, 100);
	traverseList(head);

	deleteKey(&head, 3);
	deleteKey(&head, 8);
	traverseList(head);

	deleteNode(&head, 3);
	traverseList(head);

	deleteNodePtr(head->next);
	traverseList(head);

	deleteList(&head);
	traverseList(head);

	return 0;
}
