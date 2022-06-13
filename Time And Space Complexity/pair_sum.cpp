// Pair sum in array
// You have been given an integer array/list(ARR) and a number 'num'. Find and return the total number of pairs in the array/list which sum to 'num'.
// Note:
// Given array/list can contain duplicate elements. 
// Input format :
// The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

// First line of each test case or query contains an integer 'N' representing the size of the first array/list.

// Second line contains 'N' single space separated integers representing the elements in the array/list.

// Third line contains an integer 'num'.
// Output format :
// For each test case, print the total number of pairs present in the array/list.

// Output for every test case will be printed in a separate line.
// Constraints :
// 1 <= t <= 10^2
// 0 <= N <= 10^4
// 0 <= num <= 10^9

// Time Limit: 1 sec
// Sample Input 1:
// 1
// 9
// 1 3 6 2 5 4 3 2 4
// 7
// Sample Output 1:
// 7
// Sample Input 2:
// 2
// 9
// 1 3 6 2 5 4 3 2 4
// 12
// 6
// 2 8 10 5 -2 5
// 10
// Sample Output 2:
// 0
// 2


//  Explanation for Input 2:
// Since there doesn't exist any pair with sum equal to 12 for the first query, we print 0.

// For the second query, we have 2 pairs in total that sum up to 10. They are, (2, 8) and (5, 5).

#include<bits/stdc++.h>
using namespace std;


int pairSum(int *arr, int n, int num)
{
    //Method1: Brute force or navie approach,Time Complexity O(n^2).
	// int count=0;
	// for(int i=0;i<n-1;i++){
	// for(int j=i+1;j<n;j++){
	// if(arr[i]+arr[j]==num){
	// count++;
	// }
	// }
	// }
	// return count;
    
    //Method2: Using map ,Time Complexity O(n),space Complexity O(n).
    
//     unordered_map<int,int>m;         // Extra space of n is for the unordered_map
//     int count=0;
//     for(int i=0;i<n;i++){
//         if(m[num-arr[i]]>0){
//             count+=m[num-arr[i]];
//         }
//         m[arr[i]]++;
//     }
    
//     return count;
    
    //Method3: Sort the array and perform Scanning from left and right
    //Time Complexity O(nlogn),Space Complexity O(1);
    int count=0;
    sort(arr,arr+n);
    int i=0,j=n-1;
    while(i<j){
        if(arr[i]+arr[j] > num){
            j--;
        }
        else if(arr[i]+arr[j] < num){
            i++;
        }
        else{
            int same1=1,same2=1;
            int k;
            for(k=i+1;arr[i]==arr[k];k++){
                same1++;
            }
            i=k;
            if(i>j){
                count = count + same1*(same1-1)/2;
            }else{
                for(k=j-1;arr[j]==arr[k];k--){
                	same2++;
            	}
            	j=k;
            	count = same1*same2+count++;
            }
            
        }
    }
    return count;
    
    //Note:- some time ie in case of all elements are equal then the timeComplexity will
    //       become O(n^2).
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int size;
		int x;

		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cin >> x;

		cout << pairSum(input, size, x) << endl;

		delete[] input;
	}
	
	return 0;
}