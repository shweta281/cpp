class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>>temp(matrix.size(), vector<int>(matrix[0].size(),0));
        for (int i=0; i<matrix.size(); i++){
            for (int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j]=='0') continue;
                if(i==0) temp[i][j]= 1;
                else{
                    temp[i][j]+= temp[i-1][j]+ 1;
                }
            }
        }
        // for (auto x:temp){
        //     for (auto y: x){
        //         cout<<y<<" ";
        //     }
        //     cout<<endl;
        // }
        int finalans=0;
        for (int i=0; i<matrix.size(); i++){
            stack<int>s1;
            vector<int>left;
            vector<int>right;
            for (int j=0; j<matrix[0].size(); j++){
                if(s1.empty()){
                    s1.push(j);
                    left.push_back(-1);
                }
                else{
                    while(s1.empty()!=true && temp[i][s1.top()]>=temp[i][j]){
                        s1.pop();
                    }
                    if(s1.empty()){
                        left.push_back(-1);
                    }
                    else{
                        left.push_back(s1.top());
                    }
                    s1.push(j);
                }
            }
            while(!s1.empty()) s1.pop();
            for (int j=matrix[0].size()-1; j>=0; j--){
                if(s1.empty()){
                    s1.push(j);
                    right.push_back(-1);
                }
                else{
                    while(s1.empty()!=true && temp[i][s1.top()]>=temp[i][j]){
                        s1.pop();
                    }
                    if(s1.empty()){
                        right.push_back(-1);
                    }
                    else{
                        right.push_back(s1.top());
                    }
                    s1.push(j);
                }
            }
            reverse(right.begin(), right.end());
            int ans=0;
            for (int j=0; j<matrix[0].size(); j++){
                int l=left[j];
                int r=right[j];
                if(r==-1) r=matrix[0].size();
                ans=max(ans, temp[i][j]*(r-l-1) );
            }
            finalans=max(finalans, ans);
        }
        return finalans;
    }
};
