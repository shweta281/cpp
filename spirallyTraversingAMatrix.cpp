//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int counter=0;
        int left=0;
        int right=m-1;
        int up=0;
        int down=n-1;
        vector<int>ans;
        while(counter<m*n){
            for (int i=left; i<=right; i++){
                if(counter>=m*n) break;
                ans.push_back(matrix[up][i]);
                counter++;
            }
            up++;
            for (int i=up; i<=down; i++){
                if(counter>=m*n) break;
                ans.push_back(matrix[i][right]);
                counter++;
            }
            right--;
            for (int i=right; i>=left; i--){
                if(counter>=m*n) break;
                ans.push_back(matrix[down][i]);
                counter++;
            }
            down--;
            for (int i=down; i>=up; i--){
                if(counter>=m*n) break;
                ans.push_back(matrix[i][left]);
                counter++;
            }
            left++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
