#include<iostream>
using namespace std;

class Fraction{
    private:
    int numerator,denominator;

    public:
    Fraction(int numerator,int denominator){
        this -> numerator=numerator;
        this -> denominator = denominator;
    }

    void display(){
        cout<<this -> numerator<<"/"<<this -> denominator<<endl; 
    }

    void simplify(){
        int gcd=1;
        int x = min(this->numerator,this->denominator);
        for(int i=1;i<=x;i++){
            if(this->numerator % i == 0 && this->denominator % i ==0){
                gcd=i;
            }
        }

        this->numerator = this->numerator / gcd;
        this->denominator /= gcd;
    }

    void add(Fraction const& f2){
        int lcm = this->denominator * f2.denominator;
        int num = this->numerator*f2.denominator + f2.numerator*this->denominator;

        this->numerator = num;
        this->denominator = lcm;
        simplify();
        //we are using the reference to avoid the unnecessay copy of the Object 
        //and other important thing is we have made that reference object as const so that changes cant be done to that object using reference inside this function.
    }

    void multiply(Fraction f){
        this->numerator *= f.numerator;
        this->denominator *= f.denominator;

        simplify();
    }

};

int main(){
    Fraction f1(5,10);
    f1.display();
    Fraction f2(7,10);
    f2.display();
    f2.add(f1);
    f2.display();
    f1.multiply(f2);
    f1.display();
}