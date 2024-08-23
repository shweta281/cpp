#include<iostream>
using namespace std;

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
    }
    
int main(){
    int g=gcd(5,gcd(7,10));
    cout<<g<<endl;
    }
