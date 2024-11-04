#include <sstream>
using namespace std;

class Solution {
public:
    string compressedString(string &word) {
        string comp = "";
        int n = word.size();
        for (int i = 0; i < n; i++) {
            char curr = word[i];
            int count = 0;
            while (i < n && word[i] == curr && count < 9) {
                i++;
                count++;
            }
            i--; 
            comp.push_back(count+'0');
            comp.push_back(curr);  
        }
        return comp;
    }
};
