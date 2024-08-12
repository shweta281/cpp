class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int>seti;
        unordered_set<int>setj;
        for (int i=0; i<matrix.size(); i++){
            for (int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j]==0){
                    seti.insert(i);
                    setj.insert(j);
                }
            }
        }
        for (int i=0; i<matrix.size(); i++){
            for (int j=0; j<matrix[0].size(); j++){
                if(seti.find(i)!=seti.end()) matrix[i][j]=0;
                if(setj.find(j)!=setj.end()) matrix[i][j]=0;
            }
        }
    }
};
