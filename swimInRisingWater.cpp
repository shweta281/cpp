#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution {
public:
    struct Compare {
        bool operator()(vector<int> const & a, vector<int> const & b)
        { return a[2] > b[2]; }
    };
    int di[4]={ -1,1,0,0 };
    int dj[4]={ 0,0,-1,1 };
    int swimInWater(vector<vector<int> >& grid) {
        priority_queue<vector<int> , vector<vector<int> >, Compare >q;
        int ans=INT_MAX;
        int arr[]={0,0,grid[0][0]};
        vector<int>temp(arr, arr+3);
        q.push(temp);
        // vector<vector<vector<int>>>vis(grid.size(), vector<vector<int>>(grid.size(),vector<int>(grid.size()*grid.size(),0)));
        vector<vector<int> >vis(grid.size(), vector<int>(grid.size(),0));
        while(q.empty()!=true){
            int i=q.top()[0];
            int j=q.top()[1];
            int time=q.top()[2];
            q.pop();
            vis[i][j]=1;
            // cout<<i<<" "<<j<<" "<<time<<endl;
            if(i==grid.size()-1 && j==grid[0].size()-1 ) return time;
            for (int k=0;k<4;k++){
                // cout<<(di[k]+i)<<" "<<(dj[k]+j)<<" "<<vis[]<<endl;
                if(di[k]+i<0 ||  di[k]+i>=grid.size() || dj[k]+j<0 || 
                dj[k]+j>=grid[0].size() || vis[di[k]+i][dj[k]+j]!=0){
                    continue;
                }
                int arr1[]={di[k]+i,dj[k]+j,max(grid[di[k]+i][dj[k]+j],time)};
                vector<int>temp1(arr1, arr1+3);
                q.push(temp1);
            }
            
        }
        return ans;
    }
};
int main(){
    Solution* s= new Solution();
    int arr[][5]= {{0,1,2,3,4},
                  {24,23,22,21,5},
                  {12,13,14,15,16},
                  {11,17,18,19,20},
                  {10,9,8,7,6}};
    vector<vector<int> >grid;
    for (int i=0; i<sizeof(arr)/sizeof(arr[0]); i++){
        vector<int>temp(arr[i], arr[i]+ sizeof(arr[i])/sizeof(int));
        grid.push_back(temp);
        }
    cout<<s->swimInWater(grid)<<endl;
    
    }
