#include<iostream>

using namespace std;

bool check(int n){
    if((n&(n<<1))!=0) return false;
    return true;
    }
int main(){
    int n=456;
    while(true){
        n++;
        if(check(n)){
            cout<<n;
            break;
            }
        }
    }
    
