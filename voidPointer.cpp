#include<iostream>
using namespace std;
int main(){
    int a=5;
    int* p=&a;
    void* ptr=&a;
    cout<<p<<" "<<ptr<<endl;
    // cout<<*(int*)*ptr;  void pointers cannot be derefereced directly
    cout<<*p<<endl;
    }
