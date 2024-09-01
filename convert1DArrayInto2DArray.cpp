class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(original.size()!=m*n) return {};
        vector<vector<int>>ans;
        for (int i=0; i<original.size(); i+=n){
            vector<int>temp(original.begin()+i, original.begin()+i+n);
            ans.push_back(temp);
        }
        return ans;
    }
};
