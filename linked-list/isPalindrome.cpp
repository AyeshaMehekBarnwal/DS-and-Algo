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

//using stack
bool isPalindrome(Node *head)
{
	if(head == NULL || head->next == NULL)
		return true;

	stack <int> s;
	Node *temp = head;

	while(temp != NULL)
	{
		s.push(temp->data);
		temp = temp->next;
	}

	while(head != NULL)
	{
		int curr = s.top();
		s.pop();
		if(curr != head->data)
			return false;
		head = head->next;
	}

	return true;
}

int main()
{
	Node *head = NULL;
	int key = 1;
	InsertAtBeginning (&head, 0);
	InsertAtBeginning (&head, 9);
	InsertAtBeginning (&head, 6);
	InsertAtBeginning (&head, 2);
	InsertAtBeginning (&head, 8);
	InsertAtBeginning (&head, 2);
	InsertAtBeginning (&head, 6);
	InsertAtBeginning (&head, 9);
	InsertAtBeginning (&head, 0);

	int noOfNodes = findLengthIterative(head);
	cout << "Total number of nodes : " << noOfNodes << endl;

	isPalindrome(head) ? cout << "Linked list id palindrome!" << endl : cout << "Linked list is not palindrome!" << endl; 

	return 0;
}
