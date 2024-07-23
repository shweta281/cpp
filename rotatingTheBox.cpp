class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        for (int i=0; i<box.size(); i++){
            int j=0, k=0;
            while(k<box[0].size()){
                // cout<<j<<" "<<k<<endl;
                if(box[i][k]=='*'){
                    j=k;
                    j++;
                    k++;
                }
                else if(j<box[0].size() && k<box[0].size() && box[i][j]=='#' && box[i][k]=='.'){
                    if(k<j){
                        k++;
                        continue;
                    }
                    box[i][j]='.';
                    box[i][k]='#';
                    j++;
                    k++;
                }
                else if(j<box[0].size() && box[i][j]!='#') j++;
                else if(k<box[0].size() && box[i][k]!='.') k++;
                else{
                    j++;
                    k++;
                }
            }
        }
        vector<vector<char>>ans(box[0].size(), vector<char>(box.size()));
        for (int i=0; i<box.size(); i++){
            for (int j=0; j<box[0].size(); j++){
                ans[j][box.size()-i-1]=box[i][j];
            }
        }
        return ans;
    }
};
