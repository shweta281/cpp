class Solution {
public:
    void print(vector<string>arr){
        for (int i=0; i<arr.size(); i++) cout<<arr[i]<<" ";
        cout<<endl;
    }
    bool ispalindrom(string s){
        for (int i=0;i<s.length()/2;i++){
            if(s[i]!=s[s.length()-1-i]) return false;
        }
        return true;
    }
    void asd(string s, int i, int j, vector<string>temp, vector<vector<string>>&ans){
        if(i>=s.length()){
            ans.push_back(temp);
        }
        if(j<=s.length()){
            asd(s, i, j+1, temp, ans);
            if(ispalindrom(s.substr(i, j-i))){
                temp.push_back(s.substr(i,j-i));
                asd(s, j, j+1, temp, ans);
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        asd(s, 0, 1, temp, ans);
        return ans;
    }
};
