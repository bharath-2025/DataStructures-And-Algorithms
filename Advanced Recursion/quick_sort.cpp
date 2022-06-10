#include<iostream>
using namespace std;


int partition(int input[],int si,int ei){
    
    int pivot=input[si],pos=si;
    
    //for loop to calculate the total no of elements lesser than or equal to pivot element.
    for(int i=si+1;i<=ei;i++){
        if(input[i]<=pivot){
            pos++;
        }
    }
    
    // Swapping the pivot with the element at the index=pos.
    int temp=pivot;
    input[si] = input[pos];
    input[pos] = temp;
    
    //cout<<si<<" "<<ei<<endl;
    
    //Arranging all the elements lesser than pivot to the left and greater elements to the right.
    int i=si,j=ei;
    while(i<j){
        if(input[i]<=pivot){
            i++;
        }
        else if(input[j]>pivot){
            j--;
        }
        else{
            int temp = input[i];
            input[i] = input[j];
            input[j] = temp;
            i++;
            j--;
        }
    }
    
    return pos;
    
    
    
}



void helper(int input[],int si,int ei){
    //base case
    if(si>=ei){
        return;
    }
    
    int c = partition(input,si,ei);
    
    helper(input,si,c-1);
    
    helper(input,c+1,ei);
    
}


void quickSort(int input[], int size) {
  
    helper(input,0,size-1);
}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}


