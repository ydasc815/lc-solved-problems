class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> m(128, 0);
        for(char c:t) m[c]++;
        int cntr = t.size(), start = 0, end = 0, head = 0, d = INT_MAX;
        while(end < s.size()) {
            if(m[s[end++]]-- > 0) cntr--;
            while(cntr == 0) {
                if(end - start < d) d = end - (head=start);
                if(m[s[start++]]++ == 0) cntr++;
            }
        }
        return d == INT_MAX ? "" : s.substr(head, d);
    }
};