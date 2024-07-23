class Solution {
public:
    string losingPlayer(int x, int y) {
        int i=0;
        while(x>=1 && y>=4){
            x-=1;
            y-=4;
            i=1-i;
        }
        if(i==1) return "Alice";
        return "Bob";
    }
};
