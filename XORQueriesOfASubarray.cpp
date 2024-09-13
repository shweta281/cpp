class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        for (int i=1; i<arr.size(); i++){
            arr[i]^=arr[i-1];
            // cout<<arr[i]<<" ";
        }
        vector<int>ans;
        for (int i=0; i<queries.size(); i++){
            int query_left=queries[i][0];
            int query_right=queries[i][1];
            if(query_left==0){
                // cout<<arr[query_right]<<" ";
                ans.push_back(arr[query_right]);
            }
            else{
                // cout<<(arr[query_left-1]^arr[query_right])<<" ";
                ans.push_back(arr[query_left-1]^arr[query_right]);
            }
        }
        return ans;
    }
};
