// A child is running up a staircase with N steps, and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return number of possible ways W.
// Input format :
// Integer N
// Output Format :
// Integer W
// Constraints :
// 1 <= N <= 30
// Sample Input 1 :
// 4
// Sample Output 1 :
// 7
// Sample Input 2 :
// 5
// Sample Output 2 :
// 13

int staircase(int n){
    //Base case: if no.of steps == 0 or 1 then there is 1 way to go.
    if(n==0 || n==1){
        return 1;
    }

    if(n<0){
        return 0;
    }

    //I will climb 1 step and asking recursion to calculate the no.of ways to climb n-1 steps;
    int result1 = staircase(n-1);
    //I will climb 2 step and asking recursion to calculate the no.of ways to climb n-2 steps;
    int result2 = staircase(n-2);
    //I will climb 3 step and asking recursion to calculate the no.of ways to climb n-3 steps;
    int result3 = staircase(n-3);

    //Total no.of ways
    return result1+result2+result3;
}


#include <iostream>
using namespace std;

int main() {
    int n, output;
    cin >> n;
    output=staircase(n);
    cout<< output <<endl;
}
