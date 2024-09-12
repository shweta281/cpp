class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char>s(allowed.begin(), allowed.end());
        int ans=0;
        for (int i=0; i<words.size(); i++){
            int flag=1;
            for (char j: words[i]){
                if(s.find(j)==s.end()){
                    flag=0;
                    break;
                }
            }
            ans+=flag;
        }
        return ans;
    }
};
