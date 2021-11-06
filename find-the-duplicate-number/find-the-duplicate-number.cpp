class Solution {
public:
    int findDuplicate(vector<int>& n) {
        int s = n[0], f = n[0];
        do {
            s = n[s];
            f = n[n[f]];
        } while(s != f);
        f = n[0];
        while(f != s) {
            s = n[s];
            f = n[f];
        }
        return s;
    }
};