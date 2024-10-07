class Solution {
public:
    vector<string> makeWords(string s){
        vector<string> ans;
        string temp = "";
        for (int i = 0; i < s.length(); i++){
            if(s[i] == ' '){
                ans.push_back(temp);
                temp = "";
                continue;
            }
            temp += s[i];
        }
        ans.push_back(temp);
        return ans;
    }
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> word1 = makeWords(sentence1);
        vector<string> word2 = makeWords(sentence2);
        for (auto x: word1){
            cout<<x<<" ";
        }
        cout<<endl;
        for (auto x: word2){
            cout<<x<<" ";
        }
        cout<<endl;
        int count = 0;
        int n = word1.size(), m = word2.size();
        int i = 0, j = 0;
        for (; i < min(m, n); i++){
            if(word1[i] != word2[i]){
                break;
            }
        }
        for (; i < min(m, n); i++){
            if(word1[i] != word2[i]){
                break;
            }
        }
        cout<<i<<" "<<m<<" "<<n<<endl;
        // i++;
        if(i == min(m ,n)){
            return true;
        }
        for (; j < min(m, n); j++){
            cout<<word1[n-j-1]<<endl;
            if(word1[n - j - 1] != word2[m - j - 1]){
                break;
            }
        }
        // j++;
        cout<<j<<endl;
        if(j == min(m, n)){
            return true;
        }
        cout<<(i+j)<<endl;
        if ( i + j >= min(m, n)) return true;
        return false;
    }
};
