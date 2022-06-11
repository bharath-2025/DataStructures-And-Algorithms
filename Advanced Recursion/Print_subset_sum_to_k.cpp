// Given an array A and an integer K, print all subsets of A which sum to K.
// Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
// Note : The order of subsets are not important. Just print them in different lines.
// Input format :
// Line 1 : Size of input array
// Line 2 : Array elements separated by space
// Line 3 : K 
// Sample Input:
// 9 
// 5 12 3 17 1 18 15 3 17 
// 6
// Sample Output:
// 3 3
// 5 1


#include <iostream>
using namespace std;

void helper(int input[],int size1,int output[],int size2,int sum){
    //Base case
    if(sum==0){
        for(int i=0;i<size2;i++){
            cout<<output[i]<<" ";
        }
        cout<<endl;
        return;
    }

    if(sum<0 || size1==0){
        return;
    }

    //If the element is not included
    helper(input+1,size1-1,output,size2,sum);

    //If the element is included
    //We are making the copy of the elements in output array into new_out array.
    //Because if we pass the output array instead of doing this then changes will get reflected in the original array itself.
    int new_out[size2+1];
    for(int i=0;i<size2;i++){
        new_out[i]=output[i];
    }
    new_out[size2]=input[0];

    helper(input+1,size1-1,new_out,size2+1,sum-input[0]);
}


void printSubsetSumToK(int input[],int size, int k){

    int output[0];
    helper(input,size,output,0,k);

}

int main() {
  int input[1000],length,k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  cin>>k;
  printSubsetSumToK(input, length,k);
}
