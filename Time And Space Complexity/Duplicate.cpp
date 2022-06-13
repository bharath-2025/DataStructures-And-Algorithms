// Duplicate in array
// You have been given an integer array/list(ARR) of size N which contains numbers from 0 to (N - 2). Each number is present at least once. That is, if N = 5, the array/list constitutes values ranging from 0 to 3, and among these, there is a single integer value that is present twice. You need to find and return that duplicate number present in the array.
// Note :
// Duplicate number is always present in the given array/list.
// Input format :
// The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

// First line of each test case or query contains an integer 'N' representing the size of the array/list.

// Second line contains 'N' single space separated integers representing the elements in the array/list.
// Output Format :
// For each test case, print the duplicate element in the array/list.

// Output for every test case will be printed in a separate line.
// Constraints :
// 1 <= t <= 10^2
// 0 <= N <= 10^6

// Time Limit: 1 sec
// Sample Input 1:
// 1
// 9
// 0 7 2 5 4 7 1 3 6
// Sample Output 1:
// 7
// Sample Input 2:
// 2
// 5
// 0 2 1 3 1
// 7
// 0 3 1 5 4 3 2
// Sample Output 2:
// 1
// 3


#include <iostream>
using namespace std;

#include<bits/stdc++.h>
int findDuplicate(int *arr, int n)
{
    //Method1:O(n^2)
    //Using the concept of Xor Calculation.
    // for(int i=0;i<n-1;i++){
    //     for(int j=i+1;j<n;j++){
    //         if(arr[i]^arr[j]==0){
    //             return arr[i];
    //         }
    //     }
    // }
    // return -1;
    
    //Method2:O(n),space complexity:O(n);
    //Using the Concept of Hashing.
    //int temp[n]={0};
    //for(int i=0;i<n;i++){
    //     temp[arr[i]]++;
    //}

    //for(int i=0;i<n;i++){
    //    if(temp[i]==2){
    //         return i;
    //    }
    //}
    //return -1;
    
    //Method3:Sorting O(nlogn),space complexity O(1);
    // sort(arr,arr+n);
    // for(int i=0;i<n-1;i++){
    //     if(arr[i]==arr[i+1]){
    //         return arr[i];
    //     }
    // }
    // return -1;
    
    //Best Approach
    //Method4: TimeComplexity:O(n),space Complexity:O(1)
    
    //given all the numbers are from 0 to n-2.
    //So sum of n-2 nutural numbers = (n-2)(n-1)/2.
    //Find the sum of all the no's in the array and subtract the sum of n-2 natural numbers then we will get the duplicate element.
    
    int Orginal_sum=(n-2)*(n-1)/2;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    
    int duplicate = sum - Orginal_sum;
    
    return duplicate;
    
    
}

int main()
{
	int t;
	cin >> t;
	
	while (t--)
	{
		int size;
		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cout << findDuplicate(input, size) << endl;
	}

	return 0;
}