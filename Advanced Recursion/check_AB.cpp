//Check AB
// Suppose you have a string, S, made up of only 'a's and 'b's. Write a recursive function that checks if the string was generated using the following rules:
// a. The string begins with an 'a'
// b. Each 'a' is followed by nothing or an 'a' or "bb"
// c. Each "bb" is followed by nothing or an 'a'
// If all the rules are followed by the given string, return true otherwise return false.
// Input format :
// String S
// Output format :
// 'true' or 'false'
// Constraints :
// 1 <= |S| <= 1000
// where |S| represents length of string S.
// Sample Input 1 :
// abb
// Sample Output 1 :
// true
// Sample Input 2 :
// abababa
// Sample Output 2 :
// false
// Explanation for Sample Input 2
// In the above example, a is not followed by either "a" or "bb", instead it's followed by "b" which results in false to be returned.


#include <bits/stdc++.h>
using namespace std;

bool helper(char input[]){
    //base case
    if(input[0]=='\0'){
        return true;
    }

    //recursion on subproblem
    bool ans = helper(input+1);

    //if the ans of subproblem is equal to true then we will check further with input[0] else directly we can return false.
    if(ans){
        if(input[0]=='a'){
            if(input[1]=='a' || input[1]=='x'){
                return true;
            }
        }
        else if(input[0]=='x'){
            if(input[1]=='a'){
                return true;
            }
        }
        else{
            return false;
        }
    }

    return ans;
}

bool checkAB(char input[]){

    //cout<<input<<endl;
    //Converting the bb in input into x eg:abbabba ---> aXaXa to make the problem simple
    int i=0,j=0;
    while(input[i]!='\0'){
        if(input[i]=='b' && input[i+1]=='b'){
            input[j]='x';
            j++;
            i+=2;
        }
        else{
            input[j]=input[i];
            j++,i++;
        }
    }
    input[j]='\0';

    //cout<<input<<endl;

    if(input[0] != 'a'){
        return false;
    }

    return helper(input+1);
}

int main() {
    char input[100];
    bool ans;
    cin >> input;
    ans=checkAB(input);
    if(ans)
        cout<< "true" << endl;
    else
        cout<< "false" << endl;

}
