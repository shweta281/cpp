class Solution {
public:

    int helper( vector<vector<int>>& books, int i, int shelf, vector<int>&mem){
        if(i>=books.size()) return 0;
        if(mem[i]!=-1) return mem[i];
        int ans=INT_MAX;
        int curr_width=shelf;
        int maxheight=0;
        for (int j=i; j<books.size(); j++){
            if(curr_width>=books[j][0]){
                maxheight=max(maxheight, books[j][1]);
                curr_width-=books[j][0];
                ans=min(ans,helper(books, j+1, shelf, mem )+maxheight);
            }
            else{
                break;
            }
        }
        return mem[i]=ans;
    }
    int minHeightShelves(vector<vector<int>>& books, int shelf) {
        vector<int>mem(books.size(), -1);
        return helper(books, 0, shelf, mem);
    }
};
