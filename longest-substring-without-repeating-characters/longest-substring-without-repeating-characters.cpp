class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        map<char, int> m;
        int i=0, j=1, ans = 1;
        m[s[i]]++;
        while(j < s.length()) {
            if(m[s[j]] == 0) {
                m[s[j]]++, j++;
                ans = max(ans, j-i);
            } else {
                m[s[i]]--; i++;
            }
        }
        return ans;
    }
};