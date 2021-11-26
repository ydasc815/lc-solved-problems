class Solution {
public:
    int wateringPlants(vector<int>& p, int c) {
        int cnt = 0, k = c, i = 0;
        while(i < p.size()) {
            if(p[i] <= k) {
                cnt++;
                k -= p[i];
            } else {
                cnt += 2*(i+1) - 1;
                k = c - p[i];
            } i++;
        }
        return cnt;
    }
};