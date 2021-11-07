class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        set<string> st;
        for(string temp:d) {
            int i=0, j=0;
            while(i<s.length()) {
                if(s[i] == temp[j]) j++;
                i++;
                if(j == temp.length()) break;
            }
            if(j == temp.length()) st.insert(temp);
        }
        string ret = "";
        for(auto& i:st) {
            if(i.length() > ret.length()) ret = i;
        }
        return ret;
    }
};