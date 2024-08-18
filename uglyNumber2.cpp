class Solution {
public:
    int nthUglyNumber(int n) {
        unordered_set<long long>s;
        priority_queue<long long, vector<long long>, greater<long long>>q;
        q.push(1);
        s.insert(1);
        while(n>1){
            long long curr_n=q.top();
            q.pop();
            n--;
            if(s.find(curr_n*2)==s.end()){
                s.insert(curr_n*2);
                q.push(curr_n*2);
            }
            if(s.find(curr_n*3)==s.end()){
                s.insert(curr_n*3);
                q.push(curr_n*3);
            }
            if(s.find(curr_n*5)==s.end()){
                s.insert(curr_n*5);
                q.push(curr_n*5);
            }
        }
        return q.top();
    }
};
