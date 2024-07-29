class Solution {
public: 
    int desc(vector<int>&arr, int prev, int curr, int s, vector<vector<int>>&vis1){
        if(s==0) return 1;
        if(curr>=arr.size()) return 0;
        if(vis1[prev+1][s-1]!=-1) return vis1[prev+1][s-1];
        if(prev==-1){
            return vis1[prev+1][s-1]=desc(arr, curr, curr+1, s-1, vis1)+ 
            desc(arr,prev,curr+1,s, vis1);
        }
        else{
            if(arr[prev]>arr[curr]){
                return vis1[prev+1][s-1]= 
                desc(arr, curr, curr+1, s-1, vis1)+ desc(arr,prev,curr+1,s, vis1);
            }
            else{
                return vis1[prev+1][s-1]= desc(arr, prev, curr+1, s, vis1);
            }
        }
    }
    int asc(vector<int>&arr, int prev, int curr, int s, vector<vector<int>>&vis2){
        if(s==0) return 1;
        if(curr>=arr.size()) return 0;
        if(vis2[prev+1][s-1]!=-1) return vis2[prev+1][s-1];
        if(prev==-1){
            return vis2[prev+1][s-1]= asc(arr, curr, curr+1, s-1, vis2)+ 
            asc(arr,prev,curr+1,s, vis2);
        }
        else{
            if(arr[prev]<arr[curr]){
                return vis2[prev+1][s-1]= asc(arr, curr, curr+1, s-1, vis2)+ 
                asc(arr,prev,curr+1,s, vis2);
            }
            else{
                return vis2[prev+1][s-1]= asc(arr, prev, curr+1, s, vis2);
            }
        }
    }
    int numTeams(vector<int>& rating) {
        vector<vector<int>>vis1(rating.size(), vector<int>(3,-1));
        vector<vector<int>>vis2(rating.size(), vector<int>(3,-1));
        return desc(rating, -1, 0, 3, vis1)+ asc(rating, -1, 0, 3, vis2);
    }
};
