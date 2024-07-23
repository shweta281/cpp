class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord==endWord) return 0;
        unordered_set<string> s(wordList.begin(), wordList.end());
        queue<pair<string, int>>q;
        q.push({beginWord, 1});
        while(q.empty()!=true){
            string word=q.front().first;
            int ans=q.front().second;
            q.pop();
            if(word==endWord) return ans;
            // cout<<word<<endl;
            for (int i=0;i<word.length(); i++){
                string newword=word;
                for ( char letter='a'; letter<='z';letter++){
                    newword[i]=letter;
                    if(s.find(newword)!=s.end()){
                        if(newword==endWord) return ans+1;
                        s.erase(newword);
                        q.push({newword, ans+1});
                    }
                }
            } 
        }
        return 0;
    }
};
