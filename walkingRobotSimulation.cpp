class Solution {
public:
//1 north 2 south -1 right -2 left
    int robotSim(vector<int>& comm, vector<vector<int>>& obs) {
        set<vector<int>>s(obs.begin(), obs.end());
        int x=0, y=0;
        int dir=1;
        int ans=0;
        for (int i=0; i<comm.size(); i++){
            if(comm[i]==-1){
                if(dir==1) dir=-1;
                else if(dir==2) dir=-2;
                else if(dir==-1) dir=2;
                else dir=1;
            }
            else if(comm[i]==-2){
                if(dir==1) dir=-2;
                else if(dir==2) dir=-1;
                else if(dir==-1) dir=1;
                else dir=2;
            }
            else{
                if(dir==1){
                    for (int j=1; j<=comm[i]; j++){
                        if(s.find({x, y+1})!=s.end()){
                            break;
                        }
                        y++;
                    }
                }
                else if(dir==2){
                    for (int j=1; j<=comm[i]; j++){
                        if(s.find({x, y-1})!=s.end()){
                            break;
                        }
                        y--;
                    }
                }
                else if(dir==-1){
                    for (int j=1; j<=comm[i]; j++){
                        if(s.find({x+1, y})!=s.end()){
                            break;
                        }
                        x++;
                    }
                }
                else{
                    for (int j=1; j<=comm[i]; j++){
                        if(s.find({x-1, y})!=s.end()){
                            break;
                        }
                        x--;
                    }
                }
            }
            cout<<x<<" "<<y<<endl;
            ans=max(ans, x*x + y*y);
        }
        cout<<x<<" "<<y<<endl;
        return ans;
    }
};
