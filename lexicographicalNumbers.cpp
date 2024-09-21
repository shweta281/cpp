class Solution {
public:
    vector<int>ans;
    void helper(int i ,int n){
        if(i>n) return;
        for (int j=i; j<i+(i==1? 9 : 10); j++){
            if(j>n) break;
            ans.push_back(j);
            helper(j*10,n);
        }
        return;
    }
    vector<int> lexicalOrder(int n) {
        helper(1, n);
        return ans;
    }
};
