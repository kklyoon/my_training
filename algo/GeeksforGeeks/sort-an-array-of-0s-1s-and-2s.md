
원본 : https://www.geeksforgeeks.org/sort-an-array-of-0s-1s-and-2s/

## Sort an array of 0s, 1s and 2s

Given an array A[] consisting 0s, 1s and 2s. The task is to write a function that sorts the given array. The functions should put all 0s first, then all 1s and all 2s in last.

0,1,2 으로 이루어진 배열을 정렬하라

가장 심플한 방법은 [0,1,2 를 세는방법](https://www.geeksforgeeks.org/sort-array-0s-1s-2s-simple-counting/)이지만 배열을 한번 더 써야하는 단점이 있음

배열을 네가지의 영역으로 나눈다. 
1. a[0..Lo-1] zeroes 
1. a[Lo..Mid-1] ones 
1. a[Mid..Hi] unknown
1. a[Hi+1..N-1] twos 

Lo 와 Mid 에 해당되는 인덱스를 0으로 놓고 시작하면서
Lo 에 있는 값은 0
Hi 에 있는 값은 2
Mid 에 있는 값은 1 이라고 생각하면서 인덱스를 더하거나 줄여가면서 값을 바꿔준다.
예를들어 a[Mid] 에 있는 값이 0이면 a[Lo] 와 swap 하고 Lo++  
a[Mid] 에 있는 값이 1이면 Mid++
a[Mid] 에 있는 값이 2이면 a[Hi] 와 swap  하고 Hi--
Mid 와 Hi 가 같아질 때까지 반복한다.

```c++
// C++ program to sort an array 
// with 0,1 and 2 in a single pass 
#include<bits/stdc++.h> 
using namespace std; 



// Function to sort the input array, 
// the array is assumed 
// to have values in {0, 1, 2} 
void sort012(int a[], int arr_size) 
{ 
	int lo = 0; 
	int hi = arr_size - 1; 
	int mid = 0; 
	
	// Iterate till all the elements 
	// are sorted 
	while (mid <= hi) 
	{ 
		switch (a[mid]) 
		{ 
			
			// If the element is 0 
		case 0: 
			swap(a[lo++], a[mid++]); 
			break; 
			
			// If the element is 1 . 
		case 1: 
			mid++; 
			break; 
			
			// If the element is 2 
		case 2: 
			swap(a[mid], a[hi--]); 
			break; 
		} 
	} 
} 



// Function to print array arr[] 
void printArray(int arr[], int arr_size) 
{ 
	// Iterate and print every element 
	for (int i = 0; i < arr_size; i++) 
		cout << arr[i] << " "; 

} 

// Driver Code 
int main() 
{ 
	int arr[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	
	sort012(arr, n); 

	cout << "array after segregation "; 
	
	printArray(arr, n); 

	return 0; 
} 

// This code is contributed by Shivi_Aggarwal 

```