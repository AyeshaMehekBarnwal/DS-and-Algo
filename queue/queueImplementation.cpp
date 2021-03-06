#include<bits/stdc++.h>
using namespace std;

class myQueue {
	private:
		int front, rear, size;
		int *arr;

	public:
		myQueue(int size) {
			this->size = size;
			front = -1;
			rear = -1;
			arr = new int[size];
		}

		void enqueue(int data);
		int dequeue();
		bool isFull();
		bool isEmpty();
};

bool myQueue :: isFull() {
	if(((rear + 1) % size) == front)
		return true;
	return false;
}

bool myQueue :: isEmpty() {
	if((rear == -1) && (front == -1))
		return true;
	return false;
}

void myQueue :: enqueue(int data) {
	if(rear == -1 && front == -1) {
		rear = 0;
		front = 0;
		arr[rear] = data;
	}

	else if(isFull())
	{
		cout << "The queue is full!" << endl;
		return;
	}
	else {
		rear = (rear + 1) % size;
		arr[rear] = data;
	}
}

int myQueue :: dequeue() {
	if(isEmpty())
	{
		cout << "The queue is empty!" << endl;
		return -1;
	}

	else if(front == rear) {
		int temp = arr[front];
		front = -1;
		rear = -1;
		return temp;
	}

	else {
		int temp = arr[front];
		front = (front + 1) % size;
		return temp;
	}
}

int main()
{
	myQueue q(5);
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	q.enqueue(6);

	cout << q.dequeue() << endl;
	q.enqueue(100);
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;

	return 0;
}
