#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class solution{
    public:
    vector<int>maxSlidingWindow( vector<int>&nums, int k){
        vector<int>ans;
        priority_queue<vector<int> >pq;
        for (int i=0;i<k;i++){
            int arr[]={nums[i],i};
            vector<int>temp( arr, arr+2);
            pq.push(temp);
        }
        ans.push_back(pq.top()[0]);
        for (int i=k;i<nums.size();i++){
            while(pq.empty()!=true && pq.top()[1]<=i-k){
                pq.pop();
            }
            int arr[]={nums[i],i};
            vector<int>temp( arr, arr+2);
            pq.push(temp);
            ans.push_back(pq.top()[0]);
        }
        return ans;    
    }
};

void print(vector<int>&arr){
    for (int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
    
int main(){
    solution* s = new solution();
    int arr[] = {1,3,-1,-3,5,3,6,7};
    vector<int>nums(arr, arr+sizeof(arr)/sizeof(int));
    int k;
    k=3;
    vector<int>ans=s->maxSlidingWindow(nums, k);
    print(ans);
}








