class Solution {
public:
//(12+n)/4+3=3
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum=0;
        for (int i=0; i<rolls.size(); i++){
            sum+=rolls[i];
        }
        sum= (mean*(n+rolls.size()))-sum;
        if(sum<n || sum>n*6) return {};
        vector<int>ans;
        int k=n;
        for (int i=0; i<k; i++){
            ans.push_back(sum/n);
            sum-=sum/n;
            n--;
        }
        return ans;
    }
};
