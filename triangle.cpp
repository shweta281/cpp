class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int ans=INT_MAX;
        int size=0;
        for (int i=0; i<triangle.size()-1; i++){
            size=triangle[i].size();
            vector<int>temp(size+1, INT_MAX);
            for (int j=0; j<size; j++){
                int left=j;
                int right=j+1;
                temp[left]=min(temp[left], triangle[i][j]+triangle[i+1][left]);
                if(right<=size){
                    temp[right]=min(temp[right], triangle[i][j]+triangle[i+1][right]);
                }

            }
            // for (int d=0; d<size+1; d++){
            //     cout<<temp[d]<<endl;
            // }
            triangle[i+1]=temp;
        }
        // cout<<size<<endl;
        for (int i=0; i<size+1; i++){
            ans=min(ans, triangle[size][i]);
        }
        return ans;
    }
};
