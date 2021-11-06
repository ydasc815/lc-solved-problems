class Solution {
public:
    int findDuplicate(vector<int>& n) {
        map<int, int> m;
        for(int i:n) {
            m[i]++;
            if(m[i] > 1) return i;
        }
        return -1;
    }
};