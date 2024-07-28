#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n-1];
    for (int i=2;i<=n;i++){
        arr[i-2]=0;
        }
    for (int i=2; i<=n; i++ ){
        if(arr[i-2]==0){
            cout<<i<<" ";
            int curr=i*i-2;
            while(curr<=n){
                arr[curr]=1;
                curr=curr+i;
                }
            }
        }
    }
