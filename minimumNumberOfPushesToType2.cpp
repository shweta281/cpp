class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int>temp;
        for (int i=0; i<word.length(); i++){
            temp[word[i]]++;
        }
        vector<pair<char, int>>temp1(temp.begin(), temp.end());
        sort(temp1.begin(), temp1.end(), [](pair<char,int>&a, pair<char,int>&b){
            return a.second>b.second;
        });
        int ans=0;
        for (int i=0; i<temp1.size(); i++){
            ans+=(i/8+1)*temp1[i].second;
        }
        return ans;
    }
};
