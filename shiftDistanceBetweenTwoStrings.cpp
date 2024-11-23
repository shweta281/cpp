class Solution {
public:
    long long knext(vector<int>& next, int s, int step){
        int i = s;
        long ans = 0;
        while(step > 0){
            if(i >= 26){
                i = 0;
            }
            ans += next[i];
            step--;
            i++;
        }
        return ans;
    }
long long kprev(vector<int>& prev, int s, int step){
        int i = s;
        long long ans = 0;
        while(step > 0){
            if(i < 0){
                i = 25;
            }
            ans += prev[i];
            step--;
            i--;
        }
        return ans;
    }
    long long shiftDistance(string s, string t, vector<int>& next, vector<int>& p) {
        long long kans = 0;
        int n = s.length();
        for (int i = 0; i < n; i++){
            if(s[i] == t[i]){
                continue;
            }
            int l = s[i] - 'a';
            int steps = t[i] - 'a';
            int lsteps= steps, rsteps = steps;
            if(steps < l){
                rsteps = 26 - l + steps; 
            } else {
                rsteps = steps - l;
            }
            if(steps > l){
                lsteps = l + 26 - steps;
            } else {
                lsteps = l - steps;
            }
            // cout<<l<<" "<<rsteps<<" "<<lsteps<<endl;
            kans += min(knext(next, l, rsteps), kprev(p, l, lsteps));
        }
        return kans;
    }
};
