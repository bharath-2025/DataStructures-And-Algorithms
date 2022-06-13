                                                            //Array Intersection
// You have been given two integer arrays/list(ARR1 and ARR2) of size N and M, respectively. You need to print their intersection; An intersection for this problem can be defined when both the arrays/lists contain a particular value or to put it in other words, when there is a common value that exists in both the arrays/lists.
// Note :
// Input arrays/lists can contain duplicate elements.

// The intersection elements printed would be in the order they appear in the first sorted array/list(ARR1).


// Input format :
// The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

// The first line of each test case or query contains an integer 'N' representing the size of the first array/list.

// The second line contains 'N' single space separated integers representing the elements of the first the array/list.

// The third line contains an integer 'M' representing the size of the second array/list.

// The fourth line contains 'M' single space separated integers representing the elements of the second array/list.
// Output format :
// For each test case, print the intersection elements in a row, separated by a single space.

// Output for every test case will be printed in a separate line.
// Constraints :
// 1 <= t <= 10^2
// 0 <= N <= 10^6
// 0 <= M <= 10^6

// Time Limit: 1 sec 
// Sample Input 1 :
// 2
// 6
// 2 6 8 5 4 3
// 4
// 2 3 4 7 
// 2
// 10 10
// 1
// 10
// Sample Output 1 :
// 2 3 4
// 10
// Sample Input 2 :
// 1
// 4
// 2 6 1 2
// 5
// 1 2 3 4 2
// Sample Output 2 :
// 1 2 2
// Explanation for Sample Output 2 :
// Since, both input arrays have two '2's, the intersection of the arrays also have two '2's. The first '2' of first array matches with the first '2' of the second array. Similarly, the second '2' of the first array matches with the second '2' if the second array.


#include <bits/stdc++.h>
using namespace std;

void intersection(int *arr1, int *arr2, int n, int m) 
{
    //Method1:O(n*m)  -->Navie Approach
    // sort(arr1,arr1+n);
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         if(arr1[i]==arr2[j]){
    //             cout<<arr1[i]<<" ";
    //             arr2[j]=INT_MIN;
    //             break;
    //         }
    //     }
    // }
    
    //Method2: Sort both the arrays and linearly use the merge approach to find intersection element. (O(nlogn) + O(m+n))
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);
    
    int i=0,j=0;
    while(i<n && j<m){
        if(arr1[i]<arr2[j]){
            i++;
        }
        else if(arr2[j]<arr1[i]){
            j++;
        }
        else{
            //this is the case where both are having same element
            cout<<arr1[i]<<" ";
            i++;
            j++;
        }
    }
    
    //Method3: Hashing or using hashMaps. TimeComplexity:O(n)  SpaceComplexity:O(n)
    
//     unordered_map<int,int>temp;
//     //In the question it is mentioned that the intersection elements printed would be in the order they appear in the first sorted array/list(ARR1).
//     //So thats the reason we have to sort the first array at the start itself eventhough its not required.
//     sort(arr1,arr1+n);
//     for(int i=0;i<m;i++){
//         temp[arr2[i]]++;
//     }
    
//     for(int j=0;j<n;j++){
//         if( temp[arr1[j]] > 0 ){
//             cout<<arr1[j]<<" ";
//             temp[arr1[j]]--;
//         }
//     }
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{

		int size1, size2;

		cin >> size1;
		int *input1 = new int[size1];

		for (int i = 0; i < size1; i++)
		{
			cin >> input1[i];
		}

		cin >> size2;
		int *input2 = new int[size2];

		for (int i = 0; i < size2; i++)
		{
			cin >> input2[i];
		}

		intersection(input1, input2, size1, size2);
		
		delete[] input1;
		delete[] input2;
		
		cout << endl;
	}

	return 0;
}