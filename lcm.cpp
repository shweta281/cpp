#include<iostream>
using namespace std;

//a x b = LCM(a, b) * GCD (a, b)


int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
    }
int lcm(int a, int b){
    return (a *b)/(gcd(a, b));
    }
    
int main(){
    cout<<lcm(5,7)<<endl;
    }
