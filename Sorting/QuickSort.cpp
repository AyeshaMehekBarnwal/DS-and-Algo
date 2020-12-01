#include<bits/stdc++.h>
using namespace std;

void swap(int *num1, int *num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

int partition(int arr[], int l, int h)
{
	int pivot = arr[l];
	int i = l + 1; 
	int j = h;

	while(1)
	{
		while(i < h && pivot >= arr[i])
		{
			i++;
			
		}

		while(j > l && pivot < arr[j])
		{
			j--;
		}

		if(i < j)
			swap(arr[i], arr[j]);

		else
		{
			swap(arr[j], arr[l]);
			return j;
		}
	}	
}

void quickSort(int arr[], int l, int h)
{
	if(l < h)
	{
		int pi = partition(arr, l, h);
		quickSort(arr, l, pi - 1);
		quickSort(arr, pi + 1, h);
	}
}

int main()
{
	
	int arr[] = { 12, 11, 13, 5, 6 };  
    int n = sizeof(arr) / sizeof(arr[0]);  
  
    quickSort(arr, 0, n - 1);  
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;  
  
    return 0;
}
