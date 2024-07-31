class Solution {
public:
    int minSwaps(string s) {
        //checking for odd as 1
        int turn10=0;
        int turn11=0;
        for (int i=0; i<s.length(); i++){
            if(i&1){
                if(s[i]!='1'){
                    turn11++;
                }
            }
            else{
                if(s[i]!='0'){
                    turn10++;
                }
            }
        }
        //checking for odd as 0
        int ans=INT_MAX;
        if(turn10==turn11) ans=turn10;
        int turn00=0;
        int turn01=0;
        for (int i=0; i<s.length(); i++){
            if(i&1){
                if(s[i]!='0'){
                    turn01++;
                }
            }
            else{
                if(s[i]!='1'){
                    turn00++;
                }
            }
        }
        if(turn01==turn00) ans=min(ans,turn01);
        if(ans==INT_MAX) return -1;
        return ans;

    }
};
