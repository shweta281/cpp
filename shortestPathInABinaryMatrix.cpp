class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1) return -1;
        priority_queue<pair<pair<int,int>,int>, vector<pair<pair<int,int>,int>>,
         compare>q;
        q.push({{0,0},1});
        vector<int>di={-1,1,0,0,-1,-1,1,1};
        vector<int>dj={0,0,-1,1,-1,1,-1,1};
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),-1));
        vis[0][0]=0;
        while(q.empty()!=true){
            int i=q.top().first.first;
            int j=q.top().first.second;
            int count=q.top().second;
            q.pop();
            if(i==grid.size()-1 && j==grid[0].size()-1) return count;
            for (int k=0;k<8;k++){
                if(i+di[k]<0 || j+dj[k]<0 || i+di[k]>=grid.size() || j+dj[k]>=grid[0].size())
                    continue;
                if(grid[i+di[k]][j+dj[k]]==1 || vis[i+di[k]][j+dj[k]]!=-1) continue;
                vis[i+di[k]][j+dj[k]]=0;
                q.push({{i+di[k],j+dj[k]},count+1});
            }
        }
        return -1;
    }
};
