#include <iostream>
using namespace std;

void merge(int input[],int si,int ei){
    int mid=(si+ei)/2;
    int i=si,j=mid+1;
    int temp[ei-si];
    int k=0;
    while(i<=mid && j<=ei){
        if(input[i]<input[j]){
            temp[k]=input[i];
            k++;
            i++;
        }
        else{
            temp[k]=input[j];
            k++;
            j++;
        }
    }
    
    if(i<=mid){
        for(;i<=mid;i++){
            temp[k]=input[i];
            k++;
        }
    }else{
        for(;j<=ei;j++){
            temp[k]=input[j];
            k++;
        }
    }
    
    for(int i=0,j=si;i<k && j<=ei ;i++,j++){
        input[j]=temp[i];
    }
        
}


void helper(int input[], int si,int ei){
    if(si>=ei){
        return;
    }
    
    int mid = (si+ei)/2;
    helper(input,si,mid);
    helper(input,mid+1,ei);
    
    merge(input,si,ei);
}

void mergeSort(int input[], int size){
	
    helper(input,0,size-1);
        
}


int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}
