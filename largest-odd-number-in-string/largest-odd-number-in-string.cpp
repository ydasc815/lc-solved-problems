class Solution {
public:
    string largestOddNumber(string n) {
        int i = n.length()-1;
        while(i >= 0) {
            if((n[i] - '0') % 2 != 0) {
                return n.substr(0, i+1);
            }
            i--;
        }
        return "";
    }
};