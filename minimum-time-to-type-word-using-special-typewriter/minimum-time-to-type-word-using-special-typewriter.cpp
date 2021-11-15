class Solution {
public:
    int minTimeToType(string w) {
        int cnt = w.length();
        char curr = 'a';
        for(int i=0; i<w.length(); i++) {
            cnt += min(abs(curr - w[i]), abs(26 - abs(curr - w[i])));
            curr = w[i];
        }
        return cnt;
    }
};