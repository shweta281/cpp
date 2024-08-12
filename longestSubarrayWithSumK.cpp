//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int a[],  int n, int k) 
    { 
        // Complete the function
        unordered_map<int, int>map;
        map[0]=-1;
        int ans=0,sum=0;
        for (int i=0; i<n; i++){
            sum+=a[i];
            if(map.find(sum-k)!=map.end()){
                ans=max(ans, i-map[sum-k]);
            }
            if(map.find(sum)==map.end()){
                map[sum]=i;
            }
        }
        return ans;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends
