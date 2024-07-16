#include<iostream>
#include<map>
#include<vector>
#include<queue>
using namespace std;

class Solution{
    public:
    int minlen( string s1, string s2){
        return min(s1.length(), s2.length());
    }
    bool pref(string s1, string s2, int kmin){
        for ( int i=0;i<kmin;i++){
            if(s1[i]!=s2[i]) return false;
        }
        return true;
    }
    string alienDictionary(string dict[], int n, int k) {
        map<char,vector<char> >adjlist;
        map<char, int>indeg;
        for (int i=0;i<n-1;i++){
            string w1=dict[i],w2=dict[i+1];
            if(w1.length()>w2.length() && pref(w1,w2,minlen(w1,w2))) return "";
            for (int j=0;j<minlen(w1,w2); j++){
                if(w1[j]!=w2[j]){
                    adjlist[w1[j]].push_back(w2[j]);
                    indeg[w2[j]]++;
                    indeg[w1[j]]=max(0,indeg[w1[j]]);
                    break;
                    
                }
            }
        }
        queue<char>q;
        for ( map<char,int>::iterator i= indeg.begin(); i!=indeg.end();i++){
            // cout<<(i->first)<<":"<<i->second<<endl;
            if(i->second==0) q.push(i->first);
        }
        string ans="";
        while(q.empty()!=true){
            char ch=q.front();
            ans+=ch;
            q.pop();
            for ( int i=0; i<adjlist[ch].size();i++){
                indeg[adjlist[ch][i]]--;
                if(indeg[adjlist[ch][i]]==0){
                    q.push(adjlist[ch][i]);
                }
            }
        }
        // cout<<ans<<endl;
        return ans;
    }
};

int main(){
    Solution* s= new Solution();
    string dict[]={"baa","abcd","abca","cab","cad"};
    cout<<s->alienDictionary(dict, 5, 4);
    }
