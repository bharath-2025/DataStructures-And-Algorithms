#include<iostream>
#include<math.h>
using namespace std;

// //Method 1:

// int subsequence(string input,string* output){
//     if(input.size()==0){
//         return 1;
//     }

//     int smallerOutputSize = subsequence(input.substr(1),output);
//     for(int i=0;i<smallerOutputSize;i++){
//         output[i + smallerOutputSize] = input[0] + output[i];
//     }

//     return 2*smallerOutputSize;
// }


// int main(){
//     string s;
//     cin>>s;

//     int n=s.size();

//     string* output = new string[1000];
//     int x = subsequence(s,output);

//     for(int i=0;i<x;i++){
//         cout<<output[i]<<endl;
//     }
// }


// The main drawback of method 1 is that we are using an extra size for output which becomes bulky on some cases so to avoid that we can directly print the subsequence on getting it rather than storing it somewhere.

// Method2:

void print_subseq(string input,string output){
    if(input.size()==0){
        cout<<output<<endl;
        return;
    }

    print_subseq(input.substr(1),output);
    print_subseq(input.substr(1),output+input[0]);
}

int main(){
    string s;
    cin>>s;
    string output="";
    print_subseq(s,output);
}


// Hence this method 2 is going to use much less space when compared to method1 so the execution will be fast.