class Solution {
public:
    int trap(vector<int>& h) {
        vector<int> premax(h.size(), 0), sufmax(h.size(), 0);
        int curmax = h[0];
        for(int i=0; i<h.size(); i++) {
            curmax = max(curmax, h[i]);
            premax[i] = curmax;
        }
        curmax = h[h.size()-1];
        for(int i=h.size()-1; i>=0; i--) {
            curmax = max(curmax, h[i]);
            sufmax[i] = curmax;
        }
        int ans = 0;
        for(int i=0; i<h.size(); i++) {
            ans += min(premax[i], sufmax[i]) - h[i];
        }
        return ans;
    }
};