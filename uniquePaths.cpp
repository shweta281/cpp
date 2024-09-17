class Solution {
public:
//nCr
//8!
// 3! 5!
    int uniquePaths(int m, int n) {
        if(m==1 || n==1) return 1;
        double ans=1;
        double t=min(m,n)-1;
        for (int i=m+n-2; i>=max(m ,n); i--){
            cout<<i<<endl;
            if(t<=0) t=1;
            if(i/t == floor(i/t)){
                ans*=i/t;
                t--;
            } else {
                ans*=i;
            }
            
        }
        while(t>1){
            ans/=t;
            t--;
        }
        return ans;
        //
    }
};
