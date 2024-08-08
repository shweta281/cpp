class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rstart, int cstart) {
        // vector<vector<int>>ans(rows, vector<int>(cols, 0));
        vector<vector<int>>finals;
        int up=rstart;//0
        int down=rstart+1;//1
        int left=cstart;//0
        int right=cstart+1;//1
        int count=1;
        while(count<=rows*cols){
            for (int i=left; i<right; i++){
                // cout<<i<<" "<<up<<" ";
                if(count>rows*cols || up<0) break;
                if(i>=cols || i<0) continue;
                // ans[up][i]=count;
                finals.push_back({up, i});
                count++; 
            }
            left--;
            for (int i=up; i<down; i++){
                // cout<<i<<" "<<right<<" ";
                if(count>rows*cols || right>=cols) break;
                if(i>=rows || i<0) continue;
                // ans[i][right]=count;
                finals.push_back({i, right});
                count++; 
            }
            up--;
            for (int i=right; i>left; i--){
                // cout<<i<<" "<<down<<" ";
                if(count>rows*cols || down>=rows) break;
                if(i<0 || i>=cols) continue;
                // ans[down][i]=count;
                finals.push_back({down, i});
                count++; 
            }
            right++;
            for (int i=down; i>up; i--){
                // cout<<i<<" "<<left<<" ";
                if(count>rows*cols || left<0) break;
                if(i<0 || i>=rows) continue;
                // ans[i][left]=count;
                finals.push_back({i, left});
                count++; 
            }
            down++;
            // cout<<count<<endl;
        }
        return finals;
    }
};
