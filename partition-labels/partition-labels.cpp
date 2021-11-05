class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char, int> m; int x = 0;
        set<char> st;
        vector<int> v;
        for(char c:s) m[c]++;
        for(int i=0; i<s.length(); i++) {
            m[s[i]]--;
            if(m[s[i]] > 0) st.insert(s[i]);
            else {
                st.erase(s[i]);
                if(st.size() == 0) {
                    v.push_back(i - x + 1);
                    x = i+1;
                }
            }
        }
        return v;
    }
};