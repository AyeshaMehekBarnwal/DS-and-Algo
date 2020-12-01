#include<bits/stdc++.h>
using namespace std;

int binarySearchItr(int arr[], int n, int key)
{
	int l = 0, r = n;
	int m; 


	while(l <= r)
	{
		m = l + (r - l) / 2;
		
		if(arr[m] == key)
			return m;

		else if(arr[m] > key)
			r = m - 1;

		else
			l = m + 1;	
	}

	return -1;
}

int binarySearchRec(int arr[], int l, int r, int key)
{
	if(l <= r)
	{
		int mid = l + (r - l) / 2;
		if(arr[mid] == key)
			return mid;

		if(arr[mid] > key)
			return binarySearchRec(arr, 0, mid - 1, key);
		else
			return binarySearchRec(arr, mid + 1, r, key);
	}

	return -1;
}

int main()
{
	int arr[] = { 2, 3, 4, 10, 40 }; 
    int key = 10; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int result = binarySearchItr(arr, n, key); 
	int res = binarySearchRec(arr, 0, n - 1, key);
    (result == -1) ? cout << "Element is not present in array"
                   : cout << "Element is present at index " << result << endl;

	(res == -1) ? cout << "Element is not present in array"
                   : cout << "Element is present at index " << res << endl;


	 
    return 0;
}
