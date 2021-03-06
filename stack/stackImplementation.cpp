#include<bits/stdc++.h>
using namespace std;

class myStack {
	private:
		int top;
		int size;
		int *arr;

	public:
		myStack(int size) {
			this->size = size;
			top = -1;
			arr = new int[size];
		}

	void push(int data);
	int pop();
	bool isFull();
	bool isEmpty();
};

bool myStack :: isFull() {
	if(top == size)
		return true;
	return false;
}

bool myStack :: isEmpty() {
	if(top == -1)
		return true;
	return false;
}

void myStack :: push(int data) {
	if(isFull())
		return;

	arr[++top] = data;
}

int myStack :: pop() {
	if(isEmpty())
		return -1;
	int temp = arr[top];
	top--;
	return temp;	
}

int main()
{
	myStack st(5);
	st.push(1);	
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);

	cout << st.pop() << endl;
	return 0;
}

