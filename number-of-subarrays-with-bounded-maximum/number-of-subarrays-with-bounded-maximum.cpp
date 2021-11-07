class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& n, int l, int r) {
        int ans=0, left=-1, right=-1;
        for(int i=0; i<n.size(); i++) {
            if(n[i] > r) left = i;
            if(n[i] >= l) right = i;
            ans += right-left;
        }
        return ans;
    }
};