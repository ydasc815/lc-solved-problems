class Solution {
public:
    int removeDuplicates(vector<int>& n) {
        int i=0;
        while(i != n.size()) {
            if(i+2 < n.size() && n[i] == n[i+1] && n[i+1] == n[i+2]) n.erase(n.begin()+i+2);
            else i++;
        }
        return n.size();
    }
};