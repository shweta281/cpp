class Solution {
public:
    bool isCircularSentence(string sen) {
        int n = sen.length();
        vector<string> heh;
        string temp = "";
        for (int i = 0; i < n; i++){
            if(sen[i] == ' '){
                heh.push_back(temp);
                temp = "";
            } else {
                temp+=sen[i];
            }
        }
        heh.push_back(temp);
        int m = heh.size();
        for (int i = 0; i < m; i++){
            int size = heh[i].length();
            // cout<<(heh[i][size - 1])<<" "<<heh[(i + 1) % m][0]<<endl;
            if(heh[i][size - 1] != heh[(i + 1) % m][0]){
                return false;
            }
        }
        return true;
    }
};
