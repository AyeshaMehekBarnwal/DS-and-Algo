#include<bits/stdc++.h>
using namespace std;

void swap(int *num1, int *num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void selectionSort(int arr[], int n)
{
	int min_index;
	for(int i = 0; i < n - 1; i++)
	{
		min_index = i;
		for(int j = i + 1; j < n; j++)
		{
			if(arr[j] < arr[min_index])
				swap(arr[j], arr[min_index]);
		}
	}
}

int main()
{
	int arr[] = { 12, 11, 13, 5, 6 };  
    int n = sizeof(arr) / sizeof(arr[0]);  
  
    selectionSort(arr, n);  
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;  
  
    return 0;
}
