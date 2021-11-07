class Solution {
public:
    string pushDominoes(string d) {
        d = 'L' + d + 'R';
        int ptr=0;
        while(ptr<d.length()) {
            if(d[ptr] == '.') {
                int start=ptr-1;
                while(d[ptr] == '.') ptr++;
                int end=ptr;
                query(d,start,end);
            } else ptr++;
        }
        d.pop_back();
        return d.substr(1);
    }
    
    void query(string& s, int start, int end) {
        if(s[start] == 'R' && s[end] == 'L') {
            int i=start+1, j=end-1;
            while(i<j) {
                s[i] = s[start];
                s[j] = s[end];
                i++, j--;
            }
        } else if(s[start] == s[end]) {
            int i=start+1;
            while(i<end) {
                s[i] = s[start];
                i++;
            }
        }
    }
};