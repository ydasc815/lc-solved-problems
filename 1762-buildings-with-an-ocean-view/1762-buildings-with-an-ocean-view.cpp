class Solution {
public:
    vector<int> findBuildings(vector<int>& h) {
        vector<int> res; res.push_back(h.size()-1);
        int mx = h[h.size()-1];
        for(int i=h.size()-2; i>=0; i--) {
            if(h[i] > mx) {
                res.push_back(i);
                mx = h[i];
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};