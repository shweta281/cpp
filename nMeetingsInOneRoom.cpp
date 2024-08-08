//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    //1 3 0 5 8 5
    //2 4 6 7 9 9
    //
    int maxMeetings(int n, int start[], int end[]) {
        vector<vector<int>>temp;
        for ( int i=0; i<n; i++){
            temp.push_back({start[i], end[i]});
        }
        sort(temp.begin(), temp.end(), [](vector<int>&a, vector<int>&b){
            return a[1]<b[1];
        });
        int e=-1;
        int ans=0;
        for (int i=0; i<n; i++){
            if(temp[i][0]>e){
                e=temp[i][1];
                ans++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(n, start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends
