#include<bits/stdc++.h>
using namespace std;

void swap(int *num1, int *num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void bubbleSort(int arr[], int n)
{
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = 0; j < n - i - 1; j++)
		{
			if(arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
	}
}

int main()
{
	int arr[] = {64, 34, 25, 12, 22, 11, 90};  
    int n = sizeof(arr)/sizeof(arr[0]);  
    bubbleSort(arr, n);  
    cout<<"Sorted array: \n";  
    for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl; 
    return 0; 
}
